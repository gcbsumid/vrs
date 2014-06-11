#ifndef ENTITYSYSTEM_HPP
#define ENTITYSYSTEM_HPP 

#include <memory>

#include "IEntitySystem.hpp"
// #include "EntityType.hpp"
#include "../ServiceManager.hpp"

#include "PlayerEntity.hpp"

class EntitySystem : public IEntitySystem {
public:
    EntitySystem() {}
    virtual ~EntitySystem() {}

    void initialize(std::shared_ptr<ServiceManager> serviceManager);

    template<typename EntityType>
    EntityType* createEntity();

private:
    std::shared_ptr<ServiceManager> mServiceManager;
};

#endif