
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       12-02, Makro fuer Wertetausch II
/*
/*      Konzepte/       Definition und Benutzung eines typunabhaengigen Makros
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm benutzt das Makro SWAP2, welches die Werte
/*                      zweier Variablen beliebiger Typen tauscht
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

#define SWAP2(type,x,y) \
            {type temp; temp = x; x = y; y = temp;}

/*****************************************************************************/
/* Funktionen  definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int a = 10, b = 20;
    float c = 13.45F, d = 34.56F;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 12-02, Makro fuer Wertetausch II ----------\n\n");

    printf("\nDas Programm tauscht den Inhalt zweier Variablen");
    printf("\nverschiedener Typen mit einem Makro.\n");
    printf("\nTausch zweier int-Variablen.");
    printf("\nVor Tausch:  a = %-5d, b = %-5d",a,b);
    SWAP2(int,a,b);                                /* Typ int wird uebergeben */
    printf("\nNach Tausch: a = %-5d, b = %-5d\n",a,b);
    printf("\nTausch zweier float-Variablen.");
    printf("\nVor Tausch:  c = %.2f, d = %.2f",c,d);
    SWAP2(float,c,d);                              /* Typ float wird uebergeben */
    printf("\nNach Tausch: c = %.2f, d = %.2f",c,d);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************
  - Bearbeiten Sie die analoge Aufgabenstellung wie fuer das
    Beispielprogramm 12.1.
  - Setzen Sie den Makro SWAP2 auch innerhalb des Beispielprogramms 10.18 ein.
  - Entwickeln Sie ein Makro, welches testet, ob ein Wert einer Variablen x
    eines beliebigen einfachen Typs in einem gegebenen abgeschlossenen
    Intervall [a,b] liegt. Testen Sie den Makro mit einer geeigneten
    main-Funktion.
******************************************************************************/

