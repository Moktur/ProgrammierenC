
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       04-01, Ausgabe von Zeichen
/*
/*      Konzepte/       Zeichenausgabe mit der Funktion putchar
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>           /* macht auch Funktion putchar verfuegbar */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-01, Zeichen-Ausgabe mit putchar --------\n\n");

    printf("\nDas Programm gibt einzelne Zeichen mit putchar aus.\n\n");
    putchar('a');       /* Uebergabe der Zeichenkonstanten */
    putchar('b');       /* 'a', 'b', 'c' und */
    putchar('c');       /* Ausgabe von a, b und c */
    putchar(97);        /* Uebergabe der ASCII-Codenummern */
    putchar(98);        /* 97 - 99 und ebenfalls */
    putchar(99);        /* Ausgabe von a, b und c */
    printf("\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Trennen Sie die ausgegebenen Buchstaben durch Blanks
    (Zeichen: ' ', ASCII-Code-Nr.: 32).

  Geben Sie weitere Zeichen mit putchar aus.

******************************************************************************/
