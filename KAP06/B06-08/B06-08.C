
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-08, Abfrage des Wochentages
/*
/*      Konzepte/       Aufzaehlungsvariable,
/*      Sprachelemente: switch-case-Anweisung
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
/* Aufzaehlungstyp definieren
/*****************************************************************************/

enum tag {SO, MO, DI, MI, DO, FR, SA};

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */

    /* Variable vom Aufzaehlungstyp 'enum tag' definieren */
    enum tag Wochentag;
    
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-08, Abfrage eines Wochentages ----------\n\n");

    printf("\nDas Programm differenziert Wochentage anhand der eingegebenen Nummer.\n");

    /* Eingabe */
    printf("\nBitte eine Wochentagsnummer eingeben");
    printf(" (Sonntag = 0, Montag = 1,...): ");
    scanf_s("%d", &Wochentag);

    /* Verarbeitung / Ausgabe */
    if (Wochentag < SO || Wochentag > SA)
         printf("\nEingabe unzulaessig!");
    else
    {
         /* Je nachdem was fuer ein Tag heute ist, eine andere Ausgabe */
         switch (Wochentag)
         {
             case SO: /* Falls heute Sonntag */
                      printf("\nHeute ist Sonntag,");
                      printf(" heute wird nicht gearbeitet.\n");
                      break;
             case MO: /* Falls heute Montag */
                            printf("\nMontag, eine lange Woche liegt vor uns.\n");
                      break;
             case SA: /* Falls heute Samstag */
                            printf("\nSamstag, endlich Wochenende!\n");
                      break;
             default: /* Ansonsten */
                      printf("\nEin ganz normaler Tag heute.\n\n");
                      break;
         } /* end switch */
    }      /* end else */
    PAUSE;
}
