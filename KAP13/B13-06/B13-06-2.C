
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-06, Zufallszahlen
/*
/*      Konzepte/       mehrere Quelldateien, Speicherklassen fuer Variablen
/*      Sprachelemente: und Funktionen
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Diese Quelldatei definiert/deklariert alle Funktionen,
/*                      die fuer die Berechnung einer Reihe von Pseudo-
/*                      Zufallszahlen noetig sind. Die globale Variable
/*                      Zufallszahl ist als static definiert, damit nicht von
/*                      anderen Quelldateien aus auf sie zugegriffen werden
/*                      kann. Wird eine neue Zufallszahl benoetigt, muss sie
/*                      durch einen Aufruf der Funktion Random() abgefragt
/*                      werden. Die Funktion NaechsteZufallszahl() ist auch
/*                      statisch definiert, damit nur in dieser Quelldatei
/*                      bestimmt wird, wann eine neue Zufallszahl zu berechnen
/*                      ist. Auf die beiden anderern Funktionen SetSeed() und
/*                      Random() kann von aussen zugegriffen werden, sie
/*                      bilden die Schnittstellen nach aussen, und sind daher
/*                      mit der Speicherklasse extern (ohne besonderes
/*                      Schluesselwort) definiert.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Konstanten definieren
/*****************************************************************************/

#define FAKTOR 25173
#define INCR   13849
#define MODUL  65536 

/*****************************************************************************/
/* Globale Variablen deklarieren
/*****************************************************************************/

/* Auf Globale der Speicherklasse extern kann grundsaetzlich von allen Quell-
   dateien eines Programms aus zugegriffen werden. Falls in einer Quelldatei
   zugegriffen werden soll, wo die Variable nicht DEFINIERT ist, muss diese
   unter Verwendung des Schluesselwortes "extern" DEKLARIERT werden. */
extern unsigned long aufruf_zaehler;

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

/* Die Variable Zufallszahl ist wegen der Wahl der Speicherklasse static nur 
   in dieser Quelldatei sichtbar, kann nicht von anderen Quelldateien gelesen
   oder veraendert werden */
static unsigned int Zufallszahl;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Auf diese Funktionen kann von anderen Quelldateien zugegriffen werden, da
   es sich um Funktionen  der Speicherklasse extern handelt. Wird keine
   explizite Speicherklasse angegeben, wird extern als Speicherklasse
   angenommen */
void SetSeed(unsigned int seed);
unsigned int Random(void);

/* Auf diese Funktion kann aufgrund der Wahl der Speicherklasse static NICHT
   von anderen Quelldateien zugegriffen werden */
static void NaechsteZufallszahl(void);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion: SetSeed
/*  Aufgabe:        Setzt den Ausgangswert fuer die Pseudozufallszahlen
/*  Parameter:      Ausgangswert als 'unsigned int'
/*  Liefert:        Kein Rueckgabewert
/*  Beschreibung:   Diese Funktion setzt den Ausgangswert fuer die Zufalls-
/*                  zahlenreihe. Da anderer Quelldateien auf die Variable
/*                  Zufallszahl nicht zugreifen koennen, muss dies ueber diese
/*                  Funktion geschehen.
/*****************************************************************************/

void SetSeed(unsigned int seed)
{
    /* Anweisungen */

    Zufallszahl = seed;
}

/*****************************************************************************/
/* Funktion: Random
/*  Aufgabe:        liefert eine Pseudozufallszahl
/*  Parameter:      Kein Parameter
/*  Liefert:        Zufallszahl als 'unsigned int'
/*  Beschreibung:   Die Funktion liefert die naechste Zufallszahl. Da andere
/*                  Quelldateien nicht auf die Variable Zufallszahl zugreifen
/*                  koennen, muss das durch diese Funktion geschehen. Dadurch
/*                  wird auch gewaehrleistet, dass durch den Aufruf der
/*                  Funktion NaechsteZufallszahl() auch wirklich eine neue
/*                  Zahl generiert wird.
/*****************************************************************************/

unsigned int Random(void)
{
    /* Anweisungen */

    /* Zaehle die Aufrufe */
    ++aufruf_zaehler;

    /* berechne die naechste Zufallszahl */
    NaechsteZufallszahl();

    /* Rueckgabewert liefern */
    /* Liefere die aktuelle Zufallszahl an die aufrufende Funktion zurueck. */
    return Zufallszahl;
}

/*****************************************************************************/
/* Funktion: NaechsteZufallszahl
/*  Aufgabe:        Berechnet die naechste Zufallszahl
/*  Parameter:      Kein Parameter
/*  Liefert:        Kein Rueckgabewert
/*  Beschreibung:   Diese Funktion berechnet nach einer Formel eine neue
/*                  Pseudo zufallszahl. Da dies eine statische Funktion ist,
/*                  kann diese nicht von anderen Quelldateien aus aufgerufen
/*                  werden. So wird gewaehrleistet, dass nur dann eine neue
/*                  Zufallszahl berechnet wird, wenn es auch noetig ist.
/*****************************************************************************/

static void NaechsteZufallszahl(void)
{
    /* Anweisungen */

    /* Berechne die naechste Pseudozufallszahl */
    Zufallszahl = (FAKTOR * Zufallszahl + INCR) % MODUL;
}
