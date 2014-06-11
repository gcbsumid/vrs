#include "EntitySystem.hpp"

void EntitySystem::initialize(std::shared_ptr<ServiceManager> serviceManager) {
    mServiceManager = serviceManager;
}

template<typename EntityType>
EntityType* EntitySystem::createEntity() {
    EntityType* entity = new EntityType();
    entity->initialize(mServiceManager);
    return entity;
}