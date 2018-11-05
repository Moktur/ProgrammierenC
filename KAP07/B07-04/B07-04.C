
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-04, Initialisierung von lokalen
/*                      und globalen Variablen
/*
/*      Konzepte/       automatische und selbstdefinierte Initialisierung
/*      Sprachelemente: von lokalen und globalen Variablen
/*
/*      Aufgabenteil:   nein
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Warnung: Nutzung nicht initialisierter lokaler Variable.
/*						Erklaerung aus Kontext.
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
/* Globale Variablen definieren
/*****************************************************************************/

int global_a;           /* Wird automatisch mit 0 initialisiert */
int global_b = 100;     /* explizite Initialisierung */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    int lokal_a;        /* Wird NICHT automatisch initialisiert und
                           enthaelt daher Speichermuell */
    int lokal_b = 100;  /* explizite Initialisierung */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-04, Initialisierung von Variablen ------\n\n");

    printf("\nDas Programm veranschaulicht die Initialisierung ");
    printf("\nvon globalen und lokalen Variablen.\n");

    /* Ausgabe der Variablenwerte */
    printf("\nInhalte der GLOBALEN Variablen:\n\n");
    printf("\tglobal_a: %8d\twurde automatisch initialisiert\n", global_a);
    printf("\tglobal_b: %8d\twurde explizit initialisiert\n", global_b);

    printf("\nInhalte der LOKALEN Variablen:\n\n");
    printf("\tlokal_a:  %8d\tenthaelt Speichermuell\n", lokal_a);
    printf("\tlokal_b:  %8d\twurde explizit initialisiert\n\n", lokal_b);
    PAUSE;
}
