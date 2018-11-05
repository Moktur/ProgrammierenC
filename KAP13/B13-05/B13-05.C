
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-05, Zufallszahlen
/*
/*      Konzepte/       Speicherklasse static fuer lokale Variablen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm gibt eine Reihe von Pseudozufallszahlen
/*                      aus. Die neue Zufallszahl wird mit einer Formel aus
/*                      der alten berechnet, die in einer static-Variable
/*                      zwischen den Funktionsaufrufen gespeichert bleibt.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Konstanten / Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

#define START  17UL
#define FAKTOR 25173UL
#define INCR   13849UL
#define MODULO 65536UL

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

unsigned int zufallszahl(void);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int z;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 13-05, Zufallszahlen I --------------------\n\n");
    printf("\nDas Programm erzeugt Pseudozufallszahlen und gibt sie aus.\n");

    /* Zufallszahlen ausgeben */
    for (z = 1; z < 100; z++)
      {   printf("\n%2d. Zufallszahl: %5u", z, zufallszahl());
          if (z%10 == 0)
             PAUSE;
      }
    PAUSE;
}

/* Funktion zufallszahl
   erzeugt die naechste Pseudo-Zufallszahl */
unsigned int zufallszahl(void)
{
    /* Lokale Variablen definieren */
    static unsigned long int zufall = START;

    /* Anweisungen */

    /* naechste Zufallszahl bestimmen */
    zufall = (FAKTOR * zufall + INCR) % MODULO;

    /* Zufallszahl liefern */
    return zufall;
}
