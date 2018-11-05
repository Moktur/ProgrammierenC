
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-05, Manipulation von Namen I
/*
/*      Konzepte/       Stringfunktionen der Bibliothek string.h
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm liest wiederholt Vorname und Zuname von der Tastatur
/*          ein und gibt sie im Format "Zuname, Vorname" nebst Laenge des
/*          Namens am Bildschirm aus; ausserdem wird ein Vergleich mit dem
/*          vorher bearbeiteten Namen durchgefuehrt. Das Programm setzt
/*          Stringbearbeitungsfunktionen der Standardbibliothek ein.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <string.h>     /* Bearbeitungsfunktionen fuer Strings */

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
    char vorname[16],zuname[21],        /* Stringfelder */
         name[38], name_alt[38];
    static char komma[3] = ", ";        /* Stringkonstante, hier Speicherklasse
                                           static erforderlich */
    int laenge;                         /* Laenge des gesamten Namens */
    int name_vergleich;                 /* Resultat eines Namenvergleichs */
    int weiter;                         /* 0: nein, d.h. abbrechen, sonst: ja*/

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-05, Namensmanipulation I ---------------\n\n");

    printf("\nDas Programm bearbeitet Vor- und Zunamen.\n");

    strcpy_s(name_alt, 37, "");			/* Feld name_alt init. mit leerem String */
    do
    {
        fflush(stdin);					/* Vgl. voriges Programmbeispiel B08-03 */
        printf("\nBitte Vornamen (max. 15 Zeichen) eingeben und mit");
        printf(" RETURN beenden.\n");
        gets_s(vorname, 15);
        printf("Bitte Zunamen (max. 20 Zeichen) eingeben und mit");
        printf(" RETURN beenden.\n");
        gets_s(zuname, 20);

        strcpy_s(name, 37, zuname);       /* zuname nach name kopieren */
        strcat_s(name, 37, komma);        /* Komma anhaengen */
        strcat_s(name, 37, vorname);      /* vorname anhaengen */

        printf("\nVorname: %s Zuname: %s", vorname, zuname);
        printf("\nZuname und Vorname: %s", name);
        laenge = strlen(name);      /* Laenge des gesamten Namens ermitteln */
                                    /* Komma und Leerzeichen mitzaehlen */
        printf("\nDer Name enthaelt %d Zeichen.",laenge);

        /* Vergleich mit vorigem Namen */
        name_vergleich = strcmp(name,name_alt);
        if (name_vergleich == 0)
            printf("\nName wiederholte sich!");
        else if (name_vergleich < 0)
            printf("\nAktueller Name lexikographisch vor vorherigem Namen!");
        else
            printf("\nAktueller Name lexikographisch nach vorherigem Namen!");

        strcpy_s(name_alt, 37, name);     /* name nach name_alt kopieren */

        printf("\nNoch einen Namen bearbeiten (0:nein,sonst:ja): ");
        scanf_s("%d",&weiter);
    } while(weiter);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Machen Sie sich klar, dass die Laengen der Stringfelder vorname, zuname,
    komma und name konsistent gewaehlt wurden.
  - Die Sicherheit bei der Eingabe der Zeichenketten sollte erhoeht werden.
    Bisher wird nicht kontrolliert, ob eine zu lange Zeichenkette
    eingegeben wird. Modifizieren Sie das Programm wie folgt:
    (1) Definieren Sie einen Puffer mit 51 Zeichen fuer die Eingabe
        (kaum jemand wird einen Namen mit laenger als 50 Zeichen eintippen).
    (2) Lesen Sie mit gets jeweils zuerst in den Puffer ein.
    (3) Kontrollieren Sie dann mit der Funktion strlen, ob ein
        eingelesener Vor- oder Zuname die Laenge des vorgesehenen
        Stringfeldes (15 bzw. 20) ueberschreitet. Falls ja, muss
        die Eingabe zurueckgewiesen werden. Verlassen Sie ggf. das
        Programm mit einer Meldung und return.
    (4) Bei korrekter Eingabe kopieren Sie die Zeichenkette im Puffer
        in das vorgesehene Stringfeld mit strcpy.
  - Gehen Sie noch einen kleinen Schritt weiter: legen Sie die Eingabe
    in eine do-while-Schleife. Lassen Sie die Eingabe wiederholen, wenn
    eine Zeichenkette zu lang ist.
  - Bei dem Namensvergleich ist unschoen, dass beim ersten Mal ein
    Vergleich mit der leeren Zeichenkette in name_alt durchgefuehrt wird.
    Fuehren Sie eine Zusatzvariable first ein, mit der der erste Vergleich
    unterdrueckt wird.

******************************************************************************/
