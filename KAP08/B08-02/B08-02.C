
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-02, Primzahlberechnung mit dem Sieb des Eratosthenes
/*
/*      Konzepte/       mehrere Funktionen, Vektoren, Steueranweisungen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <conio.h>

/*****************************************************************************/
/* Konstanten und Makros definieren
/*****************************************************************************/
#define MAX 1000

/* warten auf return */
#define  PAUSE {printf("\nRETURN!\n");fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

int input_obergrenze(void);
void berechne_primzahlen(int obergrenze);
void output_primzahlen(int obergrenze); 

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

int sieb[MAX];

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int obergrenze;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-02, Sieb des Eratosthenes --------------\n\n");
    printf("\nDas Programm berechnet alle Primzahlen im Intervall\n");
    printf("[2,Obergrenze] mit dem Sieb des Eratosthenes.\n");

    obergrenze = input_obergrenze();

    /* Programmende bei falscher Eingabe */
    if (obergrenze == 0)
    {
        PAUSE;
        return;
    }

    berechne_primzahlen(obergrenze);
    output_primzahlen(obergrenze);

    PAUSE;
}

/* liest und pr�ft Obergrenze */
int input_obergrenze(void)
{
    int obergrenze;

    printf("\nBitte ganzzahlige Obergrenze eingeben (<= %d): ", MAX);
    scanf_s("%u",&obergrenze);

    if (obergrenze < 2 || obergrenze > MAX)
    {
        printf("\nObergrenze unzulaessig");
        obergrenze = 0;
    }

    return obergrenze; 
}

/* berechnet Primzahlen mit Sieb des Eratosthenes */
void berechne_primzahlen(int obergrenze)
{
    int i, j;

    /* initialisiere Menge sieb */
    for (i = 2; i <= obergrenze; i++)
        sieb[i] = 1;

    /* entferne alle Nicht-Primzahlen aus der Menge sieb */
    for (i = 2; i <= obergrenze/2; i++)
    {
        if (sieb[i] == 1)
        {
            /* entferne alle Vielfachen von i ab 2*i aus sieb */
            for (j = 2*i; j <= obergrenze; j = j + i)
                sieb[j] = 0;
        }
    }
}

/* gibt Primzahlen bis obergrenze aus */
void output_primzahlen(int obergrenze)
{
	 int i, j = 0;
    printf("\nBerechnete Primzahlen bis: %d\n", obergrenze);
    for (i = 1; i <= obergrenze; i++)
    {
        /* Ausgabe Zahl, wenn noch in Menge enthalten */
        if (sieb[i] == 1)
		  {   printf(" %3u ", i);
				/* Zeilenvorschub nach 10 Zahlen, Pause nach 100 Zahlen */
				j++;
				if (j%10==0) printf("\n");
				if (j%100==0) PAUSE;
		  }
    }

    printf("\nEnde der Primzahlliste.");
}

