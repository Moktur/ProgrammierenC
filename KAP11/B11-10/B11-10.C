
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-10, Personendaten verwalten
/*
/*      Konzepte/       Lesen und Schreiben von Binaerdateien
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm speichert alle beschriebenen Elemente
/*                      eines Vektors in eine Binaerdatei und liest sie
/*                      wieder ein.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funktionen zur Stringmanipulation */

/*****************************************************************************/
/* Konstanten / Makros definieren
/*****************************************************************************/

/* Maximale Groesse des Vektors */
#define MAXIMUM 5

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Typen definieren
/*****************************************************************************/

/* Die Struktur PERSON enthaelt Daten ueber eine Person */
typedef struct 
        {
                unsigned int nummer;
                char         name[21];
                char         vorname[21];
        } PERSON;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void InitialisiereVektor(PERSON *vektor);
char FrageStrukturdatenAb(PERSON *vektor);
void GebeVektorAus(PERSON *vektor, char letzterEintrag);
void SchreibeDatei(PERSON *vektor, char letzterEintrag);
char LeseDatei(PERSON *vektor);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    PERSON person[MAXIMUM];     /* Vektor mit Elementen des selbstdefinierten
                                   Datentyps PERSON */
    char letzterEintrag;        /* speichert den Index des letzten be-
                                   schriebenen Elements */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-10, Personendatei verwalten ------------\n\n");
    printf("\nDas Programm verwaltet Personendaten in einer Binaerdatei.\n");

    /* Initialisiere den Vektor */
    InitialisiereVektor(person);
    /* Frage die Personen-Daten ab, sichere Index des letzten Eintrags */
    letzterEintrag = FrageStrukturdatenAb(person);
    /* Gib die Personen-Daten am Bildschirm aus */
    GebeVektorAus(person, letzterEintrag);
    /* Schreibe Vektor (bis zum letzten Eintrag) in eine Datei */
    SchreibeDatei(person, letzterEintrag);
    /* Initialisiere den Vektor ein zweites Mal */
    InitialisiereVektor(person);
    /* Lese Daten aus der Datei in den Vektor */
    letzterEintrag = LeseDatei(person);
    /* Gib die Personen-Daten am Bildschirm ein zweites Mal aus */
    if (letzterEintrag != -1)
          GebeVektorAus(person, letzterEintrag);
    PAUSE;
}

/* Funktion InitialisiereVektor,
   initialisiert den Vektor vektor */
void InitialisiereVektor(PERSON *vektor)
{
    /* Lokale Variablen definieren */
    PERSON *aktuell;    /* Zeiger auf das aktuell zu bearbeitende Element */

    /* Anweisungen */

    /* Initialisiere alle Elemente im Vektor */
    for (aktuell = vektor; aktuell - vektor < MAXIMUM; aktuell++)
    {
        aktuell->nummer = 0;
        strcpy_s(aktuell->name, (int)sizeof(aktuell->name)-1, "");
        strcpy_s(aktuell->vorname, (int)sizeof(aktuell->vorname)-1, "");
    }
}

/* Funktion: FrageStrukturdatenAb
   fragt die Personen-Daten ab, liefert Index des letzten Eintrags zurueck */
char FrageStrukturdatenAb(PERSON *vektor)
{
    /* Lokale Variablen definieren */
    PERSON *aktuell;    /* Zeiger auf das aktuell zu bearbeitende Element */

    /* Anweisungen */

    /* Informationen */
    printf("\nBitte geben Sie die Daten von max. 5 Personen ein.");
    printf("\nNamen und Vornamen duerfen max. 20 Zeichen umfassen und");
    printf("\nkeine Leerzeichen enthalten. Als Nummern werden positive");
    printf("\nint-Werte erwartet. Die Nummer 0 beendet die Eingabe.\n");

    /* Gehe alle Elemente des Vektor durch */
    for (aktuell = vektor; aktuell - vektor < MAXIMUM; aktuell++)
    {
        printf("\nNummer : ");
        scanf_s("%u", &(aktuell->nummer));
        /* Wenn abfrage noch nicht abgebrochen wurde */ 
        if (aktuell->nummer != 0)
        {
            /* Frage die restlichen Daten auch ab */
            printf("Name   : ");
            scanf_s("%s", aktuell->name, (int)sizeof(aktuell->name)-1);
            printf("Vorname: ");
            scanf_s("%s", aktuell->vorname, (int)sizeof(aktuell->vorname)-1);
        }
        else
            /* Ansonsten breche die Abfrage ab */
            break;
    }

    /* Rueckgabewert liefern */

    /* Liefere Index des letzten beschriebenen Elements zurueck */
    return (aktuell - vektor);
}

/* Funktion GebeVektorAus
   gibt die Personen-Daten im Vektor vektor am Bildschirm aus */
void GebeVektorAus(PERSON *vektor, char letzterEintrag)
{
    /* Lokale Variablen definieren */
    PERSON *aktuell;    /* Zeiger auf das aktuell zu bearbeitende Element */

    /* Anweisungen */

    printf("\n\nDie Daten des Vektors:\n\n");
    /* Gebe alle Elemente des Vektor am Bildschirm aus */
    for (aktuell = vektor; aktuell - vektor < letzterEintrag; aktuell++)
    {
        printf("Nummer : %d\n", aktuell->nummer);
        printf("Name   : %s\n", aktuell->name);
        printf("Vorname: %s\n\n", aktuell->vorname);
    }
}

/* Funktion SchreibeDatei
   schreibt Vektor (bis zum letzten Eintrag) in eine Datei */
void SchreibeDatei(PERSON *vektor, char letzterEintrag)
{
    /* Lokale Variablen definieren */
    FILE   *datei;
    char   dateiname[30];

    /* Anweisungen */

    /* Frage den Dateinamen ab */
    printf("\nGeben Sie den Dateinamen ein.\nACHTUNG! Eine vorhandene ");
    printf("Datei mit gleichem Namen wird geloescht!\n");
    printf("\nDateiname: ");
    scanf_s("%s", dateiname, (int)sizeof(dateiname)-1);

    /* Oeffne Datei zum Schreiben im Binaermodus */
    fopen_s(&datei, dateiname, "wb");
    if (datei == NULL)
    {
        /* Wenn Datei nicht erstellt werden konnte, gib Fehlermeldung aus */
        printf("\nFEHLER beim Erstellen der Datei!");
        PAUSE;
        return;
    }

    printf("\nIch schreibe nun die Daten in die Datei %s\n", dateiname);
    /* Schreibe jedes beschriebene Element in die Datei */
    fwrite(vektor, sizeof(PERSON), letzterEintrag, datei);

    /* Schliesse die Datei */
    fclose(datei);
}

/* Funktion: LeseDatei
   liest Daten aus der Datei in den Vektor */
char LeseDatei(PERSON *vektor)
{
    FILE   *datei;
    char   dateiname[13];
    char   letzterEintrag;

    /* Frage den Dateinamen ab */
    printf("\n\nGeben Sie den Namen der Datei ein, aus der ich lesen soll.");
    printf("\n\nDateiname: ");
    scanf_s("%s", dateiname, (int)sizeof(dateiname)-1);

    /* Oeffne Datei zum Lesen im Binaermodus */
    fopen_s(&datei, dateiname, "rb");
    if (datei == NULL)
    {
        /* Wenn Datei nicht gelesen werden konnte, gib Fehlermeldung aus */
          printf("\nFEHLER beim Lesen der Datei");
          PAUSE;
        /* Liefere -1 als Zeichen zurueck, nicht gelesen werden konnte */
        return -1;
    }

    /* Lese Datei direkt in den Vektor, maximale Anzahl der zu lesenden
       Elemente ist MAXIMUM. Wenn die Datei schon vorher zuende ist, bricht
       die Funktion den Lesevorgang automatisch ab */
    printf("\nIch lese  nun die Daten aus der Datei %s\n", dateiname);
    letzterEintrag = fread(vektor, sizeof(PERSON), MAXIMUM, datei);

    /* Schliesse die Datei */
    fclose(datei);

    /* Liefere Anzahl der gelesenen Elemente zurueck */
    return letzterEintrag;
}
