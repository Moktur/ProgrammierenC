/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS, 1996
/*
/*      C-Kurs
/*
/*      Beispiel:       13-07, Boolscher Datentyp
/*
/*      Konzepte/       Boolscher Datentyp, Definitionsdateien
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Definitionsdateien (*.h) werden zur gesonderten
/*                      Definition von Konstanten, Typen und weiteren
/*                      Programmelementen benutzt. Definitionsdateien
/*                      werden mit der Praeprozessoranweisung #include in
/*                      Programmdateien (*.c) eingebunden, wobei ab dieser
/*                      Stelle die in der Definitionsdatei definierten oder
/*                      deklarierten Programmelemente bereitstehen.
/*                      Hier wird in der Definitionsdatei B13-07.h der
/*                      Boolsche Datentyp mit den beiden (Wahrheits-)Werten
/*                      True (Wahr) und False (Falsch) definiert. Im Unter-
/*                      schied zu anderen Varianten der Definition des
/*                      Boolschen Datentyps wird pro Wahrheitswert hier nur
/*                      ein Byte benoetigt.
/*                      Die Praeprozessoranweisung #ifndef und #endif
/*                      verhindern gemeinsam mit der Definitionsanweisung
/*                      #define _INC_boolean, dass bei mehrfachem Einbinden
/*                      der Definitionsdatei der Typ boolean und die zuge-
/*                      hoerigen Konstanten mehrfach definiert werden, was
/*                      einen Fehler zur Folge haette.
/*
/*      Bemerkung:      Das Beispiel umfasst die beiden Dateien B13-07.h und
/*                      B13-07.c
/*
/*****************************************************************************/

/* Verhindern, dass diese Definitionsdatei mehrfach eingebunden wird: Beim
   ersten Einbinden ist der Name _INC_boolean noch nicht definiert. Dann wird
   der Name definiert und die Anweisungen werden ausgefuehrt. Bei jedem weiteren
   Einbinden ist _INC_boolean schon definiert und die Anweisungen werden
   uebergangen */

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
