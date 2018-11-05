
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       01-02, Berechnung des Minimums zweier Zahlen
/*
/*      Konzepte/       main-Funktion, Variablen, Konstanten, EA-Bibliothek
/*      Sprachelemente: Funktion printf, if-else-Auswahl
/*
/*      Aufgabenteil:   nein
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Es werden die sicheren Funktionen z.B. scanf_s(...)
/*                      anstatt scanf(...) genutzt. Die _s Versionen der bekannten
/*						Funktionen bieten „mehr Sicherheit“ als ihre Vorgänger.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* EA-Funktionen bereitstellen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE  {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    float a, b, min;

    /* Anweisungen */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 01-02, Minimum zweier reeller Zahlen ------\n\n");

    /* Eingabe */
    printf("\nBitte jede Eingabe mit RETURN beenden.");
    printf("\nBitte reelle Zahlen mit Dezimalpunkt (z.B. 5.9) eingeben.\n");
    printf("\nErste Zahl: ");
    scanf_s("%f",&a);
    printf("Zweite Zahl: ");
    scanf_s("%f",&b);

    /* Berechnung */
    if (a < b)          /* Test der Bedingung a < b */
        min = a;        /* wenn erfuellt: Anweisung-1 */
    else                /* andernfalls: */
        min = b;        /* Anweisung-2 */

    /* Ausgabe */
    printf("Minimum von %f und %f lautet: %f", a, b, min);
    PAUSE;
}

