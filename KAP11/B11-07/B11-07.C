
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-07, Dateizugriff II
/*
/*      Konzepte/       Oeffnen der Datei zum Lesen, Inhalt der Datei lesen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm oeffnet eine Datei, liest deren Inhalt
/*                      zeilenweise und gibt ihn am Bildschirm aus.
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
    FILE *datei;           /* Zeigt auf die FILE-Struktur der Datei */
    char dateiname[30];    /* Name der zu oeffnenden Datei */
    char inhalt[80];       /* Inhalt der Datei */
    int z = 0;             /* Zeilenzaehler */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-7, Dateizugriff II ---------------------\n\n");
    printf("\nDas Programm liest Daten zeilenweise aus einer Datei.\n");

    /* Frage Benutzer nach Dateinamen */
    printf("\nBitte geben Sie den DOS-Namen der Datei ein,");
    printf(" die Sie lesen wollen!");
    printf("\n\nDateiname: ");
    scanf_s("%s", dateiname, (int)sizeof(dateiname)-1);

    /* Oeffne die Datei zum Lesen */
    printf("\nIch oeffne nun die Datei \"%s\" zum Lesen.", dateiname);
    fopen_s(&datei, dateiname, "r");
    /* Wenn die Datei nicht geoeffnet werden kann */
    if (datei == NULL)
    {
        /* dann gib eine Fehlermeldung aus und beende das Programm */
        printf("\nFEHLER beim Oeffnen der Datei!");
        PAUSE;
        return;
    }

    /* Daten aus der Datei lesen und am Bildschirm ausgeben */
    printf("\n\nIch lese nun zeilenweise den Inhalt der Datei.\n");

    /* Solange noch etwas zu lesen ist... */
    while (fgets(inhalt, 80, datei))
      {
          /* ...schreibe es auf den Bildschirm */
          printf("%s", inhalt);
          if ((++z)%15 == 0) /* Pause nach 15 Zeilen */
                PAUSE;
      }

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

