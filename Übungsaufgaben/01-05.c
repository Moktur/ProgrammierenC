#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

void main(void)
{
    /* lokale Variablen */
    int i;


    /* Anweisungen */

    i= 2;

    /* Bildschirmausgabe */

    printf("\nDies ist meine %d. Programmiersprache.", i);


    PAUSE;

    }
