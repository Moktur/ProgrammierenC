
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-10, Zeiger und Zeichenketten
/*
/*      Konzepte/       Zeigeranwendung auf Zeichenketten
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm enthaelt verschiedene Varianten einer Funktion, die
/*          Zeichenketten kopiert und zeigt moegliche Aufrufsformen;
/*          knapper C-Quellcode wird auch demonstriert.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void strcpy1(char dest[], char source[]);
void strcpy2(char *dest, char *source);
void strcpy3(char *dest, char *source);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    char quell_string[21] = "Hallo"; 
    char ziel_string[25], *str_zgr;
  
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-10, Zeiger und Zeichenketten -----------\n\n");

    printf("\nDas Programm kopiert Zeichenketten.\n");
    /* konstante Zeichenkette als Quellstring moeglich */
    strcpy1(ziel_string, "kopieren");
    printf("\nZielstring:  %s",ziel_string);

    printf("\nQuellstring: %s",quell_string); 
    strcpy2(ziel_string, quell_string);
    printf("\nZielstring:  %s",ziel_string);

    quell_string[4] = 'e';
    printf("\nQuellstring: %s",quell_string);
    str_zgr = ziel_string;               /* folgender Aufruf kopiert */
    strcpy3(str_zgr, quell_string);      /* nach ziel_string */
    printf("\nZielstring:  %s",ziel_string);

    str_zgr = "Guten Morgen";            /* Zuweisung eines konstanten Strings
                                            an char-Zeiger ist moeglich */

    /* beachte aber: fuer das statische Feld ist eine Initialisierung
       quell_string = "Hallo" nur bei Definition des Feldes moeglich */

    printf("\nQuellstring: %s", str_zgr);
    strcpy3(ziel_string, str_zgr);
    printf("\nZielstring:  %s",ziel_string);
    PAUSE;
}

/* folgende Funktionen kopieren Zeichenketten */

/* Funktion strcpy1 - Variante 1 : Index-Zugriff */
void strcpy1(char dest[], char source[])
{
    int i = 0;

    while ((dest[i] = source[i]) != '\0')
        i++;
}

/* Erlaeuterung: ab i=0 werden die Zeichen einzeln von source nach dest
   kopiert; wurde das Nullzeichen '\0' uebergeben, ist anschliessend (!) der
   Wert des Ausdrucks (dest[i] = source[i]) gleich dem Nullzeichen und das
   Kopieren wird beendet */

/* Funktion strcpy2 - Variante 2 : Zeiger-Zugriff */
void strcpy2(char *dest, char *source)
{       
    /* Verarbeitungslogik wie bei Variante 1 */
    while ((*dest = *source) != '\0')       /* Zeichen-Zugriff ueber Zeiger
                                               und Inhalt-von-Operator */
    {    
        dest++;         /* Zeiger-Inkrementierung */
        source++;
    }
}

/* Funktion strcpy3 - Variante 3 : Zeiger-Zugriff, knapper */
void strcpy3(char *dest, char *source)
{
    /* vgl. Variante 2 */
    while ((*dest++ = *source++) != '\0')
        { ; }
    /* Kopieren und Inkrementierung zusammen daher leerer Schleifenrumpf */
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Verdeutlichen Sie sich, wie die beiden letzten Varianten der
    Kopierfunktion arbeiten. Vollziehen Sie das Vorgehen im einzelnen
    nach.
  - Schreiben Sie eine Funktion, die eine Zeichenkette an eine
    andere anhaengt (vgl. Funktion strcat aus string.h). Testen Sie
    diese mit einer main-Funktion, die analog zur obigen aufgebaut ist.

******************************************************************************/
