
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-06, n-te Potenz von 2
/*
/*      Konzepte/       for-Schleife
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

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
    int  n,     /* Exponent */
         i;     /* Zaehler */
    long p;     /* Potenz */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-06, n-te Potenz von 2 ------------------\n\n");
    printf("\nDas Programm ermittelt die Potenz 2 hoch n.\n");

    /* Eingabe und Potenzierung in for-Schleife */
    printf("\nBitte Exponent n (0 <= n <= 20) eingeben: ");scanf_s("%d",&n);

    /* beachte: Initialisierung und Reinitialisierung mit ","-Operator */

    for (p = 1, i = n;  /* Potenz und Laufvariable initialisieren */
         i > 0;         /* Laufvariable i, Bereich: n >= i > 0 */
         p *= 2, i--)   /* Potenz mit 2 multiplizieren , i abwaerts zaehlen */
    { ; }               /* Leeranweisung im Schleifenrumpf */

    /* Ausgabe */
    printf("\nExponent n = %d,  Potenz 2**n = %ld", n, p);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  (1)Modifizieren Sie das Programm derart, dass der eingegebene Exponent n
     geprueft wird. Falls n nicht im (ganzzahligen) Intervall [0,20] liegt,
     soll der Exponent zurueckgewiesen und die Eingabe wiederholt werden.
     Verwenden Sie fuer die kontrollierte Exponenteneingabe eine do-while-
     Schleife. Warum ist dieser Schleifentyp fuer die Kontrolle von
     Eingabewerten besonders gut geeignet?
  (2)Fuer welchen maximalen Wert des Exponenten n kann 2**n mit dem Typ
     long noch korrekt berechnet werden? Erweitern Sie dementsprechend
     das zulaessige Exponentenintervall bei der Eingabe. Kann der maximale
     Exponent durch die Verwendung des Typs unsigned long noch vergroessert
     werden?
  (3)Sehen Sie ferner auch die Eingabe einer variablen ganzzahligen Basis b 
     im Bereich [2,4] vor. Legen Sie die Maximalwerte fuer den Exponenten 
     bezogen auf den Basiswert analog zu (2) geeignet fest. Lesen Sie die 
     Basis b zuerst ein und pruefen Sie den zugehoerigen Exponenten wie 
     unter (1) angegeben jeweils ab.

******************************************************************************/
