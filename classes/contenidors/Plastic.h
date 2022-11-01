#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Plastic: public ContenidorBrossa {
    public:
        Plastic(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::GROC, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="KILOS";
            EFFICIENCY=0.8;
        };

        string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        float getQReciclat(){return reciclat;}
        // implementacio NO efficient.
        // string getType(){return TIPUS;}  // fa el mateix que getTipusBrossa()

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){
            if(pes<tara) throw_error("el pes total no pot ser mes petit que el tara.");
            reciclat+=EFFICIENCY*(pes-tara);
        }

        ~Plastic(){}
        
    float reciclat=0;
};