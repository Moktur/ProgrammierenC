
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-09, Aktenstapel
/*
/*      Konzepte/       einfach verkettete unsortierte Liste, Stapel,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT Aktenstapel.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Definitionsdatei fuer den ADT Aktenstapel einbinden */
#include "B14-09-2.h"

/*****************************************************************************/
/* Statische Variable definieren
/*****************************************************************************/

/* Zeiger auf das oberste Element des Stacks */
static pKNOTEN OberstesElement = NULL;

/*****************************************************************************/
/* Statische Funktionen deklarieren
/*****************************************************************************/

/* Erzeugt einen neuen Knoten mit den uebergebenen Werten */
static pKNOTEN ErzeugeNeuenKnoten(unsigned long nummer, char *zeichen,
                                  char *bearbeiter);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   push()
/* Aufgabe:
/*   Schiebt ein Element mit den uebergebenen Daten auf den Stack
/* Parameter:
/*   nummer: Die Nummer der Akte
/*   zeichen: Das Aktenzeichen
/*   bearbeiter: Der Name des Sachbearbeiters
/* Rueckgabewert:
/*   keiner
/* Bemerkung:
/*   Die Funktion entspricht der Funktion FuegeKnotemAmAnfangEin() in der
/*   einfach verketteten Liste.
/*****************************************************************************/

void push(unsigned long nummer, char *zeichen, char *bearbeiter)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Erzeuge einen neuen Knoten */
    NeuerKnoten = ErzeugeNeuenKnoten(nummer, zeichen, bearbeiter);

    /* Nachfolger des neuen Knoten ist das bisher erste Element des Stacks */
    NeuerKnoten->nachfolger = OberstesElement;

    /* Neues oberstes Element des Stacks ist der neue Knoten */
    OberstesElement = NeuerKnoten;
}

/*****************************************************************************/
/* Funktion:
/*   pop()
/* Aufgabe:
/*   Loescht das oberste Element des Stacks und liefert die Daten
/* Parameter:
/*   nummer:     Ein Zeiger auf die Variable, die nachher die Nummer der Akte
/*               enthalten soll.
/*   zeichen:    Ein Zeiger auf ein mind. 5 Zeichen langes char-Array, das
/*               nachher das Aktenzeichen enthalten soll.
/*   bearbeiter: Ein Zeiger auf ein mind. 30 Zeichen langes char-Array, das
/*               nachher den Namen des Sachbearbeiters enthalten soll.
/* Rueckgabewert:
/*   TRUE, falls ein Element in Stack war
/*   FALSE, falls der Stack leer ist
/* Bemerkung:
/*   Die Funktion entspricht der Funktion GibKnotenAmAnfangAus() und der
/*   Funktion LoescheKnotenAmAnfang() in der einfach verketteten Liste.
/*****************************************************************************/

boolean pop(unsigned long *nummer, char *zeichen, char *bearbeiter)
{
    /* Lokale Variablen definieren */
    pKNOTEN AlterKnoten;    /* Der zu loeschende Knoten */

    /* Wenn der Stack leer ist, gibt es nichts zu tun */
    if (OberstesElement == NULL)
        return FALSE;

    /* Sichere Zeiger auf den ersten Knoten */
    AlterKnoten = OberstesElement;

    /* Sichere die Daten des obersten Elements */
    *nummer = OberstesElement->aktennummer;
    strncpy_s(zeichen, 4, OberstesElement->aktenzeichen, 4);
    zeichen[4] = '\0'; /* Zeichenkette muss spaetestens an der 5. Stelle
                          terminiert werden */
    strncpy_s(bearbeiter, 29, OberstesElement->sachbearbeiter, 29);
    bearbeiter [29] = '\0'; /* Zeichenkette muss spaetestens an der
                               30. Stelle terminiert werden */

    /* Neues oberstes Element des Stacks ist der naechste Knoten */
    OberstesElement = AlterKnoten->nachfolger;

    /* Gib Speicherplatz fuer den zu loeschenden Knoten frei */
    free(AlterKnoten);

    /* Liefere Rueckgabewert zurueck */
    return TRUE;
}

/*****************************************************************************/
/* Funktion:
/*   top()
/* Aufgabe:
/*   Liefert die Daten des obersten Elements, ohne es zu loeschen
/* Parameter:
/*   nummer:     Ein Zeiger auf die Variable, die nachher die Nummer der Akte
/*               enthalten soll.
/*   zeichen:    Ein Zeiger auf ein mind. 5 Zeichen langes char-Array, das
/*               nachher das Aktenzeichen enthalten soll.
/*   bearbeiter: Ein Zeiger auf ein mind. 30 Zeichen langes char-Array, das
/*               nachher den Namen des Sachbearbeiters enthalten soll.
/* Rueckgabewert:
/*   TRUE, falls ein Element in Stack war
/*   FALSE, falls der Stack leer ist
/* Bemerkung:
/*   Die Funktion entspricht der Funktion GibKnotenAmAnfangAus()in der einfach
/*   verketteten Liste.
/*****************************************************************************/

boolean top(unsigned long *nummer, char *zeichen, char *bearbeiter)
{
    /* Wenn der Stack leer ist, gibt es nichts zu tun */
    if (OberstesElement == NULL)
        return FALSE;

    /* Ermittle die Daten des obersten Elements */
    *nummer = OberstesElement->aktennummer;
    strncpy_s(zeichen, 4, OberstesElement->aktenzeichen, 4);
    OberstesElement->aktenzeichen[4] = '\0'; /* Zeichenkette muss spaetestens
                                                an der 5. Stelle terminiert
                                                werden */
    strncpy_s(bearbeiter, 29, OberstesElement->sachbearbeiter, 29);
    OberstesElement->sachbearbeiter [29] = '\0'; /* Zeichenkette muss spaetes-
                                                    tens an der 30. Stelle
                                                    terminiert werden */

    /* Liefere Rueckgabewert zurueck */
    return TRUE;
}

/*****************************************************************************/
/* Funktion:
/*   Anzahl()
/* Aufgabe:
/*   Liefert die Anzahl der Elemente auf dem Stack
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   Anzahl der Elemente auf dem Stack
/* Bemerkung:
/*   Die Funktion entspricht der Funktion ErmittleAnzahlDerKnoten()in der
/*   einfach verketteten Liste.
/*****************************************************************************/

unsigned long Anzahl(void)
{
    /* Lokale Variablen definieren */
    int     Anzahl;           /* Die Anzahl der Elemente auf dem Stack */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */

    /* Bisher wurden 0 Elemente gezaehlt */
    Anzahl = 0;

    /* Erster zu bearbeitende Knoten ist das oberste Element auf dem Stack */
    AktuellerKnoten = OberstesElement;

    /* Solange noch nicht das Ende der Liste erreicht wurde, zaehle die
       Elemente */
    while (AktuellerKnoten != NULL)
    {
        /* Zaehle dieses Element hinzu */
        ++Anzahl;

        /* Bearbeite naechsten Knoten in der Liste */
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* Liefere die Anzahl der Knoten zurueck */
    return Anzahl;
}

/*****************************************************************************/
/* Statische Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   ErzeugeNeuenKnoten()
/* Aufgabe:
/*   Reserviert den Speicherplatz fuer einen neuen Knoten und initialisiert
/*   die Elemente mit den uebergebenen Werten.
/* Parameter:
/*   nummer: Die Nummer der Akte
/*   zeichen: Das Aktenzeichen
/*   bearbeiter: Der Name des Sachbearbeiters
/* Rueckgabewert:
/*   Liefert einen Zeiger auf den neuen Knoten
/*****************************************************************************/

static pKNOTEN ErzeugeNeuenKnoten(unsigned long nummer, char *zeichen,
                                  char *bearbeiter)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Reserviere Speicherplatz fuer den neuen Knoten */
    NeuerKnoten = malloc(sizeof(KNOTEN));

    /* Schreibe die uebergebenen Werte in den Knoten */
    NeuerKnoten->aktennummer = nummer;
    strncpy_s(NeuerKnoten->aktenzeichen, 4, zeichen, 4);
    NeuerKnoten->aktenzeichen[4] = '\0'; /* Zeichenkette muss spaetestens an
                                            der 5. Stelle terminiert werden */

    strncpy_s(NeuerKnoten->sachbearbeiter, 29, bearbeiter, 29);
    NeuerKnoten->sachbearbeiter[29] = '\0'; /* Zeichenkette muss spaetestens
                                               an der 30. Stelle terminiert
                                               werden */

    /* Initialisiere Zeiger auf den Nachfolger */
    NeuerKnoten->nachfolger = NULL;

    /* Liefere Zeiger auf den neuen Knoten zurueck */
    return NeuerKnoten;
}
