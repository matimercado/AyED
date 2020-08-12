using namespace std;

#include <iostream>

#include "Pila.h"
#include "Archivo.h"
#include "TokenHtml.h"

int main() {

    Pila<string> *html = new Pila<string>;

    Archivo file;


    file.set_html("/home/matimercado/git/AyED/Parcial1/table.html");
    file.set_html2("/home/matimercado/git/AyED/Parcial1/table.html");

    cout<<"================================= Tokenize =================================\n"<<endl;

    file.get_html();

    cout<<"=================================== Show =================================\n"<<endl;

    file.givePila(html);

    Thtml pruebahtml;
    Tbody pruebabody;
    Th2 pruebah2;
    Ttable pruebatable;
    Ttr pruebatr;
    Tth pruebath;
    Ttd pruebatd;

    pruebahtml.get_parseo(html);
    pruebahtml.show();

    pruebabody.get_parseo(html);
    pruebabody.show();

    pruebah2.get_parseo(html);
    pruebah2.show();

    pruebatable.get_parseo(html);
    pruebatable.show();

    pruebatr.get_parseo(html);
    pruebatr.show();

    pruebath.get_parseo(html);
    pruebath.show();

    pruebatd.get_parseo(html);
    pruebatd.show();

<<<<<<< HEAD
    **/


=======
    //cout << "\nLa pila html sigue viva:" << endl << html->toPrint("") << endl;
>>>>>>> mati
}


