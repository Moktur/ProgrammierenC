
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       09-03, Verwaltung von Lehrgangsdaten
/*
/*      Konzepte/       Bitfelder
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Programm liest Daten von Teilnehmern einer beruflichen
/*          Weiterbildung ein und gibt sie aus. Zur Aufgabenstellung
/*          vgl. Kap. 9.4. Demonstriert wird der Umgang mit Bitfeldern.
/*
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

/* Definition des Bitfeldtyps WB_TEILNEHMER */
typedef struct
{
    unsigned int nr:8;          /* 0..255 */
    unsigned int kurs_A:1;      /* 0..1, 0 = nein, 1 = ja */
    int          note_A:3;      /* -4..+3 */
    unsigned int kurs_B:1;      /* analog kurs_A */
    int          note_B:3;      /* analog note_A */
} WB_TEILNEHMER;

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

/* globales Strukturfeld vom Typ PERSON */
WB_TEILNEHMER  wb_teilnehmer[255];

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

WB_TEILNEHMER einlesen_teilnehmer(void);
void ausgeben_teilnehmer(WB_TEILNEHMER teilnehmer);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int           i, anz_teilnehmer;
    WB_TEILNEHMER teilnehmer;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 09-03, Lehrgangsdatenverwaltung -----------\n\n");
    printf("\nDas Programm verwaltet Weiterbildungsdaten mit Bitfeldern.\n");

    /* Eingabe */
    printf("\nDateneingabe.");
    printf("\nAnzahl Teilnehmer der Weiterbildung eingeben (<=255): ");
    scanf_s("%d",&anz_teilnehmer);

    for (i = 0; i < anz_teilnehmer; i++)
        wb_teilnehmer[i] = einlesen_teilnehmer();

    /* Ausgabe */
    printf("\nDatenausgabe.");
    for (i = 0; i < anz_teilnehmer; i++)
        ausgeben_teilnehmer(wb_teilnehmer[i]);
    printf("\n\nGroesse einer Bitfeld-Struktur in Bytes: %d",
           sizeof(teilnehmer));
    PAUSE;
}

/* liest Daten fuer einen Weiterbildungsteilnehmer ein, beachte: Rueckgabewert
   ist vom Typ WB_TEILNEHMER */
WB_TEILNEHMER einlesen_teilnehmer(void)
{
    unsigned int nr;
    unsigned int beteiligt;
    int          note;
    WB_TEILNEHMER teilnehmer;

    printf("\nTeilnehmer-Nr: "); scanf_s("%d", &nr);
    teilnehmer.nr = nr;

    printf("Teilnahme an Kurs A (0:nein,1:ja): "); scanf_s("%d",&beteiligt);
    teilnehmer.kurs_A = beteiligt;
    if (teilnehmer.kurs_A == 1)
    {
        printf("Note Kurs A (-4..+3): "); scanf_s("%d",&note);
        teilnehmer.note_A = note;
    }

    printf("Teilnahme an Kurs B (0:nein,1:ja): "); scanf_s("%d",&beteiligt);
    teilnehmer.kurs_B = beteiligt;
    if (teilnehmer.kurs_B == 1)
    {
        printf("Note Kurs B (-4..+3): "); scanf_s("%d",&note);
        teilnehmer.note_B = note;
    }

    return teilnehmer;
}

/* gibt Daten fuer einen Weiterbildungsteilnehmer aus, beachte: formaler
   Parameter ist vom Typ WB_TEILNEHMER */
void ausgeben_teilnehmer(WB_TEILNEHMER teilnehmer)
{
    printf("\nTeilnehmer-Nr: %d", teilnehmer.nr);
    printf("\nTeilnahme Kurs A (0:nein,1:ja): %d", teilnehmer.kurs_A);
    if (teilnehmer.kurs_A == 1)
        printf("  Note Kurs A (-4..+3): %d", teilnehmer.note_A);
    printf("\nTeilnahme Kurs B (0:nein,1:ja): %d", teilnehmer.kurs_B);
    if (teilnehmer.kurs_B == 1)
        printf("  Note Kurs B (-4..+3): %d", teilnehmer.note_B);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Verbessern Sie die Ausgabe, indem die Teilnahme an einem
    Kurs durch die Worte "ja" bzw. "nein" angezeigt wird.
  - Variieren Sie die Breite der Komponenten der Bitfeldstruktur
    sowie deren Typ. Stellen Sie die Auswirkung auf die Groesse der
    Bitfeldstruktur sowie auf den darstellbaren Bereich fest.
  - Fuehren Sie eine oder mehrere weitere Komponenten in die
    Bitfeldstruktur wie z.B. Klausurnote und Note der muendlichen
    Pruefung geeignet ein und erweitern Sie die Datenpflegefunktionen
    entsprechend. Ermitteln Sie erneut den Platzbedarf
    der modifizierten Bitfeldstruktur.

******************************************************************************/
