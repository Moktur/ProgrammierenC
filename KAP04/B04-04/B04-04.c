
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       04-04, Ausgabe mit printf I
/*
/*      Konzepte/       Funktion printf, Formatspezifikationen
/*      Sprachelemente:
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int i = 100,j = -1;
    long z = 1234567;
    float x = 23.45E-5F, y = 0.11F;
    char c = 'd';
    static char Rs[] = "Rhinozeros"; /* Zeichenkettte */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-04, Ausgabe mit printf I ---------------\n\n");

    printf("\nDas Programm zeigt einige Beispiele der Ausgabe mit printf.\n");

    /* Ausgabe mit printf */
    printf("\n %d %i %x %u",i,i,i,i);
    printf("\n %d %i %x %u",j,j,j,j);
    printf("\n %d %f",z,z);
    printf("\n %f %E",x,x);
    printf("\n %d",x);
    printf("\n %f %E",y,y);
    printf("\n %d %u %c",c,c,c);
    printf("\n %s",Rs);
    PAUSE;
}
