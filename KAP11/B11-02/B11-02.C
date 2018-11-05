
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-02, Zeilenweises Kopieren einer Textdatei
/*
/*      Konzepte/       Lesen und Schreiben mit den Funktionen fgets, fputs
/*      Sprachelemente: 
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
	 char puffer[81];                      /* Max. 80 Zeichen pro Zeile */
    char quelldatei[13], zieldatei[13];
    FILE *ifp, *ofp;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-02, Textdatei zeilenweise kopieren -----\n\n");
    printf("\nDas Programm kopiert zeilenweise eine Textdatei.\n");

    printf("\nDOS-Name der Quelldatei: "); gets_s(quelldatei, (int)sizeof(quelldatei)-1);
    printf("DOS-Name der Zieldatei: "); gets_s(zieldatei, (int)sizeof(zieldatei)-1);

    if (fopen_s(&ifp, quelldatei, "r") != 0)
    {
        printf("\nDatei %s konnte nicht geoeffnet werden",quelldatei);
        PAUSE;
        return;
    }

    fopen_s(&ofp, zieldatei, "w");

    while (fgets(puffer, sizeof(puffer), ifp))
           fputs(puffer, ofp);

    fclose(ifp);
    fclose(ofp);
    printf("\nDatei %s nach Datei %s kopiert!",quelldatei,zieldatei);
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Bearbeiten Sie die analoge Aufgabe wie bei Beispielprogramm 11.1

******************************************************************************/
