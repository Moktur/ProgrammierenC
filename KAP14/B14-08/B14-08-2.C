
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-08, Telefonbuch II
/*
/*      Konzepte/       Doppelt verkettete unsortierte Liste,
/*      Sprachelemente: Modularisierung, ADT
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT
/*                      Telefonbuch-II.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Definitionsdatei fuer ADT Telefonbuch II  einbinden */
#include "B14-08-2.h"

/*****************************************************************************/
/* Statische Variable definieren
/*****************************************************************************/

/* Zeiger auf den Kopf der Liste */
static pKNOTEN ListenKopf = NULL;
/* Zeiger auf den Fuss der Liste */
static pKNOTEN ListenFuss = NULL;

/*****************************************************************************/
/* Statische Funktionen deklarieren
/*****************************************************************************/

/* Erzeugt einen neuen Knoten mit den uebergebenen Werten */
static pKNOTEN ErzeugeNeuenKnoten(char *name, char *telefon);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   LoescheGanzeListe()
/* Aufgabe:
/*   Erzeugt eine leere Liste. Um das zu erreichen, wird wenn noetig die
/*   gesamte alte Liste geloescht.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void LoescheGanzeListe(void)
{
    /* Solange die Liste noch nicht leer ist, loesche den ersten Knoten */
    while (ListenKopf != NULL)
        LoescheKnotenAmAnfang();
}

/*****************************************************************************/
/* Funktion:
/*   FuegeKnotenAmAnfangEin()
/* Aufgabe:
/*   Fuegt einen Knoten mit den uebergebenen Werten am Anfang der Liste ein.
/* Parameter:
/*   name: Der Name der Person, die abgespeichert werden soll
/*   telefon: Die Telefonnummer der Person, die abgespeichert werden soll
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void FuegeKnotenAmAnfangEin(char *name, char *telefon)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Erzeuge einen neuen Knoten */
    NeuerKnoten = ErzeugeNeuenKnoten(name, telefon);

    /* Wenn die Liste noch leer ist, ist der neue Knoten am Kopf und am Fuss */
    if (ListenKopf == NULL)
        ListenKopf = ListenFuss = NeuerKnoten;
    /* Wenn die Liste nicht leer ist, fuege den Knoten am Anfang ein */
    else
    {
        /* Der bisher erste Knoten kriegt als Vorgaenger den neuen Knoten */
        ListenKopf->vorgaenger = NeuerKnoten;
        /* Der Nachfolger des neuen Knoten ist der bisher erste Knoten */
        NeuerKnoten->nachfolger = ListenKopf;
        /* Der neue Kopf der Liste ist der neue Knoten */
        ListenKopf = NeuerKnoten;
    }
}

/*****************************************************************************/
/* Funktion:
/*   FuegeKnotenAmEndeEin()
/* Aufgabe:
/*   Fuegt einen Knoten mit den uebergebenen Werten am Ende der Liste ein.
/* Parameter:
/*   name: Der Name der Person, die abgespeichert werden soll
/*   telefon: Die Telefonnummer der Person, die abgespeichert werden soll
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void FuegeKnotenAmEndeEin(char *name, char *telefon)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Erzeuge einen neuen Knoten */
    NeuerKnoten = ErzeugeNeuenKnoten(name, telefon);

    /* Wenn die Liste noch leer ist, ist der neue Knoten am Kopf und am Fuss */
    if (ListenKopf == NULL)
        ListenKopf = ListenFuss = NeuerKnoten;
    /* Wenn die Liste nicht leer ist, fuege den Knoten am Ende ein */
    else
    {
        /* Der bisher letzte Knoten kriegt als Nachfolger den neuen Knoten */
        ListenFuss->nachfolger = NeuerKnoten;
        /* Der Vorgaenger des neuen Knoten ist der bisher letzte Knoten */
        NeuerKnoten->vorgaenger = ListenFuss;
        /* Der neue Fuss der Liste ist der neue Knoten */
        ListenFuss = NeuerKnoten;
    }
}

/*****************************************************************************/
/* Funktion:
/*   LoescheKnotenAmAnfang()
/* Aufgabe:
/*   Loescht den ersten Knoten der Liste.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void LoescheKnotenAmAnfang(void)
{
    /* Lokale Variablen definieren */
    pKNOTEN ErsterKnoten;  /* Zeigt auf den zu loeschenden Knoten */

    /* Wenn die Liste leer ist, gibt es nichts zu tun */
    if (ListenKopf == NULL)
        return;

    /* Sichere einen Zeiger auf den ersten Knoten, damit er spaeter geloescht
       werden kann */
    ErsterKnoten = ListenKopf;

    /* Wenn der erste Knoten einen Nachfolger hat */ 
    if (ErsterKnoten->nachfolger != NULL)
    {
        /* Dann wird dieser zum neuen ersten Knoten in der Liste */
        ListenKopf = ErsterKnoten->nachfolger;
        /* Der erste Knoten in der Liste hat keinen Vorgaenger */
        ListenKopf->vorgaenger = NULL;
    }
    /* Wenn der letzte Knoten in der Liste geloescht wurde */
    else
        /* Ist die Liste leer */
        ListenKopf = ListenFuss = NULL;
    
    /* Gib Speicherplatz fuer den zu loeschenden Knoten frei */
    free(ErsterKnoten);
}

/*****************************************************************************/
/* Funktion:
/*   LoescheKnotenAmEnde()
/* Aufgabe:
/*   Loescht den letzten Knoten der Liste.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void LoescheKnotenAmEnde(void)
{
    /* Lokale Variablen definieren */
    pKNOTEN LetzterKnoten;  /* Zeigt auf den zu loeschenden Knoten */

    /* Wenn die Liste leer ist, gibt es nichts zu tun */
    if (ListenKopf == NULL)
        return;

    /* Sichere einen Zeiger auf den letzten Knoten, damit er spaeter geloescht
       werden kann */
    LetzterKnoten = ListenFuss;

    /* Wenn der letzte Knoten einen Vorgaenger hat */ 
    if (LetzterKnoten->vorgaenger != NULL)
    {
        /* Dann wird dieser zum neuen letzen Knoten in der Liste */
        ListenFuss = LetzterKnoten->vorgaenger;
        /* Der letzte Knoten in der Liste hat keinen Nachfolger */
        ListenFuss->nachfolger = NULL;
    }
    /* Wenn der letzte Knoten in der Liste geloescht wurde */
    else
        /* Ist die Liste leer */
        ListenKopf = ListenFuss = NULL;
    
    /* Gib Speicherplatz fuer den zu loeschenden Knoten frei */
    free(LetzterKnoten);
}

/*****************************************************************************/
/* Funktion:
/*   GibKnotenAmAnfangAus()
/* Aufgabe:
/*   Gibt die Daten des ersten Knoten in der Liste aus.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void GibKnotenAmAnfangAus(void)
{
    /* Wenn die Liste leer ist, gibt es nichts zu tun */
    if (ListenKopf == NULL)
        return;

    /* Gib die Daten aus */
    printf("            %s, %s\n", ListenKopf->name, ListenKopf->telefon);
}

/*****************************************************************************/
/* Funktion:
/*   GibKnotenAmEndeAus()
/* Aufgabe:
/*   Gibt die Daten des letzten Knoten in der Liste aus.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void GibKnotenAmEndeAus(void)
{
    /* Wenn die Liste leer ist, gibt es nichts zu tun */
    if (ListenKopf == NULL)
        return;

    /* Gib die Daten aus */
    printf("            %s, %s\n", ListenFuss->name, ListenFuss->telefon);
}

/*****************************************************************************/
/* Funktion:
/*   GibAlleKnotenAus()
/* Aufgabe:
/*   Gibt die Daten aller Knoten in der Liste aus.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void GibAlleKnotenAus(void)
{
    /* Lokale Variablen definieren */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */

    /* Erstes zu bearbeitende Knoten ist der erste Knoten der Liste */
    AktuellerKnoten = ListenKopf;

    /* Solange noch nicht das Ende der Liste erreicht wurde, gib die Daten
       der aktuelle Knoten aus */
    while (AktuellerKnoten != NULL)
    {
        /* Gib die Daten des aktuellen Knoten aus */
        printf("            %s, %s\n", AktuellerKnoten->name,
                                       AktuellerKnoten->telefon);

        /* Bearbeite naechsten Knoten in der Liste */
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }
}

/*****************************************************************************/
/* Funktion:
/*   ErmittleAnzahlDerKnoten()
/* Aufgabe:
/*   Ermittelt die Anzahl der Knoten in der Liste.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   Liefert die Anzahl der Knoten in der Liste
/*****************************************************************************/

unsigned int ErmittleAnzahlDerKnoten(void)
{
    /* Lokale Variablen definieren */
    int     Anzahl;           /* Die Anzahl der Knoten in der Liste */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */

    /* Bisher wurden 0 Knoten gezaehlt */
    Anzahl = 0;

    /* Erstes zu bearbeitende Knoten ist der erste Knoten der Liste */
    AktuellerKnoten = ListenKopf;

    /* Solange noch nicht das Ende der Liste erreicht wurde, zaehle die
       Knoten */
    while (AktuellerKnoten != NULL)
    {
        /* Zaehle diesen Knoten hinzu */
        ++Anzahl;

        /* Bearbeite naechsten Knoten in der Liste */
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* Liefere die Anzahl der Knoten zurueck */
    return Anzahl;
}

/*****************************************************************************/
/* Funktion:
/*   GibKnotenMitNamenAus()
/* Aufgabe:
/*   Gibt die Daten aller Knoten mit dem uebergebenen Namen aus.
/* Parameter:
/*   name: Der gesuchte Name
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void GibKnotenMitNamenAus(char *name)
{
    /* Lokale Variablen definieren */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */
    int     gefunden = 0;     /* Wurde der entsprechende Knoten gefunden?
                                            1 = ja bzw. 0 = nein */
    /* Erstes zu bearbeitende Knoten ist der erste Knoten der Liste */
    AktuellerKnoten = ListenKopf;

    /* Solange noch nicht das Ende der Liste erreicht wurde, suche Knoten mit
       dem uebergebenen Namen */
    while (AktuellerKnoten != NULL)
    {
        /* Ist der Knoten gefunden, gib die Daten aus */
        if (strcmp(AktuellerKnoten->name, name) == 0)
        {
            gefunden = 1;    /* Ein Knoten mit dem angegebenen Namen wurde
                                gefunden */
            printf("            %s, %s\n", AktuellerKnoten->name,
                                           AktuellerKnoten->telefon);
        }
        /* Bearbeite naechsten Knoten in der Liste */
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* Wenn keine Knoten mit dem angegebenen Namen gefunden wurde,
        gib eine Meldung aus */
    if (gefunden == 0)
    {
        printf("Es wurde kein Eintrag mit dem angegebenen Namen");
        printf(" gefunden.\n");
    }
}

/*****************************************************************************/
/* Funktion:
/*   LoescheKnotenMitNamen()
/* Aufgabe:
/*   Loescht alle Knoten in der Liste, die den uebergebeben Namen haben.
/* Parameter:
/*   name: Der gesuchte Name
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void LoescheKnotenMitNamen(char *name)
{
    /* Lokale Variablen definieren */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */
    pKNOTEN AlterKnoten;      /* Der zu loeschende Knoten */
    int     gefunden = 0;     /* Wurde der entsprechende Knoten gefunden?
                                            1 = ja bzw. 0 = nein */
    /* Wenn die Liste leer ist, gibt es nichts zu tun */

    if (ListenKopf == NULL)
          {
          printf("Das Telefonbuch ist leer!\n");
          return;
          }

    AktuellerKnoten = ListenKopf;
    while (AktuellerKnoten != NULL)
    {
        /* Gehoert der aktuelle Knoten zu den gesuchten, dann loesche ihn */
        if (strcmp(AktuellerKnoten->name, name) == 0)
        {
            /* Ein gesuchter Knoten wurde gefunden */
            gefunden = 1;
            /* Ist der gefundene Knoten der erste in der Liste */
            if (AktuellerKnoten == ListenKopf)
            {
                /* Loesche den Knoten */
                LoescheKnotenAmAnfang();
                /* Naechster aktuelle Knoten ist der neue erste in der Liste */
                AktuellerKnoten = ListenKopf;
                /* Setzte Schleife fort */
                continue;
            }

            /* Ist der gesuchte Knoten am Ende der Liste */
            if (AktuellerKnoten == ListenFuss)
            {
                /* Loesche den Knoten */
                LoescheKnotenAmEnde();
                /* Beende Funktion, da das Ende der Liste erreicht wurde */
                return;
            }

            /* Der gefundene Knoten ist mitten in der Liste */

            /* Sichere den zu loeschenden Knoten */
            AlterKnoten = AktuellerKnoten;
            /* Schneide den Knoten aus der Liste */
            AlterKnoten->nachfolger->vorgaenger = AlterKnoten->vorgaenger;
            AlterKnoten->vorgaenger->nachfolger = AlterKnoten->nachfolger;
            /* Naechster aktueller Knoten ist der Nachfolger des zu loeschenden
               Knotens */
            AktuellerKnoten = AlterKnoten->nachfolger;
            /* Gib Speicherplatz fuer den zu loeschenden Knoten frei */
            free(AlterKnoten);
            /* Setzte Schleife fort */
            continue;
        }

        /* Untersuche naechsten Knoten in der Liste */
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* Wenn keine Knoten mit dem angegebenen Namen gefunden wurde,
        gib eine Meldung aus */
    if (gefunden == 0)
    {
        printf("Es wurde kein Eintrag mit dem angegebenen Namen");
        printf(" gefunden.\n");
    }
}

/*****************************************************************************/
/* Statische Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   ErzeugeNeuenKnoten()
/* Aufgabe:
/*   Reserviert den Speicherplatz fuer einen neuen Knoten und initialisiert
/*   die Elemente mit den uebergebenen Werten.
/* Parameter:
/*   name: Der Name der Person, die abgespeichert werden soll
/*   telefon: Die Telefonnummer der Person, die abgespeichert werden soll
/* Rueckgabewert:
/*   Liefert einen Zeiger auf den neuen Knoten
/*****************************************************************************/

static pKNOTEN ErzeugeNeuenKnoten(char *name, char *telefon)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;  /* Zeiger auf den neuen Knoten */

    /* Reserviere Speicherplatz fuer den neuen Knoten */
    NeuerKnoten = malloc(sizeof(KNOTEN));

    /* Schreibe die uebergebenen Werte in den Knoten */
    strncpy_s(NeuerKnoten->name, 19, name, 19);
    NeuerKnoten->name[19] = '\0'; /* Zeichenkette muss spaetestens an der 20.
                                     Stelle terminiert werden */
    strncpy_s(NeuerKnoten->telefon, 14, telefon, 14);
    NeuerKnoten->telefon[14] = '\0'; /* Zeichenkette muss spaetestens an der
                                        15. Stelle terminiert werden */

    /* Initialisiere Zeiger auf den Vorgaenger */
    NeuerKnoten->vorgaenger = NULL;
    /* Initialisiere Zeiger auf den Nachfolger */
    NeuerKnoten->nachfolger = NULL;

    /* Liefere Zeiger auf den neuen Knoten zurueck */
    return NeuerKnoten;
}
