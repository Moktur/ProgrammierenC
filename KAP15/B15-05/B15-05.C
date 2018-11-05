
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       15-05, Abfrage des Wochentages
/*
/*      Konzepte/       Funktionen und -Typen aus der time.h-Bibliothek
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <time.h>       /* Funktionen zur Verarbeitung der Zeit */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Aufzaehlungstyp definieren
/*****************************************************************************/

enum tag {SO, MO, DI, MI, DO, FR, SA};

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    /* Variable vom Aufzaehlungstyp 'enum tag' definieren */
    enum tag Wochentag;

    /* Das folgende dient zur Bestimmung des Wochentages */
    /* Anwendung der Typen time_t, struct tm sowie der Funktionen 
       time und localtime */

    time_t ltime;
    struct tm today;

    /* Anweisungen */
    time(&ltime);
    localtime_s(&today, &ltime);
    Wochentag = today.tm_wday;
    
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 15-05, Abfrage des aktuellen Wochentages --\n\n");
    printf("Das Programm ermittelt den heutigen Tag, indem es die\n");
    printf("entsprechenden Informationen mit Hilfe der Systemuhr bestimmt.\n");

    /* Je nachdem was fuer ein Tag heute ist, eine andere Ausgabe */
    switch (Wochentag)
    {
        case SO: printf("\nHeute ist Sonntag.\n");   break;
        case MO: printf("\nHeute ist Montag.\n");    break;
        case DI: printf("\nHeute ist Dienstag.\n");  break;
        case MI: printf("\nHeute ist Mittwoch.\n");  break;
        case DO: printf("\nHeute ist Donnerstag.\n");break;
        case FR: printf("\nHeute ist Freitag.\n");   break;
        case SA: printf("\nHeute ist Samstag.\n");   break;
        default: printf("\nFehler aufgetreten!\n");  break;
    }
    PAUSE;
}
