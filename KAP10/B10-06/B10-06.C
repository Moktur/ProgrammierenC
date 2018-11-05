
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-06, Funktion fuer Wertetausch von Variablen II
/*
/*      Konzepte/       Parameteruebergabe nach call-by-reference-Konzept
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:
/*          Programm zur Vertauschung der Werte zweier int-Variablen;
/*          Funktionsaufruf nach dem call by reference-Konzept mit
/*          Adressuebergabe
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

void tausche2(int *xzgr, int *yzgr); /* Prototyp */

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
    printf("----- Beispiel: 10-06, Funktion fuer Wertetausch II --------\n\n");
    printf("\nDas Programm tauscht die Werte zweier Variablen.\n");

    printf("\nwert1: %d  wert2: %d", wert1, wert2);  /*...vor Vertauschung*/
    tausche2(&wert1, &wert2);                        /* Aufruf Tausch-Funktion,
                                                 diesmal mit Adressuebergabe */
    printf("\nwert1: %d  wert2: %d", wert1, wert2);  /*...nach Vertauschung*/
    PAUSE;
}

/* 2. Tauschfunktion -
   tauscht Werte an uebergebenen Speicherplaetzen bzw. Adressen */
void tausche2(int *xzgr, int *yzgr)
{

    int temp;

    /* (1) Wert unter Adresse xzgr wird in temp gesichert */
    temp = *xzgr;

    /* (2) Wert unter xzgr wird mit Wert unter Adresse yzgr ueberschrieben*/
    *xzgr = *yzgr;

    /* (3) Wert unter Adresse yzgr wird mit gesichertem altem Wert
           unter der Adresse xzgr ueberschrieben */
    *yzgr = temp;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Ergaenzen Sie die 2. Tauschfunktion um Zwischenausgaben nach den
  Schritten (1) bis (3), mit denen Sie jeweils die Inhalte der
  Speicherplaetze (Adressen) temp, xzgr, yzgr protokollieren.

******************************************************************************/
