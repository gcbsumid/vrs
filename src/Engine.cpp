#include "Engine.hpp"
#include <string>

using namespace VRS;

Engine::Engine() 
    : mRenderSystem(new RenderSystem) 
    , mInputSystem(new InputSystem)
{

}

Engine::~Engine() {

}

void Engine::initialize() {
    mRenderSystem->initialize();
    mInputSystem->initialize(mRenderSystem->getRenderWindow());
    mInputSystem->addKeyListener(&mInputListener, "temp base");
    mInputSystem->addMouseListener(&mInputListener, "temp base");

    mRenderSystem->initScene();
}

void Engine::run() {
    try {
        while (!mRenderSystem->isWindowClosed() && !mInputListener.isShutDown()) {
            mInputSystem->capture();
            mRenderSystem->run();
        }
        mRenderSystem->logMessage("endOfProgram");
    } catch (Ogre::Exception &e) {
        std::cout << "Ogre Exception: " << e.what() << std::endl;
    }
}