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
            if(!verificar_codi()) 
                throw_error("El codi ha de tenir 2 lletres i 4 numeros separats per un guio.");
            this->codi=codi;

            if(color<0 && color>4) 
                throw_error("El color ha de ser un valor entre 0 i 4.");
            this->color=color;

            if((anyColocacio!=0 && ubicacio=="")||(anyColocacio==0 && ubicacio!="")) 
                throw_error("nomes poden tenir valors \"null\"s els dos a l'hora");
            this->ubicacio=ubicacio;
            
            if(anyColocacio>getAnyActual()) 
                throw_error("No es pot colocar un contenidor en el futur.");
            this->anyColocacio=anyColocacio;

            if(tara<=0) 
                throw_error("La tara ha de ser un valor positiu.");
            this->tara=tara;
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
            }
        }
        string getUbicacio(){
            if(ubicacio=="") throw_error("El contenidor no esta ubicat");
            else return ubicacio;
        }
        string getEstat(){
            if(ubicacio=="") return "Retirat";
            int rest=getAnyActual()-anyColocacio;
            if(rest>5) return "Vell";
            if(rest<3) return "Nou";
            return "Seminou";
        }
        string getCodi(){return codi;} 

        // SETS
        void setUbicacio(string ubicacio){
            if(ubicacio=="") retirarViaPublica();
            else{
                this->ubicacio=ubicacio;
                this->anyColocacio=getAnyActual();
            }
        }

        // ACTIONS
        void retirarViaPublica(){
            if(ubicacio=="") throw_error("El contenidor no esta a la via pública");
            this->anyRetirada=getAnyActual();
            this->ubicacio="";
            this->anyColocacio=0;
        }
        void toString(){
            cout << getReciclat(); // mes efficient.
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
        virtual string getReciclat()=0;
        virtual float getQReciclat()=0;
        // virtual string getType()=0; // implementacio NO efficient.


        // OPERATORS
        bool operator>(ContenidorBrossa *p){return codi.compare(p->getCodi())>0;}
        bool operator<(ContenidorBrossa *p){return !((*this)>(p));} 
        bool operator==(ContenidorBrossa *p){return ( !( (*this)>p ) && !( (*this)<p) );}


        // DECONSTRUCTOR
        ~ContenidorBrossa(){} 

    protected:
        float tara;

        // CHECK: implementacio mes efficient.
        string UMESURA;
        float EFFICIENCY;

    string codi, ubicacio;
    int color,anyColocacio,anyRetirada;
    
    int getAnyActual(){
        time_t now;
        struct tm *now_tm;
        now=time(NULL);
        now_tm=localtime(&now);
        return now_tm->tm_year+1900;
    }

    bool verificar_codi(){
        if(codi.length()!=7) 
            throw_error("el codi ha de ser XX-YYY, X sent lletres majs, i Y nums.");
    
        string letters=codi.substr(0, 2),
            dash=codi.substr(2, 1),
            numbers=codi.substr(3, 4);
        bool ex=0; int x=0;
        try{ x=stoi(numbers); }
        catch(exception& e){ ex=1; }
        
        if(dash!="-")
            throw_error("el 3r char ha de ser un \"-\"!");
        if(!("AA"<=letters&&letters<="ZZ"))
            throw_error("els dos primers chars had d'estar entre AA-ZZ!");
        if (ex || x<1111 || x>9999) 
            throw_error("el rang dels nums ha de ser [1111, 9999]");
        
        return 1;
    }

    // mes efficient seria crear una classe Error i guardarho alla.
    void throw_error(string error){
        cerr<<"ERROR: "<<error<<endl; throw;
    }
};