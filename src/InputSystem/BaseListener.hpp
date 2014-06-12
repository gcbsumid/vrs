#ifndef BASELISTENER_HPP
#define BASELISTENER_HPP

#include "Components/KeyboardComponent.hpp"
#include "Components/MouseComponent.hpp"

// Todo: eventually remove this. This is only temporary

class BaseListener : public KeyboardComponent, public MouseComponent {
public:
    BaseListener();
    virtual ~BaseListener();

    bool keyPressed(const OIS::KeyEvent &e);
    bool keyReleased(const OIS::KeyEvent &e);

    bool mouseMoved( const OIS::MouseEvent &e );
    bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    bool isShutDown();
private:
    bool mShutDown;
};

#endif