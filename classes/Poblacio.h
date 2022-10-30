#include <iostream>
#include "ContenidorBrossa.h"

using namespace std;

class Poblacio{
    public:
        Poblacio(){
           private node *contendiors;
           contendiors = new node[5];
        }
        
        Poblacio(ContenidorBrossa *g):ContenidorBrossa(){
            afegirContenidor(g);
        }
        
        void afegirContenidor(ContenidorBrossa *g){
            // Mètode void afegirContenidor(ContenidorBrossa *p) que simula l’alta d’un contenidor. El mètode llança una excepció si el contenidor ja està al magatzem. Dos contenidors són iguals si tenen el mateix codi, invoqueu obligatòriament l’operador d’igualtat sobrecarregat de la classe ContenirBrossa. Sempre que es tingui que localitzar un contenidor brossa obligatòriament cal invocar a l’operador == usant la simbologia de l’operador

            
        }
        
        ~Poblacio(){
            delete[] contendiors;
        }

    private:

        struct node{
            ContenidorBrossa *contenidor;
            node *seg;
        };
};