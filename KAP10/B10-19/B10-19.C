
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-19, Personendaten in einem Strukturvektor
/*
/*      Konzepte/       Zeiger auf Strukturen und der Zugriff auf die
/*      Sprachelemente: Komponenten von Strukturen mit Hilfe von Zeigern
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm liest Personendaten fuer mehrere Personen
/*                      ein, speichert diese in einem Vektor von Strukturen ab
/*                      und gibt die Personendaten abschliessend wieder aus.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <conio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funtionen fuer die Stringmanipulation */

/*****************************************************************************/
/* Konstanten / Makros / Typen definieren
/*****************************************************************************/
#define MAXZEICHEN 20 
#define maximum 50      /* Anzahl der Elemente im Vektor */

                        /* warten auf return */
#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

typedef struct          /* Strukturtyp PERSON */
{
    char name[MAXZEICHEN];
    char vorname[MAXZEICHEN];
    int  alter;
} PERSON;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void eingabe(PERSON *person);
void ausgabe(PERSON *person);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    PERSON Person[maximum];    /* Vektor von Struct PERSON */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-19, Personendaten in Strukturvektor ----\n\n");
    printf("\nDas Programm liest und gibt Personendaten aus.");
    printf("\nNamen und Vornamen duerfen max. 19 Zeichen umfassen.");
    printf("\nEin '*' als Name beendet die Eingabe.");

    /* Eingabe der Daten */
    eingabe(Person);         /* Uebergabe Feldanfang Vektor Person */

    /* Ausgabe der Daten */
    ausgabe(Person);         /* Uebergabe Feldanfang Vektor Person */
    PAUSE;
}

/* Funktion eingabe, liest Personendaten ein */
void eingabe(PERSON *person)
{
    /* Lokale Variablen definieren */
    PERSON *aktuell;
    int    nummer = 1;

    /* Anweisungen */

    /* aktuell zeigt auf das 1. Element des Vektors */
    aktuell = person;
    /* Daten der Personen einlesen */
    do
    {
        /* Abfragen der Personalien */
        printf("\n\nEingabe der Daten von Person Nr. %d\n", nummer);
        printf("Name (Ende: *) : ");
        scanf_s("%s", &(aktuell->name), MAXZEICHEN-1);
        /* Wenn nicht * eingegeben wurde, dann weiter abfragen */
        if (strcmp(aktuell->name, "*"))
        {
            printf("Vorname: ");
            scanf_s("%s", &(aktuell->vorname), MAXZEICHEN-1);
            printf("Alter: ");
            scanf_s("%d", &(aktuell->alter));
        }
        /* aktuell zeigt auf das naechste Element */
        ++aktuell;
        /* Nummer um eins erhoehen */
        ++nummer;
    }
    /* Solange, bis maximum erreicht oder Eingabe abgebrochen wurde */
    while ((aktuell-person) < maximum && strcmp((aktuell-1)->name, "*"));
}

/* Funktion ausgabe, gibt Personendaten aus */
void ausgabe(PERSON *person)
{
    /* Lokale Variablen definieren */
    PERSON *aktuell;
    int nummer;

    /* Anweisungen */

    /* aktuell zeigt auf das 1. Element des Vektors */
    aktuell = person;
    /* erste Nummer */
    nummer = 1;

    /* Ausgabe Listenkopf */
    printf("\n\n\t\t\tPersonendaten");
    printf("\n\t\t\t=============");
    printf("\n\n    Nummer                Name             Vorname");
    printf("     Alter");
    printf("\n    --------------------------------------------------------\n");

    /* Solange der Name nicht gleich * ist (markiert das Ende der Eingabe)
        und nicht bereits maximum Saetze ausgegeben */
    while (strcmp(aktuell->name, "*") &&
              nummer <= maximum)
    {
        /* Gib die Personendaten aus */
        printf("%10d%20s%20s%10d\n", nummer, aktuell->name,
               aktuell->vorname, aktuell->alter);
        /* aktuell zeigt auf das naechste Vektorelement */
        ++aktuell;
        /* Nummer um eins erhoehen */
        ++nummer;
    }
}
