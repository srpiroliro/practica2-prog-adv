// TO DO:
//      1. comprovar que implementacio mes efficent es correcte (legal)
//           en cas de que no ho sigui, borrar tot que tingui 
//                 // implementacio mes efficient. 
//           i substituirho per la 
//                 // implementacio NO efficient.

#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Plastic: public ContenidorBrossa {
    public:
        // TODO:
        // Cada subclasse informarà a la superclasse del seu color (imprescindible 
        // usar els atributs estàtics de la classe ContenidorBrossa). 
        // No ha de ser un paràmetre del constructor. L’atribut propi s’inicialitza a zero.
        //                                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        //                                                          ?????

        Plastic(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::GROC, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="KILOS";
            EFFICIENCY=0.8;
            TIPUS="Plastic";
        };


        // implementacio NO efficient.
        // string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        // string getType(){return TIPUS;} 

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara);}

        ~Plastic(){}
        
    float reciclat;
};