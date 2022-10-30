#include <iostream>
#include <string>
#include <ContenidorBrossa.h>

using namespace std;

class Rebuig{
    public:
        Rebuig(
            string codi,
            string ubicacio,
            int anyColocacio, 
            float tara
        ){
            super(codi, ContenidorBrossa.GRIS, ubicacio, anyColocacio, tara);
        }

        string getReciclat(){
            return reciclat + " tones";
        }

    private:
        float reciclat; //tones
}