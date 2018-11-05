
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-01, Zeichenweises Kopieren einer Textdatei
/*
/*      Konzepte/       Umgang mit Textdateien, Oeffnen und Schliessen mit den
/*      Sprachelemente: Funktionen fopen, fclose, Lesen und Schreiben mit den
/*                      Funktionen fgetc, fputc
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

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
    int c;
    char quelldatei[30], zieldatei[30];
    FILE *ifp, *ofp;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-01, Textdatei zeichenweise kopieren ----\n\n");

    printf("\nDas Programm kopiert eine Textdatei zeichenweise.\n");
    printf("\nDOS-Name der Quelldatei: "); gets_s(quelldatei, (int)sizeof(quelldatei)-1);
    printf("DOS-Name der Zieldatei: "); gets_s(zieldatei, (int)sizeof(zieldatei)-1);

    if (fopen_s(&ifp, quelldatei, "r") != 0)
    {
        printf("\nDatei %s konnte nicht geoeffnet werden",quelldatei);
        PAUSE;
        return;
    }

    fopen_s(&ofp, zieldatei, "w");

    while ((c = fgetc(ifp)) != EOF)
        fputc(c, ofp);

    fclose(ifp);
    fclose(ofp);
    printf("\nDatei %s nach Datei %s kopiert!",quelldatei,zieldatei);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Erstellen Sie mit einem Editor eine Quelldatei und testen Sie das Programm.
  - Modifizieren Sie das Programm wie folgt: Die Zieldatei soll nicht neu
    geschrieben, sondern die Quelldatei an eine bestehende Zieldatei angehangen
    werden. Testen Sie auch diese Modifikation, nachdem Sie vorher eine
    Zieldatei erstellt haben.

******************************************************************************/
