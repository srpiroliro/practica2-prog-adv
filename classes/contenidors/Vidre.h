#include <string>
#include <iostream>
#include "../ContenidorBrossa.h"

class Vidre: public ContenidorBrossa {
    public:
        // TODO:
        // Cada subclasse informarà a la superclasse del seu color (imprescindible 
        // usar els atributs estàtics de la classe ContenidorBrossa). 
        // No ha de ser un paràmetre del constructor. L’atribut propi s’inicialitza a zero.
        //                                            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        //                                                          ?????

        Vidre(string codi,string ubicacio,int anyColocacio,int tara):ContenidorBrossa(codi, ContenidorBrossa::GRIS, ubicacio, anyColocacio, tara){
            // implementacio mes efficient.
            UMESURA="UNITAT";
            EFFICIENCY=3; // 1kg = 3u
        };

        // long int getQReciclada(){return reciclat;}
        // string getReciclat(){return("Reciclat: "+to_string(reciclat)+" "+UMESURA);}
        float getReciclat(){return reciclat;}
        // implementacio NO efficient.
        // string getType(){return TIPUS;} 

        // implementacio NO efficient.
        // void toString(){
        //     ContenidorBrossa::toString();
        //     cout << getReciclat();
        // }

        void buidat(float pes){reciclat+=EFFICIENCY*(pes-tara);}

        ~Vidre(){}
        
    long int reciclat=0; // nombres d'envasos reciclats
};