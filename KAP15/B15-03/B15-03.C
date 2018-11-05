
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       15-03, stdarg.h
/*
/*      Konzepte/       Standard-Bibliothek, stdarg.h
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt die Definition und Anwendung von
/*                      Funktionen mit variablen Parameterlisten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>        /* Enthaelt Ein- und Ausgabefunktionen */
#include <stdarg.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

long Summe(int a, ...);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    long summe;

    /* Anweisungen */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 15-02, stdarg.h ---------------------------\n\n");
    printf("\nDas Programm zeigt eine Funktion mit variabler Argument-\n");
    printf("anzahl. Die Funktion addiert eine Reihe von Zahlen, die ihr\n");
    printf("als Parameter uebergeben werden. Damit die Funktion das Ende\n");
    printf("der Parameterliste erkennt, muss der letzte Parameter eine\n");
    printf("0 sein.\n");

    /* Berechnung der Summen */
    summe = Summe(2, -3, 4, -5, 6, 0);
    printf("\nDie Summe von (2, -3, 4, -5, 6, 0) ist: %ld\n", summe);
    summe = Summe(-8, 3, 0);
    printf("\nDie Summe von (-8, 3, 0) ist: %ld\n", summe);

    PAUSE;
}

/*****************************************************************************/
/* Funktion: summe
/*  Berechnet die Summe aller uebergebenen Argumente. Die Funktion verlangt
/*  als letztes Argument eine Null, damit sie weiss, wann die Argumentliste
/*  zu Ende ist.
/*  Die Argumente werden der Reihe nach in einem bestimmten Speicherbereich
/*  gespeichert, von wo aus sie mit den Funktionen va_start, va_arg und
/*  va_end gelesen werden. Wenn die Funktion nicht eine 0 als letzten
/*  Parameter hat, wird weiter in einem nicht initialisierten Speicherbereich
/*  gelesen, bis zufaellig eine 0 gefunden wird.
/*****************************************************************************/

long Summe(int a, ...)
{
    /* Lokale Variablen definieren */
    int  summand;
    long summe = 0;     /* Speichert die Summe */
    va_list parameter;  /* zeigt nacheinander auf jedes unbekannte Argument */

    /* Anweisungen */

    /* Erster Summand ist bekannt */
    printf("\nIch addiere %d", a);
    summe += a;

    /* Wenn erstes Argument schon 0 war, dann abbrechen */
    if (a == 0)
        return summe;

    /* Starte die Abarbeitung der unbekannten Parameterliste */
    va_start(parameter, a);  /* parameter zeigt nun auf das erste unbekannte
                                Argument, a ist das letzte bekannte Argument */

    /* Bearbeitet der Reihe nach alle Argumente, bis 0 als Abschluss gefunden
       wird */
    do
    {
        /* Bestimme den Wert des naechsten Parameters */
        summand = va_arg(parameter, int);
        printf("\nIch addiere %d", summand);
        summe += summand;
    }
    while (summand != 0);

    /* Beende die Abarbeitung der unbekannten Parameterliste */
    va_end(parameter);

    /* Rueckgabewert liefern */
    return summe;
}

/*****************************************************************************/
/* Aufgaben:
/******************************************************************************

  Entfernen Sie im Funktionsaufruf der Funktion Summe den letzten Parameter
  (die abschliessende Null), und schauen Sie, wie sich das Programm verhaelt.

******************************************************************************/
