#include "RenderSystem.hpp"
#include "OGRE/OgreSceneManager.h"

#include <exception>
#include <vector>
#include <iostream>

using namespace VRS;

RenderSystem::RenderSystem() :
    mRenderSystemConfigFileName(""),
    mPluginConfigFileName("plugins.cfg"),
    mResourcesConfigFileName("resources.cfg"),
    mLogFileName("renderSystem.log"),
    mWindowWidth(800),
    mWindowHeight(600),
    mFullScreen(false) {

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

        // initialise([create window automatically], [window name], [custom capabilities])
        mRoot->initialise(false, "Browser", "");

        Ogre::NameValuePairList mRenderingParams;
        mRenderingParams["FSAA"] = "0";
        mRenderingParams["vsync"] = "true";

        // Create Window
        mWindow = mRoot->createRenderWindow("Browser", mWindowWidth, mWindowHeight, mFullScreen, &mRenderingParams);

        // Create Scene Manager
        mSceneManager = mRoot->createSceneManager(Ogre::ST_GENERIC, "SceneManager");
        mRootSceneNode = mSceneManager->getRootSceneNode();

        std::unique_ptr<ResourceManager> resMan(new ResourceManager(mSceneManager, mRootSceneNode));
        mResourceManager = std::move(resMan);
    } catch (Ogre::Exception &e) {
        std::cout << "Ogre Exception: " << e.what() << std::endl;
    }
}

RenderSystem::~RenderSystem() {
}

void RenderSystem::run() {
    // Clears OS messages (e.g. Input messages)
    mRoot->clearEventTimes();

    try {
        Ogre::SceneNode* lightNode = mSceneManager->getSceneNode("sun");
        while (!mWindow->isClosed()) {
            Ogre::Degree angle(2.5);
            lightNode->yaw(angle);

            mWindow->update(false);
            mWindow->swapBuffers();
            mRoot->renderOneFrame();
            Ogre::WindowEventUtilities::messagePump();
        }

        Ogre::LogManager::getSingleton().logMessage("endOfProgram");
    } catch (Ogre::Exception &e) {
        std::cout << "Ogre Exception: " << e.what() << std::endl;
    }
}

void RenderSystem::loadResources() {
    mResourceManager->loadResourcesFromConfigFile(mResourcesConfigFileName);
}

void RenderSystem::addCommand(Command* command) {
    // Todo: Implement
}

void RenderSystem::processCommands() {
    // Todo: Implement
}


// Temp
void RenderSystem::initScene(std::string dotSceneFilename = "") {
    loadResources();
    
    if (!dotSceneFilename.empty()) {
        // Todo: Implement dotScene parse
        return;
    }
    loadHome();
}

void RenderSystem::initCamera() {
    // Create Camera
    Ogre::Camera* camera = mSceneManager->createCamera("Camera");
    Ogre::SceneNode* cameraNode = mRootSceneNode->createChildSceneNode("CameraNode");
    cameraNode->attachObject(camera);

    // Create Viewport 
    float viewportWidth = 0.88f;
    float viewportHeight = 0.88f;
    float viewportLeft = (1.0 - viewportWidth) * 0.5f;
    float viewportTop = (1.0 - viewportHeight) * 0.5f;

    unsigned short mainViewportZOrder = 100;
    Ogre::Viewport* viewport = mWindow->addViewport(camera, mainViewportZOrder, viewportLeft, viewportTop, viewportWidth, viewportHeight);
    viewport->setAutoUpdated(true);
    viewport->setBackgroundColour(Ogre::ColourValue(1,0,1));

    // Camera Settings
    float ratio = float(viewport->getActualWidth()) / float(viewport->getActualHeight());
    camera->setAspectRatio(ratio);
    camera->setNearClipDistance(1.5f);
    camera->setFarClipDistance(3000.0f);

    mWindow->setActive(true);
    mWindow->setAutoUpdated(false);
}

void RenderSystem::loadHome() {
    initCamera();

    Ogre::SceneNode* node = mRootSceneNode->createChildSceneNode();
    mResourceManager->loadMesh("MonsterHead.mesh", node);
    Ogre::SceneNode* lightNode = mRootSceneNode->createChildSceneNode("sun");
    mResourceManager->addLight(Ogre::Light::LT_DIRECTIONAL, lightNode, "sun");

    Ogre::ColourValue ambientLight(0.2f, 0.2f, 0.2f, 1.0f);
    mSceneManager->setAmbientLight(ambientLight);

    std::string nameOfResourceGroup = "Scene 1";
    Ogre::ResourceGroupManager& resourceGroupManager = Ogre::ResourceGroupManager::getSingleton();
    resourceGroupManager.createResourceGroup("nameOfResourceGroup");

    for (int i = 0; i < 5; i++) {
        Ogre::Entity* entity = mSceneManager->createEntity("MonsterHead.mesh");
        Ogre::SceneNode* node = mRootSceneNode->createChildSceneNode();
        node->attachObject(entity);

        float positionOffset = float(1+i*2) - float(5);
        positionOffset = positionOffset * 20;
        node->translate(positionOffset, positionOffset, -200.0f);

        entity->setMaterialName("BaseWite");
    }
}