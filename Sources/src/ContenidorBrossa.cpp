#include <string>
#include <regex> //legal??
#include <time.h>

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
            if (regex_match(codi, regex("[a-zA-Z]{2}-\d{4}"))) this->codi = codi;
            else throw "El codi ha de tenir 2 lletres i 4 numeros";

            if (color >= 0 && color <= 4) this->color = color;
            else throw "El color ha de ser un valor entre 0 i 4";

            this->ubicacio=ubicacio;
            
            if (anyColocacio <= getAnyActual()) this->anyColocacio = anyColocacio;
            else throw "No es pot colocar un contenidor en el futur";

            if (tara >= 0) this->tara = tara;
            else throw "La tara ha de ser un valor positiu";
        }
        ContenidorBrossa(
            string codi, 
            int color, 
            int anyRetirada,
            float tara
        ){
            this(codi, color, NULL, 0, tara);
            this->anyRetirada=anyRetirada;
        }

        const int GROC=0;
        const int GRIS=1;
        const int MARRO=2;
        const int VERD=3;
        const int BLAU=4;

        string getTipus(){
            switch(color){
                case GROC:
                    return "Plastic";
                case GRIS:
                    return "Rebuig";
                case MARRO:
                    return "Organic";
                case VERD:
                    return "Vidre";
                case BLAU:
                    return "Paper";
                default:
                    return "Desconegut";
            }
        }
        string getUbicacio(){
            if (ubicacio == NULL) throw "El contenidor no esta ubicat";
            else return ubicacio;
        }

        int getCodi(){
            return (int) codi.substr(2); //aa-1234 -> 1234
        }

        string getEstat(){
            if (ubicacio == NULL) return "Retirat";
            if (getAnyActual() - anyColocacio > 5) return "Vell";
            if (getAnyActual() - anyColocacio < 3) return "Nou";
            return "Seminou";
        }

        void retirarViaPublica(){
            if (ubicacio == NULL) throw "El contenidor no esta a la via pública";
            this->anyRetirada=getAnyActual();
            this->ubicacio=NULL;
            this->anyColocacio=0;
        }

        void setUbicacio(string ubicacio){
            if (ubicacio == NULL) retirarViaPublica();
            else {
                this->ubicacio=ubicacio;
                this->anyColocacio=getAnyActual();
            }
        }

        void toString(){
            cout << "Codi: " << codi << endl;
            cout << "Color: " << getTipus() << endl;
            if(ubicacio != NULL) cout << "Ubicacio: " << ubicacio << endl;
            else cout << "Ubicacio: Retirat" << endl;
            cout << setprecision(2) << "Tara: " << tara << endl;
        }

        virtual void buidat(float pes) = 0;
        
        virtual string getType() = 0;

        virtual string getReciclat() = 0;

        //TODO: Obligatòriament en la implementació d’un d’aquest operadors s’ha d’invocar als altres dos, i a més usant directament la simbologia de l’operador
        bool operator==(ContenidorBrossa *p){
            return codi.compare(p.codi);
        }

        bool operator<(ContenidorBrossa *p){
            return this->getCodi() < p.getCodi();
        }

        bool operator>(ContenidorBrossa *p){
            return !(this() < p);
        }

        ~ContenidorBrossa(){}

    protected:
        float tara;
    
    string codi;
    int color;
    string ubicacio;
    int anyColocacio;
    int anyRetirada;

    private:
        int getAnyActual(){
            time_t now;
            struct tm *now_tm;
            now = time(NULL);
            now_tm = localtime(&now);
            return now_tm->tm_year + 1900;
        }
};