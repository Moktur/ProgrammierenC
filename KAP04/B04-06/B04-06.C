
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       04-06, Formatierte Eingabe
/*
/*      Konzepte/       Formatierte Eingabe mit der Funktion scanf
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
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

void main(void)
{
    /* lokale Variablen */
    int   dzahl1, dzahl2;   /* 2 int-Variablen */
    float gzahl1, gzahl2;   /* 2 float-Variablen */
    char  zeichen;          /* 1 char-Variable */
    char  wort[20];         /* 1 Zeichenkettenfeld, wird in Kap. 8 behandelt */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-06, Eingabe mit scanf ------------------\n");

    printf("\nDas Programm demonstriert die Eingabe mit scanf.\n");
    printf("\nBitte jede Eingabe mit Return beenden!");
    printf("\nBitte mehrere eingegebene Zahlen durch Blanks trennen.");

    /* 1. Ganze Zahlen einlesen */
    printf("\n\nBitte zwei ganze Zahlen eingeben (z.B. 21 54): ");
    /* Einlesen zweier ganzer Zahlen in die Variablen dzahl1 und dzahl2 */
    scanf_s("%d %d", &dzahl1, &dzahl2);
    printf("Zahl Nr.1: %d und Zahl Nr.2: %d \n\n", dzahl1, dzahl2);

    /* 2. Gleitkommazahlen einlesen */
    printf("\nBitte zwei reelle Zahlen eingeben (z.B. 1.3 7.8): ");
    /* Einlesen zweier Gleitpunktzahlen in die Variablen gzahl1 und gzahl2 */
    scanf_s("%f %f", &gzahl1, &gzahl2);
    printf("Zahl Nr.1: %5.2f und Zahl Nr.2: %7.3f\n\n", gzahl1, gzahl2);

    /* 3. Rueckgabewert von scanf ermitteln */
    /*    Bemerkung: da der Rueckgabewert die Anzahl gelesener Werte
          angibt, kann er zur Kontrolle von scanf benutzt werden */
    printf("\nBitte nochmals zwei reelle Zahlen eingeben: ");
    /* Anzahl der abgearbeiteten Eingaben wird an dzahl1 geliefert */
    dzahl1 = scanf_s("%f %f", &gzahl1, &gzahl2);
    printf("Ihre Eingabe hatte %d Zahlen\n\n", dzahl1);

	fflush(stdin);

    /* 4. Abfrage eines einzelnen Zeichens (1. Version) */
    printf("\nBitte einen Buchstaben eingeben: ");
    /* Einlesen eines einzelnen Zeichens */
    scanf_s("%c", &zeichen, 1);
    printf("Sie haben ein -%c- eingegeben.\n\n", zeichen);

    /* 5. Texteingabe zeilenweise */
    printf("\nGeben Sie einen beliebigen Text zeilenweise ein. ");
    printf("\nJede Zeile muss mit Return abgeschlossen werden und ");
    printf("\nkann beliebig viele Leerzeichen enthalten.");
    printf("\nBeenden Sie den Text, indem Sie einen '*' eingeben.");
    printf("\nAusgegeben werden pro Zeile die ASCII-Nummern aller Zeichen.");
    printf("\nDer erste ASCII-Code (10) stammt noch von Ihrer letzten");
    printf("\nEingabe.\n");
    /* Bemerkung: Die do-while-Schleife wird in Kap. 6 besprochen! */

    do
    {
        scanf_s("%c", &zeichen, 1);
        printf("ASCII-Code der letzten Eingabe -> %d <-\n", zeichen);
    }
    while (zeichen != '*');

    /* 6. Zeichenketten einlesen, wird in Kap. 8 gruendlich behandelt! */
    printf("\nBitte einen Text OHNE Zwischenraum eingeben (z.B. test): ");
    /* Einlesen eines einzigen Worts */
    scanf_s("%s", &wort, 19);
    printf("Was ein(e) -%s- ist, weiss ich leider nicht...", wort);

    /* Wenn doch ein Text mit Zwischenraum eingegeben wird, wird nur das erste
       Wort abgefangen. Das zweite Wort wird mit der naechsten scanf-Anweisung
       abgefragt, das dritte mit der uebernaechsten und so weiter */
    printf("\n\nBitte zwei Woerter getrennt durch einen Zwischenraum");
    printf(" eingeben: \n");
    /* Einlesen eines einzigen Wortes */
    scanf_s("%s", &wort, 19);
    printf("Das erste Wort war ein -%s- ...", wort);
    /* Einlesen eines einzigen Wortes: erst hier wird das zweite Wort des
       Textes abgefragt */
    scanf_s("%s", &wort, 19);
    printf("\nDas zweite Wort war ein -%s- ...\n", wort);

    /* 7. Zeichenkette ohne Adress-Operator einlesen */
    /*    Bemerkung: der Operator '&' wird als Adress-Operator bezeichnet.
          Er wird in Kap. 10 behandelt. Hier ist nur zu merken, dass er
          bei scanf benoetigt wird - siehe die vorigen Beispiele.
          Allerdings koennen Zeichenketten auch OHNE Adressoperator
          eingelesen werden. Siehe folgendes Beispiel. */

    /* Parameter OHNE Adress-Operator '&': */
    printf("\nGeben Sie ein Wort ein: ");
    scanf_s("%s", &wort, 19);
    printf("Was ein(e) -%s- ist, weiss ich leider nicht...", wort);

    printf("\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Versuchen Sie, auch fuer die Positionen 1 - 4 Eingaben ohne den
  Adressoperator '&' auszufuehren. Wie reagieren der Compiler und das
  Programm in diesen Faellen?

******************************************************************************/
