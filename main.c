#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define N 100
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void rand_dig(char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
void swap_unsigned(unsigned*, unsigned*);
void swap_char(char*, char*);
void bubbleSort(unsigned [N], char [N]);


void rand_dig(char *dig) {
    *dig = rand() % 10 + '0';
}

void rand_DNI(unsigned *DNI) {
    char dig;
    *DNI = 0;
    for (int i = 0; i < 8; i++) {
        rand_dig(&dig);
        *DNI = *DNI * 10 + (dig - '0');
    }
}

unsigned resto_DNI(unsigned DNI) {
    return DNI % 23;
}

char letra_calculada(unsigned restoDNI) {
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letra[restoDNI];
}

int main(void)
{
    srand(time(NULL));
    unsigned DNI;
    rand_DNI(&DNI);
    printf("DNI: %u\n", DNI);
    return 0;
}
