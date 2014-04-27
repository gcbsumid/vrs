#ifndef LIGHTENTITY_HPP
#define LIGHTENTITY_HPP

#include "Entity.hpp"

namespace VRS {
    class LightEntity : public Entity {
    public:
        LightEntity(Ogre::SceneNode node, IResourceManager* resourceManager);
        ~LightEntity();
        void setLight(Ogre::Light::LightTypes type, std::string name);

    private:
        IResourceManager* resourceManager;
    };
}

#endif