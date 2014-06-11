#include "InputSystem.hpp"
#include <iostream>

InputSystem::InputSystem() 
    : mMouse(nullptr)
    , mKeyboard(nullptr)
    , mOgreInputSystem(nullptr) 
    {}

InputSystem::~InputSystem() {
    if (mOgreInputSystem) {
        if (mMouse) {
            mOgreInputSystem->destroyInputObject(mMouse);
            mMouse = nullptr;
        }

        if (mKeyboard) {
            mOgreInputSystem->destroyInputObject(mKeyboard);
            mKeyboard = nullptr;
        }
        
        mOgreInputSystem->destroyInputSystem(mOgreInputSystem);
        mOgreInputSystem = nullptr;

        // Clear Listeners
        mKeyListeners.clear();
        mMouseListeners.clear();
    }
}

void InputSystem::initialize(std::shared_ptr<ServiceManager> serviceManager, Ogre::RenderWindow *renderWindow) {
    mServiceManager = serviceManager;
    mServiceManager->registerInputInterface((IInputSystem*)this);
    if (!mOgreInputSystem) {
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
        mOgreInputSystem = OIS::InputManager::createInputSystem(paramList);

        // create a buffered keyboard
        if (mOgreInputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) {
            mKeyboard = static_cast<OIS::Keyboard*>(mOgreInputSystem->createInputObject(OIS::OISKeyboard, true));
            mKeyboard->setEventCallback(this);
        }

        // create a buffered mouse
        if (mOgreInputSystem->getNumberOfDevices(OIS::OISMouse) > 0) {
            mMouse = static_cast<OIS::Mouse*>(mOgreInputSystem->createInputObject( OIS::OISMouse, true));
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

void InputSystem::capture( void ) {
    // Need to capture / update each device every frame
    if (mMouse) {
        mMouse->capture();
    }
 
    if (mKeyboard) {
        mKeyboard->capture();
    }
}

void InputSystem::addKeyListener(OIS::KeyListener *keyListener, const std::string name) {
    if (mKeyboard) {
        // Check for duplicate items
        if (mKeyListeners.count(name) == 0) {
            mKeyListeners[name] = keyListener;
        }
    }
}
 
void InputSystem::addMouseListener(OIS::MouseListener *mouseListener, const std::string name) {
    if (mMouse) {
        // Check for duplicate items
        if (mMouseListeners.count(name) == 0) {
            mMouseListeners[name] = mouseListener;
        }
    }
}
 
void InputSystem::removeKeyListener(const std::string name) {
    // Check if item exists
    auto itKeyListener = mKeyListeners.find(name);
    if (itKeyListener != mKeyListeners.end()) {
        mKeyListeners.erase(itKeyListener);
    }
}
 
void InputSystem::removeMouseListener(const std::string name) {
    // Check if item exists
    auto itMouseListener = mMouseListeners.find(name);
    if (itMouseListener != mMouseListeners.end()) {
        mMouseListeners.erase(itMouseListener);
    }
}
 
void InputSystem::removeAllListeners( void ) {
    mKeyListeners.clear();
    mMouseListeners.clear();
}
 
void InputSystem::removeAllKeyListeners( void ) {
    mKeyListeners.clear();
}
 
void InputSystem::removeAllMouseListeners( void ) {
    mMouseListeners.clear();
}

void InputSystem::setWindowExtents( int width, int height ) {
    // Set mouse region (if window resizes, we should alter this to reflect as well)
    const OIS::MouseState &mouseState = mMouse->getMouseState();
    mouseState.width  = width;
    mouseState.height = height;
}

bool InputSystem::keyPressed( const OIS::KeyEvent &e ) {
    std::cout << "Trigger keyboard press!\n";
    for (auto& iter : mKeyListeners) {
        if (!iter.second->keyPressed(e)) {
            break;
        }
    }
 
    return true;
}
 
bool InputSystem::keyReleased( const OIS::KeyEvent &e ) {
    for (auto& iter : mKeyListeners) {
        if (!iter.second->keyReleased(e)) {
            break;
        }
    }
 
    return true;
}
 
bool InputSystem::mouseMoved( const OIS::MouseEvent &e ) {
    for (auto& iter : mMouseListeners) {
        if (!iter.second->mouseMoved(e)) {
            break;
        }
    }
 
    return true;
}
 
bool InputSystem::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    for (auto& iter : mMouseListeners) {
        if (!iter.second->mousePressed(e, id)) {
            break;
        }
    }
 
    return true;
}

bool InputSystem::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    for (auto& iter : mMouseListeners) {
        if (!iter.second->mouseReleased(e, id)) {
            break;
        }
    }
 
    return true;
}

Component* InputSystem::createComponent(ComponentType type, std::string name) {
    // Todo: Create components
    Component* comp = nullptr;
    switch (type) {
        case ComponentType::INPUT: 
            break;
        default: 
            // Error
            break;
    }
    return comp;
}