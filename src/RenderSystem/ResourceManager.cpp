#include "OGRE/OgreColourValue.h"
#include "OGRE/OgreConfigFile.h"
#include "OGRE/OgreMaterialManager.h"

#include "ResourceManager.hpp"

using namespace VRS;

ResourceManager::ResourceManager() :
    mSceneManager(nullptr),
    mSceneRootNode(nullptr) {
    mMaterialManager = Ogre::MaterialManager::getSingletonPtr();
}

ResourceManager::~ResourceManager() {

}

void ResourceManager::initialise(Ogre::SceneManager* sceneManager, Ogre::SceneNode* sceneRootNode) {
    mSceneManager = sceneManager;
    mSceneRootNode = sceneRootNode;
}

void ResourceManager::loadResourcesFromDirectory(std::string resourceGroupName, std::string dirName) {
    Ogre::ResourceGroupManager& resourceManager = Ogre::ResourceGroupManager::getSingleton();
    resourceManager.createResourceGroup(resourceGroupName);

    resourceManager.addResourceLocation(dirName, "FileSystem", resourceGroupName, false);
    resourceManager.initialiseResourceGroup(resourceGroupName);
    resourceManager.loadResourceGroup(resourceGroupName);

    // Note: shared pointer to mesh can be accessed by Ogre::MeshManager::getSingleton().getByName(nameOfMesh);
}

void ResourceManager::loadResourcesFromConfigFile(std::string resourcesCfg) {
    Ogre::ConfigFile cf;
    cf.load(resourcesCfg);

    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
    Ogre::ResourceGroupManager& resourceGroupManager = Ogre::ResourceGroupManager::getSingleton();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements()) {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i) {
            typeName = i->first;
            archName = i->second;
            resourceGroupManager.addResourceLocation(archName, typeName, secName);
        }
    }

    resourceGroupManager.initialiseAllResourceGroups();
}
