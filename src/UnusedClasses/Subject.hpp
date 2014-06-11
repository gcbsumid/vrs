#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <vector>
#include "Events.hpp"
#include "Entity.hpp"
#include "Observer.hpp"

class Subject {
public:
    virtual ~Subject();
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    int getNumObservers();

protected:
    void notify(const Entity& entity, Event event);

private:
    std::vector<Observer*> mObservers;
};

#endif