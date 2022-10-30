// TO DO:
//      1. comprovar que implementacio mes efficent es correcte (legal)
//           en cas de que no ho sigui, borrar tot que tingui 
//                 // implementacio mes efficient. 
//           i substituirho per la 
//                 // implementacio NO efficient.

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
            TIPUS="organic";
        };


        // implementacio NO efficient.
        // string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        // string getType(){return TIPUS;} 

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }


        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara)/1000;}

        ~Organic(){}

    float reciclat; // tones
};