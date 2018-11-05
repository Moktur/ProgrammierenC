
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       04-02, Einlesen von Zeichen
/*
/*      Konzepte/       Zeichen einlesen mit der Funktion getchar
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>           /* macht auch die Funktion getchar verfuegbar */

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
    int zeichen;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-02, Einlesen von Zeichen ---------------\n\n");

    printf("\nDas Programm liest ein Zeichen mit getchar ein.\n");

    /* Eingabe */
    printf("\nBitte einen Buchstaben eingeben und RETURN-Taste druecken: ");

    /* ein Zeichen einlesen und an Variable zeichen uebergeben */
    zeichen = getchar();

    /* Kontrollausgabe */
    printf("\nEingegebenes Zeichen: %c", zeichen);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Erweitern Sie die printf-Kontrollausgabe, indem Sie
    - vor dem schliessenden Anfuehrungszeichen ' %d  ' einfuegen und
    - nach zeichen nochmals ' ,zeichen' schreiben.
  Wie haengen beide Ausgaben der Variablen zeichen zusammen?

******************************************************************************/
