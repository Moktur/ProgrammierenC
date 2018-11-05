
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       09-07, sizeof-Operator fuer Strukturen
/*
/*      Konzepte/       sizeof-Operator, Strukturen, Unionen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm ermittelt fuer selbst definierte
/*                      Datentypen (struct und union) die belegte
/*                      Speichergroesse.
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
/* Typen definieren
/*****************************************************************************/

typedef struct
        {
            char name[20];
            char vorname[20];
            int  alter;
        } PERSON;

typedef struct 
        {
            float  gehalt;
            double betrag;
            int    nummer;
        } WARE;

typedef union
        {
            double x;
            int    z;
            char   haus[4];
        } MIETE;

typedef struct
        {
            char name[20];
            char vorname[20];
            int  nummer;
            union
            {
                double gehalt;
                struct
                {
                    float stunden;
                    float std_lohn;
                } lohn;
            } geld;
        } MITARBEITER;

typedef struct
        {
            char name[20];
            char vorname[20];
            int nummer;
            double gehalt;
            float stunden;
            float std_lohn;
        } MITARBEITER_2;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 09-07, sizeof-Operator fuer Strukturen ----\n\n");
    printf("\nDas Programm ermittelt den Speicherbedarf einiger Strukturen und Unionen.\n");

    /* Ausgabe der Laengen der selbstdefinierten Datentypen */
    printf("\n\nLaenge des Datentyps PERSON        in Bytes: %d",
        sizeof(PERSON));
    printf("\nLaenge des Datentyps WARE          in Bytes: %d",
        sizeof(WARE));
    printf("\nLaenge des Datentyps MIETE         in Bytes: %d",
        sizeof(MIETE));
    printf("\nLaenge des Datentyps MITARBEITER   in Bytes: %d",
        sizeof(MITARBEITER));
    printf("\nLaenge des Datentyps MITARBEITER_2 in Bytes: %d\n\n",
           sizeof(MITARBEITER_2));
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Wie die Beispiele zeigen, stimmt der Platzbedarf einer Struktur nicht immer
  mit der Summe der pro Komponente belegten Bytes ueberein. Der Platzbedarf
  einer Struktur kann hoeher ausfallen, weil fuer einzelne Komponenten eine
  Ausrichtung an Adressen vorgenommen wird, die durch 2, 4 bzw. 8 teilbar sind
  (Halbwort-, Wort-, Doppelwortgrenzen). Pruefen Sie fuer einzelne Strukturen
  bzw. Unionen, ob sich das Verhaeltnis der Summe der Speicherbedarfe der
  Komponenten zum Speicherbedarf der Struktur bzw. Union etwas aendert, wenn
  die Reihenfolge der Komponenten veraendert bzw. auf double-Komponenten
  verzichtet wird.

******************************************************************************/
