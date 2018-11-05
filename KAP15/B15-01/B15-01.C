
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       15-01, assert.h
/*
/*      Konzepte/       Standard-Bibliothek, Diagnosemakro
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm beschreibt die Anwendung des
/*                      in assert.h vereinbarten Diagnosemakros assert()
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>        /* Enthaelt Ein- und Ausgabefunktionen */

/* Ist NDEBUG definiert, gibt assert() keine Fehlermeldung aus */
/* #define NDEBUG */

/* #undef NDEBUG  ggf. einfuegen, wenn nicht voreingestellt */
#include <assert.h>       /* Enthaelt Diagnosemakro assert */


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

    int i = 10;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 15-01, assert.h ---------------------------\n\n");
    printf("\nDas Programm zeigt die Anwendung des Makros assert(). Wenn\n");
    printf("NDEBUG nicht definiert ist, muss eine Fehlermeldung ausgegeben\n");
    printf("werden, ansonsten gibt es keine Fehlermeldung, da der Aufruf\n");
    printf("assert() ignoriert wird.\n\n");

    #if defined NDEBUG
          printf("NDEBUG ist definiert: Es gibt keine Fehlermeldung.\n");
    #else
          printf("NDEBUG ist nicht definiert: Es gibt ggf. eine Fehlermeldung.\n");
    #endif

    /* Das Makro assert() beendet das Programm mit einer Fehlermeldung, wenn
       das uebergebene Argument gleich null ist. Da der Ausdruck i == 0 falsch
       ist und der Operator == bei einer falschen Bedingung 0 liefert, bricht
       das Programm an dieser Stelle ab. assert() kann daher z.B. benutzt werden,
       um den Wert einer Variablen an einer bestimmten Stelle im Programm zu
       testen. */
    assert(i == 0);
    PAUSE;
}

/*****************************************************************************/
/* Aufgaben:
/******************************************************************************

  Entfernen Sie im Abschnitt 'Include-Dateien laden' den Kommentar um die
  Praeprozessor-Anweisung '#define NDEBUG'. Wie reagiert das Programm nun, wenn
  der Parameter von assert gleich Null ist?

******************************************************************************/
