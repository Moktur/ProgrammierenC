
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-03, Summierung reeller Werte I
/*
/*      Konzepte/       while-Schleife
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

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}
/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int   zaehler = 0,      /* Wertezaehler */
          anzahl;           /* Wertanzahl */
    float summand,          /* Summand */
          summe = 0.;       /* Summe */

    int ende = EOF + 1;
    
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-03, Summe reller Werte I ---------------\n\n");
    printf("\nDas Programm addiert float-Werte.\n");

    printf("\nEOF = %d ", EOF);getchar();

    /* Eingabe und Berechnung in while-Schleife */
    printf("\nWieviele Werte addieren (>= 1) ? "); scanf_s("%d", &anzahl);
    while (zaehler < anzahl && ende != EOF)
    {
        printf("Naechster float-Wert? ");
        ende = scanf_s("%f",&summand);
        if (ende == EOF)
        {    
            printf("\nende = %d", ende);
            continue;
        }

        summe += summand;
        zaehler++;
    }

    /* Ausgabe */
    printf("\nAnzahl Werte: %d  Summe: %.2f", zaehler, summe);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Modifizieren Sie das Programm wie folgt:
    - Einfuehrung einer festen Obergrenze maxanzahl zu addierender Werte,
      etwa maxanzahl = 50;
    - Addition soll beendet werden, wenn entweder bereits maxanzahl Werte
      eingelesen und addiert wurden oder wenn der Nutzer die Eingabe mit
      STRG-Z (Dateiende EOF) abbricht;
    - daher sollte das Ergebnis (Rueckgabewert) von scanf abgefragt
      und mit EOF verglichen werden; das Ergebnis von scanf kann in einer
      Variablen ende (Endemarke) aufgehoben werden; eine weitere Addition
      findet innerhalb des aktuellen Schleifendurchlaufs daher nur statt,
      wenn nach dem letzten Einlesen noch ende != EOF gilt;
    - ferner muss die Bedingung im Kopf der while-Schleife wie folgt
      erweitert werden
            zaehler < anzahl && ende != EOF
    - die Endemarke ende muss daher anfangs auf einen von EOF verschiedenen
      Wert initialisiert werden, etwa ende = EOF + 1.
  Testen Sie das modifizierte Programm.

******************************************************************************/
