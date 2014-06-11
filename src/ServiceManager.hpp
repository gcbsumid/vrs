#ifndef SERVICEMANAGER_HPP
#define SERVICEMANAGER_HPP 

#include "EntitySystem/Component.hpp"
#include "RenderSystem/IRenderSystem.hpp"
// #include "InputSystem/IInputSystem.hpp"

class Engine;

class ServiceManager {
    friend class Engine;
    // friend class IInputSystem;

public:
    ServiceManager();
    virtual ~ServiceManager();

    // Interface
    Component* createComponent(ComponentType type);

private:

    void registerRenderInterface(IRenderSystem* renderSystem);
    // void registerInputSystem(IInputSystem* inputSystem);

    IRenderSystem* mRenderInterface;
    // IInputSystem* mInputInferface;
};

#endif