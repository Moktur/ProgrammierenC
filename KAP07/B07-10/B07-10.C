
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-10, Berechnung der Potenz, Version II
/*
/*      Konzepte/       Funktionsaufruf und Uebergabe der Werte durch
/*      Sprachelemente: Parameter
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Potenzieren geschieht in einer Funktion, die
/*                      die zur Berechnung noetigen Werte durch ihre
/*                      Parameter erhaelt.
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
/* Funktionen deklarieren
/*****************************************************************************/

double power(double basis, int exponent);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    double basis, ergebnis;
    int    exponent;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-10, Berechnung einer Potenz, Version II \n\n");

    printf("\nDas Programm berechnet eine Potenz zu einer reellen Basis");
    printf("\nund einem nicht negativen, ganzen Exponenten.\n");

    /* Abfrage der Werte */
    printf("\nBitte geben Sie die Basis und den Exponenten ein.");
    printf("\n\nBasis (relle Zahl): ");
    scanf_s("%lf", &basis);
    printf("Exponent (ganze Zahl, >= 0): ");
    scanf_s("%d", &exponent);

    /* Funktionsaufruf */
    ergebnis = power(basis, exponent);

    /* Ausgabe der Werte */
    printf("\nDie Potenz %lf hoch %d betraegt: %E\n",
              basis, exponent, ergebnis);
    PAUSE;
}

/* Funktion power
   berechnet eine Potenz */
double power(double basis, int exponent)
{
    /* lokale Variablen */
    int   z;
    double ergebnis = 1.0;

    /* Anweisungen */
    for (z=1; z <= exponent; z++)
        ergebnis = ergebnis * basis;

    /* Rueckgabewert liefen */
    return ergebnis;
}
