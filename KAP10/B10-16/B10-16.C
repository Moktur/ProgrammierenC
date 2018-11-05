
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-16, Vektoren und Zeiger
/*
/*      Konzepte/       Zugriff auf Feldelemente mit Zeigern
/*      Sprachelemente: Ermittlung des aktuellen Index mit Hilfe der Zeiger
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm zeigt, wie man mit Hilfe von Zeigern auf
/*                      die Elemente eines Feldes zugreifen kann.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Konstanten und Makros definieren
/*****************************************************************************/

#define maximum 20      /* Maximale Anzahl der Elemente im Vektor */

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    int vektor[maximum];    /* Vektor mit maximum Elementen vom Typ int */
    int *aktuell;           /* Zeiger auf int-Typ */
    int index, spalte;      /* int-Variablen */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-16, Vektoren und Zeiger ----------------\n");

    printf("\nDas Programm verarbeitet einen Vektor mittels Zeigern.\n");

    /* Initialisierung aller Elemente des Vektors mit 0. Hier mit
       Index-Zugriff */
    for (index = 0; index < maximum; index++)
        vektor[index] = 0;

    /* 
    Initialisierung aller Elemente des Vektors mit 0. Hier mit dem Zeiger
    aktuell. Beschreibung der for-Schleife:
        Initialisierung:   aktuell zeigt auf den Anfang des Vektors
        Ueberpruefung:     (aktuell - vektor) ermittelt den Abstand der
                           Adressen, auf die die beiden Zeiger zeigen,
                           dividiert durch die Groesse der Elemente; damit
                           ermittelt man den aktuellen Feld-Index
        Reinitialisierung: aktuell soll auf das naechste Element zeigen

    */
    for (aktuell = vektor; (aktuell - vektor) < maximum; aktuell++)
        *aktuell = 0;

    /* Eingabe von Werten mit Zeigern */
	 printf("\nBitte fuellen Sie einen Vektor mit max. 20 int-Zahlen.");
    printf("\nBrechen Sie die Eingabe mit dem Wert -1 ab.\n\n");
    for (aktuell = vektor; (aktuell - vektor) < maximum; aktuell++)
    {
        printf("Bitte den Wert von vektor[%d] eingeben: ", aktuell - vektor);
        scanf_s("%d", aktuell);
        /* Wenn -1 eingegeben wurde, dann bricht die Eingabe ab */
        if (*aktuell == -1)
            break;
    }

    /* Ausgabe des Vektors mit Zeigern */
    printf("\n\t\t\tAusgabe des Vektors");
    printf("\n\t\t\t-------------------\n");
    spalte = 0;
    for (aktuell = vektor; (aktuell - vektor) < maximum; aktuell++)
    {
        printf("%12d", *aktuell);
        spalte++;
          /* Neue Zeile, wenn 5 Zahlen nebeneinander geschrieben wurden */
        if (spalte == 5)
        {
            putchar('\n');
            spalte = 0;
        }
    }
    printf("\n");

    /* Warte auf Tastendruck */
    PAUSE;
}
