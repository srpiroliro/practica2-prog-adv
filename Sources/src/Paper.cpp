#include <iostream>
#include <string>
#include <ContenidorBrossa.h>

using namespace std;

class Paper{
    public:
        Paper(
            string codi,
            string ubicacio,
            int anyColocacio, 
            float tara
        ){
            super(codi, ContenidorBrossa.BLAU, ubicacio, anyColocacio, tara);
        }

        string getReciclat(){
            return reciclat + " kilograms";
        }

    private:
        float reciclat; //kilograms
}