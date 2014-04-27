#include "OGRE/OgreColourValue.h"
#include "OGRE/OgreConfigFile.h"

#include "ResourceManager.hpp"

using namespace VRS;

ResourceManager::ResourceManager(Ogre::SceneManager* sceneManager, Ogre::SceneNode* sceneRootNode) :
    mSceneManager(sceneManager),
    mSceneRootNode(sceneRootNode) {

}

ResourceManager::~ResourceManager() {

}

void ResourceManager::createCube() {
    std::string manualObjectName = "CubeWithAxes";
    
    // Creating manual object;
    Ogre::ManualObject* manualObj = mSceneManager->createManualObject(manualObjectName);
    manualObj->setDynamic(false);

    // Create vertices for cube
    float length = 0.7f;
    manualObj->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

    manualObj->position(length, -length, length);// a vertex
    manualObj->colour(Ogre::ColourValue(0.0f,1.0f,0.0f,1.0f));
    manualObj->position(-length, -length, length);// a vertex
    manualObj->colour(Ogre::ColourValue(1.0f,1.0f,0.0f,1.0f));
    manualObj->position(-length, length, length);// a vertex
    manualObj->colour(Ogre::ColourValue(1.0f,0.0f,0.0f,1.0f));
    manualObj->position(length, length, length);// a vertex
    manualObj->colour(Ogre::ColourValue(0.0f,0.0f,0.0f,1.0f));

    manualObj->position(length, -length, -length);// a vertex
    manualObj->colour(Ogre::ColourValue(0.0f,1.0f,1.0f,1.0f));
    manualObj->position(-length, -length, -length);// a vertex
    manualObj->colour(Ogre::ColourValue(1.0f,1.0f,1.0f,1.0f));
    manualObj->position(-length, length, -length);// a vertex
    manualObj->colour(Ogre::ColourValue(1.0f,0.0f,1.0f,1.0f));
    manualObj->position(length, length, -length);// a vertex
    manualObj->colour(Ogre::ColourValue(0.0f,0.0f,1.0f,1.0f));

    // Create faces for cube
    manualObj->triangle(0,1,2);
    manualObj->triangle(2,3,0);
    manualObj->triangle(4,6,5);
    manualObj->triangle(6,4,7);

    manualObj->triangle(0,4,5);
    manualObj->triangle(5,1,0);
    manualObj->triangle(2,6,7);
    manualObj->triangle(7,3,2);

    manualObj->triangle(0,7,4);
    manualObj->triangle(7,0,3);
    manualObj->triangle(1,5,6);
    manualObj->triangle(6,2,1); 

    manualObj->end();

    // Create vertices for axes
    float axisLength = 1.4f;
    manualObj->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
    manualObj->position(0.0f, 0.0f, 0.0f);
    manualObj->colour(Ogre::ColourValue::Red);
    manualObj->position(axisLength, 0.0f, 0.0f);
    manualObj->colour(Ogre::ColourValue::Red);
    manualObj->position(0.0f, 0.0f, 0.0f);
    manualObj->colour(Ogre::ColourValue::Green);
    manualObj->position(0.0, axisLength, 0.0);
    manualObj->colour(Ogre::ColourValue::Green);
    manualObj->position(0.0f, 0.0f, 0.0f);
    manualObj->colour(Ogre::ColourValue::Blue);
    manualObj->position(0.0, 0.0, axisLength);
    manualObj->colour(Ogre::ColourValue::Blue);

    manualObj->index(0);
    manualObj->index(1);
    manualObj->index(2);
    manualObj->index(3);
    manualObj->index(4);
    manualObj->index(5);

    manualObj->end();
    Ogre::String nameOfMesh = "MeshCubeAndAxe";
    manualObj->convertToMesh(nameOfMesh);
}

void ResourceManager::initialiseCube() {
    for (int i = 0; i < 5; i++) {
        Ogre::Entity* entity = mSceneManager->createEntity("MeshCubeAndAxe");
        Ogre::SceneNode* node = mSceneRootNode->createChildSceneNode();

        node->attachObject(entity);
        float positionOffset = float(1 + i * 2) - float(5);
        node->translate(positionOffset, positionOffset, -10.0f);
    }
}

void ResourceManager::loadResourcesFromDirectory(std::string resourceGroupName, std::string dirName) {
    Ogre::ResourceGroupManager& resourceManager = Ogre::ResourceGroupManager::getSingleton();
    resourceManager.createResourceGroup(resourceGroupName);

    resourceManager.addResourceLocation(dirName, "FileSystem", resourceGroupName, false);
    resourceManager.initialiseResourceGroup(resourceGroupName);
    resourceManager.loadResourceGroup(resourceGroupName);

    // Note: shared pointer to mesh can be accessed by Ogre::MeshManager::getSingleton().getByName(nameOfMesh);
}

void ResourceManager::loadMesh(std::string meshName, Ogre::SceneNode* sceneNode) {
    Ogre::Entity* entity = mSceneManager->createEntity(meshName);
    sceneNode->attachObject(entity);
}

void ResourceManager::addLight(Ogre::Light::LightTypes lightType, Ogre::SceneNode* sceneNode, std::string name) {
    Ogre::Light* light = mSceneManager->createLight(name);
    light->setType(lightType);
    light->setDiffuseColour(Ogre::ColourValue::White);
    light->setSpecularColour(Ogre::ColourValue::White);
    sceneNode->attachObject(light);
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
