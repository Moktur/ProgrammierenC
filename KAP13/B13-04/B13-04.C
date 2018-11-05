
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-04, register-Variablen
/*
/*      Konzepte/       Speicherklasse register
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm durchlaeuft zwei Schleifen, jeweils eine
/*                      mit automatischen und mit Register-Variablen. Dann
/*                      wird die benoetigte Rechenzeit fuer die beiden
/*                      Schleifen ausgegeben. Fuer die mit Registervariablen
/*                      ausgefuehrte Schleife sollte die Rechenzeit geringer
/*                      sein.
/*
/*                      Abhaengig von dem benutztem Compiler bzw. Rechner kann
/*                      der Fall eintreten, dass bei einem so kleinen Programm
/*                      alle Variablen als Registervariablen gehalten werden
/*                      und keine Rechenzeitdifferenz auftritt.
/*                      Die Differenz der Rechenzeit ist ferner abhaengig von
/*                      dem benutzten Betriebssystem.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <time.h>       /* Funktionen zur Zeitabfrage */

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

    /* Variablen zur Speicherung der aktuellen Rechenkern-Zeit */
    time_t start_1, start_2;
    time_t ende_1, ende_2;
    /* automatische und register-Variablen */
    unsigned long int a, c;
    register unsigned long int b, d;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 13-04, register-Variablen -----------------\n\n");

    printf("\nDas Programm prueft, ob die Speicherklasse register einen");
    printf("\nRechenzeitvorteil erbringt. Hierzu werden zwei Schleifen");
    printf("\n - eine mit und eine ohne register-Variablen - durchlaufen.\n");

    printf("\nIch durchlaufe jetzt die beiden Schleifen. Das kann eine Weile");
    printf(" dauern.\n\n");

    /* Sichere aktuelle Zeit */
    time(&start_1);
    /* Durchlaufe die Schleife 1 - ohne register-Variablen */
    for (a = 0; a < 100000000; a++)
          c = a / 2;
    /* Sichere aktuelle Zeit */
    time(&ende_1);

    /* Sichere aktuelle Zeit */
    time(&start_2);
    /* Durchlaufe die Schleife 2 - mit register-Variablen */
    for (b = 0; b < 100000000; b++)
          d = b / 2;
    /* Sichere aktuelle Zeit */
    time(&ende_2);

    /* Ausgabe der Rechenzeit fuer beide Durchlaeufe */
    printf("\nRechenzeit in s mit auto-Variablen: %ld", ende_1 - start_1);
    printf("\nRechenzeit in s mit register-Variablen: %ld", ende_2 - start_2);
    PAUSE;
}

