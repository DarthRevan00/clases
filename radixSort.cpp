#include <iostream>

const int MAXNUMS {100'000'000};
const int MAXVALUE {99'999'999};

int *nums=new int[MAXNUMS];

const int TAMPORCION {MAXNUMS/20}; //5.000.000 numeros por porcion

struct bucket {
    int numeros[TAMPORCION];
    int uso{0};
    struct bucket *sgte{NULL};
};

struct bucket *buckets=new struct bucket [10]; //en buckets se almacenan los numeros del digito correspondiente

int getDigit(int number, int dig){
    for (unsigned char i=0;i<dig;i++){
        number/=10;
    }
    return number%10;
}

int getDigitCount(int number){
    int count=1;
    while ((number/=10)!=0)
        count++;
    return count;
}

void initNumeros(){
    srand(time(NULL));   // Initialization, should only be called once.
    for (int i=0;i<MAXNUMS;i++){
        nums[i]=rand()%MAXVALUE;      // Returns a pseudo-random integer between 0 and RAND_MAX.
    }
}


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

void vaciarBucketDig(struct bucket *buc, int *n){
    //copia los numeros a nums
    for (int i=0;i<buc->uso;i++){
        nums[(*n)++]=buc->numeros[i];
    }
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
        vaciarBucketDig(&(buckets[i]),&n);
    }
}


using namespace std;

void visualizar(int n=1000){
    cout<<"[";
    for (int i=0;i<n && i<MAXNUMS;i++){
        cout<<nums[i];
        if (i+1<n)cout <<", ";
    }
    cout<<"]"<<endl;
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

int main(){
    initNumeros();
    visualizar();
    radixSort();
    visualizar();
    return 0;
}