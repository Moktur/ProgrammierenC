
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-13, Schachbrett
/*
/*      Konzepte/       geschachtelte for-Schleifen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Erzeugt ein Schachbrett auf dem Bildschirm mit zwei
/*                      verschachtelten for-Schleifen, eine fuer die Zeilen
/*                      und eine fuer die Spalten.
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
    int z, s,           /* Zeilen- und Spaltenindex */
        booly = 1;      /* Farbe schwarz oder weiss */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-13, Schachbrett ------------------------\n");

    printf("\nDas Programm erzeugt ein Schachbrett.\n\n\n");

    /* Verarbeitung / Ausgabe */

    for (z = 1; z <= 8; z++)        /* Aeussere Schleife, zaehlt die Zeilen */
    {
        printf("\t\t\t");
        for (s = 1; s <= 8; s++)    /* Innere Schleife, zaehlt die Spalten */
        {
            if (booly == 1)         /* Pruefen, ob ein schwarzes (booly == 1)
                                       oder ein weisses (booly == 0) Feld
                                       gezeichnet werden soll */
            {
                /* Gibt ein schwarzes Feld aus und wechselt die Farbe fuer
                   das naechste Feld auf weiss */
                putchar(178); putchar(178); booly = 0;
            }
            else
            {
                /* Gibt ein weisses Feld aus und wechselt die Farbe fuer
                   das naechste Feld auf schwarz */
                putchar(32); putchar(32); booly = 1;
            }
        }
    printf("\n");                   /* Springen in die naechste Zeile */
    booly = !booly;                 /* Wechsel der Farbe des Anfangsfeldes */
    }
    printf("\n");
    PAUSE;
}
