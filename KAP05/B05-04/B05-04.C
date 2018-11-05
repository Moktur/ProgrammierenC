
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-04, Zuweisungsoperatoren
/*
/*      Konzepte/       Zuweisungsoperatoren +=, -=, *=, /=, %=
/*      Sprachelemente: Zuweisungen als Ausdruecke
/*
/*      Aufgabenteil:   nein
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
    /* Variablen definieren */
    int a, b, c, d, e;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-04, Zuweisungsoperatoren ---------------\n\n");

    printf("\nDas Programm zeigt den Einsatz von Zuweisungsoperatoren.\n");

    /* Einfache Zuweisungen */

    printf("\nEinfache Zuweisungen:");
    a = 9;          /* a = 9 */
    b = 12;         /* b = 12 */
    c = d = 18;     /* c = 18 und d = 18 */
    e = 12;         /* e = 12 */
    printf("\n\ta = %d\tb = %d\tc = %d\td = %d\te = %d\n", a, b, c, d, e);

    /* Zusammengesetzte Zuweisungen */

    printf("\nZusammengesetzte Zuweisungen:");
    a += b;     /* a = a + b; */
    b -= b;     /* b = b - b; */
    c *= 2;     /* c = c * 2; */
    d /= 6;     /* d = d / 6; */
    e %= 5;     /* e = e % 5; */
    printf("\n\ta = %d\tb = %d\tc = %d\td = %d\te = %d\n", a, b, c, d, e);

    /* In- und Dekrementierung um eins */

    printf("\nInkrementierung und Dekrementierung um 1:");
    a++;    /* a = a + 1; */
    ++b;    /* b = b + 1; */
    --c;    /* c = c - 1; */
    d--;    /* d = d - 1; */
    printf("\n\ta = %d\tb = %d\tc = %d\td = %d\n", a, b, c, d);

    /* Zuweisungen als Ausdruecke */

    printf("\nZuweisungen als Ausdruecke:");

    a = 1 + (b = 12);
    /* Entspricht den Anweisungen: b = 12; a = 1 + b;

       Die Zuweisung d = 12 liefert einen Wert, der fuer die Berechnung von
       b genutzt werden kann. Die Klammerung ist an dieser Stelle notwendig,
       da der Operator + eine hoehere Prioritaet als der Zuweisungsoperator
       besitzt */
    printf("\n\ta = %d\tb = %d\tc = %d\td = %d", a, b, c, d);

    a = (b = d = 12 - 3) + (c *= 2);
    /* Entspricht den Anweisungen: d = 12 - 3; b = d; c *= 2; a = b + c;

       In diesem Ausdruck geschieht folgendes: zuerst werden b und d der Wert
       9 (12 - 3) zugewiesen (in einer Zuweisungskette liefert der am weitesten
       links stehende Ausdruck den Wert fuer eine weitere Berechnung). Dann
       wird noch der Wert von c verdoppelt. Zuletzt bekommt a die Summe von b
       und c zugewiesen */
    printf("\n\ta = %d\tb = %d\tc = %d\td = %d\n", a, b, c, d);

    /* Auswertungsreihenfolge */
    printf("\nAuswertungsreihenfolge:");
    /* Die Operationen werden entsprechend ihrer Prioritaet bearbeitet */
    a = 12 - 3 * 2;     /* a = 12 - 6 */
    b = (12 - 3) * 2;   /* b =  9 * 2 */
    /* Mehreren Operationen gleicher Prioritaet werden entsprechend der
       Assoziativitaet von links nach rechts oder umgekehrt bewertet */
    c = 12 / 3 * 4;     /* c =  4 * 4 */
    d = 12 * 3 / 4;     /* d = 36 / 4 */
    printf("\na = %d\tb = %d\tc = %d\td = %d\n", a, b, c, d);
    PAUSE;
}
