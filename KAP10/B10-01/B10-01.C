
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-01, Werte und Adressen von Variablen
/*
/*      Konzepte/       Adressoperator
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
    int i;
    float x = 1.5f, y = 2.5f;
    static int testfeld[3] = {9,8,7};

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-01, Werte und Adressen von Variablen ---\n\n");
    printf("\nDas Programm gibt Werte und Adressen von Variablen aus.\n");

    printf("\nVariable         Wert   Adresse (dez.)");
    printf("\n--------------------------------------");
    for (i = 0; i < 3; i++)
        printf("\ntestfeld[%1d]   %6d%10d",i, testfeld[i], &testfeld[i]);
    printf("\ni             %6d%10d", i, &i);
    printf("\nx             %6.2f%10d", x, &x);
    printf("\ny             %6.2f%10d\n", y, &y);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Fuehren Sie weitere lokale Variablen ein geben Sie auch deren Werte und
    Adressen aus.
  - Definieren Sie das Feld testfeld global und pruefen Sie, ob sich die
    Adressen aendern.
  - Definieren Sie nun das Feld lokal ohne Speicherklassenangabe "static",
    weisen sie die Werte an das Feld gesondert zu. Aendern sich die Adressen
    jetzt?
  - Offenbar gilt, dass lokale Variablen einerseits und globale bzw. static-
    Variablen andererseits in verschiedenen Speicherabschnitten gehalten
    werden. Auf die verschiedenen Adressbereiche der Daten eines Programms
    fuer lokale, globale und static-Variablen wird im Kap. 13 eingegangen.
  - Vergleichen Sie die (aufsteigende) Folge der Adressen mit den Typen der
    Variablen. Aendern Sie die Typen der Variablen und beobachten Sie die
    Aenderung der Adressfolge. Passt beides zusammen?

******************************************************************************/
