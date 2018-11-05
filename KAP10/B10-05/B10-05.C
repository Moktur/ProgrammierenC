
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-05, Funktion fuer Wertetausch von Variablen I
/*
/*      Konzepte/       Parameteruebergabe nach call-by-value-Konzept
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   
/*          Programm zur Vertauschung der Werte zweier int-Variablen;
/*          Funktionsaufruf nach dem call by value-Konzept;
/*          ACHTUNG: Programm leistet nicht das Verlangte; vgl. Kap. 10.2
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void tausche1(int x, int y);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    int wert1 = 10, wert2 = 20;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-05, Funktion fuer Wertetausch I --------\n\n");
    printf("\nDas Programm tauscht vermeintlich die Werte zweier Variablen.\n");

    printf("\nwert1: %d  wert2: %d", wert1, wert2);  /* ...vor Vertauschung*/
    tausche1(wert1, wert2);                          /* Aufruf Tauschfunktion,
                                                        mit Wertuebergabe */
    printf("\nwert1: %d  wert2: %d", wert1, wert2);  /* ..nach (vermeintlicher)
                                                        Vertauschung*/
    PAUSE;
}

/* 1. Tauschfunktion - tauscht Werte zweier lokaler Variablen */
void tausche1(int x, int y)
{

    int temp;
    temp  = x;      /* x sichern */
    x = y;          /* x erhaelt Wert von y */
    y = temp;       /* y erhaelt gesicherten Wert von x */
}
