#ifndef KEYBOARDCOMPONENT_HPP
#define KEYBOARDCOMPONENT_HPP

#include <OISKeyboard.h>

#include "../../EntitySystem/Component.hpp"

class KeyboardComponent : public Component {
public:
    KeyboardComponent();
    virtual ~KeyboardComponent();

    // void initialize(OIS::InputManager* mOgreInputManager);
    void initialize();

    // KeyListener Interface
    virtual bool keyPressed(const OIS::KeyEvent &e);
    virtual bool keyReleased(const OIS::KeyEvent &e);

private: 
    // OIS::Keyboard     *mKeyboard;
};

#endif