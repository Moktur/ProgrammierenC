
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-09, Aktenstapel
/*
/*      Konzepte/       einfach verkettete unsortierte Liste, Stapel,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm realisiert einen Aktenstapel als
/*                      einfach verkettete unsortierte Liste.
/*
/*                      Stellen Sie sich vor, Sie haben einen Stapel von Akten
/*                      abzuarbeiten. Zwischendurch kommt immer wieder Ihr Chef
/*                      und legt noch eine Akte oben drauf, mit den Worten
/*                      "Die schaffen Sie doch heute auch noch...". Wenn Sie
/*                      immer die oberste Akte zum Bearbeiten herunternehmen,
/*                      ist die Akte ganz unten im Stapel die letzte, die
/*                      bearbeitet wird, egal wie viele Akten dazukommen.
/*
/*                      Das Programm umfasst die 3 Dateien
/*                      - B14-09-1.c,
/*                      - B14-09-2.c und
/*                      - B14-09-2.h.
/*                      Zur Erzeugung eines ausfuehrbaren Programms sind
/*                      die Dateien B14-09-1.c und B14-09-2.c zu binden.
/*
/*                      Das Programm benutzt den ADT Aktenstapel, der durch
/*                      die Dateien B14-09-2.c und B14-09-2.h definiert ist.
/*                      Die Datei B14-09-1.c stellt einen Anwendungsmodul fuer
/*                      den ADT dar.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdio.h>
#include <string.h>

/* Definitionsdatei fuer den Stack einbinden */
#include "B14-09-2.h"

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   main ()
/* Aufgabe:
/*   Eine Beispielanwendung fuer den Stack.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void main (void)
{
    /* Lokale Variablen definieren */
    long nummer;
    long aktennummer;
    char zeichen[5];
    char bearbeiter[30];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-09, Aktenstapel ------------------------\n\n");
    printf("\nDas Programm realisiert einen Aktenstapel als einfach\n");
    printf("verkettete Liste.\n");

    /* Lege neue Akten auf den Stapel */
    printf("\nGeben Sie Aktennummer (Typ long), Aktenzeichen (4 Zeichen ");
    printf("ohne\nBlanks und Sachbearbeiter (29 Zeichen ohne Blanks) der ");
    printf("Akten an,\ndie auf den Stapel gelegt werden. Brechen Sie die ");
    printf("Eingabe mit\n-1 als Aktennummer ab.\n");
    do
    {
        /* Frage nach dem neuen Element */
        printf("\nWie lautet die Aktennummer: ");
        scanf_s("%ld", &nummer);
        /* Wenn nicht die Eingabe nicht abgebrochen wurde */
        if (nummer != -1)
        {
            /* Frage den Rest der Daten ab */
            printf("Wie lautet das Aktenzeichen: ");
			scanf_s("%s", zeichen, 4);
            printf("Wie heisst der Sachbearbeiter: ");
			scanf_s("%s", bearbeiter, 29);
            /* Schiebe diese Akte auf den Stapel */
            push(nummer, zeichen, bearbeiter);
        }
    }
    while (nummer != -1);

    /* Hole Akten vom Stapel, bis dieser leer ist */
    printf("\nIch hole die Akten alle wieder vom Stapel:\n");
    while(Anzahl() > 0)
    {
        pop(&aktennummer, zeichen, bearbeiter);
        printf("Nummer: %07ld, ", aktennummer);
        printf("Zeichen: %5s, ", zeichen);
        printf("Bearbeiter: %s\n", bearbeiter);
    }
    printf("\n\n");
    PAUSE;
}
