
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs
/*
/*      Beispiel:       14-06-1, Artikelverwaltung im Arbeitsspeicher
/*
/*      Konzepte/       Implementierung eines abstrakten Datentyps (ADT)
/*      Sprachelemente: Artikelbestand, Modularisierung, verkettete Liste
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT Artikelbestand
/*                      (Listenvariante)
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "b13-03-1.h"                  /* Definitionsdatei fuer
														Anwendungsmodul */
#include "b13-03-2.h"                  /* Definitionsdatei fuer ADT
                                          unveraendert gueltig */

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

typedef struct art_knoten              /* Knotentyp */
{
    ARTIKEL a;         /* Artikeltyp des Anwendungsmoduls */
    struct art_knoten *next;
} ART_KNOTEN;

typedef ART_KNOTEN *ART_KNOTEN_ZGR;    /* zugehoeriger Zeigertyp */

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

static ART_KNOTEN_ZGR first;           /* Zeiger auf Listenanfang */
static int anz_art_knoten;             /* Anzahl Knoten in Liste */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/* initialisiert Artikelbestand mit leerer Artikelmenge */
void init_artbestand(void)
{
    first = NULL;
    anz_art_knoten = 0;
}

/* fuegt einen Artikel aufsteigend sortiert nach Nr. in Bestand ein */
/* gibt 1 zurueck, wenn Einfuegen erfolgreich, sonst 0 */
int einfuege_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr,                 /* zeigt auf aktuellen Knoten */
                   prev,                 /* zeigt auf Vorgaenger-Knoten */
                   temp;                 /* zeigt auf neuen Knoten */

    /* neuen Knoten bereitstellen und mit uebergebenem Artikel fuellen */
    temp = (ART_KNOTEN_ZGR)malloc(sizeof(ART_KNOTEN));
    if (temp == NULL)                    /* pruefen ob malloc versagt */
    {
        printf("\nArtikelbestand nicht erweiterbar");
        return 0;
    }
    temp->a = *art_zgr;                  /* Knoten fuellen */
    temp->next = NULL;                   /* next-Zeiger init. mit NULL */

    /* Einfuegestelle bestimmen - vor erstem Artikel mit hoeherer Nr. */
    for (curr = first, prev = NULL;      /* curr = 1. Knoten, prev nicht da */
         curr != NULL;                   /* bis Listenende */
         prev = curr, curr = curr->next) /* weiter zum naechsten Knoten */
    {
        if (art_zgr->nr == curr->a.nr)  /* keine mehrfache Art.Nr. */
        {
            printf("\nArtikelnummer bereits vorhanden");
            free(temp); 
            return 0;
        }
        else if (art_zgr->nr < curr->a.nr) /* Einfuegestelle hier */
            break;
    }

    /* einfuegen an Einfuegestelle */
    if (prev == NULL)                    /* Fall 1: kein Vorgaenger ->
                                            vorn einfuegen */
    {
        temp->next = first;              /* Nachfolger ist alter erster Knoten */
        first = temp;                    /* neuer Knoten wird erster Knoten */
    }
    
    /* Fall 2: Vorgaenger prev vorhanden -> */
    else                                 /* zwischen prev und curr einfuegen */
    {
        prev->next = temp;               /* Vorgaenger wird prev */
        temp->next = curr;               /* Nachfolger wird curr */
    }
    anz_art_knoten++;                    /* Anzahl Knoten erhoehen */
    return 1;
}

/* sucht einen Artikel mit gegebener Nr. und liefert dessen Daten */
/* gibt 1 zurueck, wenn Suche erfolgreich, sonst 0 */
int  suche_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr;                 /* zeigt auf aktuellen Knoten */

    for (curr = first;                   /* beginne mit erstem Knoten */
         curr != NULL;                   /* maximal bis Listenende */
         curr = curr->next)              /* weiter zum naechsten Knoten */
    {
        if (art_zgr->nr == curr->a.nr) /* Artikeldaten bereitstellen */
        {
            *art_zgr = curr->a;
            return 1;
        }

        else if (curr->a.nr > art_zgr->nr)/* Knoten mit gesuchter Nr. kann */
            return 0;                   /* nicht mehr erscheinen wg. Sort.*/
    }
    return 0;                            /* nichts gefunden */
}

/* ueberschreibt Daten eines Artikels mit gegebener Nr. */
/* gibt 1 zurueck, wenn Ersetzen erfolgreich, sonst 0 */
int  ersetze_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr;                 /* zeigt auf aktuellen Knoten */

    for (curr = first;                   /* beginne mit erstem Knoten */
         curr != NULL;                   /* maximal bis Listenende */
         curr = curr->next)              /* weiter zum naechsten Knoten */
    {
        if (art_zgr->nr == curr->a.nr)/* Artikeldaten ersetzen */
        {
            curr->a = *art_zgr;
            return 1;
        }
        else if (curr->a.nr > art_zgr->nr)/* Knoten mit gesuchter Nr. kann */
            return 0;                /* nicht mehr erscheinen wg. Sort.*/
    }
    return 0;                            /* nichts gefunden */
}

/* fuegt einen Artikel mit gegebener Nr. aus Bestand aus */
/* gibt 1 zurueck, wenn Ausfuegen erfolgreich, sonst 0 */
int  ausfuege_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr,                 /* zeigt auf aktuellen Knoten */
                   prev;                 /* zeigt auf Vorgaenger-Knoten */

    /* auszufuegenden Knoten aufsuchen */
    for (curr = first, prev = NULL;      /* curr = 1. Knoten, prev nicht da */
         curr != NULL;                   /* maximal bis Listenende */
         prev = curr, curr = curr->next) /* weiter zum naechsten Knoten */
    {
        if (art_zgr->nr == curr->a.nr)    /* wenn Knoten gefunden */
            break;                        /* Schleife verlassen */
        else if (curr->a.nr > art_zgr->nr)/* Knoten mit gesuchter Nr. kann */
            return 0;                     /* nicht mehr erscheinen wg. Sort.*/
    }

    if (curr != NULL)                    /* auszufuegender Knoten curr gefunden */
    {
        if (prev == NULL)                /* Fall 1: curr ist erster Knoten */
            first = curr->next;          /* curr-Nachfolger wird erster Knoten */
        else                             /* Fall 2: curr besitzt Vorgaenger */
            prev->next = curr->next;     /* Nachfolger von curr wird */
                                            /* Nachfolger von prev */
        free(curr);                      /* curr-Platz an Heap zurueckgeben */
        anz_art_knoten--;                /* Knotenanzahl reduzieren */
        return 1;
    }
    else return 0;                       /* nichts gefunden */
}

/* zeigt gesamten Artikelbestand */
void anzeige_artbestand(void)
{
    ART_KNOTEN_ZGR curr;                 /* zeigt auf aktuellen Knoten */
    int i = 0;                           /* Artikelzaehler */

    if (anz_art_knoten == 0)
    {
        printf("\nKeine Artikel im Bestand!\n");
        return;
    }

    for (curr = first;                   /* beginne mit erstem Knoten */
         curr != NULL;                   /* bis Listenende */
         curr = curr->next)              /* weiter zum naechsten Knoten */
    {
        print_artikel(i++,&(curr->a));   /* 1 Artikel ausgeben, */
    }                                    /* ggf. nach Listenkopf */
}

/* reinitialisiert Artikelbestand mit leerer Artikelmenge */
void loesche_artbestand(void)
{
    ART_KNOTEN_ZGR curr,                 /* zeigt auf aktuellen Knoten */
                   next;                 /* zeigt auf Nachfolger von curr */
    /* Liste durchgehen */
    for (curr = first; curr != NULL; curr = next)
    {
        next = curr->next;              /* Adresse Nachfolger sichern */
        free(curr);                     /* aktuellen Knoten freigeben */
    }
    init_artbestand();
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  In den Funktionen suche_art, ersetze_art und ausfuege_art wurde
  jeweils ausgenutzt, dass die Artikelliste aufsteigend nach Artikel-
  nummer sortiert ist und daher ein gesuchter Artikel nicht mehr
  erscheinen kann, wenn der aktuelle Knoten bereits eine hoehere
  Nummer als die gesuchte enthaelt.

  Wird die entsprechende Abbruch- bzw. Ruecksprungbedingung

            if (curr->a.nr > art_zgr->nr)
                    Abbruch der Suche mit return

  entfernt, koennen die Funktionen auch fuer unsortierte Listen
  verwendet werden. Aber die benoetigte Rechenzeit sollte anwachsen.

  Fuehren Sie mit und ohne diese Bedingungen Tests durch und
  beobachten Sie den Zeitverbrauch. Orientieren Sie sich an dem
  Beispiel 08-02 (Funktionen fuer die Zeitmessung und Zufallszahlen-
  funktionen) und verwenden Sie Datensaetze mit zufaelligen Artikelnummern.

******************************************************************************/
