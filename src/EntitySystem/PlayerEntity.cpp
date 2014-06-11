#include "PlayerEntity.hpp"
#include "Component.hpp"

PlayerEntity::PlayerEntity() 
    : mCameraComp(nullptr)
    // , mInputComp(nullptr)
{

}

PlayerEntity::~PlayerEntity() {

}

void PlayerEntity::initialize(std::shared_ptr<ServiceManager> serviceManager) {
    mCameraComp = std::shared_ptr<CameraComponent>((CameraComponent*)serviceManager->createComponent(ComponentType::CAMERA, "Player"));
    // Todo: Create the input component
}