
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-14, Parameter der main-Funktion I
/*
/*      Konzepte/       Argumentuebergabe an die main-Funktion, Funktionen zur
/*      Sprachelemente: Umwandlung von Zeichenketten in numerische Werte
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm zeigt die Uebergabe von Argumenten an die
/*          main-Funktion, demonstriert wird auch die Umwandlung von
/*          Zeichenketten in numerische Werte mit Funktionen ato... aus
/*          der Standardbibliothek (stdlib.h). Gezeigt wird schliesslich, dass
/*          main einen Wert - hier eine int-Zahl - an das Betriebssystem
/*          zurueckgeben kann. Vgl auch Typvereinbarung von main.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>     /* wg. Umwandlungsfunktionen ato...*/
#include <string.h>     /* wg. strcpy */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n");fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

int main(int  argc,     /* Anzahl Argumente einschl. Programmname */
         char *argv[])  /* Argumente als Zeichenketten, 1.Arg. = Programmname*/
{
    /* lokale Variablen */
    int modus;          /* 1. Parameter Typ int */
    double niveau;      /* 2. Parameter Typ double */
    char datei[13];     /* 3. Parameter Typ Zeiger auf char */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-14, Parameter der main-Funktion --------\n\n");

    printf("\nDas Programm zeigt Argumentuebergabe an main-Funktion.\n");
    printf("\nDer Aufruf muss mit folgenden Parametern von DOS oder");
    printf("\naus der Programmierumgebung durchgefuehrt werden:");
    printf("\n>programname int-Zahl float-Zahl Zeichenkette\n");

    if (argc < 4)
        printf("\nZu wenige Parameter - Abbruch");
    else
    {  /* Zugriff auf Parameter */
        modus = atoi(argv[1]);      /* Umwandlung in int, vgl. stdlib.h !*/
        niveau = atof(argv[2]);     /* Umwandlung in float */
        strcpy_s(datei, (int)sizeof(datei)-1, argv[3]);     /* nur Kopie erstellen */

        /* Kontrollausgabe */
        printf("\n\nParameter fuer main");
        printf("\n  Anzahl uebergebener Parameter: %d",argc);
        printf("\n  Programmname: %s",argv[0]);
        printf("\n  modus-Parameter: %d",modus);
        printf("\n  niveau-Parameter: %.2lf",niveau);
        printf("\n  datei-Parameter: %s",datei);

        /* hier z.B. Aufruf einer Bearbeitungsfunktion
           mit Uebergabe der Parameter modus, niveau, datei */
    }

    PAUSE;

    return (0);     /* Rueckgabe eines int-Wertes von main */
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Geben Sie die Argumente von main - anders als oben -
    alle als Zeichenketten argv[i], i = 0,...,argc-1 aus.
  - Modifizieren Sie das Programm, indem Sie andere
    oder zusaetzliche Parameter fuer main vorsehen.
    Beachten Sie, dass uebergebene Argumente stets
    Zeichenketten sind. Fuehren Sie daher bei numerischen
    Parametern immer eine Umwandlung mit den oben benutzten
    oder analogen Funktionen der Standardbibliothek durch.

******************************************************************************/
