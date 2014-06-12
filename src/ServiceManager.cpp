#include "ServiceManager.hpp"

ServiceManager::ServiceManager() 
    : mRenderInterface(nullptr)
    , mInputInterface(nullptr)
{

}

ServiceManager::~ServiceManager() {
    mRenderInterface = nullptr;
}

Component* ServiceManager::createComponent(ComponentType type, std::string name) {
    switch (type) {
        case ComponentType::CAMERA:
        case ComponentType::LIGHT:
        case ComponentType::TERRAIN:
            return mRenderInterface->createComponent(type, name);
        case ComponentType::KEYBOARD:
        case ComponentType::MOUSE:
            return mInputInterface->createComponent(type, name);
        default:
            return nullptr;
    }
}

void ServiceManager::registerRenderInterface(IRenderSystem* renderSystem) {
    mRenderInterface = renderSystem;
}

void ServiceManager::registerInputInterface(IInputSystem* inputSystem) {
    mInputInterface = inputSystem;
}