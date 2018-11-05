
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-07, Telefonbuch I
/*
/*      Konzepte/       einfach verkettete Liste, sortiert und unsortiert
/*      Sprachelemente:
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT Telefonbuch-I.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Definitionsdatei fuer ADT Telefonbuch I einbinden */
#include "B14-07-2.h"

/*****************************************************************************/
/* Statische Variable definieren
/*****************************************************************************/

/* Zeiger auf den Kopf der Liste */
static pKNOTEN ListenKopf = NULL;

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

    /* Nachfolger des neuen Knoten ist der bisher erste Knoten der Liste */
    NeuerKnoten->nachfolger = ListenKopf;

    /* Neuer Kopf der Liste ist der neue Knoten */
    ListenKopf = NeuerKnoten;
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

    /* Sichere Ersten Knoten */
    ErsterKnoten = ListenKopf;

    /* Neuer Kopf der Liste ist der zweite Knoten */
    ListenKopf = ErsterKnoten->nachfolger;

    /* Gib Speicherplatz fuer den zu loeschenden Knoten frei */
    free(ErsterKnoten);
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

    /* Erster zu bearbeitende Knoten ist der erste Knoten der Liste */
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
/*   Gibt die Daten aller Knoten mit dem uebergebenen Namen aus. In der
/*   unsortierten Liste kann der Name mehrfach auftreten, in der sortierten
/*   Liste nur einmal.
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

    /* Erster zu bearbeitende Knoten ist der erste Knoten der Liste */
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
            /* Wenn wir uns auf eine sortierte Liste beschraenken wuerden,
               koennten wir hier die Funktion beenden, da der Name kein
               zweites Mal auftauchen kann:
            return;
            */
        }
        /* Bearbeite naechsten Knoten in der Liste */
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* Wenn kein Knoten mit dem angegebenen Namen gefunden wurde,
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
    pKNOTEN Vorgaenger;       /* Der Vorgaenger des aktuellen Knoten */
    int     gefunden = 0;     /* Wurde der entsprechende Knoten gefunden?
                                            1 = ja bzw. 0 = nein */

    /* Wenn die Liste leer ist, gibt es nichts zu tun */
    if (ListenKopf == NULL)
    {
        printf("Das Telefonbuch ist leer!\n");
        return;
    }

    /* Suche ab dem 2. Knoten in der Liste die zu loeschenden, bis das Ende der
       Liste erreicht wurde. (Der erste Knoten wird nachher als Sonderfall
       behandelt.) */
    Vorgaenger = ListenKopf;
    AktuellerKnoten = Vorgaenger->nachfolger;
    while (AktuellerKnoten != NULL)
    {
        /* Gehoert der aktuelle Knoten zu den gesuchten, dann loesche ihn */
        if (strcmp(AktuellerKnoten->name, name) == 0)
        {
            /* Ein gesuchter Knoten wurde gefunden */
            gefunden = 1;
            /* Trenne Knoten von der Liste */
            Vorgaenger->nachfolger = AktuellerKnoten->nachfolger;
            /* Gib den Speicherplatz frei */
            free(AktuellerKnoten);
            /* Bestimme neuen aktuellen Knoten */
            AktuellerKnoten = Vorgaenger->nachfolger;
            /* Setze Schleife fort */
            continue;

            /* Wenn wir uns auf eine sortierte Liste beschraenken, koennen
               wir an dieser Stelle die Funktion verlassen, da der Name kein
               zweites mal in der Liste vorkommt:
            return;
            */
        }

        /* Untersuche naechsten Knoten in der Liste */
        Vorgaenger = AktuellerKnoten;
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* Jetzt kommt der Sonderfall: der erste Knoten wird untersucht, ob er der
       gesuchte ist. Da der Rest der Liste schon untersucht wurde, ist man
       sicher, dass nur noch der erste Knoten unter Umstaenden geloescht
       werden muss und dass die nachfolgenden Knoten nicht mehr zu den
       gesuchten gehoeren. */
    if (strcmp(ListenKopf->name, name) == 0)
          {
          gefunden = 1;    /* Ein gesuchter Knoten wurde gefunden */
          LoescheKnotenAmAnfang();
          }

    /* Wenn kein Knoten mit dem angegebenen Namen gefunden wurde,
        gib eine Meldung aus */
    if (gefunden == 0)
          {
          printf("Es wurde kein Eintrag mit dem angegebenen Namen");
          printf(" gefunden.\n");
          }
}

/*****************************************************************************/
/* Funktion:
/*   FuegeKnotenSortiertEin
/* Aufgabe:
/*   Fuegt einen Knoten dem Namen nach sortiert in die Liste ein.
/* Parameter:
/*   name: Der Name der Person, die abgespeichert werden soll
/*   telefon: Die Telefonnummer der Person, die abgespeichert werden soll
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void FuegeKnotenSortiertEin(char *name, char *telefon)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;      /* Zeiger auf den neuen Knoten */
    pKNOTEN AktuellerKnoten;  /* Der aktuell zu bearbeitende Knoten */
    pKNOTEN Vorgaenger;       /* Der Vorgaenger des aktuellen Knoten */

    /* Erzeuge einen neuen Knoten */
    NeuerKnoten = ErzeugeNeuenKnoten(name, telefon);

    /* 1) die Liste ist leer, d.h. der neue Knoten ist der erste der Liste */
    if (ListenKopf == NULL)
    {
        ListenKopf = NeuerKnoten;
        return;
    }

    /* 2) der neue Knoten gehoert an den Anfang der Liste */
    if (strcmp(name, ListenKopf->name) < 0)
    {
        NeuerKnoten->nachfolger = ListenKopf;
        ListenKopf = NeuerKnoten;
        return;
    }

    /* 3) der neue Knoten gehoert mitten in die Liste hinein */
    Vorgaenger = ListenKopf;
    AktuellerKnoten = ListenKopf->nachfolger;
    /* Solange nicht das Ende der Liste erreicht wurde, ueberpruefe, ob der
       neue Knoten vor den aktuellen Knoten gehoert */
    while (AktuellerKnoten != NULL)
    {
        /* Wenn der neue Knoten genau zwischen den aktuellen Knoten und
           dessen Vorgaenger gehoert */
        if((strcmp(name, AktuellerKnoten->name) < 0) &&
           (strcmp(name, Vorgaenger->name) > 0))
        {
            /* Fuege neuen Knoten vor dem aktuellen Knoten ein */
            NeuerKnoten->nachfolger = AktuellerKnoten;
            Vorgaenger->nachfolger = NeuerKnoten;
            return;
        }

        /* Ueberpruefe nachfolgendes Element */
        Vorgaenger = AktuellerKnoten;
        AktuellerKnoten = AktuellerKnoten->nachfolger;
    }

    /* 4) der neue Knoten gehoert an das Ende der Liste, Vorgaenger zeigt
          jetzt auf das letzte Element der Liste */
    if (strcmp(name, Vorgaenger->name) > 0)
        Vorgaenger->nachfolger = NeuerKnoten;
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

    /* Initialisiere Zeiger auf den Nachfolger */
    NeuerKnoten->nachfolger = NULL;

    /* Liefere Zeiger auf den neuen Knoten zurueck */
    return NeuerKnoten;
}
