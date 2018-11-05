
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-10, Patientenschlange
/*
/*      Konzepte/       einfach verkettete unsortierte Liste, Schlange,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT
/*                      Patientenschlange.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Definitionsdatei fuer den ADT Patientenschlange einbinden */
#include "B14-10-2.h"

/*****************************************************************************/
/* Statische Variable definieren
/*****************************************************************************/

/* Zeiger auf den naechsten Knoten der Schlange (auf den Kopf der Liste) */
static pKNOTEN NaechsterKnoten = NULL;
/* Zeiger auf den letzten Knoten der Schlange (auf den Fuss der Liste) */
static pKNOTEN LetzterKnoten = NULL;

/*****************************************************************************/
/* Statische Funktionen deklarieren
/*****************************************************************************/

/* Erzeugt einen neuen Knoten mit den uebergebenen Werten */
static pKNOTEN ErzeugeNeuenKnoten(char *name, char *beschwerden);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   rear()
/* Aufgabe:
/*   Schiebt einen Knoten mit den uebergebenen Daten in die Schlange
/* Parameter:
/*   name: Der Name des Patienten
/*   beschwerden: Die Beschwerden, die der Patient hat
/* Rueckgabewert:
/*   keiner
/* Bemerkung:
/*   Die Funktion entspricht der Funktion FuegeKnotemAmEndeEin() in der
/*   doppelt verketteten Liste, ausser dass es hier keinen Zeiger auf den
/*   Vorgaenger eines Knoten gibt.
/*****************************************************************************/

void rear(char *name, char *beschwerden)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Erzeuge einen neuen Knoten */
    NeuerKnoten = ErzeugeNeuenKnoten(name, beschwerden);

    /* Wenn die Schlange noch leer ist, ist der neue Knoten der naechste und
       zugleich der letzte in der Schlange */
    if (NaechsterKnoten == NULL)
    {
        NaechsterKnoten = LetzterKnoten = NeuerKnoten;
    }
    /* Ansonsten ist der neue Knoten der letzte der Schlange und wird am Fuss 
       der Liste angehaengt */
    else
    {
        /* Der neue Knoten ist jetzt der Nachfolger des bisher letzten */
        LetzterKnoten->nachfolger = NeuerKnoten;
        /* Der neue Knoten ist jetzt der letzte in der Schlange */
        LetzterKnoten = NeuerKnoten;
    }
}

/*****************************************************************************/
/* Funktion:
/*   front()
/* Aufgabe:
/*   Loescht den ersten Knoten in der Schlange und liefert die Daten
/* Parameter:
/*   name:        Ein Zeiger auf ein mind. 30 Zeichen langes char-Array, das
/*                nachher den Namen des Patienten enthalten soll.
/*   beschwerden: Ein Zeiger auf ein mind. 30 Zeichen langes char-Array, das
/*                nachher die Beschwerden des Patienten enthalten soll.
/* Rueckgabewert:
/*   TRUE, falls ein Knoten in der Schlange war
/*   FALSE, falls die Schlange leer ist
/* Bemerkung:
/*   Die Funktion entspricht der Funktion GibKnotenAmAnfangAus(). Ausserdem
/*   entspricht es der Funktion LoescheKnotenAmAnfang() in der doppelt
/*   verketteten Liste, ausser das es keinen Zeiger auf den Vorgaenger gibt.
/*****************************************************************************/

boolean front(char *name, char *beschwerden)
{
    /* Lokale Variablen definieren */
    pKNOTEN AlterKnoten;    /* Der zu loeschende Knoten */

    /* Wenn die Schlange leer ist, gibt es nichts zu tun */
    if (NaechsterKnoten == NULL)
        return FALSE;

    /* Sichere Zeiger auf den naechsten Knoten in der Schlange */
    AlterKnoten = NaechsterKnoten;

    /* Sichere die Daten des naechsten Knotens */
    next(name, beschwerden);

    /* Der Nachfolger des alten Knotens ist der neue naechste Knoten */
    NaechsterKnoten = AlterKnoten->nachfolger;

    /* Ist kein Knoten mehr in der Schlange, muss auch der Zeiger auf den
       letzten Knoten auf NULL gesetzt werden */
    if (NaechsterKnoten == NULL)
        LetzterKnoten = NULL;

    /* Gib Speicherplatz fuer den zu loeschenden Knoten frei */
    free(AlterKnoten);

    /* Liefere Rueckgabewert zurueck */
    return TRUE;
}

/*****************************************************************************/
/* Funktion:
/*   next()
/* Aufgabe:
/*   Liefert die Daten des ersten Knotens, ohne ihn zu loeschen
/* Parameter:
/*   name:        Ein Zeiger auf ein mind. 30 Zeichen langes char-Array, das
/*                nachher den Namen des Patienten enthalten soll.
/*   beschwerden: Ein Zeiger auf ein mind. 30 Zeichen langes char-Array, das
/*                nachher die Beschwerden des Patienten enthalten soll.
/* Rueckgabewert:
/*   TRUE, falls ein Knoten in der Schlange war
/*   FALSE, falls die Schlange leer ist
/* Bemerkung:
/*   Die Funktion entspricht der Funktion GibKnotenAmAnfangAus()in der einfach
/*   oder der doppelt verketteten Liste.
/*****************************************************************************/

boolean next(char *name, char *beschwerden)
{
    /* Wenn die Schlange leer ist, gibt es nichts zu tun */
    if (NaechsterKnoten == NULL)
        return FALSE;

    /* Ermittle die Daten des naechsten Knotens */
    strncpy_s(name, 29, NaechsterKnoten->name, 29);
    NaechsterKnoten->name[29] = '\0'; /* Zeichenkette muss spaetestens an der
                                         30. Stelle terminiert werden */
    strncpy_s(beschwerden, 29, NaechsterKnoten->beschwerden, 29);
    NaechsterKnoten->beschwerden[29] = '\0'; /* Zeichenkette muss spaetestens
                                                an der 30. Stelle terminiert
                                                werden */

    /* Liefere Rueckgabewert zurueck */
    return TRUE;
}

/*****************************************************************************/
/* Funktion:
/*   Anzahl()
/* Aufgabe:
/*   Liefert die Anzahl der Knoten in der Schlange
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   Anzahl der Knoten in der Schlange
/* Bemerkung:
/*   Die Funktion entspricht der Funktion ErmittleAnzahlDerKnoten()in der
/*   einfach oder der doppelt verketteten Liste.
/*****************************************************************************/

unsigned long Anzahl(void)
{
    /* Lokale Variablen definieren */
    int     Anzahl;           /* Die Anzahl der Knoten in der Schlange */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */

    /* Bisher wurden 0 Knoten gezaehlt */
    Anzahl = 0;

    /* Erster zu bearbeitende Knoten ist der naechste Knoten in der Schlange */
    AktuellerKnoten = NaechsterKnoten;

    /* Solange noch nicht das Ende der Liste erreicht wurde, zaehle die
       Knoten */
    while (AktuellerKnoten != NULL)
    {
        /* Zaehle diesen Knoten hinzu */
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
/*   name: Der Name des Patienten
/*   beschwerden: Die Beschwerden des Patienten
/* Rueckgabewert:
/*   Liefert einen Zeiger auf den neuen Knoten
/*****************************************************************************/

static pKNOTEN ErzeugeNeuenKnoten(char *name, char *beschwerden)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Reserviere Speicherplatz fuer den neuen Knoten */
    NeuerKnoten = malloc(sizeof(KNOTEN));

    /* Schreibe die uebergebenen Werte in den Knoten */
    strncpy_s(NeuerKnoten->name, 10, name, 29);
    NeuerKnoten->name[29] = '\0'; /* Zeichenkette muss spaetestens an der 30.
                                     Stelle terminiert werden */
    strncpy_s(NeuerKnoten->beschwerden, 29, beschwerden, 29);
    NeuerKnoten->beschwerden[29] = '\0'; /* Zeichenkette muss spaetestens an
                                            der 30. Stelle terminiert werden */

    /* Initialisiere Zeiger auf den Nachfolger */
    NeuerKnoten->nachfolger = NULL;

    /* Liefere Zeiger auf den neuen Knoten zurueck */
    return NeuerKnoten;
}
