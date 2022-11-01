#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Vidre: public ContenidorBrossa {
    public:
        Vidre(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::GRIS, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="UNITAT";
            EFFICIENCY=3; // 1kg = 3u
        };

        string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        float getQReciclat(){return reciclat;}
        
        // string getType(){return TIPUS;}  // fa el mateix que getTipusBrossa()// implementacio NO efficient.

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara);}

        ~Vidre(){}
        
    long int reciclat=0; // nombres d'envasos reciclats
};