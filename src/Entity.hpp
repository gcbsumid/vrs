#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "OGRE/OgreEntity.h"
#include "OGRE/OgreSceneManager.h"

namespace VRS {
    class Entity{
    public:
        Entity(Ogre::SceneNode* parent);
        virtual ~Entity();

        void translate(const Ogre::Vector3 &d);
        void translate(Ogre::Real x, Ogre::Real y, Ogre::Real z);

        void scale(const Ogre::Vector3 &s);
        void scale(Ogre::Real x, Ogre::Real y, Ogre::Real z);

        void rotate(const Ogre::Vector3 &axis, const Ogre::Radian &angle);
        void rotate(const Ogre::Quaternion &q);

    protected:
        Ogre::SceneNode* mNode;
    };
}

#endif