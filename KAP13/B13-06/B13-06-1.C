
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-06, Zufallszahlen
/*
/*      Konzepte/       mehrere Quelldateien, Speicherklassen extern und static
/*      Sprachelemente: fuer globale Variablen und Funktionen
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm gibt eine Reihe von Pseudo-Zufallszahlen
/*                      an Bildschirm aus und bedient sich dabei der in der
/*                      anderen Quelldatei definierten Funktionen.
/*
/*                      Das Beispiel umfasst die beiden Programmdateien
/*                      B13-06-1.c und B13-06-2.c, die zur Erzeugung einer
/*                      ausfuehrbaren Datei gebunden werden muessen.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

/* Diese Variable speichert die Anzahl der Aufrufe der Funktion Random() in
   der Datei 13-06-2.c: es handelt sich um eine externe Globale, denn wird
   keine explizite Speicherklasse angegeben, wird extern als Speicherklasse
   angenommen */
unsigned long aufruf_zaehler = 0;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Die Schluesselwoerter 'extern' zeigen, dass die Funktionen in einer anderen
   Quelldatei definiert werden */
extern void SetSeed(unsigned int seed);
extern unsigned int Random(void);

/*
Versuch, die statische Funktion aus der anderen Quelldatei fuer diese Datei
bekannt zu machen.

extern void NaechsteZufallszahl(void);
*/

/*****************************************************************************/
/* Globale Variablen deklarieren
/* d.h. Verweis auf in anderen Quelldateien definierte globale Variablen
/*****************************************************************************/

/*
Versuch, die statische Variable aus der andereren Quelldatei fuer diese Datei
bekannt zu machen.

extern unsigned int Zufallszahl;
*/

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int zaehler;
    int startwert;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: B13-06, Zufallszahlen II ------------------\n\n");
    printf("\nDas Programm erzeugt Pseudozufallszahlen und gibt sie aus.\n");

    /* Initialisiere die Zufallsreihe */
    printf("\nBitte geben sie einen Startwert (ganz, >= 0) fuer die Zufallszahlen ein: ");
    scanf_s("%u", &startwert);
    printf("\n");
    SetSeed(startwert);

    /*
    Versuch, die Zufallszahl von aussen zu initialisieren, ohne ueber die
    Funktion SetSeet() zu gehen:
    
    Zufallszahl = 12;
    */

    /*
    Versuch, eine neue Zufallszahl mit der Funktion NaechstZufallszahl() zu
    erzeugen, obwohl diese in der anderen Quelldatei als static definiert
    wurde:
    
    NaechsteZufallszahl();
    */

    /* Gib eine Reihe von Pseudo-Zufallszahlen am Bildschirm aus */
    for (zaehler = 1; zaehler <= 20; zaehler++)
      {
        printf("\nDie %2d.Zufallszahl ist: %6u", zaehler, Random());
        if (zaehler % 5 == 0)
           PAUSE;
      }

    /* Gib die Anzahl der Funktionsaufrufe am Bildschirm aus */
    printf("\n\nAnzahl der Aufrufe der Funktion Random(): ");
    printf("%lu.\n", aufruf_zaehler);
    PAUSE;
}
