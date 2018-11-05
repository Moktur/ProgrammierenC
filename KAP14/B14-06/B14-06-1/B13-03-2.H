
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-02, Artikelverwaltung im Arbeitsspeicher
/*
/*      Konzepte/       Implementierung eines abstrakten Datentyps (ADT)
/*      Sprachelemente: Artikelbestand, Modularisierung
/*
/*      Beschreibung:   
/*          Diese Definitionsdatei gehoert zur Funktionsdatei fuer
/*          den ADT Artikelbestand B13-3-2.c  (Vektorvariante).
/*          Sie kann unveraendert auch fuer die alternativen Varianten
/*          - b14-06-1.c (Listenvariante)  und
/*          - b14-06-2.c (Baumvariante)
/*          des ADT benutzt werden.
/*****************************************************************************/

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

extern void init_artbestand(void);
extern int  einfuege_art(ART_ZGR);
extern int  suche_art(ART_ZGR);
extern int  ersetze_art(ART_ZGR);
extern int  ausfuege_art(ART_ZGR);
extern void anzeige_artbestand(void);
extern void loesche_artbestand(void);

