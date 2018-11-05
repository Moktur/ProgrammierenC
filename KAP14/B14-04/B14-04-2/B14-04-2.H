
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
/*      Beschreibung:   Definitionsdatei fuer die Funktionsdatei
/*                      b14-04-2.c (Schlange)
/*
/*****************************************************************************/

#define schlange

/*****************************************************************************/
/* Konstanten definieren
/*****************************************************************************/

extern void init_liste(void);
extern void reinit_liste(void);
extern void show_all_elems(void);
extern int add_elem(int wert);
extern int remove_elem(int *wert_zgr);
extern int show_elem(int *wert_zgr);

