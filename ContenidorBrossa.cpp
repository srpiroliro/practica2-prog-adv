#include <string>

using namespace std;

class ContenidorBrossa {
    public:
        ContenidorBrossa(
            string codi, 
            int color, 
            string ubicacio,
            int anyColocacio, 
            float tara
        ){
            this->codi=codi;
            this->color=color;
            this->ubicacio=ubicacio;
            this->anyColocacio=anyColocacio;
            this->tara=tara;
        }

        // sobrecarregar el s’ubica el contenidor directament al magatzem de l’Ajuntament,  no  s’ubica  al  carrer
        // si no es pot invocar l'altre, crear un amb valor per defecte var=Something

        const int GROC=0;
        const int GRIS=1;
        const int MARRO=2;
        const int VERD=3;
        const int BLAU=4;



    protected:
        int tara;
    
    string codi;
    int color;
    string ubicacio;
    int anyColocacio;
    int anyRetirada;
};