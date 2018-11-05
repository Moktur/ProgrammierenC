
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       02-01, syntaktische Fehler
/*
/*      Konzepte/       Beispiele fuer syntaktische Fehler
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* Standardbibliothek, EA-Funktionen

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!"; fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/******************************************************************************

void main(void)
{
    printf("\nProgramm fuehrt 2 Rechenoperationen durch\n);

    /* lokale Variablen */
    int int, z_int2, summe;
    floatfaktor1, fak tor2, produkt;

    /* Anweisungen /* Add / Mult */ */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 02-01, syntaktische Fehler ----------------\n\n");

    int = 5;
    z_int2 = 7;
    faktor1 = 3.1;
    faktor2 = E+1;

    summe = int;
    summe + = z_int2;       /* z_int2 wird zu summe addiert */

    produkt = faktor1 * faktor2

    printf("\n %d + %d = %d", int, z_int2, summe);
    printf("\n %.2f * %.2f = %.2f", faktor1, faktor2, produkt);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Das vorliegende Programm ist logisch korrekt. Jedoch enthaelt es noch
  syntaktische Fehler. Beseitigen Sie alle Fehler, bis das Programm
  laeuffaehig ist. Benutzen Sie auch die Beispielprogramme des
  ersten Kapitels, um die Fehler zu finden.

******************************************************************************/
