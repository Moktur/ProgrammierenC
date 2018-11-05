
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-16, Summe aller geraden Zahlen bis zu einem Maximum
/*
/*      Konzepte/       continue-Anweisung
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm berechnet die Summe aller geraden Zahlen
/*                      bis zu einem Maximum, das Sie bestimmen.
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

void main (void)
{
    /* lokale Variablen */
    unsigned short maximum;     /* speichert das Maximum */
    unsigned short zahl;        /* aktuell bearbeitete Zahl */
    unsigned int   summe;       /* speichert die Summe */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-16, Summe gerader Zahlen ---------------\n");

    printf("\nDas Programm berechnet die Summe aller geraden Zahlen bis\n");
    printf("zu einem Maximum, das Sie bestimmen.\n\n");

    /* Frage maximum ab */
    printf("Bitte geben Sie das Maximum an: ");
    scanf_s("%hu", &maximum);

    /* Berechne Summe aller geraden Zahlen bis maximum */
    for (zahl = 2, summe = 0; zahl <= maximum; zahl++)
    {
        /* Wenn zahl ungerade ist, dann setze die for-Schleife fort */
        if ((zahl % 2) == 1)
            continue;
        /* Ansonsten addiere die Zahl zur Summe */
        summe += zahl;
    }

    /* Gebe das Ergebnis am Bildschirm aus */
    printf("\nDie Summe aller geraden Zahlen von 2 bis ");
    printf("%hu ist %u.\n\n", maximum, summe);
    PAUSE;
}
