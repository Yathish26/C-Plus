#include<iostream>
using namespace std;

int Tables(int x){
    for (int i=0; i<x; i++){
        cout<<"Table of "<<i<<":"<< endl;
        for (int j=1; j<10; j++){
            cout<<i<<"x"<<j<<"="<<(i+j)<<endl;
        }
        cout<<endl;
    };
}




int main(){
    Tables(5);
    return 0;
}