
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-02, Volumen eines Kreiskegels II
/*
/*      Konzepte/       Programm mit mehreren Funktionen, globale Variablen
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
/* Funktionen deklarieren
/*****************************************************************************/

void berechne_kegelvol(void);
void print_kegelvol(void);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

float hoehe,                /* eingegebene Hoehe */
      radius,               /* eingegebener Radius */
      kegel_volumen;        /* berechnetes Volumen */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-02, Volumen eines Kreiskegels II -------\n\n");

    printf("\nDas Programm ermittelt ein Kreiskegelvolumen.\n");

    /* Eingabe */
    printf("\nBitte positive reelle Werte fuer Radius und Hoehe");
    printf("\neines Kreiskegels eingeben.");
    printf("\nRadius: "); scanf_s("%f",&radius);
    printf("Hoehe:  "); scanf_s("%f",&hoehe);

    /* Funktionsaufruf fuer Berechnung */
    berechne_kegelvol();

    /* Funktionsaufruf fuer Ausgabe */
    print_kegelvol();
    PAUSE;
}

/* Funktion berechnet Volumen eines Kreiskegels */
void berechne_kegelvol(void)
{   
    /* lokale Vereinbarung */
    const float pi = 3.14159F;

    /* Anweisung */
    kegel_volumen = (float)(radius*radius*pi*hoehe/3.0);
}

/* Funktion gibt berechnetes Kegelvolumen aus */
void print_kegelvol(void)
{   
    printf("\nDas Volumen des Kreiskegels betraegt: %.2f",kegel_volumen);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Verlegen Sie die Definition der globalen Variablen hinter eine der
    Funktionen oder an das Programmende. Wie reagiert der Compiler?
    Deklarieren Sie jetzt zusaetzlich die globalen Variablen am Programm-
    anfang (mit extern). Laeuft das Programm wieder? Probieren Sie auch
    lokale Deklarationen der globalen Variablen aus, bei denen am Anfang
    jeder Funktion jeweils nur die globalen Variablen deklariert werden,
    die die Funktion benoetigt. Vergewissern Sie sich etwa durch provi-
    sorische printf-Aufrufe, dass die nicht-deklarierten Variablen nicht
    sichtbar sind.
  - Erweitern Sie das Programm analog wie das Programmbeispiel 7.1. Waehlen
    Sie anstelle eines Parameters fuer den Auswahlschalter variante eine
    globale Variable.

******************************************************************************/
