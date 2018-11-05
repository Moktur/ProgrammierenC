
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       03-06, Unter- bzw. Ueberlauf
/*
/*      Konzepte/       Bereichsueberschreitung bei ganzzahligen Variablen,
/*      Sprachelemente: Unter- bzw. Ueberlauf
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <limits.h>     /* enthaelt minimale und maximale Werte fuer die
                           ganzzahligen Datentypen */

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
    /* Initialisierung aller Arten ganzzahliger Variablen mit den jeweils
       groessten und kleinsten moeglichen Werten */
    int             min_int    = INT_MIN,  max_int    = INT_MAX;
    unsigned int    min_uint   = 0,        max_uint   = UINT_MAX;

    char            min_char   = CHAR_MIN, max_char   = CHAR_MAX;
    unsigned char   min_uchar  = 0,        max_uchar  = UCHAR_MAX;

    short           min_short  = SHRT_MIN, max_short  = SHRT_MAX;
    unsigned short  min_ushort = 0,        max_ushort = USHRT_MAX;

    long            min_long   = LONG_MIN, max_long   = LONG_MAX;
    unsigned long   min_ulong  = 0,        max_ulong  = ULONG_MAX;

    /* Anweisungen */

    /* Um einen Ueberlauf zu erzwingen, wird zum groessten in der Variable
       speicherbaren Wert Eins addiert. Um einen Unterlauf zu erzwingen, wird
       vom kleinsten in der Variable speicherbaren Wert Eins subtrahiert */
    min_int    = min_int    - 1;    max_int    = max_int    + 1;
    min_uint   = min_uint   - 1;    max_uint   = max_uint   + 1;
    min_char   = min_char   - 1;    max_char   = max_char   + 1;
    min_uchar  = min_uchar  - 1;    max_uchar  = max_uchar  + 1;
    min_short  = min_short  - 1;    max_short  = max_short  + 1;
    min_ushort = min_ushort - 1;    max_ushort = max_ushort + 1;
    min_long   = min_long   - 1;    max_long   = max_long   + 1;
    min_ulong  = min_ulong  - 1;    max_ulong  = max_ulong  + 1;

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 03-06, Unter- bzw. Ueberlauf --------------\n\n");

    printf("\nDas Programm zeigt Beispiele fuer den Unter- bzw. Ueberlauf");
    printf("\nbei ganzzahligen Datentypen.\n");

    /* Ausgabe der Werte */
    printf("\n\t\tUnterlauf\tUeberlauf\n");
    printf("\t\t---------\t---------\n\n");

    printf("int:\t\t%d\t\t%d\n", min_int, max_int);
    printf("unsigned int:\t%u\t\t%u\n", min_uint, max_uint);

    printf("char:\t\t%hd\t\t%hd\n", min_char, max_char);
    printf("unsigned char:\t%hu\t\t%hu\n", min_uchar, max_uchar);

    printf("short:\t\t%hd\t\t%hd\n", min_short, max_short);
    printf("unsigned short:\t%hu\t\t%hu\n", min_ushort, max_ushort);

    printf("long:\t\t%ld\t%ld\n", min_long, max_long);
    printf("unsigned long:\t%lu\t%lu\n\n", min_ulong, max_ulong);
    PAUSE;
}
