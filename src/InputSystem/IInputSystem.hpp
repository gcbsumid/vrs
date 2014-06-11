#ifndef IINPUTSYSTEM_HPP
#define IINPUTSYSTEM_HPP

#include "../EntitySystem/Component.hpp"

class IInputSystem {
public:
    virtual Component* createComponent(ComponentType type, std::string name) = 0;
    /* data */
};

#endif