
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-08, Summierung von Vektorelementen
/*
/*      Konzepte/       Parameteruebergabe eines Vektors an eine Funktion
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

float summiere(float summen_feld[], int anz);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    static float werte[10] = {1.1F, 2.1F, 3.1F, 4.1F, 5.1F, 6.1F, 7.1F, 8.1F, 9.1F, 10.1F};
    float summe;
    int anz_sum;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-08, Summierung von Vektorelementen -----\n\n");
    printf("\nDas Programm ermittelt die Summe der ersten n Werte eines Vektors,");
    printf("\nder mit allen Werten im Programm vereinbart wurde.\n");

    /* Eingabe */
    printf("\nWieviele Werte sollen summiert werden? (<= 10)  ");
    scanf_s("%d",&anz_sum);

    /* Verarbeitung - Summation, Ausgabe */
    summe = summiere(werte, anz_sum);    /* Uebergabe Feldanfang und Anzahl  */
    printf("\nDie Summe der ersten %d Werte des Vektors betraegt: %.2f",
                anz_sum,summe);
    PAUSE;
}

/* Funktion summiert float-Werte eines Vektors */
float summiere(float summen_feld[], int anz)
{
    float summe = 0.;       /* Zwischensumme, Endsumme */

    while (--anz >= 0)                     /* dekrementieren vor Vergleich ! */
        summe += *(summen_feld + anz);     /* Summation rueckwaerts  */

    return (summe);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Kontrollieren Sie die Anzahl anz zu summierender Werte des Vektors;
    vgl. Beispielprogramm 10.7
  - Schreiben Sie eine modifizierte Funktion fuer die Summation:
        - Durchlauf des Feldes vom ersten bis zum anz-ten Element mit
          einer Laufvariablen i.
  - Schreiben Sie noch eine Version:
        - vereinbaren Sie als ersten formalen Parameter float *feld_zgr;
        - Durchlauf des Feldes mit Zeiger feld_zgr, der jeweils
          inkrementiert wird, bis er die Endeadresse feld_zgr + anz - 1
          erreicht.

******************************************************************************/
