
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-09, Zeiger und 2D-Felder
/*
/*      Konzepte/       Parameteruebergabe eines 2D-Feldes an eine Funktion
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
/* Funktionen deklarieren
/*****************************************************************************/

long summiere( int matrix[][5], int anz);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    static int quadrat[5][5] = 
        {{1,2,3,4,5},
         {6,7,8,9,10},
         {11,12,13,14,15},
         {16,17,18,19,20},
         {21,22,23,24,25}};
    long summe; 
    int anz_sum ; 

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-09, Zeiger und 2D-Felder ---------------\n\n");
    printf("\nDas Programm ermittelt Elementesumme der ersten n Zeilen ");
    printf("\neiner 5x5-Matrix, die im Programm vereinbart wurde.\n");

    /* Eingabe/ Verarbeitung per Funktionsaufruf / Ausgabe */
    printf("\nWieviele Matrixzeilen sollen summiert werden? (<= 5)  ");
    scanf_s("%d",&anz_sum);

    /* Uebergabe Feldanfang und Anzahl  Zeilen */
    summe = summiere(quadrat, anz_sum);

    printf("\nDie Summe der ersten %d Zeilen der Matrix betraegt: %ld",
                anz_sum, summe);
    PAUSE;
}

/* Funktion summiert Werte der ersten anz Zeilen der uebergebenen Matrix*/
long summiere(int matrix[][5], int anz)
{
    long summe = 0;             /* Zwischensumme, Endsumme */
    int i,j;

    for (i = 0; i < anz; i++)   /* anz Zeilen durchgehen */
    for (j = 0; j < 5; j++)     /* und jeweils alle Spalten einer Zeile */
         summe += matrix[i][j];

    return (summe);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Kontrollieren Sie die Eingabe der Zeilenanzahl in main.
  - Schreiben Sie eine andere Funktion fuer die Summation.
    Nutzen Sie dabei aus, dass die Matrix zeilenweise
    im Speicher abgelegt ist.
    Vorgaben:
        - vereinbaren Sie den ersten formalen Parameter der Funktion
          summiere2 als int-Zeiger: int *matrix_zgr
        - durchlaufen Sie bei der Summation in nur einer for-Schleife
          die ersten anz*5 Plaetze mit matrix_zgr ab der uebergebenen
          Adresse und addieren Sie jeweils: summe += *matrix_zgr.

******************************************************************************/
