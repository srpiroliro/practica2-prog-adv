#include <string>
#include <iostream>
// #include "classes/ContenidorBrossa.h"

using namespace std;


class Test {
    public:
        Test():Test("AAS"){};
        Test(string x){
            this->x=x;
        }
        string A = "ABC";
        string getX(){return x;}
    protected:
        string x;
    
};
class TestA: public Test {
    public:
        TestA(string x):Test(Test::A){
            cout << x << "+"<< Test::A << endl;
        }
};


int main(){
    TestA a=TestA("10");
    cout << a.getX() << endl;
    return 0;
}