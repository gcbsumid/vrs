#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>

#include "RenderSystem/RenderSystem.hpp"
// #include "SystemLoader.hpp"
// #include "ResourceManager.hpp"

namespace VRS {
    class Engine {
    public:
        Engine();
        ~Engine();

        void run();

    private:
        std::unique_ptr<RenderSystem> mRenderSystem;
        // std::shared_ptr<SystemLoader> mLoader;
        // std::shared_ptr<ResourceManager> mResourceManager;
    };
}

#endif