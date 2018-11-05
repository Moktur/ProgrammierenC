
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-06, Dateizugriff I
/*
/*      Konzepte/       Oeffnen einer Datei im Schreibzugriff, Schreiben
/*      Sprachelemente: in eine Datei
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm fragt den Benutzer nach einen Dateinamen
/*                      und oeffnet die Datei zum Schreiben. Zeilenweise vorge-
/*                      nommene Eingaben des Benutzers werden in die
/*                      Datei geschrieben.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <string.h>     /* Funktionen fuer Stringmanipulation */

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
    FILE *datei;           /* Zeigt auf die Struktur mit den Daten der Datei */
    char dateiname[30];    /* Name der zu oeffnenden Datei */
    char eingabe[80];      /* Eingabe des Benutzers, die in die Datei 
                              geschrieben wird */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-06, Dateizugriff I ---------------------\n\n");
    printf("\nDas Programm schreibt Daten zeilenweise in eine Datei.\n");

    /* Frage Benutzer nach Dateinamen */
    printf("\nBitte geben Sie einen Dateinamen im DOS-Format ein.");
    printf("\nWARNUNG! Falls die Datei schon existiert, wird sie geloescht!");
    printf("\n\nDateiname: ");
    scanf_s("%s", dateiname, (int)sizeof(dateiname)-1);

    /* Oeffne die Datei zum schreiben */
    printf("\nIch oeffne nun die Datei \"%s\" zum Schreiben.", dateiname);
    fopen_s(&datei, dateiname, "w");
    /* Wenn die Datei nicht geoeffnet werden kann */
    if (datei == NULL)
    {
        /* dann gib eine Fehlermeldung aus und beende das Programm */
        printf("\nFEHLER beim Oeffnen der Datei!");
        PAUSE;
        return;
    }

    /* Eingaben des Benutzers in die Datei schreiben */
    printf("\n\nBitte geben Sie den Inhalt der Datei zeilenweise ein.");
    printf("\nJede Zeile wird durch RETURN beendet. ");
    printf("\nSie brechen die Eingabe mit der Zeile '*' ab.\n\n");
    do
    {
        /* Lies die Eingabe von der Tastatur zeilenweise */
        gets_s(eingabe, (int)sizeof(eingabe)-1);
        /* Schreibe die Eingabe in die Datei */
        fputs(eingabe, datei);
        /* Haengt ein Zeilenende-Zeichen an */
        fputc('\n', datei);
    }
    while (strcmp(eingabe, "*"));

    /* Schliesse die Datei */
    printf("\nIch schliesse nun die Datei \"%s\".\n", dateiname);
    /* Wenn Datei nicht geschlossen werden kann */
    if (fclose(datei) == EOF)
    {
        /* dann gib eine Fehlermeldung aus und beende das Programm */
        printf("\nFEHLER beim Schliessen der Datei!");
        PAUSE;
        return;
    }
    PAUSE;
}
