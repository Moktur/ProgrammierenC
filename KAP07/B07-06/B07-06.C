
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-06, Menue
/*
/*      Konzepte/       Wertrueckgabe von Programmen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm gibt ein Menue auf dem Bildschirm aus
/*                      und fragt eine Eingabe ab. Diese wird von der Funktion
/*                      main mit return an das Betriebssystem zurueckgegeben,
/*                      kann in globalen Variablen des Betriebssystems gehalten
/*                      und weiterverarbeitet werden. Z.B. ist unter DOS
/*                      eine Abfrage mit errorlevel moeglich. Da die main-Funk-
/*                      tion einen char-Wert zurueckgibt, wird sie hier mit
/*                      dem Typ char vereinbart.
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

char main(void)         /* beachte Typ der main-Funktion */
{
    /* lokale Variablen */
    char eingabe;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-06, Menue ------------------------------\n\n");

    printf("\nDas Programm zeigt, wie ein Wert von main an das Betriebssystem");
    printf("\nzurueckgegeben werden kann.\n");

    /* Menue ausgeben*/
    printf("\n1: Laden");
    printf("\n2: Speichern");
    printf("\n3: Beenden");
    printf("\n\nIhre Wahl: ");

    /* Abfragen */
    scanf_s("%c", &eingabe, 1);

    /* liefere Eingabe an das Betriebssystem zurueck */
    printf("\nDie Eingabe -%c- wird jetzt an das Betriebssystem geliefert.",
              eingabe);
    PAUSE;
    return eingabe;
}
