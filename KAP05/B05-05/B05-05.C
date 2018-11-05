
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-05, Typumwandlungen
/*
/*      Konzepte/       Typumwandlungen bei Zuweisungen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Bemerkung:      Warnung: Konvertierung von 'Typ a' in 'Typ b'
/*						D.h. wenn wir eine Zahl von einem Typ in einen anderen Typ
/*						konvertiert wird der Compiler auf die Anzahl Bytes runden
/*						die der neue Typ hat. Der Rest der Daten gehen Verloren.
/* 
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar(); }

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    short int   si = 53,           si2;
    int         i  = 5248,         i2;
    long int    li = 214347L,      li2;
    float       f  = 123.867F,     f2;
    long double ld = 1423562.81F,  ld2;

    signed short   s_shrt = -123,   s_shrt_2;
    unsigned short u_shrt = 39521U, u_shrt_2;

    /* Anweisungen */
    
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-05, Typumwandlung bei Zuweisung --------\n\n");
    printf("Das Programm zeigt Zuweisungen mit Typumwandlung.");
    printf("\nMoegliche Wertverfaelschungen werden durch (!) markiert.\n");

    /* int <-> short (maschinenabhaengige Wertverfaelschung moeglich) */
    si2 = i;      /* int -> short: Wertverfaelschung moeglich */
    i2  = si;     /* short -> int */
    printf("\nshort: %6hd  -=>  int:   %6d", si, i2);
    printf("\nint:   %6d  -=>  short: %6hd", i, si2);

    /* long <-> short (maschinenabhaengige Wertverfaelschung moeglich) */
    si2 = li;   /* long -> short: Wertverfaelschung moeglich */
    li2 = si;   /* short -> long */
    printf("\nlong:  %6ld  -=>  short: %6d (!)", li, si2);
    printf("\nshort: %6d  -=>  long:  %6ld", si, li2);

    /* long <-> int (maschinenabhaengige Wertverfaelschung moeglich) */
    i2  = li;   /* long -> int: Wertverfaelschung moeglich */
    li2 = i;    /* int -> long */
    printf("\nlong:  %6ld  -=>  int:   %6d (!)", li, i2);
    printf("\nint:   %6d  -=>  long:  %6ld", i, li2);

    /* long float <-> float */
    f2 = ld;    /* long double -> float: Wertverfaelschung moeglich */
    ld2 = f;    /* float -> long double */
    printf("\n\nlong double: %12.4Lf  -=>  float:       %12.4f", ld, f2);
    printf("\nfloat:       %12.4f  -=>  long double: %12.4Lf", f, ld2);

    f2 = i;     /* int -> float */
    i2 = f;     /* float -> int: Wertverfaelschung moeglich */
    li = ld;    /* long double -> long int: Wertverfaelschung moeglich */
    printf("\n\nint:         %12d  -=>  float:    %12.4f", i, f2);
    printf("\nfloat:       %12.4f  -=>  int:      %12d (!)", f, i2);
    printf("\nlong double: %12.4Lf  -=>  long int: %12ld (!)", ld, li);

    /* signed <-> unsigned: Wertverfaelschungen moeglich */
    s_shrt_2 = u_shrt;  /* unsigned -> signed: Wertverfaelschungen moeglich */
    u_shrt_2 = s_shrt;  /* short -> signed: Wertverfaelschungen moeglich */
    printf("\n\nunsigned: %5u  -=>  signed:   %5d (!)", u_shrt, s_shrt_2);
    printf("\nsigned:   %5d  -=>  unsigned: %5u (!)\n", s_shrt, u_shrt_2);
    /* Hier wurde short stellvertretend fuer alle anderen ganzzahligen
       Variablen benutzt */
    PAUSE;
}
