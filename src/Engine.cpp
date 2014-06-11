#include "Engine.hpp"
#include <string>

Engine::Engine() 
    : mRenderSystem(new RenderSystem) 
    , mInputSystem(new InputSystem)
    , mServiceManager(new ServiceManager)
{

}

Engine::~Engine() {

}

void Engine::initialize() {
    mRenderSystem->initialize(mServiceManager);
    mInputSystem->initialize(mServiceManager, mRenderSystem->getRenderWindow());
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