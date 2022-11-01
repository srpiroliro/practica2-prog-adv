#include <string>
#include <iostream>
#define CONTENIDORS_LEN 5

using namespace std;
// void throw_error(string error){
//     cerr<<error<<endl; throw;
// }


struct node{ 
    int *con; 
    node *seg; 
};

int main(){
    node **contenidors;
    contenidors=new node*[CONTENIDORS_LEN];
    for (int i=0;i<CONTENIDORS_LEN;i++){
        contenidors[i]=NULL;
    }

    node* a5=new node;
    a5->con=new int(5);
    a5->seg=NULL;

    node* a4=new node;
    a4->con=new int(4);
    a4->seg=a5;

    node* a3=new node;
    a3->con=new int(3);
    a3->seg=a4;

    node* a2=new node;
    a2->con=new int(2);
    a2->seg=a3;


    node* aNEW=new node;
    aNEW->con=new int(333);
    aNEW->seg=NULL;
    
    int i=1;

    contenidors[i]=a2;

    node *curr=contenidors[i];
    while(curr){
        cout << *(curr->con) << endl;
        curr=curr->seg;
    }
    delete curr;

    cout << endl;
    

    node *aux=contenidors[i];
    contenidors[i]=aNEW;
    contenidors[i]->seg=aux;

    node *cur=contenidors[i];
    while(cur){
        cout << *(cur->con) << endl;
        cur=cur->seg;
    }
    // int c=0;
    // while((curr)!=NULL){
    //     curr=curr->seg;
    //     c++;
    //     cout << c << " new " << curr <<" new " << (curr!=NULL) << endl;
    // }
    cout << " asas" << endl; return 0;



    if(contenidors[1]==NULL){
    }

    cout << contenidors[1] << endl;

    return 0;
}
