#include <iostream>
#include "ContenidorBrossa.h"

using namespace std;

class Poblacio{
    public:
        Poblacio(){
           private node *contendiors;
           contendiors = new node[5];
        }

    private:

        struct node{
            ContenidorBrossa *contenidor;
            node *seg;
        };
};