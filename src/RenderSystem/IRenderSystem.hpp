#ifndef IRENDERSYSTEM_HPP
#define IRENDERSYSTEM_HPP

#include "OGRE/OgreRenderWindow.h"
#include "../EntitySystem/Component.hpp"

class IRenderSystem {
public:
    virtual ~IRenderSystem() {}   
    virtual Ogre::RenderWindow* getRenderWindow() = 0;
    virtual Component* createComponent(ComponentType type) = 0;
    // virtual void addCommand(Command*) = 0;
};

#endif