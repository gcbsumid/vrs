#ifndef LIGHTCOMPONENT
#define LIGHTCOMPONENT

#include "../../EntitySystem/Component.hpp"
#include "OGRE/OgreSceneManager.h"
// #include "OGRE/OgreLight.h"
#include <string>

class LightComponent : public Component {
public:
    LightComponent();
    virtual ~LightComponent();

    void initialize(std::string name, Ogre::SceneManager* sceneManager);
    void setParameters(Ogre::Vector3 dir, 
                       Ogre::Light::LightTypes type = Ogre::Light::LT_DIRECTIONAL,
                       Ogre::ColourValue diffuse = Ogre::ColourValue::White,
                       Ogre::ColourValue specular = Ogre::ColourValue::White);

private:
    Ogre::Vector3 mDir;
    Ogre::Light* mLight;
};

#endif