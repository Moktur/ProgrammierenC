
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-08, Dauerkalender
/*
/*      Konzepte/       zweidimensionales Feld,
/*      Sprachelemente: Indexzugriffe auf Feldelemente
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm berechnet den Wochentag eines beliebigen
/*                      eingegebenen Datums ab dem 01.01.1898
/*
/*****************************************************************************/

/* Algorithmus Dauerkalender, 0. Verfeinerung mit EVA-Schema

BIBLIOTHEKSIMPORTE;
GLOBALE VEREINBARUNGEN;

main()
{
	 EINGABE DES GESUCHTEN DATUMS;
	 BERECHNUNG DES WOCHENTAGES;
	 AUSGABE DES WOCHENTAGES;
}

*/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Feld global definieren
/*****************************************************************************/

/* Hilfsfeld fuer die Berechnung des Datums */
int tabelle[28][12] =
    {{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
     {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
     {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
     {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
     {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
     {4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
     {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
     {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
     {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
     {2, 5, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1}};


/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int tag, monat, jahr, j, schluessel, wochentag;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-08, Dauerkalender ----------------------\n\n");

    printf("\nDas Programm bestimmt den Wochentag zu einem beliebigen ");
    printf("\nDatum ab dem 01.01.1898.\n");

    /* Eingabe des zu untersuchenden Datums */
    printf("Bitte geben Sie ein Datum in der Form TT.MM.JJJJ ein: ");
    scanf_s("%d.%d.%d", &tag, &monat, &jahr);

    if (tag < 1 || tag > 31 ||
          monat < 1 || monat > 12 ||
          jahr < 1898)
      {  printf("\nUnzulaessige Eingabe!");
          PAUSE;
          return;
      }

    /* Berechne Wochentag */
    j = (jahr - 1897) % 28;
    schluessel = tabelle[j][monat - 1];
    wochentag = (schluessel + tag) % 7;

    /* Ergebnis am Bildschirm ausgeben */
    printf("\nDer %02d.%02d.%4d ist/war/wird ein ", tag, monat, jahr);
    switch (wochentag)
    {
        case 0: printf("Samstag!\n");    break;
        case 1: printf("Sonntag!\n");    break;
        case 2: printf("Montag!\n");     break;
        case 3: printf("Dienstag!\n");   break;
        case 4: printf("Mittwoch!\n");   break;
        case 5: printf("Donnerstag!\n"); break;
        case 6: printf("Freitag!\n");    break;
    }
    PAUSE;
}
