
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-03, Artikelverwaltung im Arbeitsspeicher
/*
/*      Konzepte/       Implementierung eines abstrakten Datentyps (ADT)
/*      Sprachelemente: Artikelbestand, Modularisierung
/*
/*      Beschreibung:   Diese Definitionsdatei gehoert zum Anwendungsmodul
/*                      B13-03-1.c fuer die Artikelverwaltung.
/*****************************************************************************/

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

/* Artikeltyp */
typedef struct artikel
{
    int     nr;             /* Artikelnummer */
    char    name[16];       /* Artikelname */
    float   preis;          /* Artikelpreis */
} ARTIKEL;

/* zugehoeriger Zeigertyp */
typedef ARTIKEL *ART_ZGR;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Prototypen - nur fuer Anwendungsmodul selbst
   Steuerung ueber Konstante anwendungsmodul */

#ifdef anwendungsdatei

void erfassen_artikel(void);
void anzeigen_artikel(void);
void aendern_artikel(void);
void loeschen_artikel(void);

#endif

/* Prototyp der Funktion print_artikel;
   diese wird von Funktion anzeige_artbestand
   (aller Varianten) des ADT Artikelbestand gerufen
*/

void print_artikel(int, ART_ZGR);
