
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-17, Zeigerzugriff auf 2D-Felder
/*
/*      Konzepte/       Zugriff auf Elemente eines zweidimensionalen Feldes
/*      Sprachelemente: mit Hilfe von Zeigern
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm erzeugt ein Feld feld[z][s], wobei z
/*                      die Zeile, s die Spalte angibt. Dann gibt das
/*                      Programm das Feld am Bildschirm aus.
/*
/*                      Organisation eines Feldes im Speicher:
/*                      Ein Feld arr[x][y] mit x = y = 10 ist zeilenweise
/*                      im Speicher abgelegt:
/*                         (0,0)(0,1)(0,2)...(0,9) ->
/*                         (1,0)(1,1)........(1,9) ->
/*                         (2,0).................. ->
/*                         ..................(9,9)
/*                      dabei bedeutet z. B. (0,2) der Speicherplatz fuer das
/*                      Element arr[0][2] in Zeile 0 und Spalte 2.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Konstanten und Makros definieren
/*****************************************************************************/

#define z_max 10    /* Maximale Anzahl der Zeilen */
#define s_max 10    /* Maximale Anzahl der Spalten */

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
	 short feld[z_max][s_max];       /* 2D-Feld vom Elementtyp short int */
	 int z, s;
    short *aktu;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-17, Zeigerzugriff auf 2D-Felder --------\n");

    printf("\nDas Programm greift mit Zeigern auf ein 2D-Feld zu.\n\n");
    /* Initialisieren des Feldes mit Indizes und mit einem Zeiger */
    for (z = 0; z < z_max; z++)         /* Alle Zeilen abarbeiten */
        for (s = 0; s < s_max; s++)     /* Alle Spalten abarbeiten */
        {
				/* aktu zeigt auf das Element feld[z][s] */
				aktu = (short*) feld + z * s_max + s;
            /* Dem Feldelement, auf das aktu zeigt, wird ein Wert zugeordnet */
            *aktu = s * 10 + z;
        }

    /* Ausgabe des Feldes mit Indizes und einem Zeiger */
    for (z = 0; z < z_max; z++)
    {
        for (s = 0; s < s_max; s++)
        {
				aktu = (short*) feld + z *s_max + s;
            printf("%6hd", *aktu);
        }
        printf("\n");
    }
    PAUSE;
}
