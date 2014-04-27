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
        virtual void loadMesh(std::string meshName, Ogre::SceneNode* sceneNode) = 0;
        virtual void addLight(Ogre::Light::LightTypes lightType, Ogre::SceneNode* sceneNode, std::string name) = 0;
    };

    class ResourceManager : public IResourceManager {
    public:
        ResourceManager(Ogre::SceneManager* sceneManager, Ogre::SceneNode* sceneRootNode);
        ~ResourceManager();

        void createCube();
        void initialiseCube();

        void loadResourcesFromConfigFile(std::string resourcesCfg);
        void loadResourcesFromDirectory(std::string resourceGroupName, std::string dirName);
        void loadMesh(std::string meshName, Ogre::SceneNode* sceneNode);
        void addLight(Ogre::Light::LightTypes lightType, Ogre::SceneNode* sceneNode, std::string name);

    private:
        Ogre::SceneManager* mSceneManager;
        Ogre::SceneNode* mSceneRootNode;
    };    
}

#endif