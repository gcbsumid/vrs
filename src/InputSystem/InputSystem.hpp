#ifndef INPUTMANGER_HPP
#define INPUTMANGER_HPP 

#include <memory>
#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISInputManager.h>
// #include <OISJoyStick.h>

#include <OgreRenderWindow.h>

#include "IInputSystem.hpp"
#include "Components/KeyboardComponent.hpp"
#include "Components/MouseComponent.hpp"
#include "../ServiceManager.hpp"

class InputSystem : public IInputSystem, public OIS::KeyListener, public OIS::MouseListener {
public:
    InputSystem();
    virtual ~InputSystem();

    void initialize(std::shared_ptr<ServiceManager> serviceManager, Ogre::RenderWindow *renderWindow);
    void capture();

    void addKeyListener(KeyboardComponent* keyListener, const std::string name);
    void addMouseListener(MouseComponent* mouseListener, const std::string name);

    void removeKeyListener(const std::string name);
    void removeMouseListener(const std::string name);

    void removeAllListeners();
    void removeAllKeyListeners();
    void removeAllMouseListeners();

    void setWindowExtents( int width, int height );

    // Public interface 
    virtual Component* createComponent(ComponentType type, std::string name);

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
    OIS::InputManager *mOgreInputManager;

    std::map<std::string, KeyboardComponent*> mKeyListeners;
    std::map<std::string, MouseComponent*> mMouseListeners;

    // Service Manager
    std::shared_ptr<ServiceManager> mServiceManager;
};

#endif