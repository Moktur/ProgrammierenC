
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-07, Umfang und Flaeche eines Kreises
/*
/*      Konzepte/       Funktionsaufruf und Wertrueckgabe
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm ermittelt fuer verschiedene Kreise
/*                      jeweils wahlweise den Umfang oder die Flaeche
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros und Konstanten definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

const float PI = 3.14159f;    /* eine der wichtigsten Zahlen */

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

float umfang(float durchmesser);
float flaeche(float radius);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    float radius;         /* Radius */
    float resultat;       /* Resultat = Umfang oder Flaeche */
    char  wahl;           /* gewuenschte Berechnung, u = Umfang, f = Flaeche */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-07, Umfang und Flaeche eines Kreises ---\n\n");

    printf("\nDas Programm berechnet wiederholt");
    printf(" Umfang oder Flaeche eines Kreises.");

    /* Berechnungen */
    printf("\nGeben Sie als Radius jeweils einen positiven reellen Wert ein.");
    printf("\nBrechen Sie die Berechnungen ab, indem Sie als Radius einen ");
    printf("\nnegativen Wert eingeben.\n");
    do
    {
          /* Radius abfragen */
          printf("\nRadius: ");
          scanf_s("%f", &radius);

        if (radius >= 0)
        {
			fflush(stdin);
            /* Art der Berechnung abfragen */
            printf("Umfang oder Flaeche berechnen (u/f) ? ");
            scanf_s("%c", &wahl, 1);

            switch (wahl)
            {
                case 'u':
                case 'U':
                    /* Funktionsaufruf */
                          resultat = umfang(radius);
                          printf("Der Umfang des Kreises betraegt: %.2f \n", resultat);
                    break;
                case 'f':
                case 'F':
                    /* Funktionsaufruf */
                          resultat = flaeche(radius);
                          printf("Die Flaeche des Kreises betraegt: %.2f \n", resultat);
                    break;
                default:
                    printf("Welche Berechnung soll ich durchfuehren?\n");
            }
        }
    } while (radius >= 0);
    PAUSE;
}

/* Funktion: umfang
   berechnet den Umfang eines Kreises */
float umfang(float radius)
{    
    /* lokale Variablen */
    float ergebnis;

    /* Anweisungen */
    ergebnis = 2 * PI * radius;

    /* Rueckgabewert liefern */
    return (ergebnis);
}

/* Funktion: flaeche
   berechnet den Flaecheninhalt eines Kreises */
float flaeche(float radius)
{
    /* lokale Variablen */
    float ergebnis;

    /* Anweisungen */
    ergebnis = radius * radius * PI;

    /* Rueckgabewert liefern */
    return ergebnis;
}
