
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-04-1, Stapel
/*
/*      Konzepte/       Implementierung verschiedener Typen von verketteten
/*      Sprachelemente: Listen, Definitionsdateien und Modularisierung
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Funktionsdatei B14-04-1.c. Realisiert
/*                      einen Stapel als verkettete Liste.
/*
/*                      B14-04-1 ist mit dem Anwendungsmodul b14-04-4.c
/*                      zu einem ausfuehrbaren Programm zu binden.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

typedef struct element *ELEM_ZGR;      /* Zeigertyp fuer Stack-Element */
struct element                         /* Knotentyp fuer Stack-Element */
{
    int            wert;      /* einziges Nutzdatum */
    ELEM_ZGR       next;      /* Zeiger auf naechstes Stack-Element */
};

static ELEM_ZGR first;                 /* externer Zeiger auf oberstes
                                          Stack-Element, d.h. Listenanfang */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/* initialisiert externen Zeiger first mit Nullwert */
void init_liste(void)
{
    first = NULL;
}

/* zeigt alle Stackelemente von oben nach unten */
void show_all_elems(void)
{
    ELEM_ZGR curr;                       /* Hilfszeiger auf Stackelement */
    int i = 0;                           /* Elementzaehler */

    /* Vorgehen:
       - Zeiger curr durchlaeuft die Adressen aller Stackelemente
       - hierzu wird curr anfangs mit first initialisiert und nach einem
         Schleifendurchlauf gemaess curr = curr->next jeweils auf das
         naechste Element gesetzt
       - pro Durchlauf werden Elementnummer und Nutzwert curr->wert ausgegeben
       - die Schleife endet, wenn curr vorher den Nullwert erhalten hat, d.h.
         wenn kein weiteres Element mehr vorhanden ist
    */

    printf("\nAktueller Stapel:\n\t");
    for (curr = first; curr != NULL; curr = curr->next)
    {
          printf("%-2d->", curr->wert);
          if (++i%12 == 0) printf("\n\t"); /* neue Zeile nach 12 Elementen */
    }
    printf("(NIL)");
}

/* loest den Stack auf */
void reinit_liste(void)
{
    ELEM_ZGR curr, next;                 /* Hilfszeiger auf 2 aufeinander-
                                            folgende Stackelemente */

    /* Vorgehen:
       - Zeiger curr durchlaeuft die Adressen aller Stackelemente bis zum
         Listenende
       - pro Schleifendurchlauf wird das Stackelement zu curr entfernt
       - vor der Platzfreigabe wird die Adresse des naechsten Elements im
         Zeiger next gemerkt und nach der Freigabe an curr zugewiesen
       - abschliessend wird der externe Zeiger first mittels
         Aufruf der Funktion init_liste auf Nullwert gesetzt
    */
    for (curr = first; curr != NULL; curr = next)
    {
        next = curr->next;
        free(curr);
    }

    init_liste();
}

/* - fuegt neues Stackelement mit Wert wert am oberen Stackende ein,
   - gibt 1 zurueck, wenn Einfuegen erfolgreich, 0 sonst */
int add_elem(int wert)
{
    ELEM_ZGR temp;                       /* Zeiger auf neues Stackelement */

    /* neues Stackelement im Heap allokieren und fuellen */
    temp = (ELEM_ZGR)malloc(sizeof(struct element));
    if (temp == NULL)                    /* wenn malloc versagt abbrechen */
        return 0;
    temp->wert = wert;                   /* neuen Wert eintragen und ...*/
    temp->next = NULL;                   /* next-Zeiger mit NULL init. */

    /* Vorgehen:
       - wenn Stack bereits Elemente enthaelt, wird das alte oberste Element
         Nachfolger des neuen Elements (1)
       - sonst ist neues Element einziges Stack-Element ohne Nachfolger;
         sein next-Zeiger wurde bereits mit NULL gefuellt
       - in jedem Fall wird das neue Element das oberste Stack-Element (2), auf
         das first nun verweist
       - Reihenfolge der Aktionen (1) und (2) darf nicht vertauscht werden,
         da andernfalls die alte in first enthaltene Adresse verloren ist,
         bevor sie genutzt wurde !
    */
    if (first != NULL)          /* (1) */
        temp->next = first;
    first = temp;               /* (2) */
    return 1;
}

/* - fuegt oberstes Stackelement aus und liefert dessen Wert unter Adresse
     wert_zgr
   - gibt 1 zurueck, wenn Ausfuegen erfolgreich, 0 sonst */
int  remove_elem(int *wert_zgr)
{
    ELEM_ZGR temp;        /* Hilfszeiger auf altes 1. Stackelement */

    if (first == NULL)    /* wenn nichts zu loeschen abbrechen */
        return 0;

    /* Vorgehen:
       - Wert des obersten Elements wird unter Adresse wert_zgr abgelegt
       - die Adresse des alten obersten Stackelements wird gerettet (1)
       - die Adresse des zuvor 2., nun obersten Elements wird first
         zugewiesen (2)
       - der Speicherplatz des alten obersten Elements wird freigegeben (3)
       - Reihenfolge entspricht dem Umstand, dass einerseits Adresse des
         Nachfolgers eines auszufuegenden Elements noch benoetigt wird,
         andererseits auf freigegebenen Heapplatz nicht mehr zugegriffen werden
         sollte !
    */
    *wert_zgr = first->wert;
    temp = first;               /* (1) */
    first = first->next;        /* (2) */
    free(temp);                 /* (3) */
    return 1;
}

/* - liefert Wert des obersten Stackelements unter Adresse wert_zgr
   - gibt 1 zurueck, wenn Wert geliefert werden konnte, 0 sonst */
int  show_elem(int *wert_zgr)
{
    if (first == NULL)                /* wenn kein Wert vorhanden abbrechen */
        return 0;
    *wert_zgr = first->wert;          /* sonst obersten Wert liefern */
    return 1;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Realisieren Sie folgende zusaetzliche Funktionen:
  - int show_min_elem(int *wert_zgr);
    Funktion liefert kleinsten Wert aller Stacklemente zurueck
    unter der Adresse wert_zgr; Funktion gibt 1 zurueck, wenn
    Wert geliefert werden konnte, sonst - bei leerem Stack - 0;
  - int count_stack(void);
    Funktion gibt Anzahl der Elemente im Stack zurueck
  - int is_empty_stack(void)
    Funktion liefert 0 (falsch) zurueck, wenn der Stack
    mindestens ein Element enthaelt, sonst 1
  Achten Sie darauf, dass eventuell zusaetzlich eingefuehrte
  globale Variablen im Stackmodul wie Anzahl aller Elemente
  nach aussen verborgen werden.

  Testen Sie diese Funktionen, nachdem Sie die Anwendungsdatei
  b14-04-4.c geeignet modifiziert haben.
******************************************************************************/
