#include "RenderSystem.hpp"
#include "Components/CameraComponent.hpp"
#include "OGRE/OgreSceneManager.h"
#include "OGRE/OgreLogManager.h"
#include "OGRE/OgreSceneNode.h"
#include "OGRE/OgreViewport.h"
#include "OGRE/OgreCamera.h"

#include <exception>
#include <vector>
#include <iostream>

RenderSystem::RenderSystem() :
    mRenderSystemConfigFileName(""),

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 
    mPluginConfigFileName("plugins_d.cfg"),
    mResourcesConfigFileName("resources_d.cfg"),
#else
    mPluginConfigFileName("plugins.cfg"),
    mResourcesConfigFileName("resources.cfg"),
#endif
    mLogFileName("renderSystem.log"),
    mResourceManager(new ResourceManager()),
    mWindowWidth(800),
    mWindowHeight(600),
    mFullScreen(false) {

}

RenderSystem::~RenderSystem() {

}

void RenderSystem::run() {
    // mInputManager->capture();
    Ogre::SceneNode* lightNode = mSceneManager->getSceneNode("sun");
    Ogre::Degree angle(2.5);
    lightNode->yaw(angle);

    mWindow->update(false);
    mWindow->swapBuffers();
    mRoot->renderOneFrame();
    Ogre::WindowEventUtilities::messagePump();
}

void RenderSystem::loadResources() {
    mResourceManager->loadResourcesFromConfigFile(mResourcesConfigFileName);
}

void RenderSystem::initialize(std::shared_ptr<ServiceManager> serviceManager) {
    mServiceManager = serviceManager;
    mServiceManager->registerRenderInterface((IRenderSystem*)this);
    try {
        // Create the Ogre root object
        std::cerr << "mPlugin: " << mPluginConfigFileName << std::endl;
        std::unique_ptr<Ogre::Root> root(new Ogre::Root(mPluginConfigFileName, mRenderSystemConfigFileName, mLogFileName));
        mRoot = std::move(root);

        const Ogre::RenderSystemList& mRenderSystemList = mRoot->getAvailableRenderers();
        if (mRenderSystemList.size() == 0) {
            Ogre::LogManager::getSingleton().logMessage("Sorry, no rendersystem was found.");
            throw std::runtime_error("No Render System was found.");
        }
        mRoot->setRenderSystem(mRenderSystemList[0]); 

        // initialize([create window automatically], [window name], [custom capabilities])
        mRoot->initialise(false, "Browser", "");

        Ogre::NameValuePairList mRenderingParams;
        mRenderingParams["FSAA"] = "0";
        mRenderingParams["vsync"] = "true";

        // Create Window
        mWindow = mRoot->createRenderWindow("Browser", mWindowWidth, mWindowHeight, mFullScreen, &mRenderingParams);

        // Create Scene Manager
        mSceneManager = mRoot->createSceneManager(Ogre::ST_GENERIC, "SceneManager");
        mRootSceneNode = mSceneManager->getRootSceneNode();

        // Resource Manager
        mResourceManager->initialize(mSceneManager, mRootSceneNode);

    } catch (Ogre::Exception &e) {
        std::cerr << "Ogre Exception: " << e.what() << std::endl;
    }
}

// void RenderSystem::addCommand(Command* command) {
//     // Todo: Implement
// }

// void RenderSystem::processCommands() {
//     // Todo: Implement
// }


// Temp
void RenderSystem::initScene(std::string dotSceneFilename) {
    loadResources();
    
    if (!dotSceneFilename.empty()) {
        // Todo: Implement dotScene parse
        return;
    }
    loadScene();
}

void RenderSystem::initCamera() {
    // Create Camera
    Ogre::Camera* camera = mSceneManager->createCamera("Camera");
    Ogre::SceneNode* cameraNode = mRootSceneNode->createChildSceneNode("CameraNode");
    cameraNode->attachObject(camera);

    // Create Viewport 
    float viewportWidth = 1.0f;
    float viewportHeight = 1.0f;
    float viewportLeft = 0.0f;
    float viewportTop = 0.0f;

    unsigned short mainViewportZOrder = 100;
    Ogre::Viewport* viewport = mWindow->addViewport(camera, mainViewportZOrder, viewportLeft, viewportTop, viewportWidth, viewportHeight);
    viewport->setAutoUpdated(true);
    viewport->setBackgroundColour(Ogre::ColourValue(1,0,1));

    // Camera Settings
    float ratio = float(viewport->getActualWidth()) / float(viewport->getActualHeight());
    camera->setAspectRatio(ratio);
    camera->setPosition(Ogre::Vector3(1683, 50, 2116));
    camera->lookAt(Ogre::Vector3(1963, 50, 1660));
    camera->setNearClipDistance(0.1f);
    if (mRoot->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_INFINITE_FAR_PLANE)) {
        // enable infinite far clip distance if we can
        camera->setFarClipDistance(0);   
    } else {
        camera->setFarClipDistance(50000.0f);
    }

    mWindow->setActive(true);
    mWindow->setAutoUpdated(false);
}

void RenderSystem::loadScene() {
    initCamera();

    // Set Lights 
    Ogre::Vector3 lightDir(0.55, -0.3, 0.75);
    lightDir.normalise();
    Ogre::Light* light = mSceneManager->createLight("sun");
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    light->setDirection(lightDir);
    light->setDiffuseColour(Ogre::ColourValue::White);
    light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));
    mSceneManager->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

    // terrainGlobals = OGRE_NEW Ogre::TerrainGlobalOptions();


    // // Creating monster head entity
    // Ogre::SceneNode* node = mRootSceneNode->createChildSceneNode("MonsterHead");
    // Ogre::Entity* mosterHeadEntity = mSceneManager->createEntity("MonsterHead.mesh");
    // node->attachObject(mosterHeadEntity);

    // // Creating sun
    // Ogre::SceneNode* lightNode = mRootSceneNode->createChildSceneNode("sun");
    // Ogre::Light* light = mSceneManager->createLight("sun");
    // light->setType(Ogre::Light::LT_DIRECTIONAL);
    // light->setDiffuseColour(Ogre::ColourValue::White);
    // light->setSpecularColour(Ogre::ColourValue::White);
    // lightNode->attachObject(light);

    // // setting the ambient light
    // Ogre::ColourValue ambientLight(0.2f, 0.2f, 0.2f, 1.0f);
    // mSceneManager->setAmbientLight(ambientLight);

    // std::string nameOfResourceGroup = "Scene 1";
    // Ogre::ResourceGroupManager& resourceGroupManager = Ogre::ResourceGroupManager::getSingleton();
    // resourceGroupManager.createResourceGroup("nameOfResourceGroup");

    // for (int i = 0; i < 5; i++) {
    //     Ogre::Entity* entity = mSceneManager->createEntity("MonsterHead.mesh");
    //     Ogre::SceneNode* node = mRootSceneNode->createChildSceneNode();
    //     node->attachObject(entity);

    //     float positionOffset = float(1+i*2) - float(5);
    //     positionOffset = positionOffset * 20;
    //     node->translate(positionOffset, positionOffset, -200.0f);

    //     entity->setMaterialName("BaseWite");
    // }
}

Ogre::RenderWindow* RenderSystem::getRenderWindow() {
    return mWindow;
}

void RenderSystem::clearEventTimes() {
    // Clears OS messages (e.g. Input messages)
    mRoot->clearEventTimes();
}

bool RenderSystem::isWindowClosed() {
    return mWindow->isClosed();
}

void RenderSystem::logMessage(std::string msg) {    
    Ogre::LogManager::getSingleton().logMessage(msg);
}

Component* RenderSystem::createComponent(ComponentType type) {
    // Todo: Create components
    Component* comp = nullptr;
    switch (type) {
        case ComponentType::CAMERA: 
        {
            CameraComponent* cameraComp = new CameraComponent;
            cameraComp->initialize(mSceneManager, mRootSceneNode, mWindow, true);
            comp = (Component*)cameraComp; 
        }
            break;
        case ComponentType::LIGHT:

        case ComponentType::TERRAIN:

        default: 
            // Error
            break;
    }
    return comp;
}