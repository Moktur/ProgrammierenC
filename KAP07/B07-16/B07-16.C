
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-16, Fibonacci-Zahlen
/*
/*      Konzepte/       rekursiver Funktionsaufruf zur
/*      Sprachelemente: Berechnung der Fibonacci-Zahlen
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:
/*
/*      Der italienische  Mathematiker Fibonacci  hat sich  im 13. Jahrhundert
/*      mit dem auch heute noch aktuellen Thema der Bevoelkerungsexplosion be-
/*      schaeftigt. Er  versuchte, das Wachstum einer  Kaninchenpopulation aus
/*      einem Kaninchenpaar  vorherzusagen. Dabei ging  er davon aus, dass die
/*      Tragezeit bei Kaninchen ein  Monat dauert und dass  Kaninchen im Alter
/*      von einem  Monat geschlechtsreif  und zugleich  auch traechtig werden.
/*      Weiterhin nahm er an, dass jedes  Kaninchenpaar zwei Kinder, ein weib-
/*      liches und ein maennliches, bekommt.  Die Population, d. h. die Anzahl
/*      der  Kaninchenpaare in  einem gegebenen  Monat,  ergibt sich  dann als
/*      Summe der  Paare des Vormonats und der aktuellen Anzahl  der geborenen
/*      Paare,  die  genau der  Paaranzahl vor  zwei Monaten  entspricht.  Die
/*      Geburten des Vormonats werden erst in diesem Monat geschlechtsreif. In
/*      den ersten beiden Monaten ist  die Population jeweils 1, da die Stamm-
/*      eltern erst zu Eltern heranreifen muessen.
/*
/*      Die Bildungsvorschrift fuer die Fibonacci-Zahlen lautet demnach:
/*
/*          fib(1) = 1                      Anzahl der Paare im 1. Monat
/*          fib(2) = 1                      Anzahl der Paare im 2. Monat
/*          fib(n) = fib(n-2) + fib(n-1)    Anzahl der Paare in den folgenden
/*                                          Monaten (n >= 3)
/*
/*     Die ersten 7 Fibonacci-Zahlen ergeben sich hiernach wie folgt:
/*          1, 1, 2, 3, 5, 8, 13
/*
/*      Bemerkung:    	Der Laufzeitfehler "Run-Time Check Failure #2
/*						- Stack around the variable 'nzahl' was corrupted."
/*						tritt nur in der Debug-Version auf und kann vernachlässigt 
/*                      werden. Einfach auf weiter klicken.
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

unsigned long int fib(unsigned int n);   /* Berechnet die n-te Fibonnaci-Zahl */

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

unsigned long int call = 0; /* Zaehlt die Funktionsaufrufe von fib(n) */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    unsigned char nzahl;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-16, Fibonacci-Zahlen -------------------\n\n");
    printf("\nDas Programm berechnet rekursiv die Fibonacci-Zahlen.\n\n");

    /* Frage den zu berechnenden Monat ab */
    printf("Die wievielte Fibonacci-Zahl soll berechnet werden (1 - 255)? ");
    scanf_s("%hu", &nzahl);

    printf("\nIch berechne nun Fib(%hu).", nzahl);
    printf(" Das kann eine Weile dauern...\n");

    /* Gib das Ergebnis am Bildschirm aus */
    printf("\nFib(%hu) = %lu.\n", nzahl, fib(nzahl));
    printf("%lu Funktionsaufruf(e) war(en) noetig.\n", call);
    PAUSE;
}

/* Funktion fib
   berechnet die n-te Fibonacci-Zahl */
unsigned long int fib(unsigned int n)
{
    /* Anweisungen */

    /* Aufrufe zaehlen */
    call++;

    /* Berechne die Fibonacci-Zahl */
    if (n > 2)
        /* rekursiver Aufruf der Funktion */
        return (fib(n-1) + fib(n-2));
    else
        /* Im 1. und 2. Monat ist das Ergebnis bekannt */
        return 1;
}

/*****************************************************************************/
/* Notiz
/******************************************************************************
  Da bei der rekursiven Ermittlung der Fibonacci-Zahlen jeder Aufruf
  der Funktion fib  zwei weitere nach sich zieht, waechst die Anzahl der 
  Aufrufe exponentiell an. Rekursion ist daher kein geeignetes Mittel zur 
  Berechnung der Fibonacci-Zahlen, die iterativ (in einer Schleife) effizient
  bestimmt werden koennen. Haben Ihre iterative Berechnung und die Zeitmessung
  dies bestaetigt?  
******************************************************************************/
