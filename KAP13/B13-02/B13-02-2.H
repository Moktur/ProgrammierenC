
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       13-02, Implementation einer Menge
/*
/*      Konzepte/       Modularisierung von Programmen, mehrere Quelldateien
/*      Sprachelemente: Implementierung eines abstrakten Datentyps
/*
/*      Beschreibung:   Definiert die fuer die Implementation einer Menge
/*                      noetigen Datentypen und deklariert die Funktionen,
/*                      die die Schnittstelle zur Menge bilden und mit denen
/*                      man die Menge manipulieren kann.
/*
/*****************************************************************************/

/* Definition des Namens _INC_menge verhindert mehrfaches Einfuegen
   dieser Definitionsdatei  */

#ifndef _INC_menge
#define _INC_menge

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Boolschen Datentyp bekannt machen */
#include "B13-02-3.h"

/*****************************************************************************/
/* Konstanten definieren
/*****************************************************************************/

/* Kleinstes Element der Menge */
#define MENGE_MIN_ELEMENT       0

/* Groesstes Element der Menge */
#define MENGE_MAX_ELEMENT       2047

/* Groesstmoegliche Anzahl der Elemente in der Menge */
#define MENGE_ANZ_ELEMENTE      MENGE_MAX_ELEMENT - MENGE_MIN_ELEMENT + 1

/* Anzahl der Array-Elemente */
#define MENGE_ARRAY_SIZE        MENGE_ANZ_ELEMENTE / 8

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Darstellung der Menge als ein Array von char-Variablen */
typedef unsigned char MENGE[MENGE_ARRAY_SIZE];

/* Elemente der Menge sind positive ganze Zahlen -> unsigned int */
typedef unsigned int  ELEMENT;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

/* Initialisiere Menge -> leere Menge */
extern void Menge_leereMenge(MENGE menge);

/* Vereinigung zweier Mengen */
extern void Menge_Vereinigung(MENGE menge_1, MENGE menge_2, MENGE ergebnis);

/* Durchschnitt zweier Mengen */
extern void Menge_Durchschnitt(MENGE menge_1, MENGE menge_2, MENGE ergebnis);

/* Fuege Element zur Menge hinzu */
extern void Menge_FuegeHinzu(MENGE menge, ELEMENT element);

/* Entferne Element aus der Menge */
extern void Menge_Entferne(MENGE menge, ELEMENT element);

/* Pruefen, ob Element in der Menge vorhanden ist */
extern boolean Menge_ElementVorhanden(MENGE menge, ELEMENT element);

#endif /* #ifndef _INC_menge */
