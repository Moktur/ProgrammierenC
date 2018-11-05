
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-01, arithmetische Operatoren
/*
/*      Konzepte/       Arithmetische Operatoren fuer die vordefinierten
/*      Sprachelemente: ganzzahligen und gebrochenen Datentypen
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
    /* lokale Variablen */
    int   a  = 30,   b  = 12,   c = -7,      d = -3,     res_int;
    float e  = 4.6f, f  = 9.1f, g = -7.135f, h = -2.23f, res_float;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-01, arithmetische Operatoren -----------\n\n");

    printf("\nDas Programm zeigt den Einsatz arithmetischer Operatoren.\n");

    /* Anzeigen der Werte */
    printf("\n\n a = %d \t b = %d \t c = %d \t d = %d", a, b, c, d);
    printf("\n e = %.2f \t f = %.2f \t g = %.2f \t h = %.2f\n\n", e, f, g, h);

    /* Addition gleicher Datentypen */
    printf("\nAddition");
    res_int = a + b;
    printf("\n(int   + int  )    a + b = %d", res_int);
    res_float = e + f;
    printf("\n(float + float)    e + f = %.2f", res_float);

    /* Addition verschiedener Datentypen */
    res_float = a + e;
    printf("\n(int   + float)    a + e = %.2f", res_float);
    res_float = e + a;
    printf("\n(float + int  )    e + a = %.2f\n", res_float);

    /* Subtraktion gleicher Datentypen */
    printf("\nSubtraktion");
    res_int = a - b;
    printf("\n(int   - int  )    a - b = %d", res_int);
    res_float = e - f;
    printf("\n(float - float)    e - f = %.2f", res_float);

    /* Subtraktion verschiedener Datentypen */
    res_float = a - e;
    printf("\n(int   - float)    a - e = %.2f", res_float);
    res_float = e - a;
    printf("\n(float - int  )    e - a = %.2f\n", res_float);

    /* Warte auf Tastendruck */
    PAUSE;

    /* Anzeigen der Werte */
    printf("\n\n a = %d \t b = %d \t c = %d \t d = %d", a, b, c, d);
    printf("\n e = %.2f \t f = %.2f \t g = %.2f \t h = %.2f\n\n", e, f, g, h);

    /* Multiplikation gleicher Datentypen */
    printf("\nMultiplikation");
    res_int = a * b;
    printf("\n(int   * int  )    a * b = %d", res_int);
    res_float = e * f;
    printf("\n(float * float)    e * f = %.2f", res_float);

    /* Multiplikation verschiedener Datentypen */
    res_float = a * e;
    printf("\n(int   * float)    a * e = %.2f", res_float);
    res_float = e * a;
    printf("\n(float * int  )    e * a = %.2f\n", res_float);

    /* Division gleicher Datentypen */
    printf("\nDivision");
    res_int = a / b;
    printf("\n(int   / int  )    a / b = %d", res_int);
    res_float = e / f;
    printf("\n(float / float)    e / f = %.2f", res_float);

    /* Division verschiedener Datentypen */
    res_float = a / e;
    printf("\n(int   / int  )    a / e = %.2f", res_float);
    res_float = e / a;
    printf("\n(float / int  )    e / a = %.2f\n", res_float);

    /* Taste druecken */
    PAUSE;

    /* Anzeigen der Werte */
    printf("\n\n a = %d \t b = %d \t c = %d \t d = %d", a, b, c, d);
    printf("\n e = %.2f \t f = %.2f \t g = %.2f \t h = %.2f\n\n", e, f, g, h);

    /* Restbildung mit modulo-Operator % fuer ganzzahlige Datentypen */
    printf("\nRestbildung mit %%-Operator fuer ganzzahlige Datentypen");
    res_int = a % b;
    printf("\n(int %% int)   a %% b = %d\n", res_int);

    /* Division ganzzahliger Datentypen mit negativen Vorzeichen */
    printf("\nDivision ganzzahliger Datentypen mit negativen Vorzeichen");
    res_int = a / c;
    printf("\n(pos / neg)   a / c = %d", res_int);
    res_int = c / a;
    printf("\n(neg / pos)   c / a = %d", res_int);
    res_int = c / d;
    printf("\n(neg / neg)   c / d = %d\n", res_int);

    /* Division gebrochener Datentypen mit negativen Vorzeichen */
    printf("\nDivision gebrochener Datentypen mit negativen Vorzeichen");
    res_float = e / g;
    printf("\n(pos / neg)   a / c = %.2f", res_float);
    res_float = g / e;
    printf("\n(neg / pos)   c / a = %.2f", res_float);
    res_float = g / h;
    printf("\n(neg / neg)   c / d = %.2f\n", res_float);
    PAUSE;
}
