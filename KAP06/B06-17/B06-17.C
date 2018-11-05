
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-17, Verbundanweisungen
/*
/*      Konzepte/       Verbundanweisungen in Bloecken und mit Kommaoperator
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
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

void main (void)
{
    /* lokale Variablen */
    int a, b;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-17, Verbundanweisungen -----------------\n\n");

    printf("\nDas Programm zeigt den Umgang mit Verbundanweisungen");
    printf(" und Kommaoperator.\n");

    a = 1;
    b = 2;
    printf("\na = %d\tb = %d", a, b);

    /* Verbundanweisung als Block */
    {
        /* lokale Vereinbarungen sind moeglich */
        int c = 5;  /* Variable c ist nur innerhalb dieses Blocks
                       definiert */
        a = 3;
        b = 4;
        printf("\na = %d\tb = %d\tc = %d", a, b, c);
    }

    /* Verbundanweisung mit Kommaoperator */
    a = 6, b = 7, printf("\na = %d\tb = %d", a, b), printf("\n");

    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

   Wie reagiert der Compiler, wenn Sie nach dem lokalen Block, in welchem
   die Variable c definiert wurde, diese mit printf ausgeben wollen?

******************************************************************************/

