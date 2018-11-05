
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-03, Berechnung von n! ("n-Fakultaet")
/*
/*      Konzepte/       Rekursion
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   n! ist wie folgt definiert:
/*                      n! := n*(n-1)*(n-2)*...*1, 1! := 0! := 1,
/*                      n >= 0, ganz
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
/* Funktionen deklarieren
/*****************************************************************************/

long fakultaet(int k, int n);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    long endwert;
    int n;

    /* Information */
     printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
     printf("----- Beispiel: 07-03, Berechnung von n-Fakultaet ---------\n\n");
      printf("\nDas Programm ermittelt rekursiv n-Fakultaet fuer n <= 10.\n");

    /* Eingabe */
    printf("\nBitte ganze Zahl n (0 <= n <= 10) eingeben: ");scanf_s("%d",&n);

    /* Funktionsaufruf fuer Berechnung */
    endwert = fakultaet(n, n);

    /* Ausgabe */
    printf("\nArgument n = %d  n-Fakultaet n! = %ld", n, endwert);
    PAUSE;
}

/* - Funktion gibt k! fuer uebergebenes k zurueck
   - 2. Parameter nur fuer Ausgabesteuerung, siehe unten */
long fakultaet(int k, int n)
{
    long wert;
    int i;

    printf("\n");
    for (i = n; i > k; i--) printf(" ");    /* Ausgabe einruecken */
    printf("Aufruf der Fakultaetsfunktion fuer k = %d", k);

    if (k <= 1)                        /* Abbruchbedingung fuer Rekursion */
        wert = 1;
    else
        wert = k * fakultaet(k-1, n);  /* rekursiver Aufruf fuer k - 1 */

    printf("\n");
    for (i = k; i < n; i++) printf(" ");    /* Ausgabe einruecken */
    printf("Jetzt berechnet: %2d! = %ld", k, wert);
    return wert;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Stellen Sie das Argument n der Funktion fakultaet nicht als (2.)
    Parameter, sondern als Globale zur Verfuegung.
  - Schreiben Sie eine Funktion fakultaet_iter, die n! in einer
    Schleife ermittelt, d.h. iterativ vorgeht. Testen Sie die Funktion
    fakultaet_iter, indem Sie sie aus main anstelle von fakultaet aufrufen.
  - Welche Funktion sollte schneller sein und warum?
  - Bestimmen Sie den Maximalwert n, fuer den das Programm die Fakultaet
    (korrekt) ermitteln kann anhand des Wertebereiches fuer den Typ long.
    Kann das Argument erhoeht werden, wenn anstelle von long-Variablen
    unsigned-long-Variablen verwendet werden?

******************************************************************************/
