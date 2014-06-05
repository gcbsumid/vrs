#ifndef BASELISTENER_HPP
#define BASELISTENER_HPP

#include <OISMouse.h>
#include <OISKeyboard.h>

class BaseListener : public OIS::KeyListener, public OIS::MouseListener {
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