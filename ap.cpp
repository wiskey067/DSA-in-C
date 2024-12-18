#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int *p,i;
    p = new int[5];
    p[0]=2,p[1]=2,p[2]=4,p[3]=5 ;
    for(i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    } 
    
    }
