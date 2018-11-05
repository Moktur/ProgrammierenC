
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-12, Artikeldaten in einem Strukturvektor
/*
/*      Konzepte/       Zeigeranwendung auf Strukturen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm liest Artikeldaten in ein Strukturfeld ein und gibt
/*          diese wieder aus. Demonstriert wird der Zeigerzugriff auf
/*          Strukturen, vermieden wird das Kopieren von Strukturen.
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

struct artikel
{
    int  nummer;
    char bezeichnung[21];
    float preis;
};

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void einlesen_artikel(struct artikel *art_zgr);
void ausgeben_artikel(struct artikel *art_zgr);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    struct artikel artikel_liste[10];    /* Strukturvektor */
    struct artikel *art_zgr;
    int anz, i;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-12, Artikeldaten in Strukturvektor -----\n\n");
    printf("\nDas Programm liest Artikeldaten ein und gibt diese wieder aus.\n");
    printf("\nArtikelnamen duerfen max. 20 Zeichen umfassen und keine Leerzeichen");
    printf("\nenthalten. Artikelnummern werden als int-Werte, Preise als float-");
    printf("\nWerte erwartet.\n");

    /* Eingabe */
    printf("\nDateneingabe.");
    printf("\nBitte Artikel-Anzahl eingeben (<= 10): "); scanf_s("%d",&anz);

    /* Einlesen Artikel mit Indexzugriff */
    for (i = 0; i < anz; i++)
        einlesen_artikel(&artikel_liste[i]);

    PAUSE;
    /* Ausgabe Artikel mit Zeigerzugriff */
    printf("\nDatenausgabe.");
    i = 0;
    for (art_zgr = artikel_liste; art_zgr <= artikel_liste+anz-1; art_zgr++)
      {   
          ausgeben_artikel(art_zgr);
          if (++i%5==0)
              PAUSE;
      }
    PAUSE;
}

/* - Funktion liest Daten eines Artikels aus
   - Funktion erhaelt Strukturadresse
   - kein Kopieren von Strukturen */
void einlesen_artikel(struct artikel *art_zgr)
{
    float preis;

    printf("\nBitte Artikel eingeben");
    printf("\nArtikel-Nummer:  ");    scanf_s("%d", &art_zgr->nummer);
    printf("Artikel-Bezeichnung:  "); scanf_s("%s",art_zgr->bezeichnung, (int)sizeof(art_zgr->bezeichnung)-1);
                                      /* ohne & !*/
    printf("Artikel-Preis:  ");       scanf_s("%f", &preis);
    art_zgr->preis = preis;
}

/* - Funktion gibt Daten eines Artikels aus
   - Funktion erhaelt Strukturadresse 
   - kein Kopieren von Strukturen */
void ausgeben_artikel(struct artikel *art_zgr)
{
    printf("\n\nArtikel-Nummer:  %d", art_zgr->nummer);
    printf("\nArtikel-Bezeichnung: %s", art_zgr->bezeichnung);
    printf("\nArtikel-Preis:  %.2f", art_zgr->preis);  
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Kontrollieren Sie die korrekte Eingabe der Artikelanzahl.
  - Erweitern Sie den Strukturtyp struct artikel um weitere Komponenten.
  - Ergaenzen Sie die Funktionen fuer Ein- und Ausgabe entsprechend.

******************************************************************************/
