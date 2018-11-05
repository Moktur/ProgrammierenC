
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-06-2, Artikelverwaltung im Arbeitsspeicher
/*
/*      Konzepte/       Implementierung eines abstrakten Datentyps (ADT)
/*      Sprachelemente: Artikelbestand, Modularisierung, binaerer Suchbaum
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT Artikelbestand;
/*                      (Baumvariante).
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "b13-03-1.h"                  /* Definitionsdatei fuer
                                          Anwendungsdatei */
#include "b13-03-2.h"                  /* Definitionsdatei fuer ADT
                                          unveraendert gueltig */

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

typedef struct art_knoten              /* Typ fuer Baumknoten */
{
    ARTIKEL a;                 /* Artikeltyp des Anwendungsmoduls */
    struct art_knoten *left,   /* Zeiger auf linken Nachfolger */
    *right;                    /* Zeiger auf rechten Nachfoger */
} ART_KNOTEN;

typedef ART_KNOTEN *ART_KNOTEN_ZGR;    /* zugehoeriger Zeigertyp */

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

static ART_KNOTEN_ZGR root;            /* Zeiger auf Wurzelknoten */
static int anz_art_knoten;             /* Anzahl Knoten im Baum */

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

static void anzeige_teilbaum(ART_KNOTEN_ZGR curr, int start);
static void loesche_teilbaum(ART_KNOTEN_ZGR curr);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/* initialisiert Artikelbestand mit leerer Artikelmenge */
void init_artbestand(void)
{
    root = NULL;
    anz_art_knoten = 0;
}

/* fuegt einen Artikel aufsteigend sortiert nach Nr. in Bestand ein */
/* gibt 1 zurueck, wenn Einfuegen erfolgreich, sonst 0 */
int  einfuege_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr,                 /* zeigt auf aktuellen Knoten */
                   prev,                 /* zeigt auf Vorgaenger-Knoten von
                                            curr */
                   temp;                 /* zeigt auf neuen Knoten */

    /* neuen Knoten bereitstellen und mit uebergebenem Artikel fuellen */
    temp = (ART_KNOTEN_ZGR)malloc(sizeof(ART_KNOTEN));
    if (temp == NULL)                    /* pruefen ob malloc versagt */
    {
        printf("\nArtikelbestand nicht erweiterbar");
        return 0;
    }
    temp->a = *art_zgr;                  /* Knoten fuellen */
    temp->left = temp->right = NULL;     /* Nachfolger-Zeiger init. mit NULL */

    /* Einfuegestelle bestimmen */
    for (curr = root, prev = NULL;       /* curr = 1. Knoten, prev nicht da */
        curr != NULL;)                  /* bis Knoten ohne Nachfolger (Blatt)*/
    {
        if (art_zgr->nr == curr->a.nr)  /* keine mehrfache Art.Nr. */
        {
            printf("\nArtikelnummer bereits vorhanden");
            return 0;
        }
        else
        {
            prev = curr;                 /* Vorgaenger aktualisieren */
            if (art_zgr->nr < curr->a.nr)
                curr = curr->left;      /* nach links gehen */
            else
                curr = curr->right;     /* nach rechts gehen */
        }
    }

    /* einfuegen an Einfuegestelle */
    if (prev == NULL)                    /* Fall 1: als Wurzel*/
        root = temp;
    else if (art_zgr->nr < prev->a.nr)   /* Fall 2: links von prev */
        prev->left = temp;
    else                                 /* Fall 3: rechts von prev */
        prev->right = temp;

    anz_art_knoten++;                    /* Anzahl Knoten erhoehen */
    return 1;
}

/* sucht einen Artikel mit gegebener Nr. und liefert dessen Daten */
/* gibt 1 zurueck, wenn Suche erfolgreich, sonst 0 */
int  suche_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr;                 /* zeigt auf aktuellen Knoten */

    for (curr = root;                    /* beginne mit Wurzel */
         curr != NULL;)                  /* bis Blatt */
    {
        if (art_zgr->nr == curr->a.nr)    /* Fall 1: gefunden */
        {                                 /*         Daten bereitstellen */
            *art_zgr = curr->a;
            return 1;
        }
        else if (art_zgr->nr < curr->a.nr)/* Fall 2: links suchen */
            curr = curr->left;
        else                              /* Fall 3: rechts suchen */
            curr = curr->right;
    }
    return 0;                            /* nichts gefunden */
}

/* ueberschreibt Daten eines Artikels mit gegebener Nr. */
/* gibt 1 zurueck, wenn Ersetzen erfolgreich, sonst 0 */
int  ersetze_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR curr;                 /* zeigt auf aktuellen Knoten */

    for (curr = root;                    /* beginne mit Wurzel */
         curr != NULL;)                  /* bis Blatt */
    {
        if (art_zgr->nr == curr->a.nr)    /* Fall 1: gefunden, Daten ersetzen*/
        {
            curr->a = *art_zgr;
            return 1;
        }
        else if (art_zgr->nr < curr->a.nr)/* Fall 2: links suchen */
            curr = curr->left;
        else                              /* Fall 3: rechts suchen */
            curr = curr->right;
    }
    return 0;                            /* nichts gefunden */
}

/* fuegt einen Artikel mit gegebener Nr. aus Bestand aus */
/* gibt 1 zurueck, wenn Ausfuegen erfolgreich, sonst 0 */

int  ausfuege_art(ART_ZGR art_zgr)
{
    ART_KNOTEN_ZGR
        curr,         /* zeigt auf aktuellen Knoten */
        prev,         /* zeigt auf Vorgaenger-Knoten von curr */
        temp,         /* Hilfszeiger, siehe unten */
        tempprev;     /* zeigt auf Vorgaenger von temp */

    int prev_typ = 0; /* Typ des Vorgaengers von curr: */
                      /* 0: curr ohne Vorgaenger, d.h. curr = root  */
                      /* 1: curr hat rechten Vorgaenger (mit groesserer Nr.) */
                      /* 2: curr hat linken Vorgaenger (mit kleinerer Nr.) */
                      /* init.: ohne Vorgaenger */

    /* auszufuegenden Knoten suchen und Vorgaenger bestimmen */
    for (curr = root, prev = NULL;       /* curr = Wurzel, prev nicht da */
         curr != NULL;                   /* bis Blatt */
        )
    {
        if (art_zgr->nr == curr->a.nr)
            break;                        /* auszufuegenden Knoten gefunden */
        else if (art_zgr->nr < curr->a.nr) /* weiter links suchen */
        {
            prev = curr;
            curr = curr->left;
            prev_typ = 1;
        }
        else                               /* weiter  rechts suchen */
        {
            prev = curr;
            curr = curr->right;
            prev_typ = 2;
        }
    }

    /* --- Fallunterscheidung --- */

    /* Fall 1: nichts gefunden: Rueckgabe */
    if (curr == NULL)
        return 0;

    /* beachte: curr zeigt auf auszufuegenden Knoten, prev auf Vorgaenger */

    /* Fall 2: curr hat keinen Nachfolger:
               - in Vorgaenger prev Nachfolgeradresse NULL eintragen
               - oder Wurzel auf Nullwert setzen, wenn prev nicht da
               - Platz von curr freigeben */
    else if (curr->left == NULL && curr->right == NULL)
    {
        if      (prev_typ == 0)   root        = NULL;
        else if (prev_typ == 1)   prev->left  = NULL;
        else if (prev_typ == 2)   prev->right = NULL;
        temp = curr;                     /* temp zeigt auf Platz von curr */
    }

    /* Fall 3: curr hat nur einen Nachfolger:
               - Nachfolger nach curr kopieren incl. Zeiger (!) und
               - Platz des Nachfolgers freigeben */
    else if (curr->left == NULL)        /* nur rechter Nachfolger */
    {
        temp = curr->right;             /* temp zeigt auf rechten Nachfolger */
        *curr = *(curr->right);         /* re. Nachfolger nach curr kopieren */
    }
    else if (curr->right == NULL)       /* nur linker Nachfolger */
    {
        temp = curr->left;              /* analog wie bei rechtem Nachfolger */
        *curr = *(curr->left);
    }

    /* Fall 4: curr hat zwei Nachfolger (der kompliziertere Fall):
               - Nutzdaten von curr werden ersetzt durch Nutzdaten des Knotens
                 temp mit groesstem Sortierwert im zugeordneten linken Teilbaum
                 von curr, womit die Ordnung im Baum erhalten bleibt
               - beachte: temp hat max. einen linken Nachfolger;
               - der linke Nachfolger von temp wird
                 a) neuer rechter Nachfolger des temp-Vorgaengers,
                    falls dieser nicht curr ist
                 b) neuer linker Nachfolger von curr, sonst
               - danach kann der Platz von temp freigegeben werden */
    else
    {
        /* Knoten temp mit max. Sortierwert im linken Teilbaum zu curr bestimmen */
        for (temp = curr->left,tempprev= curr; /* temp und Vorgaenger init.*/
             temp->right != NULL;              /* bis Knoten mit max. Wert erreicht */
             tempprev = temp,                  /* Vorgaenger aktualisieren und */
             temp = temp->right)                /* weiter nach rechts */
            { ; }

        curr->a = temp->a;                     /* Nutzdaten von temp nach curr kop.*/
        if  (tempprev != curr)                 /* linker temp-Nachfolger wird */
            tempprev->right = temp->left;     /* rechter oder linker Nachfolger */
        else tempprev->left  = temp->left;     /* des temp-Vorgaengers */
    }                                        /* Ende Fall 4 */

    free(temp);                                /* Platz von temp freigeben */
    anz_art_knoten--;                          /* Knotenanzahl reduzieren */
    return 1;
}

/* zeigt gesamten Artikelbestand */
void anzeige_artbestand(void)
{
    if (anz_art_knoten == 0)
    {
        printf("\nKeine Artikel im Bestand\n");
        return;
    }

    anzeige_teilbaum(root, 1); /* Aufruf rekursive Funktion fuer Wurzel */
}

/* Hilfsfunktion: gibt Knoten eines Teilbaumes aus, rekursive Funktion,
   Traversierung in symmetrischer Ordnung */
static void anzeige_teilbaum(ART_KNOTEN_ZGR curr, int start)
{
    static int i;                        /* Zaehler fuer ausgegebene Knoten */

    i = start ? 0 : i;                   /* Knotenzaehler initialisieren */
    if (curr != NULL)                    /* wenn Teilbaum leer - nichts zu tun */
    {
        /* rekursiver Aufruf fuer linken Teilbaum */
        anzeige_teilbaum(curr->left,0);

        /* Ausgabe Wurzel Teilbaum */
        print_artikel(i++,&(curr->a));   /* 1 Artikel ausgeben,
                                                          ggf. mit Listenkopf */
        /* rekursiver Aufruf fuer rechten Teilbaum */
        anzeige_teilbaum(curr->right,0);
    }
}

/* reinitialisiert Artikelbestand mit leerer Artikelmenge */
void loesche_artbestand(void)
{
    loesche_teilbaum(root); /* Aufruf rekursiver Funktion */
    init_artbestand();
}

/* Hilfsfunktion: loescht einen Teilbaum, rekursive Funktion, Postorder-Traversierung */
static void loesche_teilbaum(ART_KNOTEN_ZGR curr)
{
    if (curr != NULL)                    /* wenn Teilbaum leer - nichts zu tun */
    {
        /* rekursiver Aufruf fuer linken Teilbaum */
        loesche_teilbaum(curr->left);

        /* rekursiver Aufruf fuer rechten Teilbaum */
        loesche_teilbaum(curr->right);

        /* loesche Wurzel Teilbaum */
        free(curr);
    }
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Vollziehen Sie im einzelnen - am besten anhand von Beispielen -
  die Arbeitsweise der Funktion fuer das Loeschen in binaeren
  Suchbaeumen nach.

******************************************************************************/
