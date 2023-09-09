// QUICKSORT
// se elige pivote
// se realiza particion a la izquierda menores a la derecha mauyores
// se repite con la lista izquierda al pivote y la lista derecha al pivote

#include <iostream>
#include "numeros.h"

//seleccion del pivote
int seleccionPivoteAzar(int inicio, int fin){
    int largo=fin-inicio;
    return rand()%largo + inicio;
}

//intercambia dos numeros dentro del array nums;
void swapNumeros (int i,int j){
    int aux=nums[i];
    nums[i]=nums[j];
    nums[j]=aux;
}

int particionar(int inicio, int fin, int pivote){
    int valorpivote=nums[pivote];
    int final=fin-1;
    swapNumeros(final,pivote); // se lleva el elemento pivote al final
    int x=inicio;
    for (int i = inicio; i<final ;i++){ // desde el inicio hasta uno menos del pivote
        if (nums[i]<valorpivote) {
            swapNumeros(i,x);
            x++;
        }
    }
    swapNumeros(final,x);
    return x;
}

void quickSort(int inicio,int final){
    int largo=final-inicio;
    if (largo<=1){
        return;
    } else {
        int pivote=seleccionPivoteAzar(inicio,final);
        int p=particionar(inicio, final, pivote); // en p devuelve la posicion definitiva de pivote
        quickSort(inicio,p); // repite orden con lista izquierda al pivote
        quickSort(p+1,final); // repite orden con lista derecha al pivote
    }
}

void quickSort(){
    quickSort(0,MAXNUMS);
}


