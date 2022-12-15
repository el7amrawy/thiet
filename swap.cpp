#include <iostream>

using namespace std;

void swap(int* x,int* y);
void increament(int* x);

int main(){
    int x=1,y=2;
    // swap(&x,&y);
    increament(&x);
    cout<<x;
}

void swap(int* x,int* y){
    int z=*x;
    *x=*y;
    *y=z;
}

void increament(int* x){
    *x+=1;
    // cout<<*x<<endl;
}