#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "OGRE/OgreRoot.h"
#include "OGRE/OgreManualObject.h"
#include "OGRE/OgreEntity.h"

namespace VRS {
    class IResourceManager {
    public:
        virtual ~IResourceManager() {}  
        virtual void loadResourcesFromConfigFile(std::string resourcesCfg) = 0;
        virtual void loadResourcesFromDirectory(std::string resourceGroupName, std::string dirName) = 0;
    };

    class ResourceManager : public IResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();

        void initialise(Ogre::SceneManager* sceneManager, Ogre::SceneNode* sceneRootNode);
        void loadResourcesFromConfigFile(std::string resourcesCfg);
        void loadResourcesFromDirectory(std::string resourceGroupName, std::string dirName);

    private:
        Ogre::SceneManager* mSceneManager;
        Ogre::SceneNode* mSceneRootNode;
        Ogre::MaterialManager* mMaterialManager;
    };    
}

#endif