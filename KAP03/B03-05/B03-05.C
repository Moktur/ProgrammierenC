
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-05, Konstanten per Praeprozessor-Anweisung
/*
/*      Konzepte/       Definition von Konstanten per Praeprozessor-
/*      Sprachelemente: Anweisung #define
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

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Konstanten definieren
/*****************************************************************************/

#define MAX         100               /* Der Konstanten MAX wird der Wert 100
                                         zugeordnet */
#define PI          3.14159f          /* Der Konstanten PI wird der Wert
                                         3.14159 zugeordnet */
#define Durchmesser 20.7f             /* Durchmesser wird der Wert 20
                                         zugeordnet */
#define Radius      Durchmesser / 2   /* Der Kreisradius kann aus dem
                                         Durchmesser berechnet werden */
#define MwSt        0.15f             /* Die MehrwertSteuer betraegt 15 % */
#define Temperatur  37.0f             /* Diese Koerpertemperatur hat ein
                                         gesunder Mensch */
#define Satz        "Hallo, da bin ich"  /* Der Konstanten Satz wird eine
                                            Zeichenkette zugeordnet */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-05, Konstanten per #define-Anweisung ---\n\n");

    printf("\nDas Programm zeigt die Definition von Konstanten mit der #define-Anweisung.\n");

    /* Ausgabe mit der Funktion printf */
    printf("\nKreisumfang: %.2f", PI * Durchmesser);
    printf("\nKreisflaeche: %.2f", PI * Radius * Radius);
    printf("\nMehrwertsteuer : %.2f", 100 * MwSt);
    printf("\n%s\n", Satz);
    printf("Koerpertemperatur: %.2f\n", Temperatur);
    PAUSE;
}
