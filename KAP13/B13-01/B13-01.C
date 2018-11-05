
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-01, ASCII-Tabelle
/*
/*      Konzepte/       lokale static-Variablen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Programm gibt ASCII-Zeichen von Code-Nr. 33 bis 128
/*                      aus, Anwendung lokaler static-Variablen
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

int zeige_zeichen(void);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 13-01, ASCII-Tabelle ----------------------\n\n");

    printf("\nDas Programm listet ASCII-Zeichen von Code-Nr. 33 bis 128 auf.\n");
    while(zeige_zeichen())
        { ; }
    PAUSE;
}

/* Funktion zeigt ein ASCII-Zeichen, erhoeht static-Zaehler */
int zeige_zeichen(void)
{
    static zaehler = 33; /* zaehler als static-Variable vereinbaren */

    if (zaehler % 10 == 3) printf("\n\t"); /* 10 Zeichen pro Zeile */
        printf("%c ",zaehler++); /* Zeichen ausgeben und Zaehler erhoehen */

    return (zaehler < 129 ? 1 : 0);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Verdoppeln Sie die while-Schleife in main. Lassen Sie das
    Program erneut laufen. Was passiert und wie ist das Resultat
    zu erklaeren?
  - Wie koennen die Funktionen zeige_zeichen und main so abgeaendert
    werden, dass mit zwei while-Schleifen in main (sowie zwei
    zusaetzlich Aufrufen von zeige_zeichen) der einfache
    ASCII-Code ab Zeichen 33 zweimal ausgegeben wird? Hinweis:
    als Parameter an zeige_zeichen uebergebener Schalter.
  - Aendern Sie die Funktion zeige_zeichen so ab, dass auch noch
    Zeichen mit Code-Nummern groesser als 128 ausgegeben werden.

******************************************************************************/
