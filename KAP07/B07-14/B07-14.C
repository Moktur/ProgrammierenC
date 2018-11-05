
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-14, Lohntuete
/*
/*      Konzepte/       Funktionsaufruf mit Werterueckgabe
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm zerlegt einen eingegebenen Geldbetrag in
/*                      DM in eine moeglichst geringe Anzahl von Geldscheinen
/*                      und -stuecke
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void Ausgabe(void);
unsigned short LeseBetragEin(void);
unsigned short Anzahl(int Betrag, int Divisor);
unsigned short Rest(int Betrag, int Divisor);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

unsigned short Betrag;
unsigned short Tausender, Fuenfhunderter, Zweihunderter, Hunderter;
unsigned short Fuenfziger, Zwanziger, Zehner;
unsigned short Fuenfer, Zweier, Einer;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-14, Lohntuete --------------------------\n\n");

    printf("\nDas Programm zerlegt einen Geldbetrag in eine moeglichst geringe");
    printf("\nAnzahl von Geldscheinen und Muenzen.\n");

    /* Aufruf der Eingabe-Funktion */
    Betrag = LeseBetragEin();

    /* Berechne die Anzahl der Scheine sowie der Muenzen */
    Tausender      = Anzahl(Betrag, 1000); Betrag = Rest(Betrag, 1000);
    Fuenfhunderter = Anzahl(Betrag,  500); Betrag = Rest(Betrag,  500);
    Zweihunderter  = Anzahl(Betrag,  200); Betrag = Rest(Betrag,  200);
    Hunderter      = Anzahl(Betrag,  100); Betrag = Rest(Betrag,  100);
    Fuenfziger     = Anzahl(Betrag,   50); Betrag = Rest(Betrag,   50);
    Zwanziger      = Anzahl(Betrag,   20); Betrag = Rest(Betrag,   20);
    Zehner         = Anzahl(Betrag,   10); Betrag = Rest(Betrag,   10);
    Fuenfer        = Anzahl(Betrag,    5); Betrag = Rest(Betrag,    5);
    Zweier         = Anzahl(Betrag,    2); Betrag = Rest(Betrag,    2);
    Einer          = Anzahl(Betrag,    1);

    /* Aufruf der Ausgabe-Funktion */
    Ausgabe();
    PAUSE;
}

/* Funktion LeseBetragEin
   liest den Betrag in DM ein, der zerlegt werden soll */
unsigned short LeseBetragEin(void)
{
    /* lokale Variablen definieren */
    unsigned short Betrag; /* speichert die Eingabe */

    /* Anweisungen */
    printf("\n");

    /* Lese den aufzuteilenden Betrag ein */
    do
    {
        /* Betrag abfragen */
		printf("Geben Sie den ganzzahligen Betrag ein (0 - 50000): ");
        scanf_s("%hd", &Betrag);
    }
    /* Solange, bis Betrag gueltig ist; hier wird gefordert: Betrag <= 50000 */
    while (Betrag > 50000);

    /* Rueckgabewert liefern */
    return Betrag;
}

/* Funktion Anzahl
   berechnet die Anzahl der benoetigten Geldscheine und -stuecke einer
   bestimmten Sorte */
unsigned short Anzahl(int Betrag, int Divisor)
{
    /* Lokale Variable definieren */
    int Anzahl;

    /* Anweisungen */

    /* Berechne die Anzehl der benoetigten Scheine */
    Anzahl = Betrag / Divisor;

    /* Rueckgabewert liefern */
    return Anzahl;
}

/* Funktion Rest
   berechnet den Restbetrag, der noch aufzuteilen ist */
unsigned short Rest(int Betrag, int Divisor)
{
    /* Anweisungen */

    /* Berechne Restbetrag */
    Betrag %= Divisor;

    /* Rueckgabewert liefern */
    return Betrag;
}

/* Funktion Ausgabe
   gibt Anzahl der benoetigten Geldscheine bzw. -stuecke am Bildschirm aus */
void Ausgabe(void)
{
    /* Anweisungen */

    printf("\n\nFolgende Geldscheine und -stuecke werden benoetigt:\n");
    printf("\nTausender:      %2hu", Tausender);
    printf("\nFuenfhunderter: %2hu", Fuenfhunderter);
    printf("\nZweihunderter:  %2hu", Zweihunderter);
    printf("\nHunderter:      %2hu", Hunderter);
    printf("\nFuenfziger:     %2hu", Fuenfziger);
    printf("\nZwanziger:      %2hu", Zwanziger);
    printf("\nZehner:         %2hu", Zehner);
    printf("\nFuenfer:        %2hu", Fuenfer);
    printf("\nZweier:         %2hu", Zweier);
    printf("\nEiner:          %2hu\n\n", Einer);
}
