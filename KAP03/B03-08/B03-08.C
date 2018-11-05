
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-08, char-Variablen
/*
/*      Konzepte/       Besonderheiten des char-Datentyps, char-Variablen
/*      Sprachelemente: als Wert oder als Zeichen gesehen
/*
/*      Aufgabenteil:   nein
/*
/*      Bemerkung:    	Der Laufzeitfehler "Run-Time Check Failure #2
/*						- Stack around the variable 'uwert' was corrupted."
/*						tritt nur in der Debug-Version auf und kann vernachlässigt 
/*                      werden. Einfach auf weiter klicken.
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
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    char wert;
    signed char swert;
    unsigned char uwert;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-08, char-Variablen ---------------------\n\n");

    printf("\nDas Programm zeigt char-Werte als Zahl und als Zeichen.\n");

    /* Zahl fuer Wert eingeben */
    printf("\nBitte geben Sie einen char-Wert an (-128 - 127): ");
    scanf_s("%hhd", &wert, 1);

    /* Ausgabe der char-Variablen als Zahl und als Zeichen */
    printf("\nWert als Zahl: %hhd\tWert als Zeichen: %c\n", wert, wert);

    /* Ausgabe der char-Variablen als Zahl und als Zeichen */
    swert = wert;
    printf("\nDerselbe Wert in einer signed char-Variablen: ");
    printf("\nWert als Zahl: %hhd\tWert als Zeichen: %c\n", swert, swert);

    /* Zahl fuer Wert eingeben */
    printf("\n\nBitte geben Sie einen positiven char-Wert an (0 - 255): ");
    scanf_s("%hhu", &uwert, 1);

    /* Ausgabe der char-Variable als Zahl und als Zeichen */
    printf("\nWert als Zahl: %hhu\tWert als Zeichen: %c\n", uwert, uwert);
	PAUSE;
}
