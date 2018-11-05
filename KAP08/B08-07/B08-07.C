
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-07, Manipulation von Namen II
/*
/*      Konzepte/       Zeichenketten, Zeicherkettenfunktionen
/*      Sprachelemente: aus string.h
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funktionen zur Stringmanipulation */

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
    int z, x;
    char name[16];      /* Vereinbarung einer Zeichenkette mit 16 Stellen */
    char geschl[6];     /* Vereinbarung einer Zeichenkette mit 6 Stellen */
    char satz[40];      /* Vereinbarung einer Zeichenkette mit 40 Stellen */
    char tut_was[18] = " geht zur Arbeit.";     /* Vereinbarung und Initiali-
                                                   sierung der Zeichenkette */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-07, Namensmanipulation II --------------\n");
    printf("\nDas Programm bearbeitet Namen mit Anrede.\n");

    /* Einlesen der Zeichenketten */
    printf("\nBitte Anrede (Frau oder Herr) angeben: ");
    scanf_s("%s", geschl, 5);

    printf("Bitte Namen eingeben (max. 15 Buchstaben): ");
    scanf_s("%s", name, 15);

    /* strcmp prueft die angegebenen Zeichenketten auf Identitaet;
       0 wird zurueckgegeben, wenn beide gleich sind */

    if((strcmp("Frau", geschl) == 0) || (strcmp("frau", geschl) == 0))
        printf("\n%s %s ist (vermutlich) weiblichen Geschlechts.", geschl, name);
    else
    if((strcmp("Herr", geschl) == 0) || (strcmp("herr", geschl) == 0))
        printf("\n%s %s ist (vermutlich) maennlichen Geschlechts.", geschl, name);
    else
    {
		printf("\nUnbekannte Anrede - hoffentlich keine Verbalinjurie");
		PAUSE;
		return;
    }

    /* strcpy: Der String geschl wird nach satz kopiert */
    strcpy_s(satz, 39, geschl);
    /* strcat: an satz wird ein Blank angehaengt */
    strcat_s(satz, 39, " ");
    /* strcat: an satz wird name angehaengt */
    strcat_s(satz, 39, name);
    /* strcat: an satz wird tut_was angehaengt */
    strcat_s(satz, 39, tut_was);
    /* Ausgabe von satz */
    printf("\n%s\n", satz);

    /* strlen: ermittelt die Laenge von satz */
    x = strlen(satz);
    printf("\nDer letzte Satz enthaelt -%d- Zeichen.", x);

    /* Zeichenweise Ausgabe von satz*/
    printf("\nUnd noch einmal...\n");
    for(z = 0; z <= x; z++)
        putchar(satz[z]);
    printf("\n\n");

    PAUSE;
}
