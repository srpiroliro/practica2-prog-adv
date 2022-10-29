#include <string>
#include <iostream>
// #include "classes/ContenidorBrossa.h"

using namespace std;


class Test {
    public:
        Test():Test("AA"){};
        Test(string x){
            this->x=x;
        }
        int operator<(Test& p){
            return x.compare(p->getX())<0;
        }

        string getX(){return x;}
    private:
        string x;
};

bool te(Test *p){
    cout << p->x << endl;
}

int main(){
    Test a=Test("10");
    // Test b=Test();
    // // Test *c = b;
    // cout << (a<b) << endl;
    return 0;
}