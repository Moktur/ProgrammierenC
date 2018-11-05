
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-07, Telefonbuch I
/*
/*      Konzepte/       Einfach verkettete Listen, unsortiert und sortiert,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm realisiert ein Telefonbuch
/*                      als einfach verkettete Liste.
/*
/*                      Das Programm umfasst die 3 Dateien
/*                      - B14-07-1.c,
/*                      - B14-07-2.c und
/*                      - B14-07-2.h.
/*                      Zur Erzeugung eines ausfuehrbaren Programms sind
/*                      die Dateien B14-07-1.c und B14-07-2.c zu binden.
/*
/*                      Das Programm benutzt den ADT Telefonbuch-I, der
/*                      durch die Dateien B14-07-2.c sowie B14-07-2.h
/*                      definiert ist. Die Datei B14-07-1.c stellt einen
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
#include "B14-07-2.h"

/*****************************************************************************/
/* Makro definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void Eingabe(unsigned int sortiert);

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
    char wahl;
    char name[MAXZEICHEN];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-07, Telefonbuch I ----------------------\n\n");
    printf("\nDas Programm realisiert ein Telefonbuch als einfach\n");
    printf("verkettete Liste.\n");
    printf("Alle Eingaben duerfen maximal 79 Zeichen lang sein und\nduerfen ");
    printf("kein Blank enthalten.\n\n");

    /* Unterscheidung zwischen sortierter und unsortierter Liste */
    printf("Wollen Sie eine sortierte Liste? Geben Sie j oder n ein: ");
    scanf_s("%c", &wahl, 1);
    printf("\n\n");
    if (wahl == 'n')
        Eingabe(0);
    else
        Eingabe(1);

    /* Anzeigen des ersten Knotens */
    printf("\n\nDer erste Knoten ist:\n");
    GibKnotenAmAnfangAus();

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
/*   Ermoeglicht die Eingabe der Daten von bis zu 10 Personen. Mit einem
/*   Parameter wird unterschieden, ob die Datem sortiert oder unsortiert in
/*   die Liste eingetragen werden sollen .
/* Parameter:
/*   sortiert: 0, wenn die Liste nicht sortiert sein soll
/*             1, wenn die Liste sortiert sein soll
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void Eingabe(unsigned int sortiert)
{
    /* Lokale Variablen definieren */
    unsigned int nummer;
    char name[MAXZEICHEN];
    char telefon[MAXZEICHEN];

    /* Eingabe der Daten */
    printf("Bitte geben Sie die Daten von bis zu 10 Personen an. Brechen Sie");
    printf(" die Eingabe\nmit einem * als Namen oder als Telefonnummer");
    printf(" ab.\n\n");

    /* Bis zu 10 Personen koennen eingegeben werden */
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
        /* Fuege Knoten sortiert oder unsortiert in die Liste ein, je nach dem
           uebergebenen Parameter */
        if (sortiert)
            FuegeKnotenSortiertEin(name, telefon);
        else
            FuegeKnotenAmAnfangEin(name, telefon);
    }
}
