//
// Created by riccardo on 16/10/20.
//

#ifndef CHAT_SUBJECT_H
#define CHAT_SUBJECT_H

#include "Observer.h"


class Subject {
public:
    virtual void attach(Observer *o) = 0;

    virtual void detach(Observer *o) = 0;

    virtual void notify() = 0 ;

    virtual ~Subject() {};

};

#endif //CHAT_SUBJECT_H
