
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-03, Variablen definieren
/*
/*      Konzepte/       Mehrere Varianten zur Definition und
/*      Sprachelemente: Initialisierung von Variablen
/*
/*      Aufgabenteil:   nein
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
/* Konstanten definieren
/*****************************************************************************/

const int aconst = 1000;
const int bconst =    1;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen definieren */

    /* 1. Variante - gemeinsam */
    int  Jahr, Monat, Tag;

    /* 2. Variante - getrennt -> mehr Platz fuer Kommentare */
    int  jahr;  /* Jahr */
    int  monat; /* Monat */
    int  tag;   /* Tag */

    /* Man beachte: es wird zwischen Gross- und Kleinschreibung unter-
       schieden. "jahr" und "Jahr" sind zwei verschiedene Variablen */

    float   betrag1, betrag2;  /* Variablen fuer gebrochene Zahlen */
    double  sum;

    char    zeichen;           /* Zeichen-Variablen bzw. Variablen fuer kleine
                                  ganze Zahlen */

    char    *zeiger;           /* Zeigerdefinition (wird spaeter behandelt) */

    static  long grz;          /* Definition mit Speicherklasse static (wird
                                  spaeter behandelt) */

    /* Jetzt Definitionen mit Initialisierung. Initialisierungswerte
       muessen Konstanten oder Ausdruecke mit Konstanten sein und
       typmaessig passen */
    long    summe1 = 0; 
    long    summe2 = aconst + bconst;

    double  betrag = aconst * 10.e-3;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-03, Variablen definieren ---------------\n\n");

    printf("\nDas Programm zeigt Varianten der Definition und");
    printf("\nInitialisierung von Variablen.");

    /* Verarbeitung und Ausgabe */
    printf("\n\n\tsumme1 = %ld \n\tsumme2 = %ld", summe1, summe2);
    printf("\n\tbetrag = %f\n\n", betrag);
    PAUSE;
}
