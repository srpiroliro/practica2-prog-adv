// TO DO:
// 1. int getCodi() o string getCodi()??
// 2. regex legal? si no ho es, partir str en tres i: 
//      [1]!="-" => MAL
//      si [0] es pot passar a int => gut (try/catch) + lalrgada de 2
//      comprovar que [2] sigui tot lletres + llargada de 4
// 3. operator>(ContenidorBrossa *c) => ajustar a la solucio del punt 1.
// 4. operator==(ContenidorBrossa *c) => (*this) or (this)

#include <string>
#include <regex> //legal??
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

class ContenidorBrossa {
    public:

        // CONSTRUCTORS
        ContenidorBrossa(
            string codi,
            int color,
            string ubicacio,
            int anyColocacio,
            float tara
        ){ 
            if(verificar_codi(codi)) this->codi=codi;
            else throw "El codi ha de tenir 2 lletres i 4 numeros separats per un guio.";

            if(color>=0 && color<=4) this->color=color;
            else throw "El color ha de ser un valor entre 0 i 4.";

            this->ubicacio=ubicacio;
            
            if(anyColocacio<=getAnyActual()) this->anyColocacio=anyColocacio;
            else throw "No es pot colocar un contenidor en el futur.";

            if(tara>=0) this->tara=tara;
            else throw "La tara ha de ser un valor positiu.";
        }
        ContenidorBrossa(
            string codi, 
            int color, 
            int anyRetirada,
            float tara
        ):ContenidorBrossa(codi,color,"",0,tara){
            this->anyRetirada=anyRetirada;
        }


        // CONSTANTS
        // enum {GROC, GRIS, MARRO, VERD, BLAU}; // enum es const
        // aka: GROC=0, GRIS=1, MARRO=2 ...

        static const int GROC=0;
        static const int GRIS=1;
        static const int MARRO=2;
        static const int VERD=3;
        static const int BLAU=4;

        // GETS
        string getTipusBrossa(){
            switch(color){
                case GROC: return "Plastic";
                case GRIS: return "Rebuig";
                case MARRO: return "Organic";
                case VERD: return "Vidre";
                case BLAU: return "Paper";
                default: return "Desconegut";
            }
        }
        string getUbicacio(){
            if(ubicacio=="") throw "El contenidor no esta ubicat";
            else return ubicacio;
        }
        string getEstat(){
            if(ubicacio=="") return "Retirat";
            int rest=getAnyActual()-anyColocacio;
            if(rest>5) return "Vell";
            if(rest<3) return "Nou";
            return "Seminou";
        }
        int getCodi(){return stoi(codi.substr(codi.length()-4));} // TODO
        // string getCodi(){return codi;}
        

        // SETS
        void setUbicacio(string ubicacio){this->ubicacio=ubicacio;}

        // ACTIONS
        void retirarViaPublica(){
            if(ubicacio=="") 
                throw "El contenidor no esta a la via pública";
            this->anyRetirada=getAnyActual();
            this->ubicacio="";
            this->anyColocacio=0;
        }
        void setUbicacio(string ubicacio){
            if(ubicacio == "") retirarViaPublica();
            else{
                this->ubicacio=ubicacio;
                this->anyColocacio=getAnyActual();
            }
        }
        void toString(){
            cout << "Codi: " << codi << '\n';
            cout << "Color: " << getTipusBrossa() << '\n';
            if(ubicacio!="") 
                cout << "Ubicacio: " << ubicacio << '\n';
            else 
                cout << "Ubicacio: Retirat" << '\n';
            cout << "Tara: " << fixed << setprecision(2) << tara << endl;
        }

        // VIRTUALS
        virtual void buidat(float pes)=0;
        virtual string getType()=0; // saber de quina classe és l’objecte sobre el que s’invoca.
        virtual string getReciclat()=0; // retornarà la quantitat de material reciclat pel contenidor.

        
        // OPERATORS
        //      TO DO:
        //         Obligatòriament en la implementació d’un d’aquest operadors s’ha d’invocar als ???altres dos???, 
        //         i a més usant directament la simbologia de l’operador. Recomanació: usar el 
        //         mètode compare per comparar string (llibreria <string.h>)

        bool operator>(ContenidorBrossa *p){return codi.compare(p->getCodi())>0;} // TODO
        bool operator<(ContenidorBrossa *p){return !((*this)>p);} 
        bool operator==(ContenidorBrossa *p){return ( !( (*this)>p ) && !( (*this)<p) );} // TODO: (*this) or (this)

        // NOT LEGAL
        //      bool operator>(ContenidorBrossa& p){return !(*this<p);}
        //      bool operator<(ContenidorBrossa& p){return this->getCodi()<p.getCodi();}



        // DECONSTRUCTOR
        ~ContenidorBrossa(){} 

    protected:
        float tara;
    
    string codi; // identificador, no hi poden haver  dos o més contenidors amb el mateix codi.
    int color; // valor enter corresponent a alguna de les constants estàtiques de la classe.
    string ubicacio; // NULL || ""=indica que està al magatzem de l’Ajuntament.

    int anyColocacio; // 4 xifres, representa l’any que entra en servei el contenidor. Si no està ubicat a la via publica el valor d’aquest atribut serà un zero
    int anyRetirada; // 4xifres, treu de la via publica el contenidor i per tant està al magatzem de l’Ajuntament. Si encara està ubicat a la via publica el valor d’aquest atribut serà zero.
    // sempre un d'aquests sera 0.


    
    int getAnyActual(){
        time_t now;
        struct tm *now_tm;
        now=time(NULL);
        now_tm=localtime(&now);
        return now_tm->tm_year+1900;
    }

    bool verificar_codi(string c){
        // verificar si ja existeix?
        // regex legal?
        return regex_match(codi, regex("[a-zA-Z]{2}-\d{4}"));
    }
};