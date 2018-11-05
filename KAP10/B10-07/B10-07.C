
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-07, Zeiger und Felder
/*
/*      Konzepte/       Zeigeranwendung auf Vektoren
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Programm liest float-Werte ein und gibt sie in der Lesereihenfolge
/*          sowie in umgekehrter Reihenfolge wieder aus.
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
/* Globale Variablen definieren
/*****************************************************************************/

float werte[20];        /* Vektor wird global vereinbart  */

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void werte_eingeben(int anz_ein);
void werte_ausgeben(int anz_aus);
void werte_invers_ausgeben(int anz_aus);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int anz;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-07, Zeiger und Felder ------------------\n\n");
    printf("\nDas Programm liest und gibt float-Werte eines Vektor aus.\n");

    /* Eingabe und Ausgabe in zwei Varianten */
    printf("\nBitte Anzahl ein- und auszugebender Werte (<= 20) eingeben: ");
    scanf_s("%d",&anz);
    werte_eingeben(anz);
    werte_ausgeben(anz);
    PAUSE;
    werte_invers_ausgeben(anz);
    PAUSE;
}

/* Funktion liest float-Werte in Vektor ein */
void werte_eingeben(int anz_ein)
{
    float *zgr;
    int i;

    printf("\n\nEingabe von float-Werten\n");
    zgr = werte;                /* Zeiger auf Feldanfang setzen */

    for (i = 0; i < anz_ein; i++)
    {
        printf("%2d-ten Wert eingeben: ", i+1);
        scanf_s("%f", zgr);       /* Einlesen unter Adresse des (i+1)-ten */
                                /* Feldelements, &-Operator entfaellt! */
        zgr++;                  /* Zeiger auf naechstes Feldelement */
    }
}

/* Funktion gibt float-Werte eines Vektors aus */
void werte_ausgeben(int anz_aus)
{
    float *zgr;
    int i = 1;

    printf("\n\nAusgabe der gelesenen float-Werte");

    /* Der Vektor werte wird mittels des Zeigers zgr durchlaufen */
    for (zgr = werte;                    /* Adresse des ersten Elements */
         zgr <= werte + anz_aus - 1;     /* Endebedingung als Zeigervergleich */
         zgr++)                          /* ein Feldelement weiter */
    {
         /* Nummer und Wert des i-ten Feldelements */
         printf("\n%2d-ter Wert ist: %f", i++, *zgr);
    }
}

/* Funktion gibt float-Werte eines Vektors in umgekehrter Reihenfolge aus */
void werte_invers_ausgeben(int anz_aus)
{
    int i;

    printf("\n\nAusgabe der gelesenen float-Werte in umgekehrter Reihenfolge");

    for (i = anz_aus; i > 0; i--)
    {
         /* Nummer, Wert des (i+1)-ten Feldelements */
         printf("\n%2d-ter Wert ist: %f", i, *(werte + i - 1));
    }
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Verdeutlichen Sie sich die Zeigerarithmetik.
  - Geben Sie beim Durchlaufen des Feldes in den Funktionen
    jeweils auch die Adresse des aktuellen Elements aus.
  - Geben Sie fuer die erste Ausgabefunktion auch die
    in der Endebedingung angegebene Vergleichsadresse
    mit aus und beobachten Sie die Zeigervergleiche.
  - Ergaenzen Sie die Eingabe der Elementanzahl  um eine
    Pruefung (anz <= 20). Lassen Sie die Eingabe wiederholen,
    wenn anz einen unzulaessigen Wert besitzt.

******************************************************************************/
