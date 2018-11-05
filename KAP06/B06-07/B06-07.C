
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-07, Zinseszinstabelle
/*
/*      Konzepte/       Umgang mit Konstanten, Beispiel fuer eine
/*      Sprachelemente: while-Schleife
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

#define  PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Konstanten definieren
/*****************************************************************************/

const float EINLAGE  = 1000.0F;      /* Anfangskapital */
const float ZINSSATZ =    0.10F;     /* Zinssatz */
const float DAUER    =   10.0F;      /* Dauer 10 Jahre */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int     jahr;        /* Jahr */
    float   betrag;      /* aufgelaufener Gesamtbetrag */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-07, Zinseszinstabelle ------------------\n\n");

    printf("\nDas Programm berechnet eine Zinseszinstabelle.\n");

    /* Variablen initialisieren */
    betrag = EINLAGE;
    jahr   = 0;

    /* Listenkopf */
    printf("\n\n\t\tJahr\tGesamtbetrag bei %.2f%%\n\n", ZINSSATZ * 100.0F);

    /* Berechnung */
    while (jahr <= DAUER)
    {
        printf("\t\t%2d\t\tEUR %.2f\n", jahr, betrag);
        betrag = betrag * ZINSSATZ + betrag;
        jahr   = jahr + 1;
    }
    PAUSE;
}
