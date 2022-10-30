#include <iostream>
#include <vector>
#include "ContenidorBrossa.h"

#include "contenidors/Organic.h"
#include "contenidors/Paper.h"
#include "contenidors/Plastic.h"
#include "contenidors/Rebuig.h"
#include "contenidors/Vidre.h"


#define CONTENIDORS_LEN 5

using namespace std;

class Poblacio {
    public:
        Poblacio(){
            contenidors=new node*[CONTENIDORS_LEN];
        }
        Poblacio(ContenidorBrossa *p):Poblacio(){
            afegirContenidor(p);
        }

        void afegirContenidor(ContenidorBrossa *p){ // TEST
            int ind=getTipusId(p->getType());

            node *curr=contenidors[ind]; // p->getColor()
            // findLast()
            while(curr){
                if(curr->con->getCodi()==p->getCodi()) 
                    throw("Ja hi existeix!");
                curr=curr->seg;
            }
            node *nou; nou->con=p;
            curr->seg=nou;
        }

        void afegirContenidor(string codi, int color, string ubicacio, int anyColocacio, float tara){
            ContenidorBrossa *p;
            switch (color){
                case 0:
                    p=new Plastic(codi,ubicacio,anyColocacio,tara);
                    break;
                case 1:
                    p=new Rebuig(codi,ubicacio,anyColocacio,tara);
                    break;
                case 2:
                    p=new Organic(codi,ubicacio,anyColocacio,tara);
                    break;
                case 3:
                    p=new Vidre(codi,ubicacio,anyColocacio,tara);
                    break;
                case 4:
                    p=new Paper(codi,ubicacio,anyColocacio,tara);
                    break;
                default: throw("uknown color");
            }
            afegirContenidor(p);
        }

        string hiEs(string codi){
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                while(curr){
                    if(curr->con->getCodi()==codi) 
                        return curr->con->getType();
                    curr=curr->seg;
                }
            }
            throw("no existeix");
        }

        void eliminarContenidor(ContenidorBrossa *c){ // TEST
            string color=hiEs(c->getCodi());
            int tipus=getTipusId(color);

            node *anterior=contenidors[tipus];
            if(anterior->con->getCodi()==c->getCodi()){
                contenidors[tipus]=anterior->seg;
            }else{
                bool trobat=0;
                while(anterior->seg!=NULL && !trobat){
                    if(anterior->seg->con->getCodi()==c->getCodi()){
                        anterior->seg=anterior->seg->seg;
                        trobat=1;
                    } else anterior=anterior->seg;
                }
            }
        }

        ContenidorBrossa* mesRendiment(){
            ContenidorBrossa* r=NULL;
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                while(curr){
                    if(curr->con->getQReciclada()>r->getQReciclada()) r=curr->con; // TODO
                    curr=curr->seg;
                }
            }
            if(r) throw("no existex cap contanidor.");
            return r;
        }

        int getQuants(int color){
            int c=0;
            node *curr=contenidors[color];
            while(curr){
                curr=curr->seg;
                c++;
            }
            return c;
        }

        int getQuants(){
            int total=0;
            for(int i=0;i<CONTENIDORS_LEN; i++){total+=getQuants(i);}
            return total;
        }

        void toString(){
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                bool primer=1;
                while(curr){
                    if(primer){
                        cout << "Contenidors de " << curr->con << ":\n";
                        cout << "+++++++++++++++++++++++++++++++++++"<<'\n\n';
                    }
                    curr->con->toString(); 
                    curr=curr->seg;
                }
                cout << "\n\n";
            }
            cout << endl;
        }

        // OPERATORS
        bool operator<(Poblacio d){return getQuants()<d.getQuants();} 
        bool operator>(Poblacio d){return !(getQuants()<d.getQuants());}
        bool operator==(Poblacio d){return ( !((*this)>d) && !((*this)<d) );} // TODO: (*this) or (this)
        

        ~Poblacio(){delete contenidors;} // "alliberar l’espai ocupat per la població: contenidors, vector i nodes" ???


    
    string nom;
    int anyCreacio;
    int habitants;

    struct node{ 
        ContenidorBrossa *con; 
        node *seg; 
    };
    node **contenidors;
    
    int getTipusId(string t){
        if(t=="Plastic") return 0;
        if(t=="Rebuig") return 1;
        if(t=="Organic") return 2;
        if(t=="Vidre") return 3;
        if(t=="Paper") return 4;
    }
};