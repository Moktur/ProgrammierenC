
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-02, Implementation einer Menge
/*
/*      Konzepte/       Modularisierung von Programmen, mehrere Quelldateien,
/*      Sprachelemente: Implementierung eines abstrakten Datentyps (ADT) MENGE
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:
/*
/*      Das Programm fragt den Benutzer nach zwei Mengen und bildet
/*      die Vereinigung und den Durchschnitt der beiden Mengen.
/*
/*      Das Programm umfasst die 4 Dateien
/*          - B13-02-1.c,
/*          - B13-02-2.h,
/*          - B13-02-2.c und
/*          - 13-02-3.h.
/*      Zur Erzeugung eines ausfuehrbaren Programms
/*      sind die Dateien B13-02-1.c und b13-02-2.c zu binden.
/*
/*      Das Programm benutzt den abstrakten Datentyp MENGE,
/*      der in den Dateien B13-02-2.h und B13-02-2.c definiert ist.
/*      Die Datei B13-02-1.c stellt einen Anwendungsmodul fuer den ADT
/*      MENGE dar. Die Definitionsdatei b13-02-3.h stellt zusaetzlich
/*      den Boolschen Datentyp bereit.
/*
/*      Implementierung des ADT MENGE basiert auf:
/*                      L. H. Miller & A. E. Quilici: "C in der Praxis"
/*                      Oldenbourg-Verlag, Muenchen usw. 1989
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

#include "B13-02-2.h"   /* Enthaelt die Funktionen und Datentypen der
                           Mengen-Implementation */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

unsigned int Frage_Menge_Ab(MENGE menge);
unsigned int Gib_Menge_Aus(MENGE menge);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion: main
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    MENGE menge_1, menge_2, ergebnis;
    unsigned int anzahl = 0;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 13-02, Mengen -----------------------------\n\n");
    printf("\nDas Programm fuehrt Mengenoperationen aus.");
    printf("\nBitte geben Sie anschliessend die Elemente ");
    printf("zweier Mengen ein.");
    printf("\nDie Elemente muessen ganzzahlig, groesser als ");
    printf("%d und kleiner als ", MENGE_MIN_ELEMENT);
    printf("%d sein. \nBrechen Sie die Eingabe mit -1 ab.", MENGE_MAX_ELEMENT);
    printf("\n");

    /* Initialisiere Mengen */
    Menge_leereMenge(menge_1);
    Menge_leereMenge(menge_2);
    Menge_leereMenge(ergebnis);

    /* Frage die beiden Mengen ab */
    printf("\n\nBitte geben Sie die Menge 'menge_1' ein:\n");
    Frage_Menge_Ab(menge_1);
    printf("\n\nBitte geben Sie die Menge 'menge_2' ein:\n");
    Frage_Menge_Ab(menge_2);

    /* Bilde die Vereinigung beider Mengen */
    printf("\n\nDie Vereinigung der beiden Mengen:\n");
    Menge_Vereinigung(menge_1, menge_2, ergebnis);
    Gib_Menge_Aus(ergebnis);

    /* Bilde den Durchschnitt beider Mengen */
    printf("\n\nDer Durchschnitt der beiden Mengen:\n");
    Menge_Durchschnitt(menge_1, menge_2, ergebnis);
    Gib_Menge_Aus(ergebnis);
    PAUSE;
}

/*****************************************************************************/
/* Funktion: Frage_Menge_Ab
/*  Aufgabe:
/*   Fragt ab, welche Elemente in der Menge sein sollen
/*  Parameter:
/*   menge: Menge, die abgefragt werden soll
/*  Rueckgabewert:
/*   unsigend int: Anzahl der Elemente in der Menge
/*****************************************************************************/

unsigned int Frage_Menge_Ab(MENGE menge)
{
    /* Lokale Variablen definieren */
    ELEMENT element;
    unsigned int anzahl = 0;

    /* Anweisungen */

    /* Frage Benutzer nach Elementen, die in der Menge sein sollen */
    do
    {
        /* Abfrage */
        printf("\nWelches weitere Element soll in der Menge sein? ");
        scanf_s("%d", &element);

        /* Wenn die Eingabe -1 war, dann breche die Abfrage ab */
        if (element == -1 )
        {
            printf("Das wars...\n");
            break;
        }

        /* Wenn Element nicht in der Menge sein kann, frage weiter ab. Die
           Eingabe -1 wurde schon abgefragt, also kann problemlos an dieser
           Stelle (element < MENGE_MIN_ELEMENT) geprueft werden */
        if (element < MENGE_MIN_ELEMENT || element > MENGE_MAX_ELEMENT)
        {
            printf("Dieses Element kann nicht zur Menge gehoeren!\n");
            continue;
        }

        /* Wenn Element schon in der Menge, dann gib Meldung aus, ansonsten
           fuege es in die Menge ein */
        if (Menge_ElementVorhanden(menge, element))
            printf("Dieses Element ist schon in der Menge!\n");
        else
        {
            printf("Ich fuege das Element %u hinzu.\n", element);
            Menge_FuegeHinzu(menge, element);
            anzahl++;
        }
    }
    /* Solange die Menge nicht maximal gefuellt ist */
    while (anzahl < MENGE_ANZ_ELEMENTE);

    /* Rueckgabewert liefern */
    /* Liefere Anzahl der Elemente in der Menge zurueck */
    return anzahl;
}

/*****************************************************************************/
/* Funktion: Gib_Menge_Aus
/*  Aufgabe:
/*   Gibt die Menge am Bildschirm aus
/*  Parameter:
/*   menge: Menge, die ausgegeben werden soll
/*  Rueckgabewert:
/*   unsigend int: Anzahl der Elemente in der Menge
/*****************************************************************************/

unsigned int Gib_Menge_Aus(MENGE menge)
{
    /* Lokale Variablen definieren */
    ELEMENT element;
    unsigned int anzahl = 0;

    /* Anweisungen */

    /* Ueberpruefe fuer jedes moegliche Element, ob es in der Menge vorhanden
        ist. Wenn ja, gib Element am Bildschirm aus und zaehle die Elemente */
    for (element = MENGE_MIN_ELEMENT; element < MENGE_MAX_ELEMENT; element++)
        if (Menge_ElementVorhanden(menge, element))
        {
            printf("%5d  ", element);
            anzahl++;
            /* Fange nach 10 Ausgaben neue Zeile an */
            if ((anzahl % 10) == 0)
               putchar('\n');
            /* Pause mit return nach 100 Elementen */
            if (anzahl % 100 == 0)
               PAUSE;
        }

    /* Wenn nicht gerade eine neue Zeile angefangen wurde, dann tue es jetzt */
    if ((anzahl % 10) != 0)
       putchar ('\n');

    /* Anzahl der angezeigten Elemente ausgeben */
    printf("Anzahl der Elemente: %d\n", anzahl);

    /* Rueckgabewert liefern */
    /* Liefere Anzahl der Elemente zurueck */
    return anzahl;
}

/*****************************************************************************/
/* Aufgaben
/******************************************************************************

  - Ergaenzen Sie den ADT MENGE der Dateien B13-02-2.c, B13-02-2.h um die
    Operation Differenz, die die Differenz "\" zweier Mengen realisiert
    gemaess:
        M1\M2 = {x | x enthalten in M1 und x nicht enthalten in M2}
    Nutzen Sie hierfuer unbedingt die statischen Funktionen in der Datei
    B13-02-2.c
  - Ergaenzen Sie die Anwendungsdatei b13-02-1.c entsprechend um die
    Bildung der Differenz der eingegebenen Mengen.
  - Testen Sie das erweiterte Programm.
******************************************************************************/
