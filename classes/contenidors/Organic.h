#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Organic: public ContenidorBrossa {
    public:
        // TODO:
        // Cada subclasse informarà a la superclasse del seu color (imprescindible 
        // usar els atributs estàtics de la classe ContenidorBrossa). 
        // No ha de ser un paràmetre del constructor. L’atribut propi s’inicialitza a zero.
        //                                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        //                                                          ?????

        Organic(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::MARRO, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="TONES";
            EFFICIENCY=0.9;
        };

        //float getQReciclada(){return reciclat;}
        //string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        float getReciclat(){return reciclat;}
        // implementacio NO efficient.
        // string getType(){return TIPUS;} 

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }


        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara)/1000;}

        ~Organic(){}

    float reciclat=0; // tones
};