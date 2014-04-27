#include "MeshEntity.hpp"

MeshEntity::MeshEntity(Ogre::SceneNode* parent, IResourceManager* resourceManager) 
    : Entity(parent)
    , mResourceManager(resourceManager)
    {

}

MeshEntity::~MeshEntity() {

}

void MeshEntity::addMesh(std::string meshName) {
    mResourceManager->loadMesh(meshName, mNode);
}