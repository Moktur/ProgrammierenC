
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-04, Summierung reeller Werte II
/*
/*      Konzepte/       do-while-Schleife
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
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
    int   zaehler = 0,      /* Wertezaehler */
          anzahl;           /* Wertanzahl */
    float summand,          /* Summand */
          summe = 0.;       /* Summand */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-04, Summe reeller Werte II -------------\n\n");

    printf("\nDas Programm addiert float-Werte.\n");

    /* Eingabe und Berechnung in do-while-Schleife */
    printf("\nWieviele Werte addieren (>=1): "); scanf_s("%d",&anzahl);
    do
    {
        printf("Naechster float-Wert? "); scanf_s("%f",&summand);
        summe += summand;
        zaehler++;
    }
    while (zaehler < anzahl);

    /* Ausgabe */
    printf("\nAnzahl Werte: %d  Summe: %.2f",zaehler, summe);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Modifizieren Sie das Programm analog zu dem vorherigen Beispielprogramm.
  Muss auch bei diesem Programm die Endemarke initialisiert werden?

******************************************************************************/
