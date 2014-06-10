#ifndef PLAYERENTITY_HPP
#define PLAYERENTITY_HPP 

#include "Entity.hpp"
#include "../RenderSystem/Components/CameraComponent.hpp"
#include <memory>

class PlayerEntity : public Entity
{
public:
    PlayerEntity();
    virtual ~PlayerEntity();

    virtual void initialize();

private:
    std::shared_ptr<CameraComponent> mCameraComp;
    // std::shared_ptr<InputComponent> mInputComp;
};

#endif