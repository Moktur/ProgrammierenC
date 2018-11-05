
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-22, Zeiger auf Funktionen 
/*
/*      Konzepte/       Zeiger auf Funktionen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt den Umgang mit Zeigern auf
/*                      Funktionen: Wie wird ein Zeiger auf eine Funktion
/*                      definiert, welche Werte koennen ihm zugewiesen werden
/*                      und wie wird die Funktion ueber den Zeiger aufgerufen.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>        /* Enthaelt Ein- und Ausgabefunktionen */
#include <math.h>         /* Enthaelt mathematische Funktionen */
#include <ctype.h>        /* Enthaelt Funktionen fuer Zeichenmanipulation */
                          /* hier benutzt: tolower */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

double Sinus(double x);
double Cosinus(double x);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen  */
    double zahl;
    double ergebnis;
    char   wahl;
    /* fkt ist ein Zeiger auf eine Funktion, die als Parameter ein double
       verlangt und ein double zurueckliefert */
    double (*fkt)(double) = NULL;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-22, Zeiger auf Funktionen --------------\n\n");

    printf("\nDas Programm benutzt Zeiger auf Funktionen.\n");
    printf("\nBitte geben Sie eine reelle Zahl ein, und entscheiden Sie dann,");
    printf("\nob ich den Sinus oder den Cosinus der Zahl berechnen soll.\n\n");

    /* Eingabe */
    printf("Zahl: ");
    scanf_s("%lf", &zahl);
    do
    {		
		fflush(stdin);
        printf("(s)inus oder (c)osinus berechnen: ");
        scanf_s("%c", &wahl, 1);
        /* Unterscheide nicht zwischen Gross- und Kleinschreibung */
        wahl = tolower(wahl);
    } while (wahl != 's' && wahl != 'c');

    /* Auswahl der richtigen Funktion */
    switch (wahl)
    {
        case 's': printf("\nIch berechne den Sinus von %lf\n", zahl);
                  /* fkt zeigt auf die Funktion Sinus() */
                  fkt = Sinus;
                  break;
        case 'c': printf("\nIch berechne den Cosinus von %lf\n", zahl);
                  /* fkt zeigt auf die Funktion Cosinus() */
                  fkt = Cosinus;
                  break;
    }

    /* Aufruf der Funktion ueber den Zeiger fkt */
    ergebnis = fkt(zahl);
    /* Ergebnis ausgeben */
    printf("\nDas Ergebnis ist: %lf\n\n", ergebnis);
    PAUSE;
}

/* Funktion Sinus,
   berechnet den Sinus einer Zahl */
double Sinus(double x)
{
    /* Rueckgabewert liefern */
    return sin(x);
}

/* Funktion Cosinus,
   berechnet den Cosinus einer Zahl */
double Cosinus(double x)
{
    /* Rueckgabewert liefern */
    return cos(x);
}

/*****************************************************************************/
/* Aufgaben:
/******************************************************************************

  1) Entfernen Sie die Funktionsdeklarationen von Sinus und Cosinus und ueber-
     setzten Sie das Programm erneut. Welcher Fehler erscheint und warum?
  2) Versuchen Sie, der Variablen fkt einen anderen Wert als einen Funktions-
     namen zuzuweisen. Was passiert bei der Compilation und der Ausfuehrung?
  3) Erweitern Sie die Auswahl der Funktionen um den Tangens (tan)

******************************************************************************/
