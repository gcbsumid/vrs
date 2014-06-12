#include "PlayerEntity.hpp"
#include "Component.hpp"

PlayerEntity::PlayerEntity() 
    : mCameraComp(nullptr)
    // , mInputComp(nullptr)
{

}

PlayerEntity::~PlayerEntity() {

}

void PlayerEntity::initialize(std::shared_ptr<ServiceManager> serviceManager, std::string name) {
    Component* comp = serviceManager->createComponent(ComponentType::CAMERA, name);
    mCameraComp = std::shared_ptr<CameraComponent>((CameraComponent*)comp);
    // Todo: Create the input component
}