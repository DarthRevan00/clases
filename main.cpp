#include <iostream>
#include <time.h>
#include <algorithm>
#include "numeros.h"
#include "radixSort.h"
#include "quickSort.h"
#include "quicksort2.h"
#include "countingSort.h"
#include "vector.h"
#include "array.h"
#include "mergeSort.h"
#include "radix_vector.h"

void medirTiempo(char const *nombre,void (*funcion)()){
    clock_t begin=clock();
    funcion();
    clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << nombre << ": " << time_spent << " segs" << std::endl;
}

int main(){
    initNumeros();
    int *respaldo=new int[MAXNUMS];
    std::copy(nums,nums+MAXNUMS,respaldo);

    medirTiempo("MERGE SORT",mergeSort);
    visualizar();


    std::copy(respaldo,respaldo+MAXNUMS,nums);
    medirTiempo("RADIX SORT",radixSort);
    visualizar();

    std::copy(respaldo,respaldo+MAXNUMS,nums);
    medirTiempo("QUICK SORT",quickSort);
    visualizar();

    std::copy(respaldo,respaldo+MAXNUMS,nums);
    medirTiempo("QUICK SORT 2",quickSort2);
    visualizar();

    std::copy(respaldo,respaldo+MAXNUMS,nums);
    medirTiempo("Counting SORT",countingSort);
    visualizar();

    std::copy(respaldo,respaldo+MAXNUMS,nums);
    vectorTest();

    std::copy(respaldo,respaldo+MAXNUMS,nums);
    arrayTest();

    std::copy(respaldo,respaldo+MAXNUMS,nums);
    medirTiempo("Radix Vector", radix_vector_sort);
    visualizar();

    delete [] respaldo;
    return 0;

}