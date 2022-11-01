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
            for (int i=0;i<CONTENIDORS_LEN;i++)
                contenidors[i]=NULL;
        }
        Poblacio(ContenidorBrossa *p):Poblacio(){afegirContenidor(p);}

        void afegirContenidor(ContenidorBrossa *p){
            if(!p) throw_error("no pots passar valors nulls!");
            // 1.
            string topic=""; bool ex=0;
            try{
                topic=hiEs(p->getCodi(), 0);
            }catch(...){
                int ind=getTipusId(p->getTipusBrossa()); // p->getType()
                node *aux=contenidors[ind];
                node *nou=new node; nou->con=p; nou->seg=aux;
                contenidors[ind]=nou;
            }
            if(topic!="") throw_error("ja existeix un d'igual!");
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

        string hiEs(string codi, bool display=1){ // INFO: bool display sha afegit per estetica.
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                while(curr!=NULL){
                    if(curr->con->getCodi()==codi) 
                        return curr->con->getTipusBrossa(); // curr->con->getType()
                    curr=curr->seg;
                }
            }
            throw_error("no existeix", display);
            return "";
        }

        void eliminarContenidor(ContenidorBrossa *c){
            int tipus=getTipusId(c->getTipusBrossa());

            node *anterior=contenidors[tipus]; bool trobat=0;
            if(*(anterior->con)==c) {
                contenidors[tipus]=anterior->seg; 
                trobat=1;
            }
            else{
                while(anterior->seg!=NULL && !trobat){
                    cout << anterior->seg->con->getCodi() << endl;
                    if(*(anterior->seg->con)==c){
                        node *aux=anterior->seg;
                        anterior->seg=anterior->seg->seg; 
                        delete aux;

                        trobat=1;
                    } else anterior=anterior->seg;
                }
            }
            if(!trobat) throw_error("no existeix");
        }

        ContenidorBrossa* mesRendiment(){
            ContenidorBrossa* r=NULL;
            for(int i=0;i<CONTENIDORS_LEN; i++){
                node *curr=contenidors[i];
                while(curr){
                    if(!r || curr->con->getQReciclat()>r->getQReciclat()) 
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
            if(getQuants()!=0){ // potser no es efficient?
                for(int i=0;i<CONTENIDORS_LEN; i++){
                    node *curr=contenidors[i]; int c=1;
                    if(curr){
                        while(curr){
                            if(c==1)
                                cout << "==============  Contenidors de " << curr->con->getTipusBrossa() << "  ==============\n\n";
                            cout << "Contenidor "<<to_string(c)<<":\n--------------\n";
                            curr->con->toString(); curr=curr->seg;
                            c++;
                        }
                        cout << "====================================================\n\n\n";
                    }
                }
            } else cout<<"CAP CONTENIDOR!"<<'\n';
            cout << endl;
        }

        // OPERATORS
        bool operator<(Poblacio d){return getQuants()<d.getQuants();} 
        bool operator>(Poblacio d){return !(getQuants()<d.getQuants());}
        bool operator==(Poblacio d){return ( !((*this)>d) && !((*this)<d) );}
        

        ~Poblacio(){
            for(int i=0;i<CONTENIDORS_LEN; i++) delete contenidors[i];
            delete[] contenidors;
        }
    
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
        return ContenidorBrossa::BLAU; // if(t=="Paper") 
    }

    void throw_error(string error, bool display=1){
        if(display) cerr<<"ERROR: "<<error<<endl;
        throw 0;
    }
};