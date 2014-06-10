#ifndef CAMERACOMPONENT_HPP
#define CAMERACOMPONENT_HPP 

#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreSceneNode.h"
#include "OGRE/OgreCamera.h"
#include "OGRE/OgreViewport.h"
#include "../../EntitySystem/Component.hpp"

class CameraComponent
{
public:
    CameraComponent();
    virtual ~CameraComponent();

    void initalise(Ogre::SceneManager* mSceneManager, Ogre::SceneNode* parentNode, Ogre::RenderWindow* window, bool infiniteFarPlane);

private:
    Ogre::SceneNode* mNode;
    Ogre::Camera* mCamera;
    Ogre::Viewport* mViewport;
};

#endif