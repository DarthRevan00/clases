#include <iostream>
#include <vector>
#include <algorithm>
#include "numeros.h"


void radix_vector_sort(){
    std::vector<int> buckets[10]; 
    const int NM=getDigitCount(MAXVALUE);
    for (int d=0;d<NM;d++){
        //copia desde nums a buckets
        for (int i=0;i<MAXNUMS;i++){
            buckets[getDigit(nums[i],d)].push_back(nums[i]);
        }
        //copia desde buckets a nums
        int *p=nums;
        for (int i=0;i<10;i++){
            std::copy(buckets[i].begin(),buckets[i].end(),p);
            p+=buckets[i].size();
            buckets[i].clear();
        }
    }

}