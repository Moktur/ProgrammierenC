
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-01, Volumen eines Kreiskegels I
/*
/*      Konzepte/       Programm mit mehreren Funktionen, Parameteruebergabe,
/*      Sprachelemente: Prototypen
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Es werden die sicheren Funktionen z.B. gets_s(vorname, 16);
/*                      anstatt gets(vorname); genutzt. Die _s Versionen der bekannten
/*						Funktionen bieten mehr Sicherheit als ihre Vorgänger,
/*						benoetigen aber zum Teil die Groesse der Arrays in Bytes.
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

float berechne_kegelvol(float hoehe, float radius);
void print_kegelvol(float vol);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    float hoehe_ein,            /* eingegebene Hoehe */
          radius_ein,           /* eingegebener Radius */
          kegel_volumen;        /* berechnetes Volumen */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-01, Volumen eines Kreiskegels I --------\n");

    printf("\nDas Programm ermittelt ein Kreiskegelvolumen.\n");

    /* Eingabe */
    printf("\nBitte positive reelle Werte fuer Radius und Hoehe");
    printf("\neines Kreiskegels eingeben.");
    printf("\nRadius: "); scanf_s("%f",&radius_ein);
    printf("Hoehe:  ");    scanf_s("%f",&hoehe_ein);

    /* Funktionsaufruf fuer Berechnung */
    kegel_volumen = berechne_kegelvol(hoehe_ein, radius_ein);

    /* Funktionsaufruf fuer Ausgabe */
    print_kegelvol(kegel_volumen);
    PAUSE;
}

/* Funktion berechnet Volumen eines Kreiskegels */
float berechne_kegelvol(float hoehe, float radius)
{   
    /* lokale Vereinbarungen */
    const float pi = 3.14159F;
    float vol;

    /* Anweisungen */
    vol = (float)(radius*radius*pi*hoehe/3.0);
    return (vol);
}

/* Funktion gibt berechnetes Kegelvolumen aus */
void print_kegelvol(float vol)
{   
    /* Anweisungen */
    printf("\nDas Volumen des Kreiskegels betraegt: %.2f",vol);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Kommentieren Sie die Prototypen aus und uebersetzen Sie erneut.
    Wie sind die Compilermeldungen zu erklaeren? Zu beachten ist, dass
    als Defaulttyp fuer Rueckgabewerte von Funktionen der Typ int
    angenommen wird.
  - Erweitern Sie das Programm derart, dass wahlweise ein Kegelvolumen
    oder ein Zylindervolumen berechnet werden kann.
    Fragen Sie hierzu ab, ob ein Kegel- oder Zylindervolumen
    bestimmt werden soll. Ergaenzen Sie die Funktionen fuer Berechnung
    und Ausgabe um einen Parameter "variante" (0:Kegelvolumen,
    1:Zylindervolumen) und aendern Sie die Funktionsnamen sinnvoll ab.

******************************************************************************/
