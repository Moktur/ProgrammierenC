
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-01, Berechnung eines Kreisumfangs
/*
/*      Konzepte/       Aufbau von Programmen, die nur die main-Funktion
/*      Sprachelemente: enthalten
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Praeprozessoranweisungen */
#include <stdio.h>      /* Standardbibliothek bereitstellen */

/*****************************************************************************/
/* Makros und Konstanten definieren
/*****************************************************************************/

/* Praeprozessoranweisungen */
#define PI 3.14159f

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen und gegebenenfalls weitere lokale Vereinbarungen */
    float radius, umfang;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-01, Kreisumfang berechnen --------------\n\n");

    /* Eingabe / Berechnung / Ausgabe */
    printf("\nDas Programm berechnet den Umfang eines Kreises.");
    printf("\nBitte Radius mit max. zwei Dezimalstellen eingeben: ");
    scanf_s("%f",&radius);
    umfang = 2*PI*radius;
    printf("\nRadius: %.2f   Zugehoeriger Kreisumfang: %.2f", radius, umfang);
    PAUSE;
}
