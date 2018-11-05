
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-08, Telefonbuch II
/*
/*      Konzepte/       Doppelt verkettete unsortierte Liste
/*      Sprachelemente:
/*
/*      Beschreibung:   Definitionsdatei fuer den ADT Telefonbuch II, gehoert
/*                      zur Funktionsdatei b14-08-2.c.
/*****************************************************************************/

#ifndef _INC_liste
#define _INC_liste
#define MAXZEICHEN 80

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Einen Knoten fuer den ADT Telefonbuch II definieren.
   Er nimmt die zu speichernden Daten auf */
typedef struct tag_knoten
        {
            char              name[20];     /* Der Name */
            char              telefon[15];  /* Die Telefonnummer */
            struct tag_knoten *vorgaenger;  /* Ein Zeiger auf den Vorgaenger */
            struct tag_knoten *nachfolger;  /* Ein Zeiger auf den Nachfolger */
        } KNOTEN;

/* Den Typ eines Zeigers auf einen Knoten definieren */
typedef KNOTEN *pKNOTEN;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Loescht alle Knoten der Liste */
void LoescheGanzeListe(void);

/* Fuegt einen Knoten am Anfang der Liste ein */
void FuegeKnotenAmAnfangEin(char *name, char *telefon);

/* Fuegt einen Knoten am Ende der Liste ein */
void FuegeKnotenAmEndeEin(char *name, char *telefon);

/* Loescht der ersten Knoten in der Liste */
void LoescheKnotenAmAnfang(void);

/* Loescht der letzten Knoten in der Liste */
void LoescheKnotenAmEnde(void);

/* Gibt die Daten des ersten Knoten in der Liste aus */
void GibKnotenAmAnfangAus(void);

/* Gibt die Daten des letzten Knoten in der Liste aus */
void GibKnotenAmEndeAus(void);

/* Gibt die Daten aller Knoten in der Liste aus */
void GibAlleKnotenAus(void);

/* Ermittelt die Anzahl der Knoten in der Liste */
unsigned int ErmittleAnzahlDerKnoten(void);

/* Gibt die Daten des/der Knoten mit dem uebergebenen Namen aus */
void GibKnotenMitNamenAus(char *name);

/* Loescht alle Knoten mit dem uebergenenen Namen */
void LoescheKnotenMitNamen(char *name);

#endif /* #ifndef _INC_liste */
