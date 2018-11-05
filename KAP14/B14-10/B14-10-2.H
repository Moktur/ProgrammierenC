
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
/*      Beschreibung:   Definitionsdatei fuer den ADT Patientenschlange,
/*                      gehoert zur Funktionsdatei B14-10-2.c
/*****************************************************************************/

#ifndef _INC_schlange
#define _INC_schlange

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Den Boolschen Datentyp definieren */
typedef char boolean;
/* Die Boolschen Konstanten definieren */
#define FALSE 0
#define TRUE 1

/* Einen Knoten fuer die Schlange definieren.
   Er nimmt die zu speichernden Daten auf.
*/
typedef struct tag_knoten
        {
            char              name[30];
            char              beschwerden[30];
            struct tag_knoten *nachfolger;  /* Ein Zeiger auf den Nachfolger */
        } KNOTEN;

/* Den Typ eines Zeigers auf einen Knoten definieren */
typedef KNOTEN *pKNOTEN;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Schiebt einen Knoten in die Schlange */
void rear(char *name, char *beschwerden);

/* Nimmt den ersten (vordersten) Knoten aus der Schlange und liefert die Daten*/
boolean front(char *name, char *beschwerden);

/* Liefert die Daten des ersten Knotens in der Schlange ohne ihn zu
   loeschen */
boolean next(char *name, char *beschwerden);

/* Liefert die Anzahl der Knoten in der Schlange */
unsigned long Anzahl(void);

#endif /* #ifndef _INC_schlange */
