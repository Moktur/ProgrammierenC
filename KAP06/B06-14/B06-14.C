
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-14, Spielkarten
/*
/*      Konzepte/       verschachtelte for-Schleifen, switch-case-Anweisung,
/*      Sprachelemente: Aufzaehlungsvariablen
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm gibt alle Spielkarten eines Skatblattes
/*                      am Bildschirm aus.
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
/* Aufzaehlungsvariablen definieren
/*****************************************************************************/

typedef enum {sieben, acht, neun, bube, dame, koenig, zehn, as} WERT;
typedef enum {karo, herz, pik, kreuz} FARBE;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    WERT wert;
    FARBE farbe;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-14, Spielkarten ------------------------\n");

    printf("\nDas Programm gibt alle Spielkarten eines Skatblatts aus.\n\n");

    /* Gehe alle Farben durch */
    for (farbe=karo; farbe<=kreuz; farbe++)
    {
        /* Fuer die aktuelle Farbe gehe alle Werte durch */
        for (wert=sieben; wert<=as; wert++)
        {
            /* Je nach Farbe die richtige Bildschirmausgabe */
            switch (farbe)
            {
                case karo : printf("Karo");  break;
                case herz : printf("Herz");  break;
                case pik  : printf("Pik");   break;
                case kreuz: printf("Kreuz"); break;
            }
            /* Je nach Wert die richtige Bildschirmausgabe */
            switch (wert)
            {
                case sieben: printf("-Sieben\n"); break;
                case acht  : printf("-Acht\n");   break;
                case neun  : printf("-Neun\n");   break;
                case bube  : printf("-Bube\n");   break;
                case dame  : printf("-Dame\n");   break;
                case koenig: printf("-Koenig\n"); break;
                case zehn  : printf("-Zehn\n");   break;
                case as    : printf("-As\n");
            }
        }

          if (farbe == kreuz)
                printf("\nDas war's...\n");
        /* Warte auf Tastendruck */
        PAUSE;
    }
}
