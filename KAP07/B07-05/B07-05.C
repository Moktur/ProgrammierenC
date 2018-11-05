
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-05, Funktionsaufrufe
/*
/*      Konzepte/       Funktionen und Beispiele fuer ihren Aufruf,
/*      Sprachelemente: mathematische Funktionen aus math.h
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <math.h>       /* Mathematische Funktionen */

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
    double res;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-05, Funktionsaufrufe -------------------\n\n");

    printf("\nDas Programm zeigt Aufrufe mathematischer Funktionen,");
    printf("\ndie in der Standardbibliothek math.h definiert sind.\n");

    /* Funktionsaufrufe und Ausgaben */

    /* sin(x) liefert den sinus von x zurueck.
       Achtung: Rechnung im Bogenmass */
    res = sin(1.570796);
    printf("\nSinus von 90�: %.4f", res);

    /* cos(x) cosinus den cosinus von x zurueck.
       Achtung: Rechnung im Bogenmass! */
    res = cos(1.570796);
    printf("\nCosinus von 90�: %.4f", res);

    /* power(x, y) liefert x hoch y zurueck,
       Basis x muss positiv, Exponent muss ganzzahlig sein */
    res = pow(7.5,2);
    printf("\n7.5 hoch 2: %.2f", res);

    /* fabs(x) liefert den absoluten Wert von x zurueck */
    res = fabs(-12.0f);
    printf("\nDer absolute Wert von -12.0 ist %.2f\n", res);
    PAUSE;
}

