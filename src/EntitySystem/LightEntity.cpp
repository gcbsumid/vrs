#include "LightEntity.hpp"
#include "Component.hpp"

LightEntity::LightEntity() 
    : mLightComp(nullptr)
{

}

void LightEntity::initialize(std::shared_ptr<ServiceManager> serviceManager, std::string name) {
    Component* comp = serviceManager->createComponent(ComponentType::LIGHT, name);
    mLightComp = std::shared_ptr<LightComponent>((LightComponent*)comp);
}