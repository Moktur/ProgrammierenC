
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-03, Inhalt-von-Operator II
/*
/*      Konzepte/       Operationen mittels Inhalt-von-Operator
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
    int i = 1, j = 2, *izgr, *jzgr;      /* 2 int's, 2 zeiger auf int's*/

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-03, Inhalt-von-Operator II -------------\n\n");
    printf("\nDas Programm fuehrt Operationen mit Inhalt-von-Operator aus.\n");

    izgr  = &i;                 /* Zeiger erhaelt Adresse von i */
    jzgr  = &j;                 /* Zeiger erhaelt Adresse von j */

    j = *izgr + *jzgr;          /* j erhaelt (indirekt) Wert i + j */
    printf("\nj = %d", j);                          /* Ausgabe 1 */
  
    *izgr = i + 1;              /* i erhaelt (indirekt) Wert 2 */
    printf("\ni = %d", i);                          /* Ausgabe 2 */

    *jzgr = *izgr * j;          /* j erhaelt (indirekt) Wert i * j */
    printf("\nj = %d  *jzgr = %d ", j, *jzgr);      /* Ausgabe 3 */

    *izgr = *jzgr / *izgr;      /* i erhaelt (indirekt) Wert j / i */
    printf("\ni = %d  *izgr = %d \n", i, *izgr);    /* Ausgabe 4 */
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Lassen Sie das Programm laufen und vollziehen Sie im einzelnen
    nach, ob richtig gerechnet wurde.
  - Was passiert, wenn der Zeiger jzgr anfangs nicht die Adresse von j
    erhaelt? Kommentieren Sie die Anweisung jzgr = &j aus und lassen
    Sie das Programm erneut laufen. Jede Zeigervariable muss geeignet
    initialisiert werden vor ihrer Benutzung mit dem Inhalt-von-Operator!
  - Was passiert, wenn in der Anweisung
    *izgr = *jzgr / *izgr zwischen / und * kein Leerzeichen steht?
    Wie ist die Compilerreaktion zu erklaeren?

******************************************************************************/
