#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "OGRE/OgreRoot.h"
#include "OGRE/OgreRenderSystem.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreWindowEventUtilities.h"

#include "ResourceManager.hpp"
#include "InputManager.hpp"
// #include "../Commands/Command.hpp"

#include <memory>
#include <queue>

namespace VRS {

    class IRenderSystem {
    public:
        virtual ~IRenderSystem() {}  
        // virtual void addCommand(Command*) = 0;
    };


    class RenderSystem : public IRenderSystem {
    public:
        RenderSystem();
        ~RenderSystem();

        // void addCommand(Command* command);
        void loadResources();
        void run();
        void initScene(std::string dotSceneFilename = "");

    private:
        void loadHome();
        void initCamera();
        // void processCommands();

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

        // std::Queue<Command*> mCommands;
    };    
}

#endif