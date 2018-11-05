
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-06, Vektoren und Felder
/*
/*      Konzepte/       Vektoren und mehrdimensionale Felder
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt den Umgang mit Vektoren und
/*                      mehrdimensionalen Feldern
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funktionen zur String-Manipulation */

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
    char  wahl[12];
    int   x, y, z;
    float feld_1[5];        /* Vereinbarung eines Vektors */
    int   feld_2[3][2];     /* Vereinbarung eines 2D-Feldes */
    int   feld_3[6][6][6];  /* Vereinbarung eines 3D-Feldes */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-06, Felder verschiedener Dimension -----\n");
    printf("\nDas Programm verarbeitet Felder verschiedener Dimensionsanzahlen.\n");

    /* Fuellung feld_2 mit Werten */
    feld_2[0][0]=5;
    feld_2[0][1]=7;
    feld_2[1][0]=12;
    feld_2[1][1]=34;
    feld_2[2][0]=9;
    feld_2[2][1]=123;

    /* Abfrage der Werte fuer feld_1 */
    printf("\nBitte fuellen Sie das erste Feld mit float-Werten:\n\n");
    for (x = 1; x <= 5; x++)
    {
        printf("%d. Wert: ", x);   /* Einlesen der Werte */
        scanf_s("%f", &feld_1[x-1]);
    }

    /* Ausgabe der gerade eingegebenen Werte von feld_1 */
    printf("\n\nDiese Werte haben Sie eingegeben:\n\n");
    for (x = 1; x <= 5; x++)
    {
        printf("Eingabe an Position %d: %.2f\n", x, feld_1[x-1]);
    }

    /* Ausgabe der Werte von feld_2 */
    printf("\n\nAusgabe eines schon mit Werten gefuellten 2D-Feldes:\n\n");
    for (x = 0; x <= 2; x++)
    {
        for (y = 0; y <= 1; y++)
            printf("feld_2[%d][%d] = %4d\t", x, y, feld_2[x][y]);
        printf("\n");
    }

    /* feld_3 mit Werten fuellen */
    printf("\n\nEin 3D-Feld wird mit Werten gefuellt...\n\n");
    for(x = 0; x <= 5; x++)
    {
        for(y = 0; y <= 5; y++)
        {
            for(z = 0; z <= 5; z++)
                /* Werte fuer die Zellen */
                feld_3[x][y][z] = x + y + z;
        }
    }

    do
    {
        /* Ausgeben der Zelleninhalte von feld_3 */

          /* Bestimmung der Zelle */
          printf("\nBitte Zelle des 3D-Feldes angeben, die ausgelesen werden soll. ");
          printf("\nZ. B. 2 0 5. Beachte: jeder Wert muss kleiner 6 sein.");
          printf("\nIhre Wahl: ");
		  fflush(stdin);
        /* Abfrage der Feldindizes */
        scanf_s("%d %d %d", &x, &y, &z);
          if (x < 0 || x > 5 ||
                y < 0 || y > 5 ||
                z < 0 || z > 5 )
            {  printf("\nUnzulaessige Eingabe!");
                PAUSE;
                return;
            }

        /* Ausgabe des Inhalts */
        printf("\nWert der Zelle[%d][%d][%d]:%5d\n", x, y, z, feld_3[x][y][z]);
        /* Noch ein Durchlauf? */
        printf("Wollen Sie noch eine Zelle auslesen (j/n)? ");
        scanf_s("%s", wahl, 11);
    }
    while (!strcmp(wahl, "j") || !strcmp(wahl, "J"));
    printf("\n\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Mit welcher Initialisierung der Matrix feld_2 bei der Definition koennen die
  obigen Wertzuweisungen entfallen? Aendern Sie das Programm dementsprechend
  ab, starten Sie es erneut und pruefen Sie Ihre Loesung.

******************************************************************************/
