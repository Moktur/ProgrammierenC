
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-07, Umrechnung Celsius in Fahrenheit
/*
/*      Konzepte/       arithmetische Operatoren
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm rechnet die von Ihnen in Celsius
/*                      angegebene Temperatur in Fahrenheit um.
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Es werden die sicheren Funktionen z.B. scanf_s(...)
/*                      anstatt scanf(...) genutzt. Die _s Versionen der bekannten
/*						Funktionen bieten �mehr Sicherheit� als ihre Vorg�nger.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    float celsius;      /* Temperatur in Celsius */
    float fahrenheit;   /* Temperatur in Fahrenheit */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-07, Umrechnung Celsius in Fahrenheit ---\n\n");

    printf("\nDas Programm rechnet eine Temperatur von Celsius in Fahrenheit um.\n");

    /* Abfrage der Temperatur in Celsius */
    printf("\nWelche Temperatur moechten Sie in Fahrenheit umrechnen: ");
    scanf_s("%f", &celsius);

    /* Umrechnung der Temperatur */
    fahrenheit = 9.0f / 5.0f * celsius + 32.0f;

    /* Ausgabe der Temperatur in Fahrenheit */
    printf("\n%.2f Grad Celsius ", celsius);
    printf("sind %.2f Grad Fahrenheit.\n", fahrenheit);
    PAUSE;
}
