#ifndef ENTITY_HPP
#define ENTITY_HPP 

class Entity
{
public:
    Entity() {}
    virtual ~Entity() {}

    virtual void initialize() = 0;
};

#endif