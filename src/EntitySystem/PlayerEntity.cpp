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
    Component* cameraComp = serviceManager->createComponent(ComponentType::CAMERA, name + "_camera");
    mCameraComp = std::shared_ptr<CameraComponent>((CameraComponent*)cameraComp);

    Component* mouseComp = serviceManager->createComponent(ComponentType::MOUSE, name + "_mouse");
    mMouseComp = std::shared_ptr<MouseComponent>((MouseComponent*)mouseComp);

    Component* keyboardComp = serviceManager->createComponent(ComponentType::KEYBOARD, name + "_keyboard");
    mKeyboardComp = std::shared_ptr<KeyboardComponent>((KeyboardComponent*)keyboardComp);

}