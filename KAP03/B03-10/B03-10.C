
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-10, roemische Zahlen
/*
/*      Konzepte/       Aufzaehlungstyp enum
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   keine
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
    /* lokale Variablen */
    int rom;

    /* erste Variante der Definition:  Typ und Variablen getrennt definiert */
    enum zahlen1 {I=1,II,III,IV,V,VI,VII,VIII,IX,X};
    enum zahlen1 rom1, rom2;

    /* zweite Variante der Definition:  Typ und Variablen zusammen definiert */
    /* enum zahlen {I=1,II,III,IV,V,VI,VII,VIII,IX,X} rom1, rom2; */

    /* dritte Variante der Definition:  mit typedef */
    /* typedef enum zahlen {I=1,II,III,IV,V,VI,VII,VIII,IX,X} ROMZAHLEN;
       ROMZAHLEN rom1, rom2; */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-10, Roemische Zahlen -------------------\n\n");

    printf("\nDas Programm stellt einen Aufzaehlungstyp fuer roemische Zahlen vor.\n");

    /* Operationen und Zuweisungen */
    printf("\nOperationen mit zwei roemischen Zahlen:");
    printf("\n\nII  + V   = %d", II + V);
    printf("\nVII - III = %d", VII - III);
    printf("\nX   * IV  = %d", X * IV);
    printf("\nVI  / II  = %d", VI / II);

    rom1 = II;
    rom2 = V;
    rom  = rom1 * rom2;
    printf("\nrom =  %d", rom);

    /* Vergleiche */
    if (rom1 == X)
        printf("\nrom1 = X");
    if (rom2 == V)
        printf("\nrom2 = V");

    /* Zuweisung einer Zahl, die nicht in enum aufgefuehrt ist */
    printf("\n\nZuweisungen an Variable des Aufzaehltyps.");
    printf("\nZuweisung der Zahl 20, die keine Aufzaehlungskonstante ist.");
    rom1 = 20;
    printf("\n  Ist der Compiler nachsichtig? rom1 = %d", rom1);

    /* Zuweisung eines falschen Datentyps */

    /*
    printf("\nZuweisung einer float-Zahl.");
    rom1 = 1.111F;
    printf("\n  Ist der Compiler nachsichtig? rom1 = %f", rom1);
    printf("\n  Bei Zuweisung von float-Konstanten Wert-Verfaelschung!");
    */

    PAUSE;
}
