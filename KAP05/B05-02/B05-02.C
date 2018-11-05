
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-02, Vergleichs- und logische Operatoren
/*
/*      Konzepte/       Vergleichsoperatoren: <, >, ==, !=, <=, >=
/*      Sprachelemente: logische Operatoren:  ||, &&, !
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

    int a   = 7,     /* Durch das Aendern der Werte */
        b   = 10,    /* wird im Programm anders verzweigt */
        c   = 2;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-02, Vergleichs- und logische Operatoren \n\n");

    printf("\nDas Programm zeigt den Einsatz von Vergleichs-");
    printf(" u. logischen Operatoren.\n");

    /* 1. Vergleichsoperatoren */

    printf("\nErgebnisse von Vergleichen:");
    if (a > b)        /* 1.1 Groesser-Vergleich: Ist a groesser b, wird die
                             printf-Anweisung ausgefuehrt */
        printf("\n\na ist groesser als b");
    else if (a == b)  /* 1.2 Gleichheits-Vergleich: Ist a gleich b, wird die
                             printf-Anweisung ausgefuehrt */
        printf("\n\na und b sind gleich gross");
    else if (a < b)   /* 1.3 Kleiner-Vergleich: Ist a kleiner b, wird die 
                             printf-Anweisung ausgefuehrt */
        printf("\n\na ist kleiner als b");

    if (a != b)       /* 1.4 Ungleichheit: Ist a ungleich b, 
                             wird die printf-Anweisung  ausgefuehrt */
        printf("\na ist ungleich b");

    /* 2. logische Operatoren */

    printf("\n\nErgebnisse logischer Operationen:");
    /* 2.1 Logisches UND: beide Bedingungen muessen erfuellt sein, damit die
           erste printf-Anweisung ausgefuehrt wird */
    if ((a+b < 50) && (c > 2))  
        printf("\n\nLogisches UND  : beide Bedingungen waren erfuellt");
    else
        printf("\n\nLogisches UND  : mind. eine Bedingung war nicht erfuellt");

    /* 2.2 Logisches ODER: mindestens eine Bedingungen muss erfuellt sein,
           damit die erste printf-Anweisung ausgefuehrt wird */
    if ((a+b < 50) || (c > 2))
        printf("\nLogisches ODER : mind. eine Bedingung war erfuellt");
    else
        printf("\nLogisches ODER : beide Bedingungen  waren  nicht erfuellt");

    /* 2.3 Logisches NICHT: die negierte Bedingung ist erfuellt, wenn die 
           Ausgangsbedingung nicht erfuellt ist */
    if (!(c == 2))
        printf("\nLogisches NICHT: Ausgangs-Bedingung war nicht erfuellt\n\n");
    else
        printf("\nLogisches NICHT: Ausgangs-Bedingung war erfuellt\n\n");
    PAUSE;
}
