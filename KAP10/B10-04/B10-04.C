
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-04, Zeigerarithmetik
/*
/*      Konzepte/       Zeigerarithmetik
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
    int i = 10, *izgr = &i, *jzgr = NULL;   /* beachte Zeigerinitialisierung */
    float feld[5], *fzgr1, *fzgr2;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-04, Zeigerarithmetik -------------------\n\n");
    printf("\nDas Programm fuehrt Operationen der Zeigerarithmetik aus.\n");

    if (i > 5)
        jzgr = izgr;                     /* jzgr erhaelt gueltige Adresse */
    if (jzgr != NULL)                    /* Zeigervergleich */
        printf("\n*jzgr: %d\tjzgr: %d",  /* Ausgabe 1 */
        *jzgr, jzgr);
  
    fzgr1 = (float *)izgr;               /* Typumwandlung fuer Zeiger */
    printf("\nizgr: %d",izgr);           /* Ausgabe 2 */
    printf("\tfzgr1: %d", fzgr1);

    izgr++;                              /* izgr und ... */
    fzgr1++;                             /* fzgr1 um 1 Einheit (!) erhoehen */
    printf("\nizgr: %d", izgr);          /* Ausgabe 3 */
    printf("\tfzgr1: %d", fzgr1);

    fzgr1 = &feld[0];                    /* fzgr1 erhaelt Anfangsadresse
                                            des Feldes feld*/
    fzgr2 = fzgr1 + 4;                   /* fzgr2 um 4 Einheiten(!) erhoehen */
    printf("\nfzgr1: %d", fzgr1);        /* Ausgabe 4 */
    printf("\tfzgr2: %d", fzgr2);

    fzgr2 = &feld[5];                    /* fzgr2 erhaelt Adresse des letzten
                                            Elements von feld */
    i = fzgr2 - fzgr1;                   /* Zeigersubtraktion */
    printf("\nfzgr2 - fzgr1: %d\n", i);  /* Ausgabe 5 */
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Lassen Sie das Programm laufen und vollziehen Sie alle Schritte
    im einzelnen nach.
  - Aendern Sie den Initialwert von i auf 1 ab und erklaeren Sie sich,
    warum sich die Ausgabe aendert.
  - Entfernen Sie die Initialisierung von jzgr mit NULL und beobachten Sie
    was daraufhin passiert. Warum tritt eine Aenderung ein?

******************************************************************************/
