
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-02, Inhalt-Operator I
/*
/*      Konzepte/       Ausgabe mittels Inhalt-von-Operator
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
    int iwert = 10, *izgr;          /* int-Variable und int-Zeiger */
    float fwert = 2.5, *fzgr;       /* dasselbe fuer float */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-02, Inhalt-von-Operator I --------------\n\n");

    printf("\nDas Programm gibt Variablenwerte direkt und mit ");
    printf("Inhalt-von-Operator aus.\n");
    izgr = &iwert;
    fzgr = &fwert;
    printf("\n iwert:   %6d  *izgr: %6d", iwert, *izgr);      /* Ausgabe 1 */
    iwert = 8;                                                /* neuer Wert */
    printf("\n iwert:   %6d  *izgr: %6d", iwert, *izgr);      /* Ausgabe 2 */
    printf("\n fwert: %8.2f  *fzgr: %6.2f\n", fwert, *fzgr);  /* Ausgabe 3 */
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Weisen Sie auch der float-Variablen einen neuen Wert zu und geben Sie diesen
  direkt und mit dem Inhalt-von-Operator aus.

******************************************************************************/
