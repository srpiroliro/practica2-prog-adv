#include <iostream>
#include <string>
#include <ContenidorBrossa.h>

using namespace std;

class Vidre{
    public:
        Vidre(
            string codi,
            string ubicacio,
            int anyColocacio, 
            float tara
        ){
            super(codi, ContenidorBrossa.VERD, ubicacio, anyColocacio, tara);
        }

        string getReciclat(){
            return reciclat + " numero d'envasos reciclats";
        }

    private:
        long reciclat; //nombre d'envasos reciclats
}