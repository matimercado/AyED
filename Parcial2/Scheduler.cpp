#include "Scheduler.h"

//================================= Metodos Clase Scheduler =================================

void Scheduler::addClock(Clock *c) {
    clocks->add(*c);
}

void Scheduler::run() {
    srand(see);

    int y;
    Nodo<Clock> *aux1;
    aux1 = clocks->nodo();

    for (int i = 0; i < clocks->size(); i++) {

        aux1->get_dato().createEvents();
        aux1 = aux1->get_next();
    }

    addEvents();

    cout << "\nEl programa fue ejecutado a las: ";
    date();
    cout << "\n" << endl;

    for (;;) {

     Event e = getNextEvent();
     e.execute();
     write(e);

        aux++;
        launchedEvents++;

        if (aux == 500) {
            cout << "\nFelicitaciones, ha lanzado " << launchedEvents << " eventos! Desea producir más?" << endl;
            cout << "1: Si" << endl;
            cout << "2: No" << endl;
            cin >> y;
            switch (y) {

                case 1:
                    aux = 0;
                    run();
                    break;

                case 2:
                    cout << "Se lanzaron " << launchedEvents << " eventos" << endl;
                    cout << ">> Hubo un total de " << getCompares() << endl;
                    aux = 0;
                    break;
            }
            return;
        }
    }
}

void Scheduler::date() {

    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);

    cout << nowLocal.tm_mon << "-" << nowLocal.tm_mday << "-" << nowLocal.tm_year + 1900 << " ";
    cout << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << " ";
}

void Scheduler::write2() {
    ofstream file;
    file.open("Events.txt", ios::app);
    file << "\n>> Hubo un total de " << getCompares() <<endl;
    file.close();
}

void Scheduler::write(Event ev) {
    ofstream file;
    file.open("Events.txt", ios::app);

    time_t now = time(nullptr) + ev.get_id();
    struct tm nowLocal;
    nowLocal = *localtime(&now);

    file << nowLocal.tm_mon << "-" << nowLocal.tm_mday << "-" << nowLocal.tm_year + 1900 << " ";
    file << nowLocal.tm_hour << ":" << nowLocal.tm_min << ":" << nowLocal.tm_sec << " " << ev.get_name() << " "
         << "tiempo desde ejecucion -> " << ev.get_id() << "s" <<endl;

    file.close();
}
