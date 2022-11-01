#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Rebuig: public ContenidorBrossa {
    public:
        Rebuig(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::GRIS, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="TONES";
            EFFICIENCY=0.75;
        };

        // float getQReciclada(){return reciclat;}
        string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        float getQReciclat(){return reciclat;}
        // implementacio NO efficient.
        // string getType(){return TIPUS;}  // fa el mateix que getTipusBrossa()

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara)/1000;}

        ~Rebuig(){}
        
    float reciclat=0; // tones
};