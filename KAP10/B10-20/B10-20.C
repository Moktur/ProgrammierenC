
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-20, Summe zweier Brueche
/*
/*      Konzepte/       Uebergabe von Zeigern auf Strukturen an Funktionen
/*      Sprachelemente: Zugriff auf Struktur-Komponenten ueber Zeiger
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm berechnet die Summe zweier Brueche, die
/*                      Sie eingeben.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros / Typen definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/* Diese Struktur nimmt den Bruch auf */
typedef struct
        {
            int zaehler;
            int nenner;
        } BRUCH;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

int  ggT(int a, int b);
int  kgV(int a, int b);
void erweitern(BRUCH *bruch, int hauptnenner);
void kuerzen(BRUCH *bruch);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    BRUCH x, y, z;
    int   hauptnenner;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-20, Summe zweier Brueche ---------------\n\n");
    printf("\nDas Programm berechnet die Summe zweier Brueche.\n\n");

    /* Der Benutzer soll die ersten beiden Brueche eingeben */
    printf("Geben Sie bitte den 1.Bruch in der Form a/b ein: ");
    scanf_s("%d/%d", &x.zaehler, &x.nenner);
    printf("Geben Sie bitte den 2.Bruch in der Form a/b ein: ");
    scanf_s("%d/%d", &y.zaehler, &y.nenner);

    /* Berechne die Summe der beiden eingebener Brueche */
    printf("\n%d/%d + %d/%d = ", x.zaehler, x.nenner, y.zaehler, y.nenner);
    /* Bestimme den Hauptnenner */
    hauptnenner = kgV(x.nenner, y.nenner);
    /* Erweitere beide Brueche um den Hauptnenner */
    erweitern(&x, hauptnenner);
    erweitern(&y, hauptnenner);
    /* Berechne die Summe beider Brueche */
    z.zaehler = x.zaehler + y.zaehler;
    z.nenner = hauptnenner;
    /* Kuerze den Bruch */
    kuerzen(&z);
    /* Gib das Ergebnis am Bildschirm aus */
    printf("%d/%d\n", z.zaehler, z.nenner);
    PAUSE;
}

/* Funktion ggt,
   bestimmt den groessten gemeinsamen Teiler der Zahlen a und b */
int ggT(int a, int b)
{
    /* lokale Variablen definieren */
    int rest;

    /* Anweisungen */

    /* Bestimme den ggT */
    do
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    while (rest != 0);

    /* Rueckgabewert liefern */
    return a;
}

/* Funktion kgV,
   bestimmt das kleinste gemeinsame Vielfache der Zahlen a und b */
int kgV(int a, int b)
{
    /* lokale Variablen definieren */
    int kgV;

    /* Anweisungen */
    kgV = a * b / ggT(a, b);

    /* Rueckgabewert liefern */
    return kgV;
}

/* Funktion erweitern,
   erweitert den Bruch um den uebergebenen Hauptnenner */
void erweitern(BRUCH *bruch, int hauptnenner)
{
    /* Anweisungen */

    /* Erweitere den Bruch */
    bruch->zaehler *= (hauptnenner / bruch->nenner);
    bruch->nenner = hauptnenner;
}

/* Funktion kuerzen
   kuerzt den Bruch soweit es geht */
void kuerzen(BRUCH *bruch)
{
    /* lokale Variablen definieren */
    int divisor;

    /* Anweisungen */

    /* Bestimme den Divisor */
    divisor = ggT(bruch->zaehler, bruch->nenner);

    if (divisor != 1)
    {
        bruch->zaehler /= divisor;
        bruch->nenner /= divisor;
    }
}
