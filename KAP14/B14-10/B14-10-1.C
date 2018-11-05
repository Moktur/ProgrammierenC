
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-10, Patientenwarteschlange
/*
/*      Konzepte/       einfach verkettete unsortierte Liste, Schlange,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm realisiert eine Schlange als
/*                      einfach verkettete unsortierte Liste.
/*
/*                      Ein gutes Beispiel fuer eine Schlange ist eine
/*                      Arztpraxis, in der die Patienten in der Reihenfolge
/*                      behandelt werden, in der sie sich an der Rezeption
/*                      angemeldet haben. Die Schwester traegt die Daten des
/*                      Patienten an ihrem Computer ein und der Arzt ruft
/*                      die Daten bei der Behandlung des Patienten wieder
/*                      ab.
/*
/*                      Das Programm umfasst die 3 Dateien
/*                      - B14-10-1.c,
/*                      - B14-10-2.c und
/*                      - B14-10-2.h.
/*                      Zur Erzeugung eines ausfuehrbaren Programms sind
/*                      die Dateien B14-10-1.c und B14-10-2.c zu binden.
/*
/*                      Das Programm benutzt den ADT Patientenschlange, der
/*                      durch die Dateien B14-10-2.c und B14-10-2.h definiert
/*                      ist. Die Datei B14-10-1.c stellt einen Anwendungsmodul
/*                      fuer den ADT dar.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdio.h>
#include <string.h>

/* Definitionsdatei fuer den ADT Patientenschlange einbinden */
#include "B14-10-2.h"

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
/*   Eine Beispielanwendung fuer die Schlange.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void main (void)
{
    /* Lokale Variablen definieren */
    char name[30];
    char beschwerden[30];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-10, Patientenschlange ------------------\n\n");
    printf("\nDasProgramm realisiert eine Schlange als einfach verkettete");
    printf(" Liste\n");

    /* Schiebe Daten des Patienten in die Schlange */
    printf("\nGeben Sie die Namen und die Beschwerden (jeweils bis zu ");
    printf("29 Zeichen\nohne Blanks) der Patienten ein, die ");
	 printf("sich an der Rezeption anmelden.\nBrechen Sie die Eingabe mit ");
    printf("einem * als Namen ab.\n");
    do
    {
        /* Frage nach den neuen Daten */
        printf("\nWie lautet der Name des Patienten: ");
		scanf_s("%s", name, 29);
        /* Wenn nicht die Eingabe nicht abgebrochen wurde */
        if (strcmp(name, "*") != 0)
        {
            /* Frage den Rest des Daten ab */
            printf("Welche Beschwerden hat der Patient: ");
			scanf_s("%s", beschwerden, 29);
            /* Schiebe diese Daten in die Schlange */
            rear(name, beschwerden);
        }
    }
    while (strcmp(name, "*") != 0);

    /* Hole die Daten aus der Schlange, bis diese leer ist */
    printf("\nIch hole die Daten alle wieder aus der Schlange:\n");
    while(Anzahl() > 0)
    {
        front(name, beschwerden);
        printf("Name: %-25s    Beschwerden: %-25s\n", name, beschwerden);
    }
    printf("\n\n");
    PAUSE;
}
