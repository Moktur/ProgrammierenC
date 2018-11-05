
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-15, Zeiger und deren Operatoren
/*
/*      Konzepte/       Zeiger, Inhalt-von-Operator (*) und Adressoperator (&)
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm zeigt Beispiele fuer die Benutzung von
/*                      Zeigern und deren Operatoren.
/*
/*      Bemerkung:      Das Warning "C4700: Die nicht initialisierte lokale 
/*						Variable "ptr" wurde verwendet" ist beabsichtig.
/*						Drücken Sie bei der Meldung: "Run-Time Check Failure #3"
/*						tritt nur in der Debug-Version auf und kann vernachlässigt 
/*                      werden. Einfach auf weiter klicken.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int i;          /* int-Variable */
    int *ptr;       /* Zeiger auf int-Typ */
    int **ptr_ptr;  /* Zeiger auf einen Zeiger auf int-Typ */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-15, Zeiger, Operatoren * und & ---------\n");
    printf("\nDas Programm zeigt den Umgang mit den Zeigeroperatoren * und &.\n");

    /* Variablen initialisieren */
    i = 3;

    /* Variableninhalt ausgeben */
    printf("\nVariableninhalt:");
    printf("\n\ti = %d\n", i);

    /* Speicheradresse der Variable*/
    printf("\nVariablenadresse (Speicheradresse der Variablen):");
    printf("\n\t&i = %p\n", &i);

    /* ptr zeigt noch irgendwohin, da er noch nicht initialisiert wurde */
    printf("\nptr ist noch nicht initialisiert:");
    printf("\n\tptr = %p\n", ptr);

    /* Schreiben in die Adresse, auf die der noch nicht initialisierte
       Zeiger ptr zeigt
    *ptr = 3; */

    ptr = NULL;
    /* ptr zeigt nun auf NULL */
    printf("\nptr ist nun mit NULL initialisiert:");
    printf("\n\tptr = %p\n", ptr);

    /* Schreiben in die Adresse, auf die der mit NULL initialisierte
       Zeiger ptr zeigt
    *ptr = 3;  */

    /* ptr zeigt nun auf die Speicheradresse von i */
    ptr = &i;
    printf("\nptr zeigt nun auf die Speicheradresse von i:");
    printf("\n\tptr = %p\n", ptr);

    /* Inhalt der Speicherzelle ausgeben, auf die ptr zeigt */
    printf("\nInhalt der Speicherzelle, auf die ptr zeigt:");
    printf("\n\t*ptr = %d\n", *ptr);
    
    /* Warte auf Tastendruck */
    PAUSE;

    /* Die Speicheradresse von ptr */
    printf("\nDie Speicheradresse von ptr:");
    printf("\n\t&ptr = % p\n", &ptr);

    /* ptr_ptr zeigt nun auf die Speicheradresse von ptr */
    ptr_ptr = &ptr;
    printf("\nptr_ptr zeigt nun auf die Speicheradresse von ptr:");
    printf("\n\tptr_ptr = %p\n", ptr_ptr);

    /* Inhalt der Adresse, auf den der Zeiger zeigt, auf den ptr_ptr zeigt */
    printf("\nInhalt der Adresse auf den der Zeiger zeigt, ");
    printf("auf den ptr_ptr zeigt:");
    printf("\n\t**ptr_ptr = %d\n", **ptr_ptr);

    /* Zeigeratithmetik: Abstand der Speicheradressen: hier werden
       die Speicheradressen der beiden Variablen ptr und i subtrahiert.
       Dann wird das Ergebnis durch die Speichergroesse der Variablen
       geteilt (in diesem Fall meist: sizeof(int) = 4) */
    printf("\nAbstand der Speicheradressen von ptr und i:");
    printf("\n\t &ptr - &i = %p\n\n", (int *) &ptr - &i);

    PAUSE;
}
