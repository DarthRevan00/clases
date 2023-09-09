#include <iostream>
#include <time.h>
#include "numeros.h"
#include "radixSort.h"
#include "quickSort.h"
#include "countingSort.h"

void medirTiempo(char const *nombre,void (*funcion)()){
    clock_t begin=clock();
    funcion();
    clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << nombre << ": " << time_spent << " segs" << std::endl;
}

int main(){
    initNumeros();
    medirTiempo("RADIX SORT",radixSort);

    initNumeros();
    medirTiempo("QUICK SORT",quickSort);

    initNumeros();
    medirTiempo("Counting SORT",countingSort);
    return 0;
}