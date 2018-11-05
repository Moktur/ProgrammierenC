
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-11, Kaufpreisermittlung
/*
/*      Konzepte/       Funktionsaufruf mit Parameteruebergabe
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm berechnet aus Preis, Skonto, Rabatt
/*                      und Mehrwertsteuer den endgueltigen Kaufpreis.
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

float preis_berechnung(float preis, float rabatt, float skonto, float MwSt);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    float preis, rabatt, MwSt, skonto;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-11, Kaufpreisermittlung ----------------\n\n");

    printf("\nDas Programm ermittelt aus Preis, Skonto, Rabatt und");
    printf("\nMehrwertsteuer den endgueltigen Verkaufspreis.\n");
    printf("\nAlle Eingabedaten werden als nicht negative");
    printf(" reelle Werte erwartet.");

    /* Ein- und Ausgabe */
    printf("\n\nBitte Preis in EUR angeben:               ");
    scanf_s("%f", &preis);
    printf("Bitte Rabatt in Prozent angeben:         ");
    scanf_s("%f", &rabatt);
    printf("Bitte Skonto in Prozent angeben:         ");
    scanf_s("%f", &skonto);
    printf("Bitte Mehrwersteuer in Prozent angeben:  ");
    scanf_s("%f", &MwSt);
    printf("--------------------------------------------------------");

    /* Funktionsaufruf und Wertuebergabe */
    preis = preis_berechnung(preis, rabatt, skonto, MwSt);
    printf("\nDer Verkaufspreis in EUR betraegt:        %.2f\n", preis);
    printf("========================================================");
    PAUSE;
}

/* Funktion preis_berechnung
   berechnet einen Kaufpreis */
float preis_berechnung(float preis, float rabatt, float skonto, float MwSt)
{
    /* Lokale Variablen definieren */
    float EUR_MwSt, EUR_Rabatt, EUR_Skonto;

    /* Anweisungen */

    /* Berechnung */
    EUR_MwSt   = preis * MwSt / 100;
    preis     = preis + EUR_MwSt;
    EUR_Rabatt = preis * rabatt / 100;
    preis     = preis - EUR_Rabatt;
    EUR_Skonto = preis * skonto / 100;
    preis     = preis - EUR_Skonto;

    /* Rueckgabewert liefern */
    return preis;
}
