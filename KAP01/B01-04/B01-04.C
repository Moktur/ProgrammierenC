
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       01-04, Minimum von float-Zahlen
/*
/*      Konzepte/       main-Funktion, Variablen, Konstanten, EA-Bibliothek
/*      Sprachelemente: Funktion printf, while-Schleife, mehrere Funktionen
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* EA-Funktionen bereitstellen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

float berechne_minimum(float x, float y);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    float a, b;     /* Zwei reelle Zahlen, die verglichen werden sollen */
    float min;      /* Minimum */

    /* Anweisungen */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 01-04, Minimum von reellen Zahlen ---------\n\n");
    printf("\nDas Programm berechnet das Minimum von zwei reellen Zahlen.");
    printf("\nBitte reelle Zahlen mit Dezimalpunkt (z.B. 5.9) eingeben.\n\n");

    /* Eingabe */
    printf("\nErste Zahl:  ");
    scanf_s("%f", &a);
    printf("\nZweite Zahl: ");
    scanf_s("%f", &b);

    /* Berechnung, hier durch einen Funktionsaufruf */
    min = berechne_minimum(a, b);   /* uebergeben: zu vergleichenden Werte */
                                    /* zurueck: Das Minimum */

    /* Ausgabe - wie in Beispiel 2*/
    printf("\nDas Minimum von %f und %f lautet %f", a, b, min);
    PAUSE;
}

/* Funktion ermittelt Minimum im Feld zahlen */
float berechne_minimum(float x, float y)
{ 
    /* lokale Variablen */
    float minxy;

    if (x < y)         /* Minimumberechnung wie in Beispiel 2, aber: */
        minxy = x;     /* x und y werden als Parameter uebergeben */
    else
        minxy = y;

    /* Rueckgabe des berechneten Wertes */
    return minxy;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Loesen Sie die analoge Aufgabe wie fuer das Beispielprogramm 01-03.
  Hier soll also das Maximum zweier Zahlen berechnet werden, wobei 
  neben der main-Funktion eine zweite Funktion berechne_maximum() 
  zu benutzen ist.  
  Vergessen Sie nicht, Funktionsnamen, Variablennamen und 
  Kommentare anzupassen. Uebersetzen und binden Sie das modifizierte
  Programm und testen Sie es.

******************************************************************************/
