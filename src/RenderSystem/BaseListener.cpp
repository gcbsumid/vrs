#include "BaseListener.hpp"
#include <iostream>

BaseListener::BaseListener() 
    : mShutDown(false)
    {
    
}

BaseListener::~BaseListener() {

}

bool BaseListener::keyPressed(const OIS::KeyEvent &e) {
    std::cout << "I'm pressing something!\n";
    switch (e.key) {
        case OIS::KC_ESCAPE: 
            mShutDown = true;
            break;
        default:
            break;
    }
    return true;
}

bool BaseListener::keyReleased(const OIS::KeyEvent &e) {
    return true;
}

bool BaseListener::mouseMoved( const OIS::MouseEvent &e ) {
    std::cout << "Mouse is moving!\n";
    return true;
}

bool BaseListener::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    return true;
}

bool BaseListener::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    return true;
}

bool BaseListener::isShutDown() {
    return mShutDown;
}