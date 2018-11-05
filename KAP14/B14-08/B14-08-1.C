
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-08, Telefonbuch II
/*
/*      Konzepte/       Doppelt verkettete unsortierte Liste,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm realisiert ein Telefonbuch als
/*                      doppelt verkettete unsortierte Liste.
/*
/*                      Das Programm umfasst die 3 Dateien
/*                      - B14-08-1.c,
/*                      - B14-08-2.c und
/*                      - B14-08-2.h.
/*                      Zur Erzeugung eines ausfuehrbaren Programms sind
/*                      die Dateien B14-08-1.c und B14-08-2.c zu binden.
/*
/*                      Das Programm benutzt den ADT Telefonbuch-II, der
/*                      durch die Dateien B14-08-2.c sowie B14-08-2.h
/*                      definiert ist. Die Datei B14-08-1.c stellt einen
/*                      Anwendungsmodul fuer den ADT dar.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdio.h>
#include <string.h>

/* Definitionsdatei fuer einfach verkettete Liste einbinden */
#include "B14-08-2.h"

/*****************************************************************************/
/* Makro definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void Eingabe(void);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   main()
/* Aufgabe:
/*   Eine Beispielanwendung fuer die einfach verkettete Liste.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void main (void)
{
    /* Lokale Variablen definieren */
    char name[MAXZEICHEN];

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-08, Telefonbuch II ---------------------\n\n");
    printf("\nDas Programm realisiert ein Telefonbuch als doppelt\n");
    printf("verkettete Liste.\n\n");

    Eingabe();

    /* Anzeigen der ganzen Liste */
    printf("\nDie ganze Liste:\n");
    GibAlleKnotenAus();

    /* Loeschen des ersten Knotens und anzeigen des neuen ersten Knotens */
    LoescheKnotenAmAnfang();
    printf("\nIch habe den ersten Knoten geloescht. Der neue erste Knoten");
    printf(" ist:\n");
    GibKnotenAmAnfangAus();

    /* Anzeigen der ganzen Liste */
    printf("\nDie ganze Liste:\n");
    GibAlleKnotenAus();

    /* Anzahl der Knoten in der Liste ermitteln */
    printf("\nEs sind %u Knoten in der Liste.\n", ErmittleAnzahlDerKnoten());

    /* Anzeigen eines bestimmten Knotens */
    printf("\nGeben Sie den Namen der Knoten an, den ich anzeigen soll:\n");
    printf("Name: ");
    scanf_s("%s", name, MAXZEICHEN-1);
    GibKnotenMitNamenAus(name);

    /* Loeschen eines bestimmten Knotens */
    printf("\nGeben Sie den Namen der Knoten an, den ich loeschen soll:\n");
    printf("Name: ");
    scanf_s("%s", name, MAXZEICHEN-1);
    LoescheKnotenMitNamen(name);

    /* Anzeigen der ganzen Liste */
    printf("\nDie ganze Liste ist nun:\n");
    GibAlleKnotenAus();

    /* Gesamte Liste loeschen und die Anzahl der Knoten ermitteln */
    LoescheGanzeListe();
    printf("\nIch habe die gesamte Liste geloescht. Es sind");
    printf("\nnun %u Knoten in der Liste.\n", ErmittleAnzahlDerKnoten());
    PAUSE;
}

/*****************************************************************************/
/* Funktion:
/*   Eingabe()
/* Aufgabe:
/*   Ermoeglicht die Eingabe der Daten von bis zu 10 Personen.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void Eingabe(void)
{
    /* Lokale Variablen definieren */
    unsigned int nummer;
    char name[MAXZEICHEN];
    char telefon[MAXZEICHEN];
    char wahl[2];

    /* Eingabe der Daten */
    printf("Bitte geben Sie die Daten von bis zu 10 Personen an. Entscheiden");
    printf(" Sie, ob der\nneue Knoten am Anfang oder am Ende der Liste ");
    printf("Eingefuegt werden soll. Brechen\nSie die Eingabe mit einem * als");
    printf(" Namen oder als Telefonnummer ab.\n");
    printf("Alle Eingaben duerfen maximal 79 Zeichen lang sein und keine ");
    printf("Blanks enthalten.");
    printf("\n\n");

    /* Bis zu 15 Personen koennen eingegeben werden */
    for (nummer = 1; nummer <= 10; nummer++)
    {
        printf("\nBitte geben Sie Daten der %u. Person ein:\n", nummer);

        /* Namen abfragen */
        printf("Name: ");
        scanf_s("%s", name, MAXZEICHEN-1);
        /* Wenn ein * als Abbruch eingegeben wurde, breche Schleife ab */
        if (strcmp(name, "*") == 0)
            break;
        /* Telefonnummer abfragen */
        printf("Telefon: ");
        scanf_s("%s", telefon, MAXZEICHEN-1);
        /* Wenn ein * als Abbruch eingegeben wurde, breche Schleife ab */
        if (strcmp(telefon, "*") == 0)
            break;
        printf("(a)nfang oder (e)nde: ");
        scanf_s("%s", wahl, (int)sizeof(wahl)-1);
        /* Wenn ein * als Abbruch eingegeben wurde, breche Schleife ab */
        if (strcmp(wahl, "*") == 0)
            break;

        /* Fuege Knoten am Anfang oder am Ende in die Liste ein, je nach dem
           uebergebenen Parameter */
        if ( (strcmp(wahl, "a") == 0) || (strcmp(wahl, "A") == 0) )
            FuegeKnotenAmAnfangEin(name, telefon);
        else
            FuegeKnotenAmEndeEin(name, telefon);
    }
}
