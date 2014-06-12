#include "MouseComponent.hpp"

MouseComponent::MouseComponent() 
    : Component()
    // , mKeyboard(nullptr) 
{

}

MouseComponent::~MouseComponent() {
    // mKeyboard = nullptr;
}

void MouseComponent::initialize() {

}

bool MouseComponent::mouseMoved(const OIS::MouseEvent &e) {
    // handle mouse moved
    return true;
}

bool MouseComponent::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    // handle mouse pressed
    return true;
}

bool MouseComponent::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    // handle mouse release
    return true;
}