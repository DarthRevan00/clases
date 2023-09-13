// QUICKSORT
// se elige pivote
// se realiza particion a la izquierda menores a la derecha mauyores
// se repite con la lista izquierda al pivote y la lista derecha al pivote

#include <iostream>
#include "numeros.h"


//intercambia dos numeros dentro del array nums;
//optimiza poco pero se ganan 200 milisegundos
void swapNumeros2 (int &i,int &j){
    int aux=i;
    i=j;
    j=aux;
}

int *particionar2(int *inicio, int *fin, int *pivote){
    int *final=fin-1;
    swapNumeros2(*final,*pivote); 

    int *p=inicio;
    int *x=inicio;
    while(p!=final){
        if (*p<*final){
            swapNumeros2(*p,*x);
            x++;
        }
        p++;
    }
    swapNumeros2(*final,*x);
    return x;
}

void quickSort2(int *inicio,int *final){
    int largo=final-inicio;
    if (largo<=1){
        return;
    } else {
        int *pivote=((final-inicio)>>1) + inicio; //pivote elegido del medio
        int *p=particionar2(inicio, final, pivote); // en p devuelve la posicion definitiva de pivote
        quickSort2(inicio,p); // repite orden con lista izquierda al pivote
        quickSort2(p+1,final); // repite orden con lista derecha al pivote
    }
}

void quickSort2(){
    quickSort2(nums,nums+MAXNUMS);
}


