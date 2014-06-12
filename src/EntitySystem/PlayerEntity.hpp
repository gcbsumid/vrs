#ifndef PLAYERENTITY_HPP
#define PLAYERENTITY_HPP 

#include "Entity.hpp"
#include "../RenderSystem/Components/CameraComponent.hpp"
#include "../InputSystem/Components/MouseComponent.hpp"
#include "../InputSystem/Components/KeyboardComponent.hpp"

class PlayerEntity : public Entity
{
public:
    PlayerEntity();
    virtual ~PlayerEntity();

    virtual void initialize(std::shared_ptr<ServiceManager> serviceManager, std::string name);

private:
    std::shared_ptr<CameraComponent> mCameraComp;
    std::shared_ptr<KeyboardComponent> mKeyboardComp;
    std::shared_ptr<MouseComponent> mMouseComp;
};

#endif