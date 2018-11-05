
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-01, dynamische Speicherreservierung
/*
/*      Konzepte/       Dynamische Speicherreservierung mit den Funktionen
/*      Sprachelemente: malloc, calloc und free
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

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
    int *pi;
    float *pf;
    long *pl;
    long summe;
    int i;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-01, dynamische Speicherreservierung ----\n\n");
    printf("\nDas Programm zeigt die dynamische Speicherreservierung");
    printf("\nmit den Funktionen malloc, calloc und free.\n");

    pf = (float *)malloc(sizeof(float));          /* MALLOC */
    if (pf == NULL)
    {
        printf("\nReservierung von 1 float klappte nicht!");
        PAUSE;
        exit(1);
    }

    *pf = 10.99F;
    printf("\nWert auf dynamisch reserviertem float-Platz:  %.2f\n",*pf);
    free(pf);                                     /* FREE */

    pi = (int *)malloc(10*sizeof(int));           /* MALLOC */
    if (pi == NULL)
    {
        printf("\nReservierung von 10 ints klappte nicht!");
        PAUSE;
        exit(1);
    }

    printf("\nBitte 10 int-Werte eingeben!\n");
    for(summe=0,i=0; i < 10; i++)
    {
        printf("%2d-ten int-Wert eingeben: ",i+1); scanf_s("%d",pi+i);
        summe += *(pi+i);
    }
    printf("\nSummierung der Werte auf dynamisch reserv. int-Plaetzen:  %ld\n",
           summe);
    free(pi);                                     /* FREE */

    pl = (long *)calloc(5, sizeof(long));         /* CALLOC */
    if (pl == NULL)
    {
        printf("\nReservierung von 5 longs klappte nicht!");
        PAUSE;
        exit(1);
    }

    for(i=0; i < 5; i++)
       printf("\n%d-ter long-Platz initialisiert mit: %ld",i+1, *(pl+i));
    free(pl);                                     /* FREE */
    printf("\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Reservieren Sie im Beispielprogramm zusaetzlich Platz fuer
    10 floats, lesen Sie dort Werte ein und bestimmen Sie den
    kleinsten Wert, der dann auszugeben ist. Testen Sie
    wie im Beispielprogramm den Rueckgabewert von malloc ab.
  - Schreiben Sie ein Makro, das fuer einen uebergebenen Typ und
    eine uebergebene Anzahl Werte einen malloc-Aufruf durchfuehrt
    und einen Zeiger auf den Typ zurueckgibt. Auf diese Weise
    koennen malloc-Aufrufe bequemer gemacht werden. Testen Sie
    das Makro mit einer geeigneten main-Funktion.
  - Testen Sie den Zeitverbrauch von malloc und calloc.
    Schreiben Sie ein Programm, das malloc bzw. calloc
    n-mal aufruft und dabei jeweils m int's oder floats's
    reserviert. Variieren Sie bei gleichem insgesamt angefordertem
    Speicherplatz die Anzahl der malloc- bzw. calloc-Aufrufe, d.h.
    die Parameter n und m (bei gleichem Produkt n*m).
    Messen Sie die Zeit analog wie im Beispielprogramm 8.2.

******************************************************************************/
