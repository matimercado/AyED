#include "Event.h"

//================================== Metodos Clase Event ==================================

Event::Event(string name, int id) {
    this->name = name;
    this->id = id;
}

void Event::set_id(int id) {
    this->id = id;
}

void Event::set_name(string name) {
    this->name = name;
}

void Event::execute() {

    time_t now = get_id() + time(nullptr);
    struct tm nowLocal;
    nowLocal = *localtime(&now);

    cout << nowLocal.tm_mon << "-" << nowLocal.tm_mday << "-" << nowLocal.tm_year + 1900 << " ";
    cout << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << " " << get_name() << " "
    << " tiempo desde ejecucion -> " << get_id() << "s" << endl;

}