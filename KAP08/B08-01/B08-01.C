
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-01, Multiplikation eines Vektors mit einer Zahl
/*
/*      Konzepte/       Vektoren
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
    float vektor[10];   /* Vektor mit 10 floats */
    float faktor;       /* Faktor fuer Multiplikation */
    int i;              /* Index fuer Vektorzugriff */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-01, Multiplikation Vektor mit Zahl -----\n\n");

    printf("\nDas Programm multipliziert einen float-Vektor mit einem float-Faktor.\n");
    printf("\nBitte float-Faktor eingeben: ");
    scanf_s("%f", &faktor);
    printf("\nBitte Vektor mit 10 float-Zahlen eingeben:\n");

    /* Feldeingabe mit Schleife */
    for (i = 0; i < 10; i++)
    {
        printf("Platz: %d Wert: ",i+1);
        scanf_s("%f",&vektor[i]);
    }

    /* Feldverarbeitung mit Schleife */
    for (i = 0; i < 10; i++)
        vektor[i] *= faktor;

    printf("\nBerechneter Vektor (Platz und Wert):");

    /* Feldausgabe mit Schleife */
    for (i = 0; i < 10; i++)
        printf("\n%2d\t%.2f",i+1,vektor[i]);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Vergroessern Sie den Vektor und behandeln Sie die Anzahl der
    zu bearbeitenden Vektorelemente als Eingabegroesse. Zu pruefen ist, 
    ob die eingegebene Anzahl zu bearbeitender Vektorelemente 
    die Vektorlaenge ueberschreitet. In diesem Fall geben Sie eine 
    Meldung aus und beenden Sie das Programm mit return.
  - Gliedern Sie das Programm in Funktionen fuer Eingabe, Berechnung
    und Ausgabe. Definieren Sie hierzu den Vektor vektor global
    (Uebergabe von Vektoren als Parameter werden wir erst spaeter
    behandeln).
  - Schreiben Sie zusaetzliche Verarbeitungsfunktionen, z.B. Ermittlung
    der Summe, des kleinsten und des groessten Elements des Vektors,
    die dann wahlweise aufgerufen werden koennen (vgl. Beispiel 7.1).

******************************************************************************/
