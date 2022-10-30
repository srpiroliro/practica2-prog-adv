#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Rebuig: public ContenidorBrossa {
    public:
        // TODO:
        // Cada subclasse informarà a la superclasse del seu color (imprescindible 
        // usar els atributs estàtics de la classe ContenidorBrossa). 
        // No ha de ser un paràmetre del constructor. L’atribut propi s’inicialitza a zero.
        //                                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        //                                                          ?????

        Rebuig(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::GRIS, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="TONES";
            EFFICIENCY=0.75;
        };

        float getQReciclada(){return reciclat;}
        string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        // implementacio NO efficient.
        // string getType(){return TIPUS;} 

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara)/1000;}

        ~Rebuig(){}
        
    float reciclat=0; // tones
};