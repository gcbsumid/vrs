#include "CameraComponent.hpp"

CameraComponent::CameraComponent() {

}

CameraComponent::~CameraComponent() {

}

void CameraComponent::initalise(Ogre::SceneManager* sceneManager, 
                                Ogre::SceneNode* parentNode, 
                                Ogre::RenderWindow* window, 
                                bool infiniteFarPlane) {
    mCamera = sceneManager->createCamera("Camera");
    mNode = parentNode->createChildSceneNode("CameraNode");
    mNode->attachObject(mCamera);

    // Create Viewport 
    float viewportWidth = 1.0f;
    float viewportHeight = 1.0f;
    float viewportLeft = 0.0f;
    float viewportTop = 0.0f;

    unsigned short mainViewportZOrder = 100;
    Ogre::Viewport* mViewport = window->addViewport(mCamera, mainViewportZOrder, viewportLeft, viewportTop, viewportWidth, viewportHeight);
    mViewport->setAutoUpdated(true);
    mViewport->setBackgroundColour(Ogre::ColourValue(1,0,1));

    // Camera Settings
    float ratio = float(mViewport->getActualWidth()) / float(mViewport->getActualHeight());
    mCamera->setAspectRatio(ratio);
    mCamera->setPosition(Ogre::Vector3(1683, 50, 2116));
    mCamera->lookAt(Ogre::Vector3(1963, 50, 1660));
    mCamera->setNearClipDistance(0.1f);
    if (infiniteFarPlane) {
        // enable infinite far clip distance if we can
        mCamera->setFarClipDistance(0);   
    } else {
        mCamera->setFarClipDistance(50000.0f);
    }

    window->setActive(true);
    window->setAutoUpdated(false);
}
