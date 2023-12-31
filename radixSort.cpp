#include <iostream>
#include "numeros.h"

const int TAMPORCION {MAXNUMS/20+10}; //5.000.000 numeros por porcion

struct bucket {
    int numeros[TAMPORCION];
    int uso{0};
    struct bucket *sgte{NULL};
};

struct bucket *buckets=new struct bucket [10]; //en buckets se almacenan los numeros del digito correspondiente


//Funciones de BUCKETS
void agregarNumeroBucket(int n,int digito){
    struct bucket *buc=&buckets[digito];
    while(buc->sgte!=NULL)buc=buc->sgte; // se mueve a la porcion final
    if (buc->uso==TAMPORCION){ //si tiene espacio
        buc->sgte=new struct bucket; //crea una nueva porcion
        buc=buc->sgte; //la variable apunta al nuevo
    } 
    buc->numeros[buc->uso++]=n; // se agrega el numero al bucket
}

void vaciarBucketDig(struct bucket *buc, int &n){
    //copia los numeros a nums
    std::copy(buc->numeros,buc->numeros+buc->uso,nums+n);
    n+=buc->uso;
    
    //vacia las sgtes secciones
    if (buc->sgte!=NULL){
        vaciarBucketDig(buc->sgte,n);
        //elimina la memoria utilizada
        delete buc->sgte;
    } 
    //deja las variables como al inicio
    buc->uso=0;
    buc->sgte=NULL;
}

void vaciarBuckets(){
    int n=0;
    //para cada digito
    for (int i=0;i<10;i++){
        vaciarBucketDig(&(buckets[i]),n);
    }
}




void radixSort(){
    const int NM=getDigitCount(MAXVALUE);
    for (int d=0;d<NM;d++){
        for (int i=0;i<MAXNUMS;i++){
            agregarNumeroBucket(nums[i],getDigit(nums[i],d));
        }
        vaciarBuckets();
    }

}

