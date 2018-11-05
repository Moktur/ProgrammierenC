
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
/*      Beschreibung:   Definitionsdatei fuer die Funktionsdatei
/*                      b14-04-3.c (sortierte Liste)
/*****************************************************************************/

#define sortliste

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

extern void init_liste(void);
extern void reinit_liste(void);
extern void show_all_elems(void);
extern int add_elem(int wert);
extern int remove_elem(int pos, int *wert_zgr);
extern int show_elem(int pos, int *wert_zgr);

