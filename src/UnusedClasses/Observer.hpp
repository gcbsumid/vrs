#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "Events.hpp"
#include "Entity.hpp"

namespace VRS {
    class Observer {
    public:
        virtual ~Observer();
        virtual void onNotify(const Entity& entity, Event event) = 0;
    };    
}

#endif