#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

void main(void)
{
    const int aconst = 1000;
    const int bconst = 1;
    int Tag, Monat, Jahr;

    int tag;
    int monat;
    int jahr;

    float betrag1;
    float betrag2;

    double sum;

    long summe1 = 0;
    long summe2 = aconst + bconst;

    double betrag = aconst * 10.e-3;

    printf("\nHier nun die einzelnen Werte: \n\n");
    printf("\n Summe1= %i Summe2= %i, Betrag= %f", summe1, summe2, betrag);


    PAUSE;

}
