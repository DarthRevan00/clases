#include <iostream>
#include "numeros.h"

using namespace std;

int *nums;

void initNumeros(){
    nums=new int[MAXNUMS];
    srand(time(NULL));   // Initialization, should only be called once.
    for (int i=0;i<MAXNUMS;i++){
        nums[i]=rand()%MAXVALUE;      // Returns a pseudo-random integer between 0 and RAND_MAX.
    }
}

void visualizar(int n){
    cout<<"[";
    for (int i=0;i<n && i<MAXNUMS;i++){
        cout<<nums[i];
        if (i+1<n)cout <<", ";
    }
    cout<<"]"<<endl;
}

int getDigit(int number, int dig){
    for (unsigned char i=0;i<dig;i++){
        number/=10;
    }
    return number%10;
}

int getDigitCount(int number){
    int count=1;
    while ((number/=10)!=0)
        count++;
    return count;
}
