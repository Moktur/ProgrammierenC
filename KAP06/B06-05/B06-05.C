
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-05, Summe ungerader Zahlen
/*
/*      Konzepte/       for-Schleife
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
    int i,              /* Wertezaehler */
        n,              /* Wertanzahl */
        summe = 0;      /* Wertsumme */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-05, Summe ungerader Zahlen -------------\n\n");
    printf("\nDas Programm addiert die ersten n ungeraden Zahlen\n");

    /* Eingabe und Berechnung in for-Schleife */
    printf("\nBitte (ganze) Anzahl n (1 <= 1 <= 100) eingeben: ");scanf_s("%d",&n);

    for (i = 0; i < n; i++)     /* Laufvariable i, Bereich: 0 <= i < n */
    {
        summe += 2*i + 1;       /* naechste ungerade Zahl aufaddieren */
    }

    /* Ausgabe */
    printf("\nSumme der ersten %d ungeraden Zahlen ist: %d", n, summe);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Modifizieren Sie das Programm derart, dass die ersten n geraden natuerlichen
  Zahlen ab 2 addiert werden.

******************************************************************************/
