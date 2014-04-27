#include "Entity.hpp"

using namespace VRS;

Entity::Entity(Ogre::SceneNode* parent) {
    mNode = parent->createChildSceneNode();
}

Entity::~Entity() {
    mNode = nullptr;
}

void Entity::translate(const Ogre::Vector3 &d) {
    mNode->translate(d);
}

void Entity::translate(Ogre::Real x, Ogre::Real y, Ogre::Real z) {
    mNode->translate(x, y, z);
}

void Entity::scale(const Ogre::Vector3 &s) {
    mNode->scale(s);
}
void Entity::scale(Ogre::Real x, Ogre::Real y, Ogre::Real z) {
    mNode->scale(x, y, z);
}

void Entity::rotate(const Ogre::Vector3 &axis, const Ogre::Radian &angle) {
    mNode->rotate(axis, angle);
}

void Entity::rotate(const Ogre::Quaternion &q) {
    mNode->rotate(q);
}