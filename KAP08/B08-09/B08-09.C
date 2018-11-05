
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-09, Zeichenkettenfunktionen
/*
/*      Konzepte/       Funktionen aus der Bibliothek string.h
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt den Gebrauch einiger wichtiger
/*                      Funktionen aus der string.h-Bibliothek.
/*                      Zur Erlaeuterung dieser Funktionen siehe Kommentare.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funktionen fuer die Stringmanipulation */

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
    char text_1[40] = "alpha";
    char text_2[40] = "beta";
    char text_3[40] = "gamma";
    char text_4[40] = "";
    int result;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-09, Zeichenkettenfunktionen ------------\n\n");
    printf("Das Programm zeigt die Benutzung von Zeichenkettenfunktionen.\n");

    /* Ausgabe der Inhalte der Zeichenketten */
    printf("\nDie Zeichenketten wurden folgendermassen initialisiert:");
    printf("\n\ttext_1: %s", text_1);
    printf("\n\ttext_2: %s", text_2);
    printf("\n\ttext_3: %s", text_3);
    printf("\n\ttext_4: %s", text_4);

    /* 
    strcpy(string_1, string_2):
        Kopiert den Inhalt von string_2 nach string_1
    */
    printf("\n\nIch kopiere die Zeichenkette text_1 nach text_4");
    strcpy_s(text_4, 39, text_1);
    printf("\n\ttext_4: %s", text_4);

    /*
    strcat(string_1, string_2):
        Haengt die Zeichenkette string_2 an string_1 an
    */
    printf("\n\nIch haenge nun die Zeichenkette text_2 an die Zeichenkette");
    printf(" text_4 an.");
    strcat_s(text_4, 39, text_2);
    printf("\n\ttext_4: %s", text_4);

    /*
    strcmp(string_1, string_2):
        Vergleicht die beiden Zeichenketten. Ist string_1 lexikographisch
        groesser als (steht im Alphabet nach) string_2, wird eine Zahl
        groesser Null zurueckgeliefert. Ist sie kleiner, wird eine Zahl
        kleiner Null, sind beide gleich wird, Null zurueckgeliefert.
    */
    printf("\n\nIch vergleiche nun die Zeichenkette text_1 mit der");
    printf("Zeichenkette text_2");
    result = strcmp(text_1, text_2);
    if (result > 0)
        printf("\n\ttext_1 ist lexikographisch groesser als text_2");
    else if (result < 0)
        printf("\n\ttext_1 ist lexikographisch kleiner als text_2");
    else /* result = 0 */
        printf("\ntext_1 und text_2 sind lexikographisch gleich");

    /*
    strlen(string_1):
        strlen liefert die Laenge der Zeichenkette string_1 ohne das
        abschliessende Zeichen '\0'
    */
    printf("\n\nIch bestimme nun die Laenge der Zeichenkette text_3");
    result = strlen(text_3);
    printf("\n\tLaenge der Zeichenkette text_3: %d\n\n", result);
    PAUSE;
}

/*****************************************************************************/
/*  Aufgaben
/******************************************************************************

  - Versuchen Sie, eine Zeichenkette mit der Laenge L2 in eine Zeichenkette
    der Laenge L1 zu kopieren, wobei L1 < L2 ist.
  - Versuchen Sie analog eine Zeichenkette an eine andere anzuhaengen, wobei
    die Laenge der Ergebniszeichenkette den vorgesehenen Platz
    ueberschreitet.
  - Die Zielzeichenkette muss stets lang genug sein, um das Ergebnis der
    entsprechenden Funktion (kopieren, anhaengen, usw.) aufnehmen zu koennen.
    Vergessen Sie bei Ihren Berechnungen der Laenge der Zeichenketten nie das
    Zeichen '\0', das an das Ende jeder Zeichenkette gehoert.

******************************************************************************/

