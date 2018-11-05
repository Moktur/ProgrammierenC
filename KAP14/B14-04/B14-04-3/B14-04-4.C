
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-04-1,2,3, Verkettete Listen
/*
/*      Konzepte/       Implementierung verketteter Listen,
/*      Sprachelemente: Definitionsdateien und Modularisierung
/*
/*      Beschreibung:
/*
/*      Die Funktionsdatei B14-04-4.c stellt einen Anwendungsmodul
/*      fuer den Test einfach verketteter linearer Listen dar.
/*      Die Benutzung von b14-04-4.c geschieht wie folgt:
/*
/*      Listentyp    Beispielprogramm   in b14-04-4.c einzufuegende
/*                                      Definitionsdatei
/*      ---------------------------------------------------------
/*      Stapel       b14-04-1           b14-04-1.h
/*      Schlange     b14-04-2           b14-04-2.h
/*      sort. Liste  b14-04-3           b14-04-3.h
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "b14-04-3.h"        /* Einbinden Definitionsdatei fuer sort. Liste */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    char liste[21];                     /* Typ der verketteten Liste */
    unsigned int  nelem,                /* gewuenschte Anzahl Elemente */
                  seed,                 /* Wurzel Zufallszahlenerzeugung */
                  i;                    /* Elementzaehler */
    int           wert, erst_wert;      /* Elementwert */

    #ifdef stapel                       /* Ueberschrift und Eingabe Testdaten*/
        strcpy(liste, "Stapel");        /* Steuerung ueber Listenkonstanten */
    #elif defined schlange
        strcpy(liste, "Schlange");
    #elif defined sortliste
        strcpy_s(liste, 21, "Sortierte Liste");
    #endif

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810              \n");
    printf("----- Beispiele: 14-04-1,2,3, Verkettete Listen -----------              \n");
    printf("Demonstrationsprogramm fuer verkettete Listen, Listentyp: ");
    printf("%s",liste);

    #ifdef stapel                        /* Fall Stapel */
    printf("\n\nJeder aktuelle Stapel wird vom top-Element zum bottom-Element angezeigt.");

    #elif defined schlange               /* Fall Schlange */
    printf("\n\nJede aktuelle Schlange wird vom front-Element zum rear-Element angezeigt.");

    #elif defined sortliste              /* Fall sortierte Liste */
    printf("\n\nJede aktuelle sort. Liste wird von vorn nach hinten angezeigt.");

    #endif

    printf("\nGewuenschter Knotenumfang (<=20): "); scanf_s("%u",&nelem);
    if (nelem < 0 || nelem > 20)         /* gegebenenfalls Korrektur */
        nelem = 20;
    printf("Wurzel Zufallszahlen (>= 0): "); scanf_s("%u",&seed);
    srand(seed);                         /* Initialisierung Zufallszahlen */

    init_liste();                        /* Liste initialisieren */

    for (i = 0; i < nelem; i++)          /* Liste aufbauen mit nelem Elementen */
    {
        wert = rand()%99 + 1;            /* Zufallszahlen aus [1,99] */
        if (!add_elem(wert))             /* 1 Element mit wert einfuegen */
        {
            printf("\nElement nicht einfuegbar - Abbruch");
            PAUSE;
            exit(1);
        }
    }
    printf("\nListe mit %d Elementen aufgebaut", nelem);

    /* jeweils ein Element anzeigen */
    /* Steuerung ueber Listenkonstanten */
    #ifdef  stapel                       /* Fall Stapel */
        show_elem(&wert);                /* oberstes Element anzeigen*/
        i = 1;
    #elif defined schlange               /* Fall Schlange */
        show_elem(&wert);                /* erstes Element anzeigen*/
        i = 1;
    #elif defined sortliste              /* Fall sortierte Liste */
        show_elem(nelem/2, &wert);       /* mittleres Element anzeigen*/
        i = nelem/2;
    #endif

    printf("\nWert des %d-ten Elements:  %d", i, wert);
    show_all_elems();                    /* alle Elemente anzeigen */

    for (i = 0; i < nelem/2; i++)        /* 50% der erzeugten Elemente ausfuegen */
    {
        /* Steuerung ueber Listenkonstanten */
          #ifdef stapel                    /* Fall Stapel */
              remove_elem(&wert);          /* ausfuegen des jeweils obersten Elements */
          #elif defined schlange           /* Fall Schlange */
              remove_elem(&wert);          /* ausfuegen des jeweils ersten Elements */
          #elif defined sortliste          /* Fall sortierte Liste */
              remove_elem(2, &wert);       /* ausfuegen des jeweils 2. Elements */
        #endif
          if (i == 0) erst_wert = wert;    /* 1. geloeschten Wert aufheben */
    }
    printf("\n\nListe um %d Elemente reduziert", nelem/2);
    printf("\nWert des zuerst entfernten Elements:  %d", erst_wert);
    show_all_elems();                    /* alle (erhaltenen) Elemente anzeigen */

    for (i = 0; i < nelem/2; i++)        /* nochmals nelem/2 Elemente einfuegen */
    {
        wert = rand()%100;
        if (!add_elem(wert))
        {
            printf("\nElement nicht einfuegbar - Abbruch");
            PAUSE;
            exit(1);
        }
    }
    printf("\n\nListe um %d Elemente erweitert", nelem/2);
    show_all_elems();                    /* alle Elemente anzeigen */

    reinit_liste();                      /* Liste aufloesen */
    PAUSE;
}
