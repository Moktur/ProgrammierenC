
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs
/*
/*      Beispiel:       10-18, Sortieren mit Bubble Sort
/*
/*      Konzepte/       Uebergabe eines Vektors an Funktionen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm sortiert die von Ihnen eingegebenen Zahlen
/*                      der Groesse nach absteigend. Die Zahlen werden erst in
/*                      einem Vektor gespeichert, dann wird dieser Vektor mit
/*                      je einem Zeiger auf das erste und auf das letzte
/*                      Element an eine Sortierfunktion sowie eine Ausgabe-
/*                      funktion uebergeben. Das verwendete Sortierverfahren
/*                      Bubble Sort wird z.B. in Gehring, "Algorithmen  und
/*                      Datenstrukturen" (Kurs 00814) erlaeutert.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Konstanten / Makros / Typen definieren
/*****************************************************************************/

/* Maximale Anzahl der zu sortierenden Zahlen */
#define maximum 100

/* warten auf return */

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/* Bool'schen Datentyp definieren */
typedef char boolean;
#define TRUE 1
#define FALSE 0

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void eingabe(int *anfang, int **adr_ende);
void sortiere(int *anfang, int *ende);
void tausch(int *x, int *y);
void ausgabe(int *anfang, int *ende);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    int vektor[maximum];
    int *aktuell;

    /* Anweisungen*/

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-18, Sortieren mit Bubblesort -----------\n\n");

    printf("\nDas Programm sortiert einen Vektor ganzer Zahlen mit dem");
    printf("\nSortierverfahren Bubblesort.\n");
    printf("\nAls Eingabedaten fuer den Vektor werden int-Zahlen erwartet.");
    printf("\nDie Eingabe ist mit dem Wert -1 abzubrechen.\n\n");

    /* Eingabe der Werte */
    eingabe(vektor, &aktuell);

    /* Uebergabe an die Sortierfunktion */
    sortiere(vektor, aktuell);

    /* Uebergabe an die Ausgabefunktion */
    ausgabe(vektor, aktuell);

    PAUSE;
}

/* Funktion eingabe, liest Werte in Vektor ein */
void eingabe(int *anfang, int **adresse_ende)
{
    /* Lokale Variablen definieren */
    int *aktuell;

    /* Anweisungen */

    /* Eingabe der Werte mit Zeigern */
    for (aktuell = anfang; (aktuell - anfang) < maximum; ++aktuell)
    {
        printf("Bitte den Wert von vektor[%d] eingeben: ", aktuell - anfang);
        scanf_s("%d", aktuell);
        /* Wenn -1 eingegeben wurde, dann brich die Eingabe ab */
        if (*aktuell == -1)
            break;
    }
    /* Abbruchwert soll nicht mitsortiert werden */
    --aktuell;

    *adresse_ende = aktuell;
}

/* Erlaeuterung:
   - uebergebener Parameter adresse_end ist vom Typ
     Zeiger auf Zeiger auf int
   - uebergeben wird also eine Adresse, in der eine Adresse
     einer int-Zahl einzutragen ist
   - hier wird die Adresse des letzten eingelesenen Elements
     im Vektor vektor eingetragen
*/

/* Funktion sortiere,
   sortiert das uebergebene Feld;
   uebergeben werden Zeiger auf den Anfang und
   auf das Ende des zu sortierenden Bereichs */
void sortiere(int *anfang, int *ende)
{
    /* Lokale Variablen definieren */
    boolean getauscht;     /* Merkt sich, ob getauscht wurde */
    int  *aktuell;         /* Zeigt auf das zu untersuchende Element */

    /* Anweisungen */

    /* Sortieren nach dem Verfahren Bubble-Sort */
    do
    {
        /* In diesem Durchgang noch nichts getauscht */
        getauscht = FALSE;
        /* Vergleiche jedes Element mit seinem Nachfolger */
        for (aktuell = anfang; aktuell < ende; ++aktuell)
            /* Wenn Element an der falschen Stelle steht */
            if (*aktuell > *(aktuell + 1))
            {
                /* dann tausche es mit seinem Nachfolger */
                tausch(aktuell, aktuell + 1);
                /* Markiere, dass in diesem Durchgang getauscht wurde */
                getauscht = TRUE;
            }
    }
    /* Solange wiederholen, bis nichts mehr vertauscht wurde */
    while (getauscht);
}

/* Funktion tausch,
   tauscht die Inhalte der Speicherzellen, auf die die uebergebenen Variablen
   zeigen */
void tausch(int *x, int *y)
{
    /* Lokale Variablen definieren */
    int hilf;

    /* Anweisungen */
    hilf = *x;
    *x = *y;
    *y = hilf;
}

/* Funktion ausgabe,
   gibt den uebergebenen Vektor am Bildschirm aus
   uebergeben werden Zeiger auf den Anfang
   und auf das Ende des auszugebenden Bereichs (Vektors) */
void ausgabe(int *anfang, int *ende)
{
    /* Lokale Variablen definieren */
    int spalte = 0;     /* zaehlt die geschriebenen Spalten */
    int *aktuell;       /* Zeigt auf das aktuelle Element */

    /* Anweisungen */

    printf("\n\t\t\tDie sortierten Zahlen sind:\n");

    /* Arbeite alle Elemente ab */
    for (aktuell = anfang; aktuell <= ende; aktuell++)
    {
        printf("%8d",*aktuell);
        ++spalte;
        /* Wenn 8 Spalten geschrieben wurden, dann neue Zeile anfangen */
        if (spalte == 8)
        {
            printf("\n");
            spalte = 0;
        }
    }
    printf("\n\n");
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Passen Sie die Sortierung des Vektors an die entsprechenden Bedingungen
    des Beispiels 8.3 an (Laenge des Vektors, aufsteigende statt absteigende 
    Sortierung).
  - Schreiben Sie zusaetzlich eine Version der Sortierfunktion mit Index-
    Zugriff, wobei beide Versionen alternativ einsetzbar sein sollen.
  - Testen Sie - analog zum Beispiel 8.3 - den Zeitverbrauch beider
    Bubble-Sort-Versionen gegeneinander und ausserdem gegen den
    Zeitverbrauch von Insertionsort bzw. Quicksort aus Beispiel 8.2.
    Welchen Einfluss besitzen die Verwendung von Zeigerzugriff und
    das eingesetzte Sortierverfahren auf die Sortierzeiten?

******************************************************************************/

