
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-04, Ein- und Ausgabe von Strings
/*
/*      Konzepte/       Einlesen und Ausgeben von Strings mit den Funktionen
/*      Sprachelemente: getchar, scanf, gets, printf, puts
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/
#include <string.h>
#include <stdio.h>

/*****************************************************************************/
/* Makros und Konstanten definieren
/*****************************************************************************/

#define STR_END '\0'        /* Ersatzname fuer Nullzeichen */

#define PAUSE {printf("\nRETURN\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    char name[26];      /* Stringfeld */
    int i;              /* Index */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-04, Ein- und Ausgabe von Strings -------\n\n");

    printf("\nDas Programm liest drei Namen ein und gibt sie wieder aus.\n");

    /* Variante 1: String zeichenweise mit getchar/putchar  ein- und ausgeben*/
    printf("\nBitte Namen (max. 25 Zeichen) eingeben, mit RETURN beenden.\n");
    i = 0;                                  /* Eingabe bis Zeilenwechsel */
    while ((name[i] = getchar()) != '\n')
        i++;
    name[i] = STR_END;                      /* Endezeichen selbst setzen ... */
    for (i = 0; name[i] != STR_END; i++)    /* und selbst abfragen */
        putchar(name[i]);

    /* Variante 2: String ohne Zwischenraum mit scanf einlesen und mit
       printf ausgeben */
    printf("\n\nBitte Namen (max. 25 Zeichen) eingeben und mit RETURN beenden.");
    printf("\nName darf kein Leerzeichen enthalten!\n");
    scanf_s("%s", name, 25);              /* ohne &-Operator ! */
    printf("Name: %s",name);

    /* Variante 3: beliebigen String mit gets und puts ein- und ausgeben */
    fflush(stdin);      /* leert Tastaturpuffer, siehe unten */
    printf("\n\nBitte Namen (max. 25 Zeichen) eingeben, mit RETURN beenden.\n");
	// Die _s Version von gets_s kann waerend der Comilierung nicht wissen wie viel
	// Speicher sie f�r "name" reservieren soll da wir waerend der Laufzeit
	// die Groesse des Arrays bestimmen. Daher m�ssen wir explizit die Groesse mit angeben.
    gets_s(name, 25);
    puts("Name:");      /* hier Stringkonstante - geht auch */
    puts(name);         /* Name erscheint in neuer Zeile */
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Probieren Sie aus, was passiert, wenn ein mit scanf gelesener String
    Leerzeichen enthaelt.
  - Ergaenzen Sie das Programmbeispiel um Eingaben von Zeichenketten
    mit scanf und den Formatierungsvarianten [...] bzw. ^[...], vgl.
    hierzu auch Kap. 4.
  - Die Funktion gets kommt nicht zum Einlesen, wenn der Tastaturpuffer
    noch einen Zeilentrenner '\n' enthaelt. Abhilfe kann mit der Funktion
    fflush, definiert in stdio.h, geschaffen werden. Wird diese auf die
    Standardeingabe stdin bzw. die Tastatur (vgl. Kap. 11) angewendet,
    so wird (meist) der Tastaturpuffer geleert. Was passiert bei Ihrem
    Compiler, wenn der Aufruf fflush(stdin) auskommentiert wird?

  - Bemerkung: Auch in dem Makro PAUSE wird der Tastaturpuffer mit fflush
    geloescht, bevor mit getchar ein Returnzeichen eingelesen wird. 
******************************************************************************/
