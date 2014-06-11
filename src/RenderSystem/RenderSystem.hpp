#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "OGRE/OgreRoot.h"
#include "OGRE/OgreRenderSystem.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreWindowEventUtilities.h"

#include "ResourceManager.hpp"
#include "IRenderSystem.hpp"
#include "../EntitySystem/Component.hpp"
#include "../ServiceManager.hpp"
// #include "../Commands/Command.hpp"

#include <memory>
#include <queue>

class RenderSystem : public IRenderSystem {
public:
    RenderSystem();
    ~RenderSystem();

    // void addCommand(Command* command);
    void loadResources();
    void initialize(std::shared_ptr<ServiceManager> serviceManager);
    void run();

    void clearEventTimes();
    bool isWindowClosed();
    void logMessage(std::string msg);

    void initScene(std::string dotSceneFilename = "");

    // public interface
    virtual Ogre::RenderWindow* getRenderWindow();
    virtual Component* createComponent(ComponentType type, std::string name);

private:
    void loadScene();
    void initCamera();
    // void processCommands();

    // OGRE member variables 

    // Optional Config file for render system
    Ogre::String mRenderSystemConfigFileName;

    // Optional Config file for plugins
    Ogre::String mPluginConfigFileName;

    // Optional Config file for resources
    Ogre::String mResourcesConfigFileName;

    // Optional Log file name
    Ogre::String mLogFileName;

    // Ogre Root object
    std::unique_ptr<Ogre::Root> mRoot;

    // Ogre Window object 
    Ogre::RenderWindow* mWindow;

    Ogre::SceneManager* mSceneManager;
    Ogre::SceneNode* mRootSceneNode;

    std::shared_ptr<ResourceManager> mResourceManager;

    // Window Parameters
    unsigned int mWindowWidth;
    unsigned int mWindowHeight;
    bool mFullScreen;

    // Service Manager
    std::shared_ptr<ServiceManager> mServiceManager;

    // /* TEMP */
    // Ogre::TerrainGlobalOptions* mTerrainGlobals;
    // Ogre::TerrainGroup* mTerrainGroup;
    // bool mTerrainsImported;


    // std::Queue<Command*> mCommands;
}; 

#endif