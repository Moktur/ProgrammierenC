
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-04-3, sortierte Liste
/*
/*      Konzepte/       Implementierung verschiedener Typen von verketteten
/*      Sprachelemente: Listen, Definitionsdateien und Modularisierung
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Funktionsdatei B14-04-3.c.
/*                      Realisiert eine sortierte verkettete Liste.
/*
/*                      B14-04-3 ist mit dem Anwendungsmodul b14-04-4.c
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

typedef struct element *ELEM_ZGR;      /* Zeigertyp fuer Listen-Element */

struct element                         /* Knotentyp fuer Listen-Element */
{
    int            wert;      /* einziges Nutzdatum */
    ELEM_ZGR       next;      /* Zeiger auf Nachfolger */
};

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

static ELEM_ZGR first;                 /* externer Zeiger auf erstes Element */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/* initialisiert externen Zeiger first mit Nullwert */
void init_liste(void)
{
    first = NULL;
}

/* zeigt alle Listenelemente von vorn nach hinten */
void show_all_elems(void)
{
    ELEM_ZGR curr;                       /* Hilfszeiger auf Listenelement */
    int i = 0;                           /* Elementzaehler */

    /* Vorgehen: vgl. gleichnamige Funktion fuer Stapel */
    printf("\nAktuelle sortierte Liste:\n\t");
    for (curr = first; curr != NULL; curr = curr->next)
    {
          printf("%-2d->", curr->wert);
          if (++i%12 == 0) printf("\n\t"); /* neue Zeile nach 12 Elementen */
    }
    printf("(NIL)");
}

/* loest die Liste auf */
void reinit_liste(void)
{
    ELEM_ZGR curr, next;                 /* Hilfszeiger auf 2 aufeinander-
                                            folgende Listenelemente */

    /* Vorgehen: vgl. gleichnamige Funktion fuer Stapel */
    for (curr = first; curr != NULL; curr = next)
    {
        next = curr->next;
        free(curr);
    }
    init_liste();
}

/* - fuegt neues Listenelement mit Wert wert sortiert in Liste ein,
   - gibt 1 zurueck, wenn Einfuegen erfolgreich, 0 sonst */
int add_elem(int wert)
{
    ELEM_ZGR temp,                     /* Zeiger auf neues Listenelement */
             curr,                     /* Zeiger auf aktuelles Listenelement*/
             prev;                     /* Zeiger auf Element vor "curr"*/

    /* neues Listenelement im Heap allokieren und fuellen */
    temp = (ELEM_ZGR)malloc(sizeof(struct element));
    if (temp == NULL)                    /* wenn malloc versagt abbrechen */
        return 0;
    temp->wert = wert;                   /* neuen Wert eintragen und ...*/
    temp->next = NULL;                   /* next-Zeiger mit NULL fuellen */

    /* Vorgehen:
       - zuerst Einfuegestelle bestimmen
       - hierzu mit Zeiger curr und nachhaengendem Zeiger prev Liste
         durchlaufen, bis
            - entweder einzufuegender Wert kleiner als Wert des Elements curr
            - oder Listenende erreicht
    */

    for (curr = first, prev = NULL; curr != NULL; curr = curr->next)
    {
        if (wert < curr->wert)         /* wenn einzufueg. Wert uebertroffen */
            break;                     /* Schleife verlassen */
        prev = curr;                   /* nachhaengenden Zeiger prev aktual. */
    }

    /* weiteres Vorgehen:
       - neues Element temp vor curr einhaengen, d.h. curr als Nachfolger des
         neuen Elements temp eintragen
       - dies ist fuer beide moeglichen Faelle, naemlich
                curr != NULL und curr == NULL ok und bedeutet im letzteren Fall
                dass temp am Listenende eingehangen wird
       - falls Vorgaenger an Einfuegestelle vorhanden (prev != NULL),
                wird temp als Nachfolger von prev eingehangen,
                sonst wird temp das neue erste Listenelement
    */

    temp->next = curr;
    if (prev != NULL)               /* Vorgaenger zu neuem Element vorhanden */
        prev->next = temp;
    else                            /* Vorgaenger nicht vorhanden */
        first = temp;
    return 1;
}

/* - fuegt Listenelement an Position pos > 0 aus und liefert dessen Wert unter
     Adresse wert_zgr
   - gibt 1 zurueck, wenn Ausfuegen erfolgreich, 0 sonst */
int  remove_elem(int pos, int *wert_zgr)
{
    ELEM_ZGR curr,                       /* Zeiger auf aktuelles Listenelem.*/
             prev;                       /* Zeiger auf Element vor "curr"*/
    int      i = 0;                      /* Positionszaehler */

    /* Vorgehen:
       - zuerst Ausfuegestelle, d.h. Element an Position pos bestimmen
       - hierzu mit Zeiger curr und nachhaengendem Zeiger prev Liste
         durchlaufen, bis Zeiger curr das pos-te Element oder das Listenende
         erreicht hat
    */
    for (curr = first, prev = NULL; curr != NULL; curr = curr->next)
    {
        i++;                           /* Positionszaehler erhoehen */
        if (i == pos)                  /* falls Position pos erreicht */
            break;                     /* Schleife verlassen */
        prev = curr;                   /* nachhaengenden Zeiger prev aktual. */
    }

    /* weiteres Vorgehen:
       wenn Position pos nicht erreicht wurde:
       - abbrechen, da kein Element an Position pos vorhanden
       sonst:
       - Wert des Elements curr (an Position pos) bereitstellen
         und Element curr aushaengen
       - falls curr Vorgaenger prev besitzt (prev != NULL),
         Nachfolger von curr als neuen Nachfolger von prev eintragen
       - sonst Nachfolger von curr als neues erstes Element eintragen
       - Element curr selbst freigeben
    */

    if (i != pos)
        return 0;
    *wert_zgr = curr->wert;
    if (prev != NULL)                    /* curr besitzt Vorgaenger */
        prev->next = curr->next;
    else                                 /* curr ist altes erstes Element */
        first = curr->next;
    free(curr);
    return 1;
}

/* - liefert Wert des Listenelements an Position pos unter Adresse wert_zgr
   - gibt 1 zurueck, wenn Wert geliefert werden konnte, 0 sonst */
int  show_elem(int pos, int *wert_zgr)
{
    ELEM_ZGR curr;                       /* Zeiger auf aktuelles Listenelem.*/
    int      i = 0;                      /* Positionszaehler */

    /* Vorgehen: vgl. Funktion remove_elem */
    for (curr = first; curr != NULL; curr = curr->next)
    {
        if (++i == pos)                 /* falls Position pos erreicht */
        {
            *wert_zgr = curr->wert;     /* Wert bereitstellen und */
            return 1;                   /* Funktion erfolgreich beenden */
        }
    }
    return 0;                            /* Position pos nicht erreicht */
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Erstellen Sie wie fuer den Stapel (14-04-1.c) auch fuer die sortierte Liste
  je eine Funktion, die die Anzahl der Listenelemente ausgibt bzw. zurueckgibt,
  ob die Liste leer (Rueckgabewert 1) ist oder nicht (Rueckgabewert 0).
  Testen Sie die Funktionen.

******************************************************************************/

