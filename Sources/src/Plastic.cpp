#include <iostream>
#include <string>
#include <ContenidorBrossa.h>

using namespace std;

class Plastic{
    public:
        Plastic(
            string codi,
            string ubicacio,
            int anyColocacio, 
            float tara
        ){
            super(codi, ContenidorBrossa.GROC, ubicacio, anyColocacio, tara);
        }

        string getReciclat(){
            return reciclat + " kilograms";
        }
        
    private:
        float reciclat; //kilograms
}