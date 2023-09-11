#include <iostream>
#include <array>
#include <algorithm>
#include "numeros.h"

template <typename T,size_t N> 
void printArray(std::array<T,N> &a){
    std::cout <<"[ ";
    int cont=0;
    for (T & element:a){
        if (cont++>=100) break;
        std::cout << element << ", ";
    }
    std::cout<<" ]"<<std::endl;
}

void arrayTest(){
    std::array<int,MAXNUMS> *array=new std::array<int,MAXNUMS>;
    std::copy(nums,nums+MAXNUMS,array->begin());
    clock_t begin=clock();
    std::sort(array->begin(),array->end());
    clock_t end=clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout <<  "Array: " << time_spent << " segs" << std::endl;
    printArray(*array);
    delete array;
}



