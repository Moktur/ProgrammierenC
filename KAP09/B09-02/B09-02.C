
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       09-02, Elementares Unionen-Beispiel
/*
/*      Konzepte/       Unionen
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
/* Datentypen definieren
/*****************************************************************************/

typedef union       /* Definition des Unionentyps WERT  */
{
    char  cwert;
    int   iwert;
    float fwert;
} WERT;

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

/* globale Variable zur Protokollierung der Benutzung einer Union */
int protokoll;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

WERT einlesen_wert(void);
void ausgeben_wert(WERT wert);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    WERT ein_wert, aus_wert;        /* 2 Unionen */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 09-02, Elementares Unionenbeispiel --------\n\n");

    printf("\nDas Programm zeigt ein einfaches Beispiel fuer Unionen.\n");
    printf("\nLaenge der Union: %d",sizeof(WERT)); /* Laenge in Bytes */
    ein_wert = einlesen_wert();                    /* Union einlesen */
    aus_wert = ein_wert;                           /* Unionen zuweisen */
    ausgeben_wert(aus_wert);                       /* Union ausgeben */
    PAUSE;
}

/* liest Wert in eine Union ein, beachte: Rueckgabewert vom Typ WERT */
WERT einlesen_wert(void)
{
    WERT ein_wert;

    printf("\nWert-Typ (0=char,1=int,2=float): "); scanf_s("%d", &protokoll);
	fflush(stdin);
    if (protokoll == 0)
    {
        printf("\nBitte 1 Zeichen: ");
        scanf_s("%c",&ein_wert.cwert, 1);
    }
    else if (protokoll == 1)
    {
        printf("\nBitte 1 int-Wert: ");
        scanf_s("%d",&ein_wert.iwert);
    }
    else if (protokoll == 2)
    {
        printf("\nBitte 1 float-Wert: ");
        scanf_s("%f",&ein_wert.fwert);
    }

    return ein_wert;
}

/* gibt uebergebene Union aus, beachte: formaler Parameter vom Typ WERT */
void ausgeben_wert(WERT aus_wert)
{
  if (protokoll == 0)       /* Ausgabe gemaess der Protokollvariable */
        printf("\nZeichen: %c", aus_wert.cwert);
  else if (protokoll == 1)
        printf("\nint-Wert: %d", aus_wert.iwert);
  else if (protokoll == 2)
        printf("\nfloat-Wert: %f", aus_wert.fwert);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Probieren Sie aus, was passiert, wenn eine Union nicht typgerecht
    d.h. dem Typ des letzten Wertes entsprechend ausgelesen wird.
  - Aendern Sie das Programm derart ab, dass die Protokollvariable
    nicht mehr global ist, sondern als Rueckgabewert der
    Eingabefunktion bzw. als Parameter der Ausgabefunktion behandelt
    wird. Stattdessen soll die verarbeitete Union global sein.

******************************************************************************/
