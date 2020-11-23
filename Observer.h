//
// Created by riccardo on 11/11/20.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

class Observer {
public:
    virtual void update() = 0;

    virtual ~Observer() = default;
};

#endif //PROJECT_OBSERVER_H
