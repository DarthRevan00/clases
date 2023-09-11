#include <iostream>
#include <cstring>
#include "numeros.h"


void mezclar(int *array,int lizq, int lder){
    const int largo=lizq+lder;
    int *izq=array, *der=array+lizq; // marca las direcciones de inicio
    const int *fizq=der,*fder=der+lder; // deja las direcciones de fin

    int *res=new int[largo];
    for (int k=0;k<largo;k++){
        if(izq>=fizq){
            res[k]=*(der++);
        } else if (der>=fder){
            res[k]=*(izq++);
        } else if (*izq<*der){
            res[k]=*(izq++);
        } else {
            res[k]=*(der++);
        }

    }

    //copia resultado a parte adecuada
    memcpy(array,res,sizeof(int)*largo);
    delete[] res;
}

void mergeSort(int *lista,int largo){
    if (largo<=1){
        return;
    } else {
        int medio=(largo>>1);
        mergeSort(lista,medio);
        mergeSort(lista+medio,largo-medio);
        mezclar(lista,medio,largo-medio);
    }
}

void mergeSort(){
    mergeSort(nums,MAXNUMS);
}