#ifndef ENTITY_HPP
#define ENTITY_HPP 

#include "../ServiceManager.hpp"
#include <memory>

class Entity
{
public:
    Entity() {}
    virtual ~Entity() {}

    virtual void initialize(std::shared_ptr<ServiceManager> serviceMAnager, std::string name) = 0;
};

#endif