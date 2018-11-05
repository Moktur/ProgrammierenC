
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-02, einfache vordefinierte Datentypen
/*
/*      Konzepte/       Vorstellung aller einfachen vordefinierten Datentypen
/*      Sprachelemente: mit den (maschinenabhaengigen) Wertebereichen
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <limits.h>     /* enthaelt minimale und maximale Werte fuer die
                           vordefinierten ganzzahligen Datentypen */
#include <float.h>      /* enthaelt minimale und maximale Werte fuer die
                           vordefinierten gebrochenen Datentypen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{   

    /* lokale Variablen */

    /* ganzzahlige Variablen */
    int             min_int    = INT_MIN,  max_int    = INT_MAX;
    unsigned int    min_uint   = 0,        max_uint   = UINT_MAX;

    char            min_char   = CHAR_MIN, max_char   = CHAR_MAX;
    unsigned char   min_uchar  = 0,        max_uchar  = UCHAR_MAX;

    short           min_short  = SHRT_MIN, max_short  = SHRT_MAX;
    unsigned short  min_ushort = 0,        max_ushort = USHRT_MAX;

    long            min_long   = LONG_MIN, max_long   = LONG_MAX;
    unsigned long   min_ulong  = 0,        max_ulong  = ULONG_MAX;

    /* gebrochene bzw. reelle Variablen */

    /* BEACHTE: Bei Borland C++ 5.0 sind folgende Werte nicht verfuegbar:
                FLT_MAX, DBL_MAX, LDBL_MAX und LDBL_MIN
                diesem Fall sollten die Ausdruecke durch 0 ersetzt
                werden, um eine Kompilierung zu ermoeglichen */

    float           min_float  = FLT_MIN,  max_float  = FLT_MAX;
    double          min_double = DBL_MIN,  max_double = DBL_MAX;
    long double     min_ldbl   = LDBL_MIN, max_ldbl   = LDBL_MAX;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-02, einfache vordefinierte Datentypen --\n\n");

    printf("\nDas Programm gibt minimale und maximale Werte sowie Bytegroessen");
    printf("\nfuer einfache vordefinierte Datentypen an. Minima und Maxima ");
    printf("\nwerden den Definitionsdateien limits.h und float.h entnommen.");

    /* Ausgabe der Variablenwerte */
    printf("\n\nMinimum und Maximum fuer INT:\n");
    printf("\tMinimum: %d\tMaximum: %d\n", min_int, max_int);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_int));

    printf("\n\nMinimum und Maximum fuer UNSIGNED INT:\n");
    printf("\tMinimum: %u\tMaximum: %u\n", min_uint, max_uint);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_uint));

    printf("\n\nMinimum und Maximum fuer CHAR:\n");
    printf("\tMinimum: %hd\tMaximum: %hd\n", min_char, max_char);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_char));

    printf("\n\nMinimum und Maximum fuer UNSIGNED CHAR:\n");
    printf("\tMinimum: %hu\tMaximum: %hu\n", min_uchar, max_uchar);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_uchar));

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\nMinimum und Maximum fuer SHORT:\n");
    printf("\tMinimum: %hd\tMaximum: %hd\n", min_short, max_short);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_short));

    printf("\n\nMinimum und Maximum fuer UNSIGNED SHORT:\n");
    printf("\tMinimum: %hu\tMaximum: %hu\n", min_ushort, max_ushort);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_ushort));

    printf("\n\nMinimum und Maximum fuer LONG:\n");
    printf("\tMinimum: %ld\tMaximum: %ld\n", min_long, max_long);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_long));

    printf("\n\nMinimum und Maximum fuer UNSIGNED LONG:\n");
    printf("\tMinimum: %lu\tMaximum: %lu\n", min_ulong, max_ulong);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_ulong));

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\nMinimum und Maximum fuer FLOAT (bei pos. Vorzeichen):\n");
    printf("\tMinimum: %G\tMaximum: %G\n", min_float, max_float);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_float));

    printf("\n\nMinimum und Maximum fuer DOUBLE (bei pos. Vorzeichen):\n");
    printf("\tMinimum: %G\tMaximum: %G\n", min_double, max_double);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_double));

    printf("\n\nMinimum und Maximum fuer LONG DOUBLE (bei pos. Vorzeichen):");
    printf("\n\tMinimum: %LG\tMaximum: %LG\n", min_ldbl, max_ldbl);
    printf("\tVariablengroesse in Bytes: %d", sizeof(min_ldbl));

    /* Warte auf Tastendruck */
    PAUSE;
}

