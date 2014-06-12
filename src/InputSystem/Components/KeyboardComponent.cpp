#include "KeyboardComponent.hpp"

KeyboardComponent::KeyboardComponent() 
    : Component()
    // , mKeyboard(nullptr) 
{

}

KeyboardComponent::~KeyboardComponent() {
    // mKeyboard = nullptr;
}

void KeyboardComponent::initialize() {

}

bool KeyboardComponent::keyPressed(const OIS::KeyEvent &e) {
    // handle keypress
    return true;
}

bool KeyboardComponent::keyReleased(const OIS::KeyEvent &e) {
    // handle keyrelease
    return true;
}