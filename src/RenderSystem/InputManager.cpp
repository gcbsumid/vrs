#include "InputManager.hpp"
#include <iostream>

InputManager::InputManager() 
    : mMouse(nullptr)
    , mKeyboard(nullptr)
    , mInputSystem(nullptr) 
    {}

InputManager::~InputManager() {
    if (mInputSystem) {
        if (mMouse) {
            mInputSystem->destroyInputObject(mMouse);
            mMouse = nullptr;
        }

        if (mKeyboard) {
            mInputSystem->destroyInputObject(mKeyboard);
            mKeyboard = nullptr;
        }
        
        mInputSystem->destroyInputSystem(mInputSystem);
        mInputSystem = nullptr;

        // Clear Listeners
        mKeyListeners.clear();
        mMouseListeners.clear();
    }
}

void InputManager::initialise(Ogre::RenderWindow *renderWindow) {
    if (!mInputSystem) {
        // Setup of basic variables
        OIS::ParamList paramList;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;

        // Get window handle
        renderWindow->getCustomAttribute("WINDOW", &windowHnd);

        // Fill parameter list
        windowHndStr << (unsigned int) windowHnd;
        paramList.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

        // Create Input System
        mInputSystem = OIS::InputManager::createInputSystem(paramList);

        // create a buffered keyboard
        if (mInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
            mKeyboard = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject(OIS::OISKeyboard, true));
            mKeyboard->setEventCallback(this);
        }

        // create a buffered mouse
        if (mInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
            mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject( OIS::OISMouse, true));
            mMouse->setEventCallback(this);
 
            // Get window size
            unsigned int width, height, depth;
            int left, top;
            renderWindow->getMetrics(width, height, depth, left, top);
 
            // Set mouse region
            this->setWindowExtents(width, height);
        }
    }
}

void InputManager::capture( void ) {
    // Need to capture / update each device every frame
    if (mMouse) {
        mMouse->capture();
    }
 
    if (mKeyboard) {
        mKeyboard->capture();
    }
}

void InputManager::addKeyListener(OIS::KeyListener *keyListener, const std::string name) {
    if (mKeyboard) {
        // Check for duplicate items
        if (mKeyListeners.count(name) == 0) {
            mKeyListeners[name] = keyListener;
        }
    }
}
 
void InputManager::addMouseListener(OIS::MouseListener *mouseListener, const std::string name) {
    if (mMouse) {
        // Check for duplicate items
        if (mMouseListeners.count(name) == 0) {
            mMouseListeners[name] = mouseListener;
        }
    }
}
 
void InputManager::removeKeyListener(const std::string name) {
    // Check if item exists
    auto itKeyListener = mKeyListeners.find(name);
    if (itKeyListener != mKeyListeners.end()) {
        mKeyListeners.erase(itKeyListener);
    }
}
 
void InputManager::removeMouseListener(const std::string name) {
    // Check if item exists
    auto itMouseListener = mMouseListeners.find(name);
    if (itMouseListener != mMouseListeners.end()) {
        mMouseListeners.erase(itMouseListener);
    }
}
 
void InputManager::removeAllListeners( void ) {
    mKeyListeners.clear();
    mMouseListeners.clear();
}
 
void InputManager::removeAllKeyListeners( void ) {
    mKeyListeners.clear();
}
 
void InputManager::removeAllMouseListeners( void ) {
    mMouseListeners.clear();
}

void InputManager::setWindowExtents( int width, int height ) {
    // Set mouse region (if window resizes, we should alter this to reflect as well)
    const OIS::MouseState &mouseState = mMouse->getMouseState();
    mouseState.width  = width;
    mouseState.height = height;
}

bool InputManager::keyPressed( const OIS::KeyEvent &e ) {
    std::cout << "Trigger keyboard press!\n";
    for (auto& iter : mKeyListeners) {
        if (!iter.second->keyPressed(e)) {
            break;
        }
    }
 
    return true;
}
 
bool InputManager::keyReleased( const OIS::KeyEvent &e ) {
    for (auto& iter : mKeyListeners) {
        if (!iter.second->keyReleased(e)) {
            break;
        }
    }
 
    return true;
}
 
bool InputManager::mouseMoved( const OIS::MouseEvent &e ) {
    for (auto& iter : mMouseListeners) {
        if (!iter.second->mouseMoved(e)) {
            break;
        }
    }
 
    return true;
}
 
bool InputManager::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    for (auto& iter : mMouseListeners) {
        if (!iter.second->mousePressed(e, id)) {
            break;
        }
    }
 
    return true;
}

bool InputManager::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    for (auto& iter : mMouseListeners) {
        if (!iter.second->mouseReleased(e, id)) {
            break;
        }
    }
 
    return true;
}