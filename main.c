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

void rand_DNIs (unsigned dni[N], char letra[N]) {
    for (int i = 0; i < N; i++) {
        unsigned DNI = 0;
        rand_DNI(&DNI);
        dni[i] = DNI;
        letra[i] = letra_calculada(resto_DNI(dni[i]));
    }

    print_DNIs(dni, letra);
}

void print_DNIs (unsigned dni[N], char letra[N]) {
    for (int i = 0; i < N; i++) {
        printf("| %08u-%c",dni[i], letra[i]);
    }
}

void swap_unsigned(unsigned* a, unsigned* b) {
    unsigned temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(unsigned dni[N], char letra[N]) {
    unsigned swap;
    for (int i = 0; i < N; i++) {
        swap=0;
        for (int j = 0; j < N - i - 1; j++) {
            if (dni[j] > dni[j + 1]) {
                swap_unsigned(dni[j], dni[j + 1]);
                swap_char(&letra[j], &letra[j + 1]);
                swap = 1;
            }
        }
        if (!swap) break;
    }
}
int main(void)
{
    srand(time(NULL));
    unsigned DNI[N];
    char letra[N];
    rand_DNIs(DNI, letra);
    return 0;
}
