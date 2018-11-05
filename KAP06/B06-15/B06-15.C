
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-15, Textstatistik
/*
/*      Konzepte/       while-Schleife und switch-case-Abfrage
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm untersucht Ihre Eingabe und zaehlt die
/*                      Woerter, Zeilen, Ziffern, Gross-, Klein- und sonstige
/*                      Buchstaben.
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
    int zeichen;
    unsigned int anz_zeilen, anz_woerter, anz_ziffern;
    unsigned int anz_kleinbuchst, anz_grossbuchst, anz_sonstiges;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-15, Textstatistik ----------------------\n");
    printf("\nDas Programm wertet einen Text statistisch aus. ");
    printf("\nEs zaehlt die Anzahl der Zeilen, Woerter, Ziffern usw.\n");

    /* Initialisierung */
    anz_zeilen = anz_woerter = 0;
    anz_ziffern = anz_kleinbuchst = anz_grossbuchst = anz_sonstiges = 0;

    /* Texteingabe und -verarbeitung */
    printf("\nBitte geben Sie Ihren Text ein. \nBeenden Sie ihn mit STRG-Z");
    printf(" am Anfang einer neuen Zeile!");
    printf("\nIhr Text:\n");

    while ((zeichen = getchar()) != EOF)
    {
        switch (zeichen)
        {
            case '\n': ++anz_zeilen;
            case '\t':
            case ' ' : ++anz_woerter; break;
            default  : if (zeichen >= '0' && zeichen <= '9')
                           ++anz_ziffern;
                       else if (zeichen >= 'A' && zeichen <= 'Z')
                           ++anz_grossbuchst;
                       else if (zeichen >= 'a' && zeichen <= 'z')
                           ++anz_kleinbuchst;
                       else ++anz_sonstiges;
        }
    }

    /* Ergebnis ausgeben */
    printf("\n--- Textstatistik ---\n");
    printf("\nAnzahl der Woerter:            %u", anz_woerter);
    printf("\nAnzahl der Zeilen:             %u", anz_zeilen);
    printf("\nAnzahl der Ziffern:            %u", anz_ziffern);
    printf("\nAnzahl der grossen Buchstaben: %u", anz_grossbuchst);
    printf("\nAnzahl der kleinen Buchstaben: %u", anz_kleinbuchst);
    printf("\nAnzahl der sonstigen Zeichen:  %u", anz_sonstiges);
    printf("\n");
    PAUSE;
}
