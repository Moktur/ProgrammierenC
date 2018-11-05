
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-03, Artikelverwaltung im Arbeitsspeicher
/*
/*      Konzepte/       Implementierung eines abstrakten Datentyps (ADT)
/*      Sprachelemente: Artikelbestand, Modularisierung, Vektoren
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT Artikelbestand
/*                      (Vektorvariante).
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "b13-03-1.h"                  /* Definitionsdatei fuer
														Anwendungsmodul */
#include "b13-03-2.h"                  /* Definitionsdatei fuer ADT */

/*****************************************************************************/
/* Konstanten definieren
/*****************************************************************************/

#define MAXARTIKEL 2500                /* max. Artikelanzahl */

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

static ARTIKEL Artvektor[MAXARTIKEL];  /* Vektor fuer Artikelverwaltung */
static anz_artikel;                    /* Anzahl Artikel im Vektor */

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Hilfsfunktion fuer Suche, Aendern und Loeschen von Artikelsaetzen */
static int bin_artsuche(int artnr);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/* initialisiert Artikelbestand mit leerer Artikelmenge */
void init_artbestand(void)
{
    anz_artikel = 0;
}

/* fuegt einen Artikel aufsteigend sortiert nach Nr. in Bestand ein
   gibt 1 zurueck, wenn Einfuegen erfolgreich, sonst 0 */
int einfuege_art(ART_ZGR art_zgr)
{
    int i, pos;

    if (anz_artikel == MAXARTIKEL)
    {
        printf("\nArtikelbestand nicht erweiterbar");
        return 0;
    }

    /* Einfuegestelle pos bestimmen - vor erstem Artikel mit hoeherer Nr. */
    pos = anz_artikel;      /* init.: keine hoehere Nr. vorhanden,
                               am Ende einfuegen */
    for (i = 0; i < anz_artikel; i++)
    {
        if (art_zgr->nr == Artvektor[i].nr)       /* keine mehrfache Art.Nr.*/
        {
            printf("\nArtikelnummer bereits vorhanden"); return 0; 
        }
        else if (art_zgr->nr < Artvektor[i].nr)   /* Einfuegestelle hier */
        {
            pos = i;
            break;
        }
    }

    /* einfuegen an Einfuegestelle */
    for (i = anz_artikel - 1; i >= pos; i--)     /* Einfuegestelle freimachen*/
        Artvektor[i+1] = Artvektor[i];           /* restl. Artikel um 1 nach rechts */
    Artvektor[pos] = *art_zgr;                   /* neuen Artikel einfuegen */
    anz_artikel++;                               /* Artikelanzahl aktualisieren */
    return 1;
}

/* sucht einen Artikel mit gegebener Nr. und liefert dessen Daten
   gibt 1 zurueck, wenn Suche erfolgreich, sonst 0 */
int suche_art(ART_ZGR art_zgr)
{
    int pos;

    pos = bin_artsuche(art_zgr->nr);
    if (pos == -1)
        return 0;                   /* nichts gefunden */
    else
    {                               /* Artikel uebergeben */
        *art_zgr = Artvektor[pos];
        return 1;
    }
}

/* ueberschreibt Daten eines Artikels mit gegebener Nr. gibt 1 zurueck,
   wenn Ersetzen erfolgreich, sonst 0 */
int ersetze_art(ART_ZGR art_zgr)
{
    int pos;

    pos = bin_artsuche(art_zgr->nr);
    if (pos == -1)
        return 0;                   /* nichts gefunden */
    else
    {                               /* Artikel ersetzen */
        Artvektor[pos] = *art_zgr;
        return 1;
    }
}

/* fuegt einen Artikel mit gegebener Nr. aus Bestand aus gibt 1 zurueck,
   wenn Ausfuegen erfolgreich, sonst 0 */
int ausfuege_art(ART_ZGR art_zgr)
{
    int i, pos;

    pos = bin_artsuche(art_zgr->nr);
    if (pos == -1)                            /* nichts gefunden */
        return 0;
    else                                      /* Aertikel ausfuegen */
    {
        for (i = pos; i < anz_artikel-1; i++) /* Ausfuegestelle fuellen */
            Artvektor[i] = Artvektor[i+1];    /* restl. Art. um 1 nach links */
        anz_artikel--;                        /* Artikelanzahl aktualisieren */
        return 1;
    }
}

/* zeigt gesamten Artikelbestand */
void anzeige_artbestand(void)
{
    int i;

    if (anz_artikel == 0)
        printf("\nKeine Artikel im Bestand!\n");

    for (i = 0; i < anz_artikel; i++)
        print_artikel(i, &Artvektor[i]);      /* 1 Artikel ausgeben */
}                                             /* ggf. mit Listenkopf */

/* reinitialisiert Artikelbestand mit leerer Artikelmenge */
void loesche_artbestand(void)
{
    init_artbestand();
}

/* sucht binaer nach einem Artikelsatz mit Art.-Nr. artnr, gibt bei Erfolg
  dessen Index im Vektor Artvektor, sonst -1 zurueck*/
static int bin_artsuche(int artnr)
{
    int anfang, ende, mitte;    /* Elementindizes im Vektor Artvektor */

    anfang = 0;
    ende = anz_artikel;
    while (anfang <= ende)
    {
        mitte = (anfang + ende)/2;
        if (artnr < Artvektor[mitte].nr)
            ende = mitte - 1;
        else if (artnr > Artvektor[mitte].nr)
            anfang = mitte + 1;
        else                    /* Element mit gegebener Nr. gefunden */
            return mitte;
    }
  return (-1);                  /* Element mit gegebener Nr. nicht gefunden */
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Schreiben Sie eine Funktion
            static int lin_artsuche(int artnr);
    die eine lineare Suche nach einem Artikel mit vorgegebener
    Nummer durchfuehrt. Orientieren Sie sich am Beispielprogramm
    b08-02.c.  Aendern Sie diesen Modul so ab, dass anstelle binaerer
    Suche lineare Suche benutzt wird.
  - Testen Sie den Modul fuer die lineare Suche und fuer
    die binaere Suche. Schreiben Sie eine passende main-Funktion
    fuer den Test, die Sie (provisorisch) in diesem Modul plazieren.
    Orientieren Sie sich am Beispiel b08-02 (Funktionen fuer
    Zeitmessung und Zufallszahlen) und verwenden Sie
    Datensaetze mit zufaellig erzeugten Artikelnummern.
    Wie verhalten sich die Rechenzeiten fuer beide Suchvarianten?

******************************************************************************/
