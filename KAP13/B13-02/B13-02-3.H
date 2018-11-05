
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
/*      Beschreibung:   In dieser Definitionsdatei werden der Boolsche Datentyp
/*                      und die Boolschen Konstanten definiert.
/*****************************************************************************/

/* Definition des Namens _INC_boolean verhindert mehrfaches Einfuegen
   dieser Definitionsdatei  */

#ifndef _INC_boolean
#define _INC_boolean

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Definiere den Boolschen Datentyp */
typedef char boolean;
/* Definiere die Boolschen Konstanten */
#define FALSE 0
#define TRUE  1

#endif /* #ifndef _INC_boolean */
