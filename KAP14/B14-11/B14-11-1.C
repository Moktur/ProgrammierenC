
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-11, Telefonbuch III
/*
/*      Konzepte/       Binaerer Suchbaum, Modularisierung, ADT
/*      Sprachelemente:
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm realisiert ein Telefonbuch als
/*                      binaeren Suchbaum.
/*
/*                      Sie haben vor, eine grosse Menge von Telefonnummern
/*                      zu speichern. Um einen schnellen Zugriff auf die
/*                      Daten zu gewaehrleisten, ist ein binaerer Suchbaum
/*                      geeignet.
/*
/*                      Das Programm umfasst die 3 Dateien
/*                      - B14-11-1.c,
/*                      - B14-11-2.c und
/*                      - B14-11-2.h.
/*                      Zur Erzeugung eines ausfuehrbaren Programms sind
/*                      die Dateien B14-11-1.c und B14-11-2.c zu binden.
/*
/*                      Das Programm benutzt den ADT Telefonbuch III, der
/*                      durch die Dateien B14-11-2.c und B14-11-2.h definiert
/*                      ist. Die Datei B14-11-1.c stellt einen Anwendungsmodul
/*                      fuer den ADT dar.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdio.h>
#include <string.h>

/* Definitionsdatei fuer den ADT Telefonbuch III einbinden */
#include "B14-11-2.h"

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
/*   Eine Beispielanwendung fuer den Binaeren Baum.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    char name[30];
    char nummer[30];
    int wahl;

    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-11, Telefonbuch III --------------------\n\n");
    printf("\nDas Programm realisiert ein Telefonbuch als binaeren Baum.\n");

    /* Eingabe der Telefonnummern */
    printf("\nGeben Sie den Namen und die Telefonnummer ein, die in dem ");
    printf("binaeren Baum\ngespeichert werden soll. Name und Telefonnummer ");
    printf("duerfen maximal 29 Zeichen\nlang sein und duerfen keine Blanks ");
    printf("beinhalten. Brechen Sie die Eingabe\n");
    printf("mit * als Name ab.\n");
    do
    {
        /* Frage nach den Namen */
        printf("\nName: ");
		scanf_s("%s", name, 29);
        /* Wenn nicht die Eingabe nicht abgebrochen wurde */
        if (strcmp(name, "*") != 0)
        {
            /* Frage den Rest der Daten ab */
            printf("Telefonnummer: ");
			scanf_s("%s", nummer, 29);
            /* Speicher die Daten im Baum */
            FuegeKnotenEin(name, nummer);
        }
    }
    while (strcmp(name, "*") != 0);

    /* Ausgabe der Daten in gewuenschter Art */
    for (;;)
    {
        /* Menue */
        printf("\n\nIn welcher Reihenfolge sollen die Daten ausgegeben ");
        printf("werden?\n(1) Praeorder\n(2) Inorder\n(3) Postorder\n");
        printf("(4) Programm beenden\n\n> ");
        scanf_s("%d", &wahl);

        /* Ausgabe */
        switch (wahl)
        {
            case 1: printf("\nPraeorder:\n\n"); AusgabePraeorder();
                    break;
            case 2: printf("\nInorder:\n\n"); AusgabeInorder();
                    break;
            case 3: printf("\nPostorder:\n\n"); AusgabePostorder();
                    break;
            case 4: return;
        }
    }
    PAUSE;
}
