
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       09-05, Studenten-Datenbank
/*
/*      Konzepte/       Vektoren von Strukturen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm fragt nach den Daten von bis zu 50
/*                      Studenten und speichert diese in einem Strukturen-
/*                      Vektor. Die Daten koennen ueber verschiedene Such-
/*                      Funktionen abgerufen werden.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funktionen fuer die Stringmanipulation */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}
#define MAXZEICHEN 15
#define MAXSTUDENTEN 50

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

typedef struct
        {
        char name[MAXZEICHEN];
        char vorname[MAXZEICHEN];
        int  semester;
        long matrikelnr;
        } STUDENTEN;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

int abfrage(void);
void auflisten(int wahl, int anzahl);
void ausgabe(int modus, int anz_aus, int i);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

STUDENTEN student[MAXSTUDENTEN];

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int anzahl, wahl;
    char wiederholen[8];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 09-05, Studenten-Datenbank ----------------\n\n");
    printf("\nDas Programm verwaltet Studentendaten in einem Strukturenvektor.");

    /* Abfrage der Daten */
    anzahl = abfrage();

    /* Menue ausgeben */
    do
    {
      printf("\n\nAuflisten aller Datensaetze                           -=> 0");
      printf("\nSuchen eines bestimmten Datensatzes nach Namen        -=> 1");
      printf("\nSuchen eines bestimmten Datensatzes nach Semester     -=> 2");
      printf("\nSuchen eines bestimmten Datensatzes nach Matrikel-Nr. -=> 3");
      printf("\n\nIhre Wahl -=> ");
      scanf_s("%d", &wahl);
      auflisten(wahl, anzahl);
      /* Abfragen, ob die Suche wiederholt werden soll */
      printf("\nWollen Sie eine neue Suche durchfuehren (j/n)? ");
      scanf_s("%s", wiederholen, MAXZEICHEN-1);
    }
    while (!strcmp(wiederholen, "j") || !strcmp(wiederholen, "J"));
}

/* Funktion abfrage
   fragt die Daten ab, die in den Strukturen gespeichert werden sollen */

int abfrage(void)
{
    /* Lokale Variablen definieren */
    int i = -1;  /* Index der aktuellen Struktur im Vektor */
    char name[MAXZEICHEN]; /* Hilfsfeld fuer Namenseingabe */

    /* Anweisungen */

    /* Daten abfragen */
    printf("\nName und Vorname duerfen max. 14 Zeichen umfassen und");
    printf("\nduerfen keine Leerzeichen enthalten.");
    printf("\nDie Eingabe endet, wenn * als Name eingegeben wird.\n");
    do
    {
        printf("\nName:      ");
        scanf_s("%s", name, MAXZEICHEN-1);
        /* Wenn nicht * eingegeben wurde, den Rest auch abfragen */
        if (strcmp(name, "*") != 0)
        {
                ++i;   /* naechster Index */
                strcpy_s(student[i].name, MAXZEICHEN-1, name); /* Namen uebernehmen */
                printf("Vorname:   ");
                scanf_s("%s", student[i].vorname, MAXZEICHEN-1);
                printf("Semester:  ");
                scanf_s("%d", &student[i].semester);
                printf("Matr.-Nr.: ");
                scanf_s("%ld", &student[i].matrikelnr);
        }
    }
    /* abbrechen, wenn "*" als Name eingegeben wurde oder schon 50
        Studenten eingegeben wurden */
    while ((strcmp(name, "*") != 0) && (i < 49));

    /* Rueckgabewert Anzahl der Studenten liefern */
    return (i + 1);
}

/* Funktion auflisten
   listet die Daten nach den gewuenschten Kriterien auf */
void auflisten(int wahl, int anzahl)
{
    /* Lokale Variablen definieren */
    int  i;
    int  anz_aus = 0;  /* Anzahl ausgegebener Studenten */
    int  semester;
    long matrikelnr;
    char name[MAXZEICHEN];
    
    /* Anweisungen */
    switch (wahl)
    {
        case 0: /* Alle Datensaetze der Reihe nach auflisten */
                for (i = 0; i < anzahl; i++)
                {
                    /* Daten am Bildschirm ausgeben */
                          anz_aus++;
                          ausgabe(0, anz_aus,i);
                }
                    break;

        case 1: /* Zu suchenden Namen abfragen */
                printf("\n\nBitte gesuchten Namen angeben (max. 14 Zeichen): ");
                scanf_s("%s", name, MAXZEICHEN-1);
                /* Datensaetze durchsuchen */
                for (i = 0; i < anzahl; i++)
                {
                    /* Wenn Name im Datensatz mit gesuchtem uebereinstimmt */
                    if (strcmp(name, student[i].name) == 0)
                    {
                        /* Daten am Bildschirm ausgeben */
                        anz_aus++;
                        ausgabe(1, anz_aus,i);
                    }
                }
                break;

        case 2: /* Zu suchendes Semester abfragen */
                printf("\n\nBitte gesuchtes Semester angeben: ");
                scanf_s("%d", &semester);
                /* Datensaetze durchsuchen */
                for (i = 0; i < anzahl; i++)
                {
                    /* Wenn Semester im Datensatz mit gesuchtem 
                       uebereinstimmt */
                    if (semester == student[i].semester)
                    {
                        /* Daten am Bildschirm ausgeben */
                        anz_aus++;
                        ausgabe(1, anz_aus,i);
                    }
                }
                break;

        case 3: /* Zu suchende MatrikelNr. abfragen */
                printf("\n\nBitte gesuchte Matrikel-Nr. angeben: ");
                scanf_s("%ld", &matrikelnr);
                /* Datensaetze durchsuchen */
                for (i = 0; i < anzahl; i++)
                {
                    /* Wenn MatrikelNr. im Datensatz mit gesuchter
                       uebereinstimmt */
                    if (matrikelnr == student[i].matrikelnr)
                    {
                        /* Daten am Bildschirm ausgeben */
                        anz_aus++;
                        ausgabe(1, anz_aus,i);
                    }
                }
                break;
    }
    /* Wenn kein Datensatz gefunden wurde, dann ausgeben */
    if (!anz_aus)
        printf("\nKeinen entsprechenden Datensatz gefunden.\n");
}

/* Funktion ausgabe
    gibt die Daten eines Studenten auf dem Bildschirm aus*/
void ausgabe(int modus, int anz_aus, int i)
{
    /* Anweisungen */
    if (anz_aus%15 == 1)  /* Listenkopf beim 1., 16. , 31.,... Studenten*/
    {   if (modus == 0)   /* modus bestimmt nur Listenkopf, 1. Zeile */
        {   printf("\n\n\tListe aller Studenten");
            printf("\n\t=====================");
        }
        else
        {   printf("\n\n\tListe der gesuchten Studenten");
            printf("\n\t=============================");
        }
        printf("\n\n%-s%-15s%-15s%-s%-s\n%s%s",
               "Lfd.-Nr. ",
               "Name",
               "Vorname",
               "Semester ",
               "Matr.-Nr ",
               "----------------------------------------",
               "---------------------------------------");
    }

    printf("\n%-9d%-15s%-15s%-9d%-9ld",
           anz_aus, student[i].name, student[i].vorname,
           student[i].semester, student[i].matrikelnr);
    if (anz_aus%15==0) /* Pause nach je 15 Studenten */
        PAUSE;
}
