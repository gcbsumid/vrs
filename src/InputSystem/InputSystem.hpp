#ifndef INPUTMANGER_HPP
#define INPUTMANGER_HPP 

#include <memory>
#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISInputManager.h>
// #include <OISJoyStick.h>

#include <OgreRenderWindow.h>

#include "IInputSystem.hpp"
#include "../ServiceManager.hpp"

class InputSystem : public IInputSystem, public OIS::KeyListener, public OIS::MouseListener {
public:
    InputSystem();
    virtual ~InputSystem();

    void initialize(std::shared_ptr<ServiceManager> serviceManager, Ogre::RenderWindow *renderWindow);
    void capture();

    void addKeyListener(OIS::KeyListener *keyListener, const std::string name);
    void addMouseListener(OIS::MouseListener *mouseListener, const std::string name);

    void removeKeyListener(const std::string name);
    void removeMouseListener(const std::string name);

    void removeAllListeners();
    void removeAllKeyListeners();
    void removeAllMouseListeners();

    void setWindowExtents( int width, int height );

    // Public interface 
    virtual Component* createComponent(ComponentType type);

private:
    InputSystem(const InputSystem&) {}
    InputSystem& operator=(const InputSystem&);

    bool keyPressed(const OIS::KeyEvent &e);
    bool keyReleased(const OIS::KeyEvent &e);

    bool mouseMoved( const OIS::MouseEvent &e );
    bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    OIS::Mouse        *mMouse;
    OIS::Keyboard     *mKeyboard;
    OIS::InputManager *mOgreInputSystem;

    std::map<std::string, OIS::KeyListener*> mKeyListeners;
    std::map<std::string, OIS::MouseListener*> mMouseListeners;

    // Service Manager
    std::shared_ptr<ServiceManager> mServiceManager;
};

#endif