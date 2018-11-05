
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       12-01, Makro fuer Wertetausch I
/*
/*      Konzepte/       Definition und Benutzung eines Makros
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Programm benutzt das Makro SWAP, welches die Werte
/*                      zweier int-Variablen tauscht
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

#define SWAP(x,y) \
        {int temp; temp = x; x = y; y = temp;}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int a = 10, b = 20;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 12-01, Makro fuer Wertetausch -------------\n\n");

    printf("\nDas Programm tauscht die Werte zweier int-Variablen\n");
    printf("mit einem Makro.\n");
    printf("\nVor Tausch:  a = %d, b = %d",a,b);
    SWAP(a,b);
    printf("\nNach Tausch: a = %d, b = %d",a,b);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  -  Wie reagiert der Compiler, wenn in der Makrodefinition von SWAP nach dem
     Namen "SWAP" ein Blank steht?
  -  Wenden Sie den Makro SWAP in dem Beispielprogramm 8.2 in der
     Funktion fuer die Sortiermethode Selectionsort an!
******************************************************************************/
