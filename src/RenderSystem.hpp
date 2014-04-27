#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "OGRE/OgreRoot.h"
#include "OGRE/OgreRenderSystem.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreWindowEventUtilities.h"

#include "ResourceManager.hpp"

#include <memory>

namespace VRS {
    class RenderSystem {
    public:
        RenderSystem();
        ~RenderSystem();

        void run();
        void initCamera();
        void initScene();
        void loadResources();
    private:

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
    };    
}

#endif