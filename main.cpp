#include <string>
#include <iostream>
#include "classes/Poblacio.h"


using namespace std;

template <typename T>
float c(T re){ 
    cout << float(re) << " | " << to_string(re) << " | " << (re>90) << endl;
    return re;
}

void throw_error(string error){
        cerr<<"ERROR: "<<error<<endl;throw 0;
    }

double divide ( double a, double b)
    {
        if ( b == 0 ) // !! Division by zero
            throw "Division by zero";
        else
            return a / b;
    }

void e(){
    cout << "error"<< endl;
    throw_error("HELP");
}


int main(){
    ContenidorBrossa *b=new Paper("XX-9999", "F", 1003, 10);
    ContenidorBrossa *q=new Vidre("XX-9998", "E", 1003, 10);
    ContenidorBrossa *w=new Vidre("AA-2336", "D", 1003, 10);
    ContenidorBrossa *e=new Paper("AA-2338", "C", 1003, 10);


    ContenidorBrossa *r=new Rebuig("AA-1111", "B", 1003, 10);
    ContenidorBrossa *t=new Organic("ZZ-9999", "A", 1003, 10);
    ContenidorBrossa *x=new Organic("ZZ-9999", "A", 1003, 10);
    cout << "AA-1111 < ZZ-9999 = " << ( (*r)<t ) << endl; 
    cout << "AA-1111 > ZZ-9999 = " << ( (*r)>t ) << endl;
    cout << "AA-1111 == ZZ-9999 = " << ( (*r)==t ) << endl; 

    return 0;

    r->buidat(10000000);
    e->buidat(1000);
    w->buidat(1000);
    t->buidat(10000);

    Poblacio p1=Poblacio();
    Poblacio p2=Poblacio(b);

    p2.afegirContenidor(w);
    p2.afegirContenidor(e);
    p2.afegirContenidor(q);
    p1.afegirContenidor(r);
    p1.afegirContenidor(t);

    // p2.eliminarContenidor(w);
    // p2.eliminarContenidor(q);

    ContenidorBrossa *p;
    p=p1.mesRendiment();

    p->toString();

    // p1.toString();
    cout << endl << endl;
    p2.toString();

    return 0;
}
