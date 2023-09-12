#ifndef __NUMS
#define __NUMS

const int MAXNUMS {100'000'000};
const int MAXVALUE {999'999'999};

extern int *nums;

void initNumeros();
void visualizar(int n=100);

int getDigit(int number, int dig);
int getDigitCount(int number);

const int potencias10[]={
    1,
    10,
    100,
    1'000,
    10'000,
    100'000,
    1'000'000,
    10'000'000,
    100'000'000,
    1'000'000'000
};

#endif

