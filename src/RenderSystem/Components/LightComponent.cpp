#include "LightComponent.hpp"

LightComponent::LightComponent() 
    : Component() 
    , mDir(0,0,0)
    , mLight(nullptr)
{

}

LightComponent::~LightComponent() {

}

void LightComponent::initialize(std::string name, Ogre::SceneManager* sceneManager) {
    mLight = sceneManager->createLight(name);
}

void LightComponent::setParameters(Ogre::Vector3 dir, 
                                   Ogre::Light::LightTypes type,
                                   Ogre::ColourValue diffuse,
                                   Ogre::ColourValue specular) {
    mDir = dir;
    mDir.normalise();
    mLight->setType(type);
    mLight->setDirection(mDir);
    mLight->setDiffuseColour(diffuse);
    mLight->setSpecularColour(specular);
}
