
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       07-15, Turm der Brahmanen
/*
/*      Konzepte/       rekursive Funktionen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm gibt Ihnen die Reihenfolge aus, in der
/*                      Sie die Scheiben des Turms der Brahmanen umlegen
/*                      muessen.
/*
/*      Bemerkung:      
/*
/*      Im grossen Tempel zu Benares befinden sich nach einer Sage drei Stifte,
/*      auf denen 64 goldene Lochscheiben unterschiedlicher Groesse stecken.
/*      Hindupriester sind staendig beschaeftigt, eine Scheibe nach der anderen
/*      von einem Stift auf einen anderen zu versetzen, wobei niemals eine
/*      groessere auf eine kleinere zu liegen kommen darf. Der Gott Brahma hat
/*      bei der Erschaffung der Erde dem Orden alle Scheiben zu einem Kegel
/*      geformt auf einem Stift uebergeben mit dem Auftrag, die Scheiben in der
/*      geschilderten Weise umzusetzen, bis der ganze Turm ueber einem anderen
/*      Stift neu errichtet waere. Dann wuerde die Welt untergehen.
/*      Leider ist die Legende nur das Geisteskind von Edouard Lucas, dem
/*      Erfinder des Turms der Brahmanen. Die Anzahl der Zuege, um drei
/*      Scheiben zu bewegen, ist sieben oder (2^3)-1 (2^3 = 2 hoch 3). Um sechs
/*      Scheiben zu transferieren, braucht man demnach (2^6)-1 oder 63 Zuege.
/*      Die Priester in Benares wuerden also (2^64)-1 Zuege benoetigen. Wenn
/*      sie jede Sekunde einen Zug machten, braeuchten Sie dafuer
/*      400.000.000.000.000.000.000 Jahrhunderte
/*
/*      Quelle: Denkspiele der Welt
/*              Pieter van Delft & Jack Botermans
/*              Heinrich Hugendubel Verlag, Muenchen
/*
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Es werden die sicheren Funktionen z.B. scanf_s(...)
/*                      anstatt scanf(...) genutzt. Die _s Versionen der bekannten
/*						Funktionen bieten �mehr Sicherheit� als ihre Vorg�nger.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void transportiere(int anzahl, int quelle, int hilfe, int ziel);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

unsigned long int umlegungen = 0;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int scheiben;   /* Anzahl der Scheiben */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 07-15, Turm der Brahmanen -----------------\n\n");

    /* Abfragen, aus wievielen Scheiben das Spiel besteht */
    printf("Das Programm legt den Turm der Brahmanen um (Tuerme von Hanoi).\n\n");
    printf("Wieviele Scheiben sollen umgelegt werden (nicht mehr als 10)?  ");
    scanf_s("%d", &scheiben);
    if (scheiben <= 0 || scheiben > 10)
      {  printf("\nUnzulaessige Eingabe!");
          PAUSE;
          return;
      }
    printf("\n");

    /* Fuehre Umlegungsprozess durch */
    printf("\n---------- Umlegen der Scheiben ----------\n\n");
    transportiere(scheiben, 1, 2, 3);
    /* Gib das Ergebnis am Bildschirm aus */
    printf("\n%d Umlegungen waren noetig.\n", umlegungen);
    PAUSE;
}

/* Funktion transportiere
    gibt die Anleitung aus, um anzahl Scheiben von Turm quelle auf Turm
    ziel zu legen.*/
void transportiere(int anzahl, int quelle, int hilfe, int ziel)
{
    /* Anweisungen */
    /* Rekursiver Aufruf, wenn mehr als eine Scheibe zu verschieben ist */
    if (anzahl>1)
        transportiere(anzahl-1, quelle, ziel, hilfe);

    /* Gib die Anleitung am Bildschirm aus */
    printf("Bringe Scheibe %2d vom Turm %2d ", anzahl, quelle);
    printf("nach Turm %2d\n", hilfe);

    /* Zaehle die Anzahl der Umlegungen */
    umlegungen++;
    if (umlegungen%10 == 0)
          PAUSE;

    /* Rekursiver Aufruf, wenn mehr als eine Scheibe zu verschieben ist  */
    if (anzahl>1)
        transportiere(anzahl-1, ziel, hilfe, quelle);
}
