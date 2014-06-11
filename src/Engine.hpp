#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>

#include "RenderSystem/RenderSystem.hpp"
#include "InputSystem/InputSystem.hpp"
#include "ServiceManager.hpp"

// Temp
#include "InputSystem/BaseListener.hpp"

class Engine {
public:
    Engine();
    ~Engine();

    void initialize();
    void run();

private:
    // Systems
    std::unique_ptr<RenderSystem> mRenderSystem;
    std::unique_ptr<InputSystem> mInputSystem;

    // Managers
    std::shared_ptr<ServiceManager> mServiceManager;

    // Temp
    BaseListener mInputListener;
};

#endif