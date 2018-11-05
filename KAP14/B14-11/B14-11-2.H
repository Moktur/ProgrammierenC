
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-11, Telefonbuch III
/*
/*      Konzepte/       binaerer Suchbaum, Modularisierung, ADT
/*      Sprachelemente:
/*
/*      Beschreibung:   Definitionsdatei fuer den ADT Telefonbuch III,
/*                      gehoert zur Funktionsdatei B14-11-2.c
/*****************************************************************************/

#ifndef _INC_baum
#define _INC_baum

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Den Boolschen Datentyp definieren */
typedef char boolean;
/* Die Boolschen Konstanten definieren */
#define FALSE 0
#define TRUE 1

/* Knoten fuer einen Binaeren Baum definieren. Er nimmt die zu speichernden
   Daten auf. */
typedef struct tag_Knoten
        {
            char              name[30];
            char              telefon[30];
            struct tag_Knoten *links;
            struct tag_Knoten *rechts;
        } KNOTEN;

/* Den Typ eines Zeigers auf einen Knoten definieren */
typedef KNOTEN *pKNOTEN;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Fuegt einen Knoten in den binaeren Baum ein */
void FuegeKnotenEin(char *name, char *telefon);

/* Gibt die Daten des Baums aus */
void AusgabePraeorder(void);
void AusgabeInorder(void);
void AusgabePostorder(void);

#endif /* #ifndef _INC_baum */
