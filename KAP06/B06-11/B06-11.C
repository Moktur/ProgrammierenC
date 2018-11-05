
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-11, Bonbonpreisentwicklung
/*
/*      Konzepte/       while-Schleife
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm berechnet, wie lange es dauert, bis
/*                      aufgrund der Inflation der Preis einer gewissen 
/*                      Bonbonsorte einen bestimmten Betrag ueberschreitet
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
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    float bonbonpreis, inf_rate, preisgrenze;
    int jahre = 0;      /* Jahre wird auf 0 initialisiert */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-11, Bonbonpreisermittlung --------------\n\n");

    printf("\nDas Programm ermittelt, nach wieviel Jahren ein Bonbon");
    printf("\nmit einem gegebenen aktuellen Preis eine bestimmte Preisgrenze");
    printf("\nfuer eine angenommene Inflationsrate ueberschreitet.\n");

    /* Abfrage der Startwerte */
    printf("\nBitte folgende Daten zur Bonbonpreisentwicklung eingeben!");
    printf("\nHeutiger Preis eines Bonbons (EUR.Pf): ");
    scanf_s("%f", &bonbonpreis);
    printf("Inflationsrate in Prozent (x.y): ");
    scanf_s("%f", &inf_rate);
    printf("Preisgrenze fuer das Bonbon (EUR.Pf): ");
    scanf_s("%f", &preisgrenze);

    printf("\nEin Bonbon, das heute %.2f EUR kostet,\n", bonbonpreis);
    printf("kostet bei einer Inflationsrate von %.2f Prozent", inf_rate);

    /* Solange der Preis unterhalb der Grenze liegt*/
    while (bonbonpreis < preisgrenze)
    {
        bonbonpreis += bonbonpreis * inf_rate/100;  /* Berechne neuen Preis */
        jahre++;                                    /* Erhoehe jahre um eins */
    }

    /* Das Ergebnis ausgeben */
    printf("\nnach %d Jahren %.2f EUR.\n\n", jahre, bonbonpreis);
    PAUSE;
}
