#ifndef COMPONENT_HPP
#define COMPONENT_HPP

enum class ComponentType {
    // Render System Components
    CAMERA,
    LIGHT,
    TERRAIN,

    // Input System Components
    KEYBOARD,
    MOUSE,
};

class Component
{
public:
    Component() {}
    virtual ~Component() {}

    /* data */
};

#endif