#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Paper: public ContenidorBrossa {
    public:
        Paper(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::BLAU, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="KILOS";
            EFFICIENCY=0.95;
        };

        // float getQReciclada(){return reciclat;}
        string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        float getQReciclat(){return reciclat;}
        // implementacio NO efficient.
        // string getType(){return TIPUS;}  // fa el mateix que getTipusBrossa() // inutil

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara);}

        ~Paper(){}
        
    float reciclat=0;
};