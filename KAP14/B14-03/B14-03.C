
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-03, dynamische Zeichenkettenverwaltung
/*
/*      Konzepte/       Dynamische Verwaltung von Zeichenketten
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm liest und druckt Zeichenketten variabler
/*                      Laenge, die im Heap abgelegt werden.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************/
/* Konstanten / Makros  definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

#define MAXLAENGE 60        /* max. Laenge einer eingegebenen Zeichenkette */
#define MAXKETTEN 50        /* max. Anzahl verarbeitbarer Zeichenketten */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    /* Zaehler fuer und Anzahl aller Zeichenketten */
    int i, anz;

    /* Laenge einer Zeichenkette */
    int zk_laenge;

    /* Puffer fuer Eingabe einer Zeichenkette */
    char puffer[MAXLAENGE+1];
    
    /* Zeiger auf einer Zeichenkette */
    char *eine_zk;

    /* Zeichenkettentabelle, Vektor mit Zeigern auf char, nimmt Heapadressen
       der Zeichenketten auf */
    char *zk_tabelle[MAXKETTEN];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-03, dynamische Zeichenkettenverwaltung -\n\n");

    /* Eingabe und Ablage der Zeichenketten */
    printf("\nDas Programm verwaltet dynamisch reservierte Zeichenketten.\n");
    printf("\nBitte auf '?' je eine Zeichenkette mit max. 60 Zeichen eingeben.");
    printf("\nCTRL-Z beendet die Eingabe.\n");

    for (i = 0; i < MAXKETTEN; i++) /* max. MAXKETTEN Zeichenketten */
    {
        printf("? ");                  /* abbrechen, wenn Eingabe stoppt */
        if (gets_s(puffer, MAXLAENGE-1) == NULL)
            break;
        zk_laenge = strlen(puffer);    /* Laenge der Zeichenkette ermitteln */
        eine_zk = (char *) malloc(zk_laenge+1); /* ausreichend Heapplatz anf.*/
        if (eine_zk == NULL)           /* abbrechen, wenn malloc versagt */
            break;
									   /* String kopieren: puffer-> Heap */
        strcpy_s(eine_zk, zk_laenge+1, puffer); 
        zk_tabelle[i] = eine_zk;       /* Adresse String in Tabelle aufnehmen*/
    }
    anz = i; /* Anzahl Zeichenketten festhalten, letzter Index i nicht mehr
                benutzt */

    /* Ausgabe der Zeichenketten mittels Zeichenkettentabelle */
    printf("\n\n\nEingegebene Zeichenketten:");
    for (i= 0; i < anz; i++)   /* Ausgabe der i-ten Zeichenkette */
    {
        printf("\n%s", zk_tabelle[i]); /* ab Adresse zk_tabelle[i] */
        free(zk_tabelle[i]); /* Heapplatz freigeben */
        if ((i+1)%10 == 0)
            PAUSE;
    }
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Erweitern Sie das Programm um eine Sortierung der Zeichenketten.

  Variante 1:
  Verwenden Sie zur Sortierung die Funktion selectsort des Beispielprogramms
  08-02 und modifizieren Sie diese wie folgt:

  - anstelle einer Extrafunktion wird der Rumpf von selectsort
    hier der Einfachheit halber in main integriert und
    nach dem Einlesen der Zeichenketten plaziert;
  - sortiert wird der Vektor zk_tabelle, der die Adressen der
    eingelesenen Zeichenketten enthaelt;
  - gegenueber der urspruenglichen Funktion selectsort
    muessen Vergleiche und der Tausch zweier Elemente
    (des Vektors zk_tabelle) anders formuliert werden:

        char * temp;  d.h. Zeiger auf char nebst Index j und min noch einfuehren

        if (strcmp(zk_tabelle[j],zk_tabelle[min]) < 0)       Vergleich
            min = j;

        temp = zk_tabelle[i];                                Tausch
        zk_tabelle[i] = zk_tabelle[min];
        zk_tabelle[min] = temp;

  Testen Sie das erweiterte Programm.

  Variante 2:
  Nutzen Sie fuer die Sortierung analog zu dem Beispielprogramm 08-02
  die Bibliotheksfunktion qsort.

  - Hierbei sollte eine Vergleichsfunktion vergleiche_zk, die
    wiederum auf der Funktion strcmp basiert, genutzt werden.
  - Der qsort-Aufruf selbst lautet (vgl. Beispiel 08-02):
         qsort(zk_tabelle, anz, sizeof(char *), vergleiche_zk);
  - Hinweis zur Programmierung der Vergleichsfunktion:
        - es muessen Adressen der zu vergleichenden Elemente uebergeben werden,
        - die zu vergleichenden Elemente sind hier Zeichenketten, die selbst
          durch Adressen (Zeiger auf char) angegeben werden,
        - also werden Adressen von Adressen uebergeben, daher
          formale Parameter der Typen char ** bzw. Zeiger auf Zeiger auf char !
        - verglichen werden dann mit strcmp
          die Zeichenketten, also Zeiger auf char,
          daher lautet der strcmp-Aufruf: strcmp(*pp_zk1,*pp_zk2)
        - beachten Sie ggf. besondere Anforderungen Ihres Compilers
          bzgl. der Parametertypen der Vergleichsfunktion.

/******************************************************************************/
