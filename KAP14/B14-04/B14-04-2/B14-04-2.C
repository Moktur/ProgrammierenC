
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-04-2, Schlange
/*
/*      Konzepte/       Implementierung verschiedener Typen von verketteten
/*      Sprachelemente: Listen, Definitionsdateien und Modularisierung
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Funktionsdatei B14-04-2.c. Realisiert
/*                      eine Schlange als verkettete Liste.
/*
/*                      B14-04-2 ist mit dem Anwendungsmodul b14-04-4.c
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

typedef struct element *ELEM_ZGR;        /* Zeigertyp fuer Queue-Element */
struct element                           /* Knotentyp fuer Queue-Element */
{
    int         wert;      /* einziges Nutzdatum */
    ELEM_ZGR    next;      /* Zeiger auf naechstes Queue-Element */
};

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

                                                      /* externe Zeiger auf...*/
static ELEM_ZGR first,                   /* erstes und ...*/
                    last;                    /* letztes Queue-Element */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/* initialisiert externe Zeiger first und last mit Nullwert */
void init_liste(void)
{
    first = last = NULL;
}

/* zeigt alle Queueelemente von vorn nach hinten */
void show_all_elems(void)
{
    ELEM_ZGR curr;                       /* Hilfszeiger auf Queueelement */
    int i = 0;                           /* Elementzaehler */

    /* Vorgehen: vgl. gleichnamige Funktion fuer Stapel */
    printf("\nAktuelle Schlange:\n\t");
    for (curr = first; curr != NULL; curr = curr->next)
    {
          printf("%-2d->", curr->wert);
          if (++i%12 == 0) printf("\n\t"); /* neue Zeile nach 12 Elementen */
    }
    printf("(NIL)");
}

/* loest die Queue auf */
void reinit_liste(void)
{
    ELEM_ZGR curr, next;                 /* Hilfszeiger auf 2 aufeinander-
                                                          folgende Queueelemente */

    /* Vorgehen: vgl. gleichnamige Funktion fuer Stapel */
    for (curr = first; curr != NULL; curr = next)
    {
        next = curr->next;
        free(curr);
    }
    init_liste();
}

/* - fuegt neues Queueelement mit Wert wert am hinteren Queueende ein,
   - gibt 1 zurueck, wenn Einfuegen erfolgreich, 0 sonst */
int add_elem(int wert)
{
    ELEM_ZGR temp;                       /* Zeiger auf neues Queueelement */

    /* neues Queueelement im Heap allokieren und fuellen */
    temp = (ELEM_ZGR)malloc(sizeof(struct element));
    if (temp == NULL)                    /* wenn malloc versagt abbrechen */
        return 0;
    temp->wert = wert;                   /* neuen Wert eintragen und ...*/
    temp->next = NULL;                   /* next-Zeiger mit NULL fuellen */

    /* Vorgehen:
       - falls Queue nicht leer, wird das neue Element an das alte letzte
         Element angehangen (1) und dann selbst zum letzten Queueelement
         gemacht (2)
       - bei leerer Schlange muessen first und last auf das neue Element zeigen
       - Reihenfolge der Aktionen (1) und (2) darf nicht vertauscht werden,
         da andernfalls die alte in first enthaltene Adresse verloren ist,
         bevor sie genutzt wurde !
    */
    if (first != NULL)                   /* Queue nicht leer */
    {
        last->next = temp;               /* (1) */
        last = temp;                     /* (2) */
    }
    else                                 /* Queue leer */
        first = last = temp;
    return 1;
}

/* - fuegt vorderstes  Queueelement aus und liefert dessen Wert unter Adresse
     wert_zgr
   - gibt 1 zurueck, wenn Ausfuegen erfolgreich, 0 sonst */
int  remove_elem(int *wert_zgr)
{
    ELEM_ZGR temp;                       /* Hilfszeiger auf altes 1. Queueelement */

    if (first == NULL)                   /* wenn nichts zu loeschen abbrechen */
        return 0;

    /* Vorgehen: vgl. gleichnamige Funktion fuer Stapel */
    *wert_zgr = first->wert;
    temp = first;
    first = first->next;
    free(temp);
    if (first == NULL)                   /* falls Schlange nun leer, muss auch */
        last = NULL;                     /* last auf Nullwert gesetzt werden */
    return 1;
}

/* - liefert Wert des erstes Queueelements unter Adresse wert_zgr
   - gibt 1 zurueck, wenn Wert geliefert werden konnte, 0 sonst */
int  show_elem(int *wert_zgr)
{
    if (first == NULL)                   /* wenn kein Wert vorhanden abbrechen */
        return 0;
    *wert_zgr = first->wert;             /* sonst ersten Wert liefern */
    return 1;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Erstellen Sie analoge zusaetzliche Funktionen wie fuer die
  Funktionsdatei b14-04-1.c (Stapel) und testen Sie diese.

******************************************************************************/
