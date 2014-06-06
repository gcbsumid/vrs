#include "Engine.hpp"
#include <string>

using namespace VRS;

Engine::Engine() {
    std::unique_ptr<RenderSystem> renderSystem(new RenderSystem());
    mRenderSystem = std::move(renderSystem);
}

Engine::~Engine() {

}

void Engine::run() {
    mRenderSystem->initScene();

    try {
        while (!mRenderSystem->isWindowClosed()) {
            mRenderSystem->run();
        }
        mRenderSystem->logMessage("endOfProgram");
    } catch (Ogre::Exception &e) {
        std::cout << "Ogre Exception: " << e.what() << std::endl;
    }
}