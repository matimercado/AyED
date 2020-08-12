/********************************* ALGORITMOS Y ESTRUCTURAS DE DATOS - PARCIAL 2 ****************************
 *
 *                                  @author Juan Ignacio Fernández
 *                                     @author Matías Mercado
 *
 *                                              FCEFyN - 2020
 *
 ************************************************************************************************************/

#include <iostream>
#include <fstream>
#include "Clock.h"
#include "ScheBH.h"
#include "ScheHS.h"
#include "ScheList.h"
using namespace std;

void readClocks(ifstream &, Scheduler*);
void menu (Scheduler*, Scheduler*, Scheduler*);

int main() {

    ifstream file;
    ScheList *s1 = new ScheList;
    ScheHS *s2 = new ScheHS;
    ScheBH *s3 = new ScheBH;

    file.open("clock.txt");
    readClocks(file, s1);
    file.close();

    file.open("clock.txt");
    readClocks(file, s2);
    file.close();

    file.open("clock.txt");
    readClocks(file, s3);
    file.close();

    menu(s1, s2, s3);

}

void readClocks(ifstream &file, Scheduler *s) {

    int number, repeat;
    string name, type, line;
    getline(file, line);
    while (!file.eof()) {

        file >> number;
        file >> name;
        file >> type;
        file >> repeat;

        s->addClock(new Clock(number, name, type, repeat));
    }
    //cout << "Se han agregado " << s->get_clocksize() << " relojes satisfactoriante" << endl;
}

void menu (Scheduler* s1, Scheduler* s2, Scheduler* s3){

    cout << "\nPor favor elija un metodo de ordenamiendo\n" << endl;

    cout << "1: QuickSort" << endl;
    cout << "2: HeapSort" << endl;
    cout << "3: BinomialHeap" << endl;
    cout << "4: Salir" <<endl;

    int y;
    cin >> y;
    switch (y) {
        case 1:
            s1->run();
            s1->write2();
            cout << "Desea realizar otra comparacion?" << endl;
            cout << "1: Si " << endl;
            cout << "2: No, gracias " << endl;
            cin >> y;
            switch (y) {
                case 1: menu(s1,s2,s3);
                    break;
                case 2: exit(1);
            }
            break;

        case 2:
            s2->run();
            s2->write2();
            cout << "Desea realizar otra comparacion?" << endl;
            cout << "1: Si " << endl;
            cout << "2: No, gracias " << endl;
            cin >> y;
            switch (y) {
                case 1: menu(s1,s2,s3);
                    break;
                case 2: exit(1);
            }
            break;

        case 3:
            s3->run();
            s3->write2();
            cout << "Desea realizar otra comparacion?" << endl;
            cout << "1: Si " << endl;
            cout << "2: No, gracias " << endl;
            cin >> y;
            switch (y) {
                case 1: menu(s1,s2,s3);
                    break;
                case 2: exit(1);
            }

            break;

        default:
            cout << "Que tengas un buen dia :)" << endl;
            exit(1);
    }
}