
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       04-03, Ein- und Ausgabe von Zeichen
/*
/*      Konzepte/       Funktionen putchar, getchar und Konstante EOF
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int c;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-03, zeichenweise Ein- und Ausgabe ------\n\n");

    printf("\nDas Programm liest Zeichen mit getchar");
    printf(" und gibt sie mit putchar aus.");
    printf("\nBitte mehrere Zeichen eingeben und");
    printf("\ndie Eingabe mit STRG-Z (EOF, End of File) abbrechen.");
    printf("\nEingaben jeweils mit RETURN beenden.\n");

    c = getchar();              /* erstes Zeichen einlesen */
    while ( c != EOF )          /* bis End Of File erreicht */
    {                           /* EOF wird durch STRG-Z gegeben */
        putchar(c);             /* letztes Zeichen ausgeben */
        c = getchar();          /* naechstes Zeichen einlesen */
    }

    printf("\nLetztes Zeichen EOF (signed/unsigned/hex): %d %u %x",c,c,c);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Geben Sie mehrere statt nur eines Zeichens ein, bevor Sie die RETURN-Taste
    druecken. Was passiert? Der Umstand, dass alle eingegebenen Zeichen erst
    nach dem RETURN erscheinen, ist Folge des gepufferten Vorgehens von
    getchar. D.h. die eingetippten Zeichen gelangen zunaechst in einen
    Tastaturpuffer und werden erst nach dem Zeilentrenner RETURN ('\n') -
    und zwar gemeinsam - bearbeitet.
  - Welchen Wert hat die zuletzt ausgegebene Konstante EOF bei der Darstellung
    mit den angegebenen Formaten?
  - Ersetzen Sie die Abfrage auf EOF durch die Abfrage auf das Zeilentrenn-
    zeichen '\n' im Kopf der while-Schleife. Geben Sie wieder ein oder mehrere
    Zeichen, dann RETURN ein. Was passiert? Warum wird abschliessend nun 10 bzw.
    a ausgegeben?

******************************************************************************/
