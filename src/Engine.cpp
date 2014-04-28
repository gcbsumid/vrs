#include "Engine.hpp"

using namespace VRS;

Engine::Engine() {
    std::unique_ptr<RenderSystem> renderSystem(new RenderSystem());
    mRenderSystem = std::move(renderSystem);
}

Engine::~Engine() {

}

void Engine::run() {
    mRenderSystem->initScene();

    mRenderSystem->run();
}