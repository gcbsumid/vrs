#ifndef LIGHTENTITY_HPP
#define LIGHTENTITY_HPP

#include "Entity.hpp"
#include "../ServiceManager.hpp"
#include "../RenderSystem/Components/LightComponent.hpp"
#include <memory>

class LightEntity : public Entity {
public:
    LightEntity();
    virtual ~LightEntity() {}

    virtual void initialize(std::shared_ptr<ServiceManager> serviceManager, std::string name);

private:
    std::shared_ptr<LightComponent> mLightComp;
};

#endif