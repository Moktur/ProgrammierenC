
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
/*      Beschreibung:   Definitionsdatei fuer den ADT Aktenstapel, gehoert
/*                      zur Funktionsdatei B14-09-2.c.
/*****************************************************************************/

#ifndef _INC_stack
#define _INC_stack

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Den Boolschen Datentyp definieren */
typedef char boolean;
/* Die Boolschen Konstanten definieren */
#define FALSE 0
#define TRUE 1

/* Einen Knoten fuer den Aktenstapel definieren.
   Er nimmt die zu speichernden Daten auf. */
typedef struct tag_knoten
        {
            unsigned long     aktennummer;
            char              aktenzeichen[5];
            char              sachbearbeiter[30];
            struct tag_knoten *nachfolger;  /* Ein Zeiger auf den Nachfolger */
        } KNOTEN;

/* Den Typ eines Zeigers auf einen Knoten definieren */
typedef KNOTEN *pKNOTEN;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Schiebt ein Element auf den Stack */
void push(unsigned long nummer, char *zeichen, char *bearbeiter);

/* Nimmt das erste Element von dem Stack und liefert die Daten */
boolean pop(unsigned long *nummer, char *zeichen, char *bearbeiter);

/* Liefert die Daten des ersten Elements auf dem Stack ohne es zu loeschen */
boolean top(unsigned long *nummer, char *zeichen, char *bearbeiter);

/* Liefert die Anzahl der Elemente auf dem Stack */
unsigned long Anzahl(void);

#endif /* #ifndef _INC_stack */
