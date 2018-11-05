
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-12, Quadratwurzel nach Archimedes
/*
/*      Konzepte/       Funktionsaufruf mit Parameter und Wertrueckgabe
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm berechnet die Quadratwurzel einer
/*                      Zahl mit einem nach Archimedes benannten Iterations-
/*                      verfahren. Einzugeben sind die Zahl und die
/*                      Genauigkeit, um die das Ergebnis vom wahren Wert
/*                      abweichen darf.
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

double archimed(double zahl, double epsilon);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    double zahl, epsilon, resultat;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-12, Quadratwurzel nach Archimedes ------\n\n");

    printf("\nDas Programm berechnet mit einem nach ARCHIMEDES benannten");
    printf("\nIterationsverfahren die Quadratwurzel einer Zahl.");
    printf("\nAlle Eingabedaten werden als positive reelle Werte erwartet.\n");

    /* Eingabe der Werte */
    printf("\nZu welcher Zahl soll die Quadratwurzel bestimmt werden:     ");
    scanf_s("%lf", &zahl);

    printf("Vorgegebene absolute Fehlerschranke, d.h.");
    printf("\n  max. Betrag der Differenz wahrer Wert - berechneter Wert: ");
    scanf_s("%lf", &epsilon);

    if (zahl < 0 || epsilon < 0)
      {  printf("\n\nFalsche Eingabe!");
          PAUSE;
          return;
      }

    /* Berechnen und Ergebnis ausgeben */
    resultat = archimed(zahl, epsilon);
    printf("\n\nDie Quadratwurzel von %.10lf betraegt %.10lf.\n\n",
    zahl, resultat);
    PAUSE;
}

/* Funktion archimed
   berechnet die Quadratwurzel einer Zahl */
double archimed(double zahl, double epsilon)
{
    /* Lokale Variablen definieren */
    double xneu, xalt, d;
    int    i = 0;

    /* Anweisungen */
    xneu = zahl;

    /* Berechnung der Quadratwurzel */
    do
    {
        i++;
        xalt = xneu;
        xneu = 0.5f * (xalt + zahl / xalt);
        if (xalt > xneu)
            d = xalt - xneu;
        else
            d = xneu - xalt;

          printf("\n>>> %d-te Iteration <<<", i);
          printf("\nalte Loesung: %.15f", xalt);
          printf("\nneue Loesung: %.15f", xneu);
          printf("\nDifferenz:    %.15f\n", d);

        /* Warte auf Tastendruck */
          PAUSE;
    }
    while (d > epsilon);

    /* Rueckgabewert liefern */
    return xneu;
}

/*****************************************************************************/
/* Aufgaben
/******************************************************************************

  1) Schreiben Sie das Programm so um, dass der Austausch der Werte fuer
     die Funktion "archimed" ueber globale Variablen stattfindet.
  2) - Kommentieren Sie die Funktionsdeklaration von "archimed" aus und
       uebersetzen Sie das Programm erneut.
     - Tauschen Sie die Funktionsdefinitionen von "main" und "archimed"
       und uebersetzen Sie das Programm erneut.
     Wann erscheint welche Fehlermeldung und warum?
     
******************************************************************************/
