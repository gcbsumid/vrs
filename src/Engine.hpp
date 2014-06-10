#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>

#include "RenderSystem/RenderSystem.hpp"
#include "InputSystem/InputSystem.hpp"

// Temp
#include "InputSystem/BaseListener.hpp"

namespace VRS {
    class Engine {
    public:
        Engine();
        ~Engine();

        void initialize();
        void run();

    private:
        std::unique_ptr<RenderSystem> mRenderSystem;
        std::shared_ptr<InputSystem> mInputSystem;

        // Temp
        BaseListener mInputListener;
    };
}

#endif