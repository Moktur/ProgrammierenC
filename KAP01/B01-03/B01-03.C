
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       01-03, Maximum von 5 Zahlen
/*
/*      Konzepte/       main-Funktion, Variablen, Konstanten, EA-Bibliothek
/*      Sprachelemente: Funktion printf, while-Schleife
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Es werden die sicheren Funktionen z.B. scanf_s(...)
/*                      anstatt scanf(...) genutzt. Die _s Versionen der bekannten
/*						Funktionen bieten mehr Sicherheit als ihre Vorgänger.
/*
/*		Grundlagen zur Verwendung von scanf_s():
/*
/*		int myint;
/*		float myfloat;
/*		char mychar;
/*		char mystring[80];
/*
/*		scanf_s("%d", &myint);
/*		scanf_s("%f", &myfloat);
/*		scanf_s("%c", &mychar, 1);
/*		scanf_s("%s", mystring, 79);
/*		scanf_s("%d %f %c %s", &myint, &myfloat, &mychar, 1, mystring, 79);
/*
/*		Bei char und char[n](Strings) muss die Groesse des zugesicherten 
/*		Speichers mit angegeben werden.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* EA-Funktionen bereitstellen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int i;              /* Zaehler fuer reelle Zahlen */
    float max;          /* Maximum reeller Zahlen */
    float zahl;         /* eine reelle Zahl */

    /* Anweisungen */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 01-03, Maximum von 5 reellen Zahlen -------\n\n");

    /* Eingabe */
    printf("\nDas Programm bestimmt das Maximum von 5 positiven ");
    printf(" reellen Zahlen.\n.\n");
    printf("\nBitte jede Eingabe mit RETURN beenden und jeweils eine");
    printf("\npositive reelle Zahlen mit Dezimalpunkt eingeben.\n\n");

    i = 0;                              /* Zaehler initialisieren */
    max = 0.0;                          /* Maximum initialisieren */
    
    /* es folgt Schleife: */
    while (i < 5)                       /* Test: i noch kleiner als 5 ? */
    {                                   /* wenn ja, dann erneut: */
        printf("%d-te Zahl: ", i+1);
        scanf_s("%f", &zahl);           /* Einlesen der naechsten Zahl */
        if (zahl > max)                 /* Vergleich und eventuell */
	    max = zahl;						/* Aktualisierung des Maximums */
	

        i = i + 1;                      /* Zaehler aktualisieren */
    }                                   /* Ende der Schleife */

    /* Ausgabe */
    printf("\nMaximale Zahl lautet: %f", max);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Erstellen Sie durch eine einfache Modifikation aus dem Programm 01-03 ein
  Programm, welches das Minimum von 5 Zahlen bestimmt. Dabei sei vorausgesetzt,
  dass nur Zahlen kleiner als 1000.0 zu vergleichen sind. Erforderlich ist,
  dass Sie in dem Vergleich
        zahl > max
  das >-Zeichen durch das <-Zeichen ersetzen. Ausserdem muessen die Texte der
  printf-Ausgaben geaendert werden. Ferner sollten auch die Variablennamen und
  Kommentare angepasst werden: z.B. max -> min. Schliesslich ist die Variable 
  min geeignet zu initialisieren. 

  Uebersetzen und binden Sie das geaenderte Programm und fuehren Sie es aus.
  Verhaelt es sich korrekt?

******************************************************************************/

