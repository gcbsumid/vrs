#include "Subject.hpp"

using namespace VRS;

Subject::~Subject() {
    mObservers.clear();
}

void Subject::addObserver(Observer* observer) {
    mObservers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    for (unsigned int i = 0; i < mObservers.size(); i++) {
        if (mObservers.at(i) == observer) {
            mObservers.erase(mObservers.begin() + i);
            return;
        }
    }
}

int Subject::getNumObservers() {
    return mObservers.size();
}

