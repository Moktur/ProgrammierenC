
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-02, Implementation einer Menge
/*
/*      Konzepte/       Modularisierung von Programmen, mehrere Quelldateien
/*      Sprachelemente: Implementierung eines abstrakten Datentyps
/*
/*      Beschreibung:   In dieser Funktionsdatei werden die in der Definitions-
/*                      datei B13-02.h deklarierten Funktionen des ADT MENGE
/*                      definiert. Diese Funktionen bilden die Schnittstellen
/*                      zu einer gegebenen Menge, d. h. ermoeglichen Zugriffe
/*                      auf die Menge.
/*
/*                      Auf die als statisch definierten Funktionen kann nur
/*                      innerhalb dieser Quelldatei zugegriffen werden, was den
/*                      Programmierer zwingen soll, nur die Schnittstellen-
/*                      Funktionen zu verwenden.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Datentypen und externe Funktionen fuer die Menge bekannt machen */
#include "B13-02-2.h"

/*****************************************************************************/
/* statische Funktionen deklarieren
/* (externe Funktionen sind in der Definitionsdatei deklariert)
/*****************************************************************************/

static boolean Suche_Bit_Position(ELEMENT, unsigned int *, unsigned char *);
static void    Setze_Bit(MENGE, ELEMENT, boolean);
static boolean Hole_Bit(MENGE, ELEMENT);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion: Suche_Bit_Position
/*  Aufgabe:
/*   Bestimmt die Bit-Position im Array, die das Element repraesentiert.
/*  Parameter:
/*   element: Element, dessen Bit-Position gesucht wird
/*   index:   Index des Array-Elements, in dem das Bit zu finden ist.
/*   bit:     Nummer des Bits im Array-Element, welches das Element reprae-
/*            sentiert
/*  Rueckgabewert:
/*   TRUE, falls Element in der Menge speicherbar ist
/*   FALSE, falls Element ausserhalb des Zahlenbereichs liegt, den die Menge
/*      speichern kann
/*****************************************************************************/

static boolean Suche_Bit_Position(ELEMENT element,
                                  unsigned int  *index,
                                  unsigned char *bit)
{
    /* Anweisungen */

    /* Bestimme die Werte und speichere sie an den uebergebenen Adressen */
    *index = element / 8;
    *bit = element % 8;

    /* Rueckgabewert liefern */
    /* Liefere zurueck, ob element in der Menge liegen kann, also ob es nicht
       zu gross und nicht zu klein ist */
    return ((element >= MENGE_MIN_ELEMENT) && (element <= MENGE_MAX_ELEMENT));
}

/*****************************************************************************/
/* Funktion: Setze_Bit
/*  Aufgabe:
/*   Setzt oder loescht das zu einem Element gehoerende Bit
/*  Parameter:
/*   menge:   Menge, in dem das Bit gesetzt oder geloescht werden soll
/*   element: Element, dessen zugehoeriges Bit gesetzt/geloescht werden soll
/*   gesetzt: TRUE, falls das Bit gesetzt werden soll
/*            FALSE, falls das Bit geloescht werden soll
/*****************************************************************************/

static void Setze_Bit( MENGE   menge,
                       ELEMENT element,
                       boolean gesetzt)
{
    /* Lokale Variablen definieren */

    /* Index des Array-Elements, in dem das zugehoerige Bit zu finden ist */
    unsigned int  index;
    /* Position des Bits in dem Array-Element, das dem Element entspricht */
    unsigned char bit;
    /* Ist Element in der Menge speicherbar? */
    boolean speicherbar;

    /* Anweisungen */

    /* Bestimme Bitposition und ob Element speicherbar ist */
    speicherbar = Suche_Bit_Position(element, &index, &bit);

    /* Wenn Element speicherbar ist, dann setze das Bit entsprechend */
    if (speicherbar)
    {
        /* Wenn Bit gesetzt werden soll */
        if (gesetzt)
            /*
               (01 << bit) erzeugt eine "Maske", bei der nur das Bit an der
               Bitposition gesetzt ist. Der Operator | verknuepft das Array-
               Element mit dieser Maske, was dann das Bit an der Bitposition
               setzt:
                    Maske, mit (01 << bit) bestimmt     00001000
                    Array-Element                       10100110
                    Operator |                          10101110
            */
            menge[index] |= (01 << bit);
        /* Wenn Bit geloescht werden soll */
        else
            /*
               (01 << bit) erzeugt eine "Maske", bei der nur das Bit an der
               Bitposition gesetzt ist. Der Operator ~ inventiert diese Maske.
               Der Operator & verknuepft das Array-Element mit dieser Maske,
               was dann das Bit an der Bitposition loescht:
                    Maske, mit (01 << bit) bestimmt     00001000
                    Operator ~ inventiert die Maske     11110111
                    Array-Element                       10101110
                    Operator &                          10100110
            */
            menge[index] &= ~(01 << bit);
    }
}

/*****************************************************************************/
/* Funktion: Hole_Bit
/*  Aufgabe:
/*   Ueberprueft, ob das zu einem Element gehoerende Bit gesetzt ist
/*  Parameter:
/*   menge:   Menge, in dem das Bit ueberprueft werden soll
/*   element: Element, dessen zugehoeriges Bit ueberprueft werden soll
/*  Rueckgabewert:
/*   TRUE, falls Bit gesetzt ist
/*   FALSE, falls Bit nicht gesetzt ist
/*****************************************************************************/

static boolean Hole_Bit(MENGE menge, ELEMENT element)
{
    /* Lokale Variablen definieren */

    /* Zeigt an, ob das zum Element gehoerende Bit gesetzt ist */
    boolean gesetzt;
    /* Index des Array-Elements, in dem das zugehoerige Bit zu finden ist */
    unsigned int  index;
    /* Position des Bits in dem Array-Element, das dem Element entspricht */
    unsigned char bit;
    /* Ist Element in der Menge speicherbar? */
    boolean speicherbar;

    /* Anweisungen */

    /* Bestimme Bitposition und ob Element speicherbar ist */
    speicherbar = Suche_Bit_Position(element, &index, &bit);

    /* Wenn Element nicht in der Menge speicherbar ist, kann das Bit nicht
       gesetzt sein */
    if (!speicherbar)
    {
        return FALSE;
    }

    /* Bestimmen, ob das zum Element gehoerende Bit gesetzt ist */
    /*
        menge[index] ist das Array-Element, das mit dem Operator >> um bit
        Stellen nach rechts geshiftet wird, womit das gesuchte Bit nach rechts
        rutscht. Danach wird es per Operator & mit der Eins verknuepft, was
        das Bit isoliert:

        Beispiel: gesucht wird Bit Nummer 4 (Nummern der Bits: 76543210 !)
            Array-Element                                      01101001
            Um 4 Stellen nach rechts shiften (Operator >>)     00000110
            Binaerdarstellung der Eins                         00000001
            Verknuepfung mit dem Operator & liefert den        00000000
                Wert des gesuchten Bits, hier 0 also nicht
                gesetzt.
    */
    gesetzt = (menge[index] >> bit) & 01;

    /* Rueckgabewert liefern */
    return gesetzt;
}

/*****************************************************************************/
/* Funktion: Menge_leereMenge
/*  Aufgabe:
/*   Initialisiert die Menge als leere Menge (kein Element in der Menge)
/*  Parameter:
/*   menge:   Menge, die initialisiert werden soll
/*****************************************************************************/
extern void Menge_leereMenge(MENGE menge)
{
    /* Lokale Variablen definieren */
    int index;

    /* Anweisungen */

    /* Initialisiere alle Array-Elemente mit null */
    for (index = 0; index < MENGE_ARRAY_SIZE; index++)
        menge[index] = 0;
}

/*****************************************************************************/
/* Funktion: Menge_Vereinigung
/*  Aufgabe:
/*   Bildet die Vereinigung zweier Mengen
/*  Parameter:
/*   menge_1:  erste Menge
/*   menge_1:  zweite Menge
/*   ergebnis: Ergebnis-Menge
/*****************************************************************************/

extern void Menge_Vereinigung(MENGE menge_1, MENGE menge_2, MENGE ergebnis)
{
    /* Lokale Variablen definieren */
    int index;

    /* Anweisungen */

    /* Gehe die gesamten Arrays durch */
    for (index = 0; index < MENGE_ARRAY_SIZE; index++)
        /* Wenn ein Element in einer Menge ODER in der anderen Menge, dann ist
           das Element auch in der Vereinigungsmenge: Bilde logisches ODER */
        ergebnis[index] = menge_1[index] | menge_2[index];
}

/*****************************************************************************/
/* Funktion: Menge_Durchschnitt
/*  Aufgabe:
/*   Bildet den Durchschnitt zweier Mengen
/*  Parameter:
/*   menge_1:  erste Menge
/*   menge_1:  zweite Menge
/*   ergebnis: Ergebnis-Menge
/*****************************************************************************/

extern void Menge_Durchschnitt(MENGE menge_1, MENGE menge_2, MENGE ergebnis)
{
    /* Lokale Variabelen definieren */
    int index;

    /* Anweisungen */

    /* Gehe die gesamten Arrays durch */
    for (index = 0; index < MENGE_ARRAY_SIZE; index++)
        /* Wenn ein Element in einer Menge UND in der anderen Menge, dann ist
           das Element auch in der Durchschnittsmenge: Bilde logisches UND */
        ergebnis[index] = menge_1[index] & menge_2[index];
}

/*****************************************************************************/
/* Funktion: Menge_FuegeHinzu
/*  Aufgabe:
/*   Fuegt ein Element zu einer Menge hinzu
/*  Parameter:
/*   menge:   Menge, zu der das Element hinzugefuegt werden soll
/*   element: Element, das hinzugefuegt werden soll
/*****************************************************************************/

extern void Menge_FuegeHinzu(MENGE menge, ELEMENT element)
{
    Setze_Bit(menge, element, TRUE);
}

/*****************************************************************************/
/* Funktion: Menge_Entferne
/*  Aufgabe:
/*   Entfernt ein Element aus einer Menge
/*  Parameter:
/*   menge:   Menge, aus der das Element entfernt werden soll
/*   element: Element, das entfernt werden soll
/*****************************************************************************/

extern void Menge_Entferne(MENGE menge, ELEMENT element)
{
    Setze_Bit(menge, element, FALSE);
}

/*****************************************************************************/
/* Funktion: 
/*  Aufgabe:
/*   Ueberprueft, ob ein Element in einer Menge vohanden ist
/*  Parameter:
/*   menge:   Menge, die ueberprueft werden soll
/*   element: Element, das das ueberprueft werden soll
/*  Rueckgabewert:
/*   TRUE, falls Element in der Menge ist
/*   FALSE, falls Element nicht in der Menge ist
/*****************************************************************************/

extern boolean Menge_ElementVorhanden(MENGE menge, ELEMENT element)
{
    return Hole_Bit(menge, element);
}
