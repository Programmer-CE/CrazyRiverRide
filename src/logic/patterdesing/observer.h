#include <google/protobuf/message.h>

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
    Observer();
    virtual void update(google::protobuf::Message *pMessage) = 0;
};

#endif // OBSERVER_H
