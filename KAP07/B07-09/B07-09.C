
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-09, Berechnung einer Potenz, Version I
/*
/*      Konzepte/       Funktionsaufruf und Uebergabe der Werte durch
/*      Sprachelemente: globale Variablen
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Potenzieren geschieht in einer Funktion, die
/*                      die zur Berechnung noetigen Werte durch globale
/*                      Variablen erhaelt.
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

void power(void);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

double basis, ergebnis = 1.0;
int   exponent;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-09, Berechnung einer Potenz, Version I --\n\n");

    printf("\nDas Programm berechnet eine Potenz zu einer reellen Basis");
    printf("\nund einem nicht negativen, ganzen Exponenten.\n");

    /* Abfrage der Werte */
    printf("\nBitte geben Sie die Basis und den Exponenten ein.");
    printf("\n\nBasis (reelle Zahl): ");
    scanf_s("%lf", &basis);
    printf("Exponent (ganze Zahl, >= 0): ");
    scanf_s("%d", &exponent);

    /* Funktionsaufruf */
    power();

    /* Ausgabe der Werte */
    printf("\nDie Potenz %lf hoch %d betraegt: %E\n",
              basis, exponent, ergebnis);
    PAUSE;
}

/* Funktion: power
   berechnet eine Potenz */
void power(void)
{
    /* Lokale Variablen definieren */
    int z;
    /* ergebnis und basis sind schon global definiert */

    /* Anweisungen */
    for (z=1; z <= exponent; z++)
        ergebnis = ergebnis * basis;
}
