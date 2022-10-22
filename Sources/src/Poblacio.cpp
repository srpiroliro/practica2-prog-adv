#include <iostream>
#include <ContenidorBrossa.h>

using namespace std;

class Poblacio {
    public:
        //No se si res d'aquestes coses està bé, tot ho ha fet Copilot de una sola vegada :)
        Poblacio(string nom, int anyCreacio, int habitants){
            this->nom=nom;
            this->anyCreacio=anyCreacio;
            this->habitants=habitants;
        }
        string getNom(){
            return nom;
        }
        int getAnyCreacio(){
            return anyCreacio;
        }
        int getHabitants(){
            return habitants;
        }
        void setHabitants(int habitants){
            this->habitants=habitants;
        }
        void setAnyCreacio(int anyCreacio){
            this->anyCreacio=anyCreacio;
        }
        void setNom(string nom){
            this->nom=nom;
        }
        void addContenidor(ContenidorBrossa contenidor){
            contenidors.push_back(contenidor);
        }
        void removeContenidor(ContenidorBrossa contenidor){
            contenidors.remove(contenidor);
        }
        int getNumContenidors(){
            return contenidors.size();
        }
        ContenidorBrossa getContenidor(int index){
            return contenidors[index];
        }
        int getNumContenidorsColor(int color){
            int num=0;
            for (int i=0; i<contenidors.size(); i++){
                if (contenidors[i].getColor()==color) num++;
            }
            return num;
        }
        int getNumContenidorsTipus(string tipus){
            int num=0;
            for (int i=0; i<contenidors.size(); i++){
                if (contenidors[i].getTipus()==tipus) num++;
            }
            return num;
        }
        int getNumContenidorsUbicacio(string ubicacio){
            int num=0;
            for (int i=0; i<contenidors.size(); i++){
                if (contenidors[i].getUbicacio()==ubicacio) num++;
            }
            return num;
        }
        int getNumContenidorsAnyColocacio(int anyColocacio){
            int num=0;
            for (int i=0; i<contenidors.size(); i++){
                if (contenidors[i].getAnyColocacio()==anyColocacio) num++;
            }
            return
};