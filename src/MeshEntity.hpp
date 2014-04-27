#ifndef MESHENTITY_HPP
#define MESHENTITY_HPP

#include "Entity.hpp"
#include "ResouceManager.hpp"

namespace VRS {
    class MeshEntity : public Entity {
    public: 
        MeshEntity(Ogre::SceneNode* parent, IResourceManager* resourceManager);
        ~MeshEntity();

        void addMesh(std::string meshName);
    private: 
        IResourceManager* mResourceManager;
    };
}

#endif