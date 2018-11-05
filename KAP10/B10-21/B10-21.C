
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-21, Programmargumente
/*
/*      Konzepte/       Argumentuebergabe an das Programm, d. h. an dessen
/*      Sprachelemente: main-Funktion
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm gibt die uebergebenen Argumente am
/*                      Bildschirm aus. Rufen Sie das Programm also mit
/*                      zusaetzlichen Argumenten (Zeichenketten) nach dem
/*                      Programmnamen von der DOS-Kommandozeile oder
/*                      aus der Programmierumgebung auf.
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

void main(int argc, char *argv[])
{
    /* Lokale Variablen definieren */
    int i;      /* Nummer des Arguments */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-21, Programmargumente ------------------\n\n");
    printf("\nDas Programm erwartet Argumente fuer main und gibt diese aus.");
    printf("\nDie Anzahl der Argumente ist beliebig.\n");

    /* in argv[0] ist der Programmname gespeichert */
    printf("\nDer Programmname ist: %s\n", argv[0]);

    /* Gib alle Argumente der Reihe nach am Bildschirm aus. Erst ab argv[1],
       denn argv[0] ist ja der Programmname */
    printf("Die Argumente sind: ");
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], " ");
    
    /* argc ist die Anzahl der Argumente plus eins, denn der Programmname
       wird mitgezaehlt */
    printf("\nDas sind %d Argumente.\n", argc - 1);
    PAUSE;
}
