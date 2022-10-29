#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Oragnic: public ContenidorBrossa {

    public:
        Organic(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::Colors, ubicacio, anyColocacio, tara) {
            return
        }

        string getReciclat(){}
    
    float reciclat; // Tons

};