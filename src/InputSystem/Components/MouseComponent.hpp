#ifndef MOUSECOMPONENT_HPP
#define MOUSECOMPONENT_HPP

#include <OISMouse.h>

#include "../../EntitySystem/Component.hpp"

class MouseComponent : public Component {
public:
    MouseComponent();
    virtual ~MouseComponent();

    // void initialize(OIS::InputManager* mOgreInputManager);
    void initialize();

    // MouseListener Interface
    virtual bool mouseMoved( const OIS::MouseEvent &e );
    virtual bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

private: 
    // OIS::Keyboard     *mKeyboard;
};

#endif