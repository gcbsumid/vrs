#ifndef SERVICEMANAGER_HPP
#define SERVICEMANAGER_HPP 

#include "EntitySystem/Component.hpp"
#include "RenderSystem/IRenderSystem.hpp"
#include "InputSystem/IInputSystem.hpp"

class InputSystem;
class RenderSystem;

class ServiceManager {
    friend class RenderSystem;
    friend class InputSystem;
public:
    ServiceManager();
    virtual ~ServiceManager();

    // Interface
    Component* createComponent(ComponentType type, std::string name);

private:

    void registerRenderInterface(IRenderSystem* renderSystem);
    void registerInputInterface(IInputSystem* inputSystem);

    IRenderSystem* mRenderInterface;
    IInputSystem* mInputInterface;
};

#endif