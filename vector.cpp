#include <iostream>
#include <vector>
#include <algorithm>
#include "numeros.h"

template <typename T> 
void printVector(std::vector<T> v){
    std::cout <<"[ ";
    int cont=0;
    for (T & element:v){
        if (cont++>100) break;
        std::cout << element << " ";
    }
    std::cout<<" ]"<<std::endl;
}

void vectorTest(){
    // srand(time(NULL));
    // std::vector<int> vector(MAXNUMS);
    // std::generate(vector.begin(),vector.end(),[](){
    //     return rand()%MAXVALUE;
    // });
    // clock_t begin=clock();
    // std::sort(vector.begin(),vector.end());
    // clock_t end=clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // std::cout <<  "Vector: " << time_spent << " segs" << std::endl;
    // printVector(vector);

    int a[2]={1,2};
    std::cout<<a[0]<<", "<<a[1]<<", "<<&a[0]<<", "<<&a[1]<<std::endl;
    auto & [x,y]=a;
    std::cout<<x<<", "<<y<<", "<<&x<<", "<<&y<<std::endl;
}



