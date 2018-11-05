
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-08, globale und lokale Variablen
/*
/*      Konzepte/       
/*      Sprachelemente: Globale und lokale Variablen und deren "Verschattung"
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt den Gebrauch von globalen und
/*                      lokalen Variablen. Demonstriert wird (vgl. Aufgaben-
/*                      teil), dass globale Variablen innerhalb einer Funktion
/*                      nicht mehr sichtbar sind, wenn dort lokale Variablen
/*                      mit gleichem Namen vorhanden sind.
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
/* Funktionen deklarieren
/*****************************************************************************/

void fkt(void);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

int global_1 = 5;
int global_2 = 7;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    double lokal_1 = 7.2;
    double lokal_2 = 10.4;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-08, globale und lokale Variablen -------\n\n");

    printf("\nDas Programm zeigt die Sichtbarkeit von globalen und lokalen Variablen.");
    printf("\nGezeigt wird u.a., wie globale Variablen durch lokale Variablen");
    printf("\ngleichen Namens ueberdeckt werden.\n");

    printf("\nMAIN\n");
    printf("\nlokale Variablen : lokal_1  = %.2f  lokal_2  = %.2f",
                lokal_1, lokal_2);
    printf("\nglobale Variablen: global_1 = %d     global_2 = %d",
                global_1, global_2);
    fkt();
    printf("\n");
    PAUSE;
}

/* Funktion: fkt
   Ausgabe der Inhalte von Variablen */
void fkt(void)
{
    /* lokale Variablen */
    double lokal_1 = 12.34;
    double lokal_2 = 4.91;

    /* Anweisungen */
    printf("\n\n\nFUNKTION \n");
    printf("\nlokale Variablen : lokal_1  = %.2f  lokal_2  = %.2f",
                lokal_1, lokal_2);
    printf("\nglobale Variablen: global_1 = %d      global_2 = %d",
                global_1, global_2);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  1) Definieren Sie globale Variablen mit den Namen lokal_1 und lokal_2
      (nach dem Kommentar "globale Variablen definieren").
      Initialisieren Sie lokal_1 und lokal_2 mit 7.0 bzw. 10.0.
      Uebersetzen Sie das Programm erneut.
     Welche Ausgabe beobachten Sie?
  2) Kommentieren Sie in der Funktion "fkt" die Definition von lokal_1 und
     lokal_2 aus. Uebersetzen und starten Sie das Programm erneut. Welche
     Ausgaben erscheinen nun und warum?

******************************************************************************/
