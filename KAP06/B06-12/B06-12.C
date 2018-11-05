
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-12, ASCII-Tabelle
/*
/*      Konzepte/       do-while-Schleife
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm gibt eine ASCII-Tabelle am Bildschirm aus.
/*                      In einer do-while-Schleife werden die Zeichen nach-
/*                      einander ausgegeben.
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
    int l = 1;
    unsigned char c;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-12, ASCII-Tabelle ----------------------\n\n");

    printf("\nDas Programm gibt eine ASCII-Tabelle von Zeichen 32 bis 127 aus.\n\n\t");

    /* Verarbeitung / Ausgabe */
    /* Die Steuerzeichen mit den Nummern 1-31 werden uebergangen, da sie nicht
       am Bildschirm ausgegeben werden koennen */
    c = 32;

    /* Anfang do-while-Schleife; Anmerkung: Anweisungen in der
       Schleife werden mindestens einmal durchlaufen, bevor die Fortsetzungs-
       Bedingung geprueft wird */
    do
    {
        printf("%-2c%-6u", c, c); /* aktuelles Zeichen ausgeben */
        if (l == 6)    /* Nach 6 ausgegebenen Spalten einen Zeilenumbruch */
        {
            printf("\n\t");
            l = 0;
        }
        /* Erhoehe c und l um jeweils eins */
        c++;
        l++;
     } while (c <= 127); /* Fortsetzungsbedingung */

    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Verlegen Sie die Erhoehung von c in den Bedingungs-Ausdruck
  (Fortsetzungsbedingung) von while. Wie muessen die Vergleichs-Operatoren
  geaendert werden, wenn sie Prae- (++c) oder Postinkrement (c++) benutzen ?

******************************************************************************/
