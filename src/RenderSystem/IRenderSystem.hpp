#ifndef IRENDERSYSTEM_HPP
#define IRENDERSYSTEM_HPP

#include "OGRE/OgreRenderWindow.h"
#include "../EntitySystem/Component.hpp"

class IRenderSystem {
public:
    virtual Ogre::RenderWindow* getRenderWindow() = 0;
    virtual Component* createComponent(ComponentType type, std::string name) = 0;
    // virtual void addCommand(Command*) = 0;
};

#endif