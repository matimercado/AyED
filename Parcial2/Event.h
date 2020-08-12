#ifndef PARCIAL2_EVENT_H
#define PARCIAL2_EVENT_H
#include <iostream>

using namespace std;

//===================================== Clase Eventos ===================================

class Event {
private:
    int id;
    string name; // nombre = nombre clock + numero evento

public:
    Event() {};
    Event(string, int);

    void execute();
    void set_id(int);
    void set_name(string);
    int get_id() { return id; };
    string get_name() { return name; };
};

//==============================================================================

#endif //PARCIAL2_EVENT_H
