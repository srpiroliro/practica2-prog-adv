#include <iostream>
#include <string>
#include <ContenidorBrossa.h>

using namespace std;

class Organic{
    public:
        Organic(
            string codi,
            string ubicacio,
            int anyColocacio, 
            float tara
        ){
            super(codi, ContenidorBrossa.MARRO, ubicacio, anyColocacio, tara);
        }

        string getReciclat(){
            return reciclat + " tones";
        }

    private:
        float reciclat; //tones
}