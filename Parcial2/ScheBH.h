#ifndef PARCIAL2_SCHEBH_H
#define PARCIAL2_SCHEBH_H
#include "Scheduler.h"

using namespace std;

//================================= ScheBH =================================

class ScheBH : public Scheduler {
private:
    BinomialHeap<Event> events;

public:
    void addEvents();
    Event getNextEvent() override;
    string getCompares() override { return std::to_string(events.getCompares()) + " comparaciones con BinomialHeap <<\n"; };
};

//=============================================================================

#endif //PARCIAL2_SCHEBH_H
