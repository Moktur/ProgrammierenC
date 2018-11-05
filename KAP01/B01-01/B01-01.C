
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       01-01, das erste C-Programm
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
    printf("----- Beispiel: 01-01, das erste C-Programm ---------------\n\n");

    /* Variable i erhaelt Wert 1 */
    i = 1;

    /* Ausgabe mit Bibliotheksfunktion printf */
    printf("\nDies ist C-Programm Nr. %d.", i);

    /* Addition und erneute Zuweisung */
    i = i + 1;

    printf("\nDas %d-te C-Programm folgt.", i);
    PAUSE;
}   /* Hier endet main: } */

/* Hinweis zu dem Makro PAUSE:
   - der Makro dient dazu, den Bildschirm vor dem Verlassen
     eines Programms auf jeden Fall anzuhalten
   - er wird bei allen Beispielprogrammen verwendet
   - siehe auch Aufgabenteil zum Beispiel B08-03
     zur Erlaeuterung der Funktion fflush() und Kap. 4.1
     zur Erlaeuterung der Funktion getchar()
   - siehe Kap. 12 fuer Makros
*/
