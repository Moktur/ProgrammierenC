
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-09, Anwendung des sizeof-Operators
/*
/*      Konzepte/       sizeof-Operator, Speicherbedarf fuer
/*      Sprachelemente: vordefinierte Datentypen ermitteln
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

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-09, Anwendung des sizeof-Operators -----\n\n");

    printf("\nDas Programm zeigt die Anwendung des sizeof-Operators");
    printf("\nauf Typbezeichner.\n");

    /* Ausgabe der Laengen der vordefinierten Datentypen */
    printf("\nLaenge des vordefinierten Datentyps char   in Bytes: %d",
        sizeof(char));
    printf("\nLaenge des vordefinierten Datentyps int    in Bytes: %d",
        sizeof(int));
    printf("\nLaenge des vordefinierten Datentyps long   in Bytes: %d",
        sizeof(long));
    printf("\nLaenge des vordef. Datentyps unsigned char in Bytes: %d",
        sizeof(unsigned char));
    printf("\nLaenge des vordef. Datentyps unsigned int  in Bytes: %d",
        sizeof(unsigned int));
    printf("\nLaenge des vordef. Datentyps unsigned long in Bytes: %d",
        sizeof(unsigned long));
    printf("\nLaenge des vordefinierten Datentyps float  in Bytes: %d",
        sizeof(float));
    printf("\nLaenge des vordefinierten Datentyps double in Bytes: %d",
        sizeof(double));
    printf("\nLaenge des vordef. Datentyps long double   in Bytes: %d",
          sizeof(long double));
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Verwenden Sie anstelle von Typbezeichnern Variablen der entsprechenden
  vordefinierten Typen als Argumente des sizeof-Operators und ueberzeugen
  Sie sich davon, dass die Ergebnisse fuer einen Typ und eine Variable
  des Typs gleich sind.

******************************************************************************/
