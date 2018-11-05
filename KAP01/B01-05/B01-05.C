
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       01-05, das erste selbst entwickelte C-Programm
/*
/*      Konzepte/       main-Funktion, Variablen, Ein-Ausgabe-Bibliothek,
/*      Sprachelemente: Funktion printf
/*
/*      Aufgabenteil:   nein
/*
*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Ein-Ausgabe-Funktionen der Standardbliothek bereitstellen */
#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/
/* warten auf return-Taste */
#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void) /* main-Funktion beginnt */
{
    /* lokale Variablen */
    int i;

    /* Anweisungen */

	 /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
	 printf("----- Beispiel: 01-05, das erste selbstentwickelte C-Programm\n\n");

    /* Variable i erhaelt Wert 1 */
    i = 1;

    /* Ausgabe mit Bibliotheksfunktion printf */
	 printf("\nC ist meine %d-te Programmiersprache", i);

    PAUSE;
}   /* Hier endet main: } */

