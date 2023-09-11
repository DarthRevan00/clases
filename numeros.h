#ifndef __NUMS
#define __NUMS

const int MAXNUMS {100'000'000};
const int MAXVALUE {99'999'999};

extern int *nums;

void initNumeros();
void visualizar(int n=100);

int getDigit(int number, int dig);
int getDigitCount(int number);

#endif

