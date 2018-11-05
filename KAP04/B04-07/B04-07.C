
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       04-07, persoenliche Daten
/*
/*      Konzepte/       Funktionen scanf und printf
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm fragt persoenliche Daten ab und gibt
/*                      sie in tabellarischer und in Textform wieder.
/*                      Zur Definition und zum Umgang mit Zeichenketten
/*                      vgl. Kap 8.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar(); }

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    char name[32], vorname[32], geb_ort[32];
    unsigned int geb_jahr, geb_monat, geb_tag;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-07, persoenliche Daten -----------------\n\n");

    printf("\nDas Programm liest und gibt persoenliche Daten aus.");
    printf("\nHierzu benutzt es die Funktionen scanf und printf.\n");
    /* Abfrage der Daten */
    printf("\nIch werde Sie nun nach ein paar persoenlichen Daten fragen:");
    printf("\n\nName:                    ");
    scanf_s("%s", name, 31);
    printf("Vorname:                 ");
    scanf_s("%s", vorname, 31);
    printf("Geburtstag (tt.mm.jjjj): ");
    scanf_s("%u.%u.%u", &geb_tag, &geb_monat, &geb_jahr);
    printf("Geboren in:              ");
    scanf_s("%s", geb_ort, 31);

    /* Ausgabe der Daten in tabellarischer Form */
    printf("\n\n");
    printf("Ihre Daten in tabellarischer Form:\n");
    printf("\nName:\t\t%s", name);
    printf("\nVorname:\t%s", vorname);
    printf("\ngeboren am:\t%02u.%02u.%u", geb_tag, geb_monat, geb_jahr);
    printf("\ngeboren in:\t%s", geb_ort);
    
    /* Ausgabe der Daten in Textform */
    printf("\n\n\n");
    printf("Ihre Daten in Textform:\n");
    printf("\nSie heissen %s %s und Sie\n", vorname, name);
    printf("wurden am %02u.%02u.%u ", geb_tag, geb_monat, geb_jahr);
    printf("in %s geboren.\n", geb_ort);
    PAUSE;
}

