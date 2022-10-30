#include <string>
#include <iostream>
// #include "classes/ContenidorBrossa.h"
#define CONTENIDORS_LEN 5

using namespace std;

template <typename T>
int getX(T x, T y){
    return x==y;
}



int main(){
    cout << CONTENIDORS_LEN << endl;
    
    return 0;
}