#include<cstring>
#include "numeros.h"

int *valores=new int [MAXVALUE];

void initValues(){
    memset(valores,0,sizeof(int)*MAXVALUE);
}

void countingSort(){
    initValues();
    
    //Cuenta
    for (int i=0;i<MAXNUMS;i++){
        valores[nums[i]]++;
    }

    //traspasa resultado a nums
    int x=0;
    for (int i=0;i<MAXVALUE;i++){
        for (int j=0;j<valores[i];j++){
            nums[x++]=i;
        }
    }
}