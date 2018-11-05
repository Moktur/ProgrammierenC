
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-03 sowie 14-06-1, 14-06-2,
/*                      Artikelverwaltung im Arbeitsspeicher
/*
/*      Konzepte/       Implementierung eines abstrakten Datentyps (ADT)
/*      Sprachelemente: Artikelbestand, Modularisierung
/*
/*      Beschreibung:
/*
/*      Das Programm realisiert eine Artikelverwaltung im Arbeitsspeicher
/*      mit typischen Verwaltungsfunktionen wie Einfuegen-Artikel, 
/*      Aendern-Artikel usw.
/*
/*      Das Programm umfasst fuer das Beispiel 13-03 die Dateien:
/*          - b13-03-1.c,
/*          - b13-03-1.h,
/*          - b13-03-2.c,
/*          - b13-03-2.h und
/*          - b15-06.h.
/*     Zur Erzeugung eines ausfuehrbaren Programms sind die Dateien
/*     b13-03-1.c und b13-03-2.c zu binden.
/*
/*     Fuer die Beispiele 14-06-1 und 14-06-2 ist die Datei b13-02-c
/*     durch die Dateien
/*     - b14-06-1.c bzw.
/*     - b14-06-2.c zu ersetzen, waehrend die anderen Dateien
/*     unveraendert zu dem jeweiligen Beispielprogramm gehoeren.
/*     Fuer die Beispiele 14-06-1 bzw. 14-06-2 sind also die Dateien
/*     - b13-03-1.c und b14-06-1.c bzw.
/*     - b13-03-1.c und b14-06-2.c zu binden.
/*
/*     Das Programm benutzt in allen drei Varianten einen unterschiedlich
/*     implementierten ADT Artikelbestand. Dieser wird
/*     durch die Dateien
/*     - b13-03-2.c und b13-03-2.h (Vektorvariante),
/*     - b14-06-1.c und b13-03-2.h (sortierte-Listenvariante),
/*     - b14-06-2.c und b13-03-2.h (Binaerbaumvariante)
/*     bereitgestellt. Die Datei b13-03-1.c stellt einen Anwendungsmodul
/*     fuer den ADT Artikelbestand in allen drei Varianten dar, waehrend
/*     die Definitionsdatei b13-03-1.h zu diesem Anwendungsmodul gehoert.
/*     
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <ctype.h>                 /* wg. Funktion tolower, siehe main */

#define anwendungsdatei            /* zur Steuerung von #include b13-03-1.h */
#include "b13-03-1.h"              /* Definitionsdatei fuer Anwendungsmodul */
#include "b13-03-2.h"              /* Definitionsdatei fuer ADT */

/*****************************************************************************/
/* Makro definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
  char wahl;
  char eingabe;

  init_artbestand();     /* Artikelbestand leer initialisieren */

  do                     /* wiederholt Auswahlmenue anbieten und */
  {                      /* gewaehlte Funktion rufen */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("--- Beispiel: 13-03, 14-06-1, 14-06-2, Artikelverwaltung --\n");
    printf("\n%s%s%s%s%s%s%s%s%s%s",
           "\nProgramm verwaltet Artikelbestand im Arbeitsspeicher",
           "\n====================================================",
           "\nBitte eine Funktion waehlen: ",
           "\n  1. Artikel erfassen:..........E",
           "\n  2. Artikel anzeigen:..........Z",
           "\n  3. Artikel aendern:...........A",
           "\n  4. Artikel loeschen:..........L",
           "\n  5. Artikelbestand anzeigen:...B",
           "\n  6. Programm beenden:..........Q",
           "\nIhre Wahl: ");
    scanf_s("%c", &eingabe, (int)sizeof(eingabe));
    wahl = tolower(eingabe); /* Umwandlung in Kleinbuchstaben, vgl. Anhang A2 */
    switch(wahl)
    {
        case 'e': erfassen_artikel(); PAUSE; break;
        case 'z': anzeigen_artikel(); PAUSE; break;
        case 'a': aendern_artikel(); PAUSE; break;
        case 'l': loeschen_artikel(); PAUSE; break;
        case 'b': anzeige_artbestand(); PAUSE; break;
        case 'q': break;
        default : printf("\nEingabe unzulaessig"); PAUSE; break;
    }
  } while (wahl != 'q');
  loesche_artbestand();  /* Artikelbestand abschliessend loeschen */
}

/* erfasst einen Artikel */
void erfassen_artikel(void)
{
  ARTIKEL artikel;

  printf("\n<<< Artikel erfassen >>>\n");
  printf("Artikel-Nummer (positiv, ganz): "); scanf_s("%d",&artikel.nr);
  printf("Artikel-Name (max. 15 Zeichen): "); scanf_s("%s",artikel.name, (int)sizeof(artikel.name)-1);
  printf("Artikel-Preis (positiv, reell): "); scanf_s("%f",&artikel.preis);
  if (einfuege_art(&artikel))
       printf("\nArtikel wurde erfasst!");
  else printf("\nArtikel wurde nicht erfasst!");
}

/* zeigt einen Artikel an */
void anzeigen_artikel(void)
{
  ARTIKEL artikel;

  printf("\n<<< Erfassten Artikel anzeigen >>>");
  printf("\nArtikel-Nummer: "); scanf_s("%d",&artikel.nr);
  if (suche_art(&artikel))
  {
       printf("Artikel-Name: %s",artikel.name);
       printf("\nArtikel-Preis: %.2f", artikel.preis);
  }
  else printf("\nArtikel wurde nicht gefunden!");
}

/* aendert die Daten eines Artikels */
void aendern_artikel(void)
{
  ARTIKEL artikel;

  printf("\n<<< Erfassten Artikel aendern >>>");
  printf("\nArtikel-Nummer: "); scanf_s("%d",&artikel.nr);
  if (suche_art(&artikel))
  {
      printf("Artikel-Name: %s Neuer Name: ",artikel.name);
      scanf_s("%s", artikel.name, (int)sizeof(artikel.name)-1);
      printf("Artikel-Preis: %.2f Neuer Preis: ", artikel.preis);
      scanf_s("%f", &artikel.preis);
      if (ersetze_art(&artikel))
          printf("\nArtikel wurde geaendert!");
      else printf("\nArtikel wurde nicht geaendert!");
  }
  else printf("\nArtikel wurde nicht gefunden!");
}

/* loescht einen Artikel */
void loeschen_artikel(void)
{
  ARTIKEL artikel;

  printf("\n<<< Erfassten Artikel loeschen >>>");
  printf("\nArtikel-Nummer: "); scanf_s("%d",&artikel.nr);
  if (ausfuege_art(&artikel))
      printf("\nArtikel wurde geloescht!");
  else printf("\nArtikel konnte nicht geloescht werden!");
}

/* Funktion gibt aus:
   - ggf. Listenkopf einer Artikel-Bestandsliste,
   - Daten eines Artikels zu uebergebener Adresse
   Funktion wird benutzt bei Ausgabe des Artikelbestandes
   mittels Funktion anzeige_artbestand des Verwaltungsmoduls
*/
void print_artikel(int nr, ART_ZGR art_zgr)
{
  if (nr%15==0)                        /* ggf. neue Seite mit Listenkopf */
  {  
     if (nr > 0)                       /* wenn 15 Eintraege aufgelistet */
         PAUSE;
     printf("\n\n<<< Artikelbestand >>>"
       "\nArt.-Nr. Art.-Name        Art.-Preis (EUR)"
       "\n-----------------------------------------");
  }
  /* ein Artikel ausgeben */
  printf("\n%-9d%-17s%.2f", art_zgr->nr,art_zgr->name,art_zgr->preis);
}