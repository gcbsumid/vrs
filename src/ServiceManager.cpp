#include "ServiceManager.hpp"

ServiceManager::ServiceManager() 
    : mRenderInterface(nullptr)
    , mInputInterface(nullptr)
{

}

ServiceManager::~ServiceManager() {
    mRenderInterface = nullptr;
}

Component* ServiceManager::createComponent(ComponentType type) {
    switch (type) {
        case ComponentType::CAMERA:
        case ComponentType::LIGHT:
        case ComponentType::TERRAIN:
            return mRenderInterface->createComponent(type);
        case ComponentType::INPUT:
            return mInputInterface->createComponent(type);
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