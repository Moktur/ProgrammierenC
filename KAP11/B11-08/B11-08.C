
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-08, Dateiausgabe
/*
/*      Konzepte/       Argumentuebergabe, Lesen von Dateien, Lesen von
/*      Sprachelemente: stdin und schreiben auf stdout
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm aehnelt dem DOS-Befehl 'type'. Es gibt
/*                      die als Argumente uebergebenen Dateien am Bildschirm
/*                      aus. Wurde kein Argument uebergeben, wird die Tasta-
/*                      tureingabe (stdin) auf dem Bildschirm (stdout) aus-
/*                      gegeben.
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

void foutput(FILE *input);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(int argc, char *argv[])
{
    /* lokale Variablen */
    FILE *datei;    /* Zeiger auf die FILE-Struktur der Datei */
    
    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-08, Dateiausgabe -----------------------\n\n");

    printf("\nDas Programm kopiert die Tastatureingabe (stdin) oder eine Datei");
    printf("\nauf den Bildschirm (stdout).\n");

    /* Wenn kein Argument uebergeben wurde */
    if (argc == 1)
    {
        /* dann Tastatureingabe auf den Bildschirm kopieren */
        printf("\nIch kopiere Ihre Tastatureingabe auf den Bildschirm.");
        printf("\nBrechen Sie Ihre Eingabe mit STRG-Z ab.\n\n");
        foutput(stdin);
        PAUSE;
    }
    else
    {
        /* ansonsten alle Dateien der Reihe nach am Bildschirm ausgeben */
        /* Gehe alle Argumente durch. */
        while(--argc > 0)
        {
            /* Datei oeffnen. *++argv bedeutet: argv zeigt auf die Zeichen-
               kette des aktuellen Arguments, anfangs also auf den Programm-
               namen. Der Ausdruck ++argv lasst argv nun auf die Zeichenkette
               des naechsten Arguments zeigen. Mit *++argv wird also immer
               die Zeichenkette des naechsten Arguments ermittelt. */
            fopen_s(&datei, *++argv, "r");
            /* Wenn Datei nicht geoeffnet werden konnte */
            if (datei == NULL)
            {
                /* dann Fehlermeldung ausgeben und Programm beenden */
                printf("\nFEHLER beim Oeffnen der Datei %s.", *argv);
                PAUSE;
                return;
            }
            else
            {
                /* ansonsten Inhalt der Datei am Bildschirm ausgeben
                   und anschliessend schliessen */
                printf("\nAusgabe der naechsten Datei...\n");
                foutput(datei);
                PAUSE;
                fclose(datei);
            }
        }
    }
}

/* Funktion foutput,
     gibt Datei input am Bildschirm zeichenweise aus */
void foutput(FILE *input)
{
    /* lokale Variablen */
    int c;

    /* Anweisungen */

    /* solange noch kein Dateiendezeichen (EOF) gefunden */
    while((c = getc(input)) != EOF)
        /* schreibe Zeichen in Datei output */
        putc(c, stdout);
}
