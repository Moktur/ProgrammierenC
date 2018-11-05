
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrgebiet Wirtschaftsinformatik, 1997
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-02, Vektor mit Zufallszahlen
/*
/*      Konzepte/       dynamische Reservierung von Vektoren
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm erzeugt einen Vektor variabler Laenge, der ganzzahlige
/*          Zufallszahlen enthaelt, Vektor wird dynamisch reserviert
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>  /* wg. exit */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

/* warten auf return */
#define PAUSE {printf("\nRETURN!\n");fflush(stdin);getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int *zufalls_vektor;
    unsigned int i, anz, size;
    unsigned int seed;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrgebiet Wirtschaftsinformatik, C-Kurs 810\n");
    printf("----- Beispiel: 14-02, Vektor mit Zufallszahlen -----------\n\n");
    printf("\nDas Programm zeigt den Umgang mit einem");
    printf(" dynamisch reservierten Vektor.\n");

    /* Dateneingabe */
    printf("\nBitte Vektorlaenge anz eingeben (5 <= anz <= 30000): ");
    scanf("%u",&anz);
    if (anz < 5 || anz > 30000)
    {
        printf("\nVektorlaenge unzulaessig!");
        PAUSE;
        exit(1);
    }
    printf("\nBitte Startwert seed fuer Zufallszahlen eingeben (seed ganz, >=0): ");
    scanf("%u",&seed);

    /* Zufallszahlenvektor dynamisch erzeugen*/
    size = anz*sizeof(int);
    printf("\nGroesse eines int-Wertes in Bytes:              %d", sizeof(int));
    printf("\nGroesse des zu reservierenden Vektors in Bytes: %u", size);
    PAUSE;
    zufalls_vektor = (int *)malloc(size);
    if (zufalls_vektor == NULL)
    {
        printf("\nVektor nicht im Heap reservierbar!");
        PAUSE;
        exit(1);
    }

    /* Zufallszahlen erzeugen und im Vektor ablegen */
    srand(seed);                        /* Zufallszahlenfolge initialisieren */
    for (i = 0; i < anz; i++)
        zufalls_vektor[i] = rand()%999; /* Zufallszahl in [0,999] waehlen */

    /* Kontrollausgabe des Vektors */
    printf("\nErzeugter Vektor mit Zufallszahlen\n");
    printf(" (evtl. mit STRG-C abbrechen): \n");
    for (i = 0; i < anz; i++)
    {
        if (i%15==0)
            printf("\n");
        printf("%4d",zufalls_vektor[i]);
        if (i%300==299)
            PAUSE;
    }
    free(zufalls_vektor);               /* Vektorplatz freigeben */
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Machen Sie sich klar, dass bis auf die Vereinbarung des Feldes
    (als Zeiger) sowie den malloc- bzw. free-Aufruf der Umgang
    mit dynamischen Feldern sich nicht vom Umgang mit
    statisch definierten Feldern unterscheidet.
  - Gliedern Sie das Programm in Funktionen fuer die Reservierung,
    Fuellung und Ausgabe des Vektors. Erweitern Sie das Programm
    um eine Funktion fuer lineare Suche in einem nicht sortierten
    Vektor. Rufen Sie diese Funktion einmal oder mehrmals in
    main auf, nachdem per Eingabe ein Suchwert bestimmt wurde.
    Orientieren Sie sich am Beispielprogramm 8.2. Testen Sie das
    modifizierte Programm.
  - Was passiert, wenn Speicherplatz fuer mehr als ca. 32.000 ints, d.h.
    mehr als 64 KB angefordert wird? Testen Sie dies.
    Brechen Sie die Ausgabe ggf. mit STRG-C ab.

******************************************************************************/
