#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(){
    int a ;
    cout<<"enter the number:";
    cin>>a;
    int *p;
    p=&a;
    cout<<*p<<endl;
    printf("using pointer %d ",*p);
}