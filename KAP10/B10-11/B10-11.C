
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-11, Ermittlung von Wochentagsnamen
/*
/*      Konzepte/       Vektor von Zeigern auf Zeichenketten sowie Funktionen,
/*      Sprachelemente: die einen Zeiger auf eine Zeichenkette liefern
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm ermittelt Tagesnamen. Demonstriert wird die Verwendung
/*          eines Feldes von Zeigern auf Zeichenketten sowie eine Funktion, die
/*          einen Zeiger auf eine Zeichenkette zurueckgibt.
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

/* Prototyp, Funktion liefert Zeiger auf char */ 
char *ermittle_tagesnamen(int tag_nr); 

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int tages_nr;  
    char *str_zgr;
  
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-11, Tagesnamen -------------------------\n\n");

    printf("\nDas Programm ermittelt Tagesnamen zu Wochentagsnummern.\n");
    printf("\nBitte Nummer eines Wochentages eingeben (Mo = 0,..., So = 6): ");
    scanf_s("%d", &tages_nr);
    if (tages_nr < 0 || tages_nr > 6)
        printf("\nEingegebene Wochentagsnummer ist ungueltig!");
    else 
    {
        str_zgr = ermittle_tagesnamen(tages_nr);
        printf("\nName des Wochentages ist: %s", str_zgr); 
    }    
    PAUSE;
}

/* 
    Die Funktion ermittle_tagesnamen liefert bei einem Aufruf
    zur uebergebenen Tagesnummer die Adresse der Zeichenkette
    mit dem zugehoerigen Namen.

    Das Feld wochentage enthaelt Zeiger auf das jeweils erste
    Byte der vereinbarten Zeichenkettenkonstanten;
    z.B. zeigt wochentage[0] auf die Zeichenkette "Montag".
*/

char *ermittle_tagesnamen(int tag_nr)
{
    /* Feld von char-Zeigern */
    static char *wochentage[7] = {"Montag", "Dienstag",
                                  "Mittwoch", "Donnerstag",
                                  "Freitag", "Sonnabend", "Sonntag"};
    return wochentage[tag_nr];
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Schreiben Sie ein analoges Programm, das Monatsnamen zu Monatsnummern
  ausgibt.

******************************************************************************/
