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

class Poblacio{
    public:
        Poblacio(){
            contenidors=new node*[CONTENIDORS_LEN];
            for (int i=0;i<CONTENIDORS_LEN;i++){
                // node *aux=new node;
                // aux->con=NULL; aux->seg=NULL;
                // contenidors[i]=aux;

                contenidors[i]=NULL;
            }
        }
        Poblacio(ContenidorBrossa *p):Poblacio(){afegirContenidor(p);}

        void afegirContenidor(ContenidorBrossa *p){
            // 1.
            string topic=""; bool ex=0;
            try{topic=hiEs(p->getCodi());}
            catch(exception& e){ex=1;}
            
            if(ex){
                int ind=getTipusId(topic);
                node *aux=contenidors[ind];
                node *nou=new node; nou->con=p; nou->seg=aux;
                contenidors[ind]=nou;
            }

            // 2.
            // int ind=getTipusId(p->getType()); // p->getType()
            // node *curr=contenidors[ind];
            
            // while(curr){
            //     if(curr->con==p) 
            //         throw_error("Ja hi existeix!");
            //     curr=curr->seg;
            // }
            // node *nou=new node; nou->con=p; nou->seg=NULL;
            // curr->seg=nou;
        }

        void afegirContenidor(string codi, int color, string ubicacio, int anyColocacio, float tara){
            ContenidorBrossa *p;
            switch (color){
                case ContenidorBrossa::GROC:p=new Plastic(codi,ubicacio,anyColocacio,tara);break;
                case ContenidorBrossa::GRIS:p=new Rebuig(codi,ubicacio,anyColocacio,tara);break;
                case ContenidorBrossa::MARRO:p=new Organic(codi,ubicacio,anyColocacio,tara);break;
                case ContenidorBrossa::VERD:p=new Vidre(codi,ubicacio,anyColocacio,tara);break;
                case ContenidorBrossa::BLAU:p=new Paper(codi,ubicacio,anyColocacio,tara);break;
                default: throw_error("uknown color");
            }
            afegirContenidor(p);
        }

        string hiEs(string codi){
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                while(curr!=NULL){
                    if(curr->con->getCodi()==codi) 
                        return curr->con->getTipusBrossa(); // curr->con->getType()
                    curr=curr->seg;
                }
            }
            throw_error("no existeix");
        }

        void eliminarContenidor(ContenidorBrossa *c){ // TEST
            string color=hiEs(c->getCodi());
            int tipus=getTipusId(color);

            node *anterior=contenidors[tipus];
            if(*(anterior->con)==c) contenidors[tipus]=anterior->seg;
            else{
                bool trobat=0;
                while(anterior->seg!=NULL && !trobat){
                    if(*(anterior->seg->con)==c){
                        anterior->seg=anterior->seg->seg; trobat=1;
                    } else anterior=anterior->seg;
                }
            }
        }

        ContenidorBrossa* mesRendiment(){
            ContenidorBrossa* r=NULL;
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                while(curr){
                    if(curr->con->getQReciclat()>r->getQReciclat()) 
                        r=curr->con;
                    curr=curr->seg;
                }
            }
            if(r==NULL) throw_error("no existex cap contanidor.");
            return r;
        }

        int getQuants(int color){
            int c=0;
            node *curr=contenidors[color];
            while(curr){ curr=curr->seg; c++; }
            return c;
        }

        int getQuants(){
            int total=0;
            for(int i=0;i<CONTENIDORS_LEN; i++){total+=getQuants(i);}
            return total;
        }

        void toString(){
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i]; int c=1;
                while(curr){
                    if(c==1){
                        cout << "Contenidors de " << curr->con->getTipusBrossa() << ":\n";
                        cout << "+++++++++++++++++++++++++++++++++++\n\n";
                    }
                    cout << "\nContenidor "<<to_string(c)<<":\n";
                    curr->con->toString(); curr=curr->seg;
                    c++;
                }
                cout << "\n-----------------------------------" << "\n\n";
            }
            cout << endl;
        }

        // OPERATORS
        bool operator<(Poblacio d){return getQuants()<d.getQuants();} 
        bool operator>(Poblacio d){return !(getQuants()<d.getQuants());}
        bool operator==(Poblacio d){return ( !((*this)>d) && !((*this)<d) );}
        

        ~Poblacio(){delete[] contenidors;}
    
    string nom;
    int anyCreacio;
    int habitants;

    struct node{ 
        ContenidorBrossa *con; 
        node *seg; 
    };
    node **contenidors;
    
    int getTipusId(string t){
        if(t=="Plastic") return ContenidorBrossa::GROC;
        if(t=="Rebuig") return ContenidorBrossa::GRIS;
        if(t=="Organic") return ContenidorBrossa::MARRO;
        if(t=="Vidre") return ContenidorBrossa::VERD;
        if(t=="Paper") return ContenidorBrossa::BLAU;
    }

    // mes efficient seria crear una classe Error i guardarho alla.
    void throw_error(string error){
        cerr<<"ERROR: "<<error<<endl; throw;
    }
};