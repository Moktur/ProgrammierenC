
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      basierend auf:  
/*
/*      Beispiel:       13-07, Boolscher Datentyp
/*
/*      Konzepte/       Boolscher Datentyp, Definitionsdateien
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm zeigt den elementaren Umgang mit
/*                      Boolschen Variablen sowie Definitionsdateien.
/*
/*                      Das Beispiel umfasst die beiden Dateien B13-07.h und
/*                      B13-07.c
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

#include "B13-07.h"     /* Enthaelt die Definition des Boolschen Datentyps
                           und der Boolschen Konstanten */

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
    int zeile;
    boolean weiss, schwarz;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 13-07, Boolscher Datentyp -----------------\n\n");
    printf("\nDas Programm zeigt den Umgang mit Definitionsdateien.\n\n");

    /* Zuweisung von Boolschen Konstanten */
    weiss = TRUE;
    schwarz = FALSE;

    /* Zehn Ausgaben der Werte von weiss und schwarz, wobei nach jeder Zeile
       die Werte invertiert werden */
    for (zeile = 1; zeile <= 10; zeile++)
    {
        /* Ausgabe der Werte von weiss und schwarz */

        /* 1. Version: mit Vergleichsoperator */
        if (weiss == TRUE)
            printf("weiss ist wahr\t\t");
        else
            printf("weiss ist falsch\t");

        /* 2. Version: ohne Vergleichsoperator */
        if (schwarz)
            printf("schwarz ist wahr\n");
        else
            printf("schwarz ist falsch\n");

        /* Wechsel der Werte von weiss und schwarz */

        /* 1. Version: mit if-Abfrage und Operator ! */
        if (!weiss)     /* ACHTUNG: Wenn weiss gleich FALSE ist */
            weiss = TRUE;
        else
            weiss = FALSE;

        /* 2. Version: mit Operator ! */
        schwarz = !schwarz;
    }
    PAUSE;
}
