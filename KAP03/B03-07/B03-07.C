
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-07, typedef-Vereinbarung
/*
/*      Konzepte/       typedef-Vereinbarung
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

typedef int Ganzzahl;
typedef long int LangeGanzzahl;

typedef int INT_A, INT_B;       /* typedef-Anweisungen, die sich auf denselben
                                   Typ beziehen, koennen zusammengefasst
                                   werden */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    Ganzzahl      a, b;   /* eigentlich int-Variablen */
    LangeGanzzahl c;      /* eigentlich eine long-Variable */

    INT_A         alpha;  /* Beide Variablen scheinen von verschiedenem */
    INT_B         beta;   /* Typ zu sein, sind aber im Grunde beide
                                      int-Variablen, siehe typedef-Vereinbarungen */

    /* Anweisungen */

    a = 12345;
    b = 67890;
    c = a * b;

    alpha = 1000;
    beta  = alpha;        /* Auch wenn beide Variablen von verschiedenem Typ
                             sind, gibt es keine Fehlermeldung oder Warnung
                             bei der Zuweisung */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-07, typedef-Vereinbarungen -------------\n\n");

    printf("\nDas Programm zeigt einfache Beispiele");
    printf("\nfuer typedef-Vereinbarungen.\n");

    /* Ausgabe der Werte */
    printf("\n%d * %d = %ld", a, b, c);
    printf("\nalpha = %d\nbeta = %d\n\n", alpha, beta);
    PAUSE;
}
