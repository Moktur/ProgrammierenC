
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-09, Autokauf
/*
/*      Konzepte/       if-else-Anweisung
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm entscheidet je nach Ihren Eingaben,
/*                      ob sich der Kauf eines bestimmten Autos lohnt.
/*                      In If-Abfragen wird entschieden, ob das Auto
/*                      bestimmten Kriterien entspricht und die Anzahl der
/*                      Entsprechungen wird ggf. erhoeht. Abschliessend
/*                      wird eine Empfehlung gegeben.
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
    int tueren, farbe, zaehler = 0;
    long int preis;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-09, Autokauf ---------------------------\n\n");

    printf("\nDas Programm leistet Entscheidungshilfe bei einem Autokauf.");
    printf("\nBevorzugt werden: Farbe rot, vier Tueren, Preis < 25.000 EUR.");
    printf("\nGeprueft wird die Einhaltung dieser Kriterien.\n");

    /* formatierte Ein- und Ausgabe */
    printf("\nWieviele Tueren hat das Auto?  ");
    scanf_s("%d", &tueren);
    printf("\nIst das Auto rot?\nGeben Sie 1 fuer ja oder 0 fuer nein ein:  ");
    scanf_s("%d", &farbe);
    printf("\nBitte den Preis in ganzen EUR angeben: ");
    scanf_s("%ld", &preis);
    printf("\n\n");

    /* if-else-Anweisungen */

    /* hat der Wagen 4 Tueren, so wird der Ausdruck mit 1 bewertet (true)
       und der zaehler wird um eins erhoeht */
    if (tueren == 4)
        zaehler++;
    /* ist die Bedingung 0 (false) tritt der else-Fall ein und die folgende
       printf-Anweisung wird bearbeitet */
    else
        printf("\nDas Auto hat keine 4 Tueren!");

    /* ist farbe gleich 1, so ist die Bedingung wahr; bei 0 tritt der 
       else-Fall ein */
    if (farbe)
        zaehler++;
    else
        printf("\nDas Auto ist nicht rot!");

    /* ist preis kleiner 25000, so ist die Bedingung wahr; wenn das nicht der
       Fall ist tritt der else-Fall ein */
    if (preis < 25000)
        zaehler++;
    else
        printf("\nDas Auto ist sehr teuer!");

    printf("\n\n");

    /* IF und ELSE IF */
    /* Nun werden unterschiedliche Faelle behandelt, es wird aber nur zu einer
       printf-Anweisung verzweigt */
    if (zaehler == 3)
        printf("\nDas Auto erfuellt alle Anforderungen, schlagen Sie zu.");
    else if (zaehler == 2)
        printf("\nDas Auto erfuellt die meisten Anforderungen.");
    else if (zaehler == 1)
        printf("\nEine schwere Entscheidung - ueberlegen Sie gut.");
    else if (zaehler == 0)
        printf("\nFinger weg von diesem Auto !!!\n\n");
    PAUSE;
}
