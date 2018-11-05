
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-13, Pyramide aus Zahlen
/*
/*      Konzepte/       rekursiver Aufruf einer Funktion
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm erzeugt eine Zahlenpyramide mit Hilfe
/*                      einer rekursiven Funktion. (Bei Zahlen > 9 wird die
/*                      Pyramide schief.)
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
/* Funktion deklarieren
/*****************************************************************************/

void pyramiden_zeile(int);

/*****************************************************************************/
/* Globale Variable definieren
/*****************************************************************************/

int i;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int anzahl, j;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-13, Pyramide aus Zahlen ----------------\n\n");

    printf("\nDas Programm zeichnet eine Zahlenpyramide.\n");

    /* Abfrage der Werte, bis ein gueltiger Wert eingegeben wurde */
    printf("\n");
    do
    {
		printf("Wieviele Zeilen soll die Pyramide hoch sein (1-9) ? ");
        scanf_s("%d", &anzahl);
    }
    while ((anzahl < 1) || (anzahl > 9));
    printf("\n\n");

    /* Hoehe des Dreiecks */
    for (i = 1; i <= anzahl; i++)
    {
        /* Bildschirmkosmetik */
        for (j = 20; j > i; j--)
            putchar(' ');
        pyramiden_zeile(1);   /* Aufruf der Funktion */
        printf("\n");         /* Zeilenumbruch fuer naechste "Etage" */
    }
    printf("\n");
    PAUSE;
}

/* Funktion: pyramiden_zeile
   zeichnet eine Zeile der Pyramide */
void pyramiden_zeile(int zahl)
{
    /* Anweisungen */
    printf("%d", zahl);            /* Ausgabe links */
    if (zahl < i)
        pyramiden_zeile(zahl + 1);  /* rekursiver Aufruf */
    if (zahl != i)
          printf("%d", zahl);        /* Ausgabe rechts */
}

/*****************************************************************************/
/* Aufgaben
/******************************************************************************

  1) Schreiben Sie eine Variante des Programms, die ohne die globale Variable
     "i" auskommt. Erweitern Sie hierzu die Parametrisierung der Funktion
     "pyramiden_zeile".
  2) Schreiben Sie eine Variante des Programms, bei der pro Zeile "i" nicht
     die Zahlenfolge 123...i...321, sondern die Folge 101...101 mit gleicher
     Laenge, d.h. 2 x i - 1 Nullen und Einsen ausgegeben werden.

******************************************************************************/
