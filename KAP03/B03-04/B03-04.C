
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-04, Konstanten mit const-Anweisung
/*
/*      Konzepte/       Definition von Konstanten per const-Anweisung
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makors definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Lokale Konstanten definieren */

    const int   MAX         = 100;         /* Der Konstanten MAX wird der Wert
                                              100 zugeordnet */
    const float PI          = 3.14159f;    /* Der Konstanten PI wird der Wert
                                              3.14159 zugeordnet */
    const float Durchmesser = 20.7f;       /* Durchmesser wird der Wert 20
                                              zugeordnet */
    const float Radius = Durchmesser / 2;  /* Der Kreisradius kann aus dem
                                              Durchmesser berechnet werden */
    const float MwSt        = 0.19f;       /* Die MehrwertSteuer betraegt
                                              19 % */
    const float Temperatur  = 37.0f;       /* Diese Koerpertemperatur hat ein
                                              gesunder Mensch */
    const char  Satz[]      = "Hallo, da bin ich."; /* Der Konstanten Satz wird
                                                       eine Zeichenkette zuge-
                                                       ordnet */

    /*
    Wertzuweisung an eine Konstante:
    Durchmesser = 12.9f;
    */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-04, Konstanten mit const-Vereinbarung --\n\n");
    printf("\nDas Programm zeigt die Definition von Konstanten mit der const-Vereinbarung.\n");

    /* Ausgabe der Werte der Konstanten */
    printf("\nKreisumfang:       %.2f", PI * Durchmesser);
    printf("\nKreisflaeche:      %.2f",   PI * Radius * Radius);
    printf("\nMehrwertsteuer:    %.2f",   100 * MwSt);
    printf("\nKoerpertemperatur: %.2f",   Temperatur);
    printf("\n%s\n\n", Satz);
    PAUSE;
}
