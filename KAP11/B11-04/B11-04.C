
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-04, Artikeldatei verwalten II
/*
/*      Konzepte/       Umgang mit Binaerdateien, Oeffnen und Schliessen mit 
/*      Sprachelemente: den Funktionen fopen, fclose, Lesen und Schreiben mit 
/*                      den Funktionen fread, fwrite, Dateiende pruefen mit
/*                      Funktion feof
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Programm verwaltet eine Artikeldatei, Variante Binaerdatei
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

typedef struct
{
    int nummer;
    char bezeichnung[16];
    float preis;
} ARTIKEL;

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

int lies_artikel(ARTIKEL *p_artikel);
void schreibe_artikel(char datei[], ARTIKEL *p_artikel);
void erstelle_artikelliste(char datei[]);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    char artikeldatei[30];
    ARTIKEL artikel;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-04, Artikeldatei verwalten II ----------\n\n");
    printf("\nDas Programm verwaltet Artikeldaten in einer Binaerdatei.\n");
    printf("\nArtikelnamen umfassen max. 15 Zeichen und duerfen keine");
    printf("\nLeerzeichen enthalten. Artikelnummern werden als int-Werte,");
    printf("\nPreise als float-Werte erwartet.\n");

    printf("\nDOS-Name der Artikeldatei: "); gets_s(artikeldatei, (int)sizeof(artikeldatei)-1);

    while (lies_artikel(&artikel) != 0)
          schreibe_artikel(artikeldatei, &artikel);

    erstelle_artikelliste(artikeldatei);
    PAUSE;
}

/* Liest Artikeldaten ein */
int lies_artikel(ARTIKEL *p_artikel)
{
    printf("\nArtikelnummer (Dateiende = 0): ");scanf_s("%d",&p_artikel->nummer);
    if (p_artikel->nummer == 0)
        return 0;
    printf("Artikelbezeichnung: ");scanf_s("%s",p_artikel->bezeichnung, (int)sizeof(p_artikel->bezeichnung)-1);
    printf("Artikelpreis: ");scanf_s("%f",&p_artikel->preis);
    return 1;
}

/* Schreibt Artikeldaten in Binaerdatei im Anfuegemodus */
void schreibe_artikel(char datei[], ARTIKEL *p_artikel)
{
    FILE *fp;

    if (fopen_s(&fp, datei,"a+b") != 0)
    {
        printf("\nDatei %s nicht zum Anhaengen zu oeffnen",datei);
        PAUSE;
        exit(1);
    }

    fwrite(p_artikel, sizeof(ARTIKEL), 1, fp);
    fclose(fp);
}

/* Erstellt Artikelliste am Bildschirm */
void erstelle_artikelliste(char datei[])
{
    FILE *fp;
    ARTIKEL artikel;
    int i = 0;

    if (fopen_s(&fp, datei,"rb") != 0)
    {
        printf("\nDatei %s nicht zum Lesen zu oeffnen",datei);
        PAUSE;
        exit(1);
    }

    printf("\n\nArtikelliste");
    printf("\nArtikelnummer  Artikelbezeichnung  Artikelpreis");

    while (1)
    {
        fread(&artikel, sizeof(ARTIKEL), 1, fp);
        if (feof(fp))
            break;
        printf("\n%-15d%-20s%.2f", artikel.nummer,
                artikel.bezeichnung,artikel.preis);
        if (++i%10==0)
           PAUSE;
    }

    fclose(fp);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Loesen Sie die analoge Aufgabe wie fuer das Beispielprogramm 11.3.
  - Experimentieren Sie mit der Funktion feof, die in der Funktion
    erstelle_artikelliste benutzt wird. Aendern Sie hierzu die
    Stellung der Abfrage feof(fp). Probieren Sie z.B. aus:
        while (!feof(fp))
        {
            fread(...);
            printf(...);
        }

    Welche Resultate ergeben sich?

******************************************************************************/
