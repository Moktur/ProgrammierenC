
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-03, Artikeldatei verwalten I
/*
/*      Konzepte/       Lesen und Schreiben mit den Funktionen fscanf, fprintf
/*      Sprachelemente: Oeffnen im Anfuegemodus
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Programm verwaltet eine Artikeldatei, Variante Textdatei
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h> /* wg. exit() */

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
    printf("----- Beispiel: 11-03, Artikeldatei verwalten I -----------\n\n");
    printf("\nDas Programm verwaltet Artikeldaten in einer Textdatei.\n");
    printf("\nArtikelnamen umfassen max. 15 Zeichen und duerfen keine");
    printf("\nLeerzeichen enthalten. Artikelnummern werden als int-Werte,");
    printf("\nPreise als float-Werte erwartet.\n");

    /* Name der Artikeldatei einlesen */
    printf("\nDOS-Name der Artikeldatei: "); gets_s(artikeldatei, (int)sizeof(artikeldatei)-1);

    /* Saetze der Artikeldatei einlesen und schreiben */
    while (lies_artikel(&artikel) != 0)
          schreibe_artikel(artikeldatei, &artikel);

    /* Artikeldatei als Liste ausgeben */
    erstelle_artikelliste(artikeldatei);
    PAUSE;
}

/* liest Artikeldaten ein */
int lies_artikel(ARTIKEL *p_artikel)
{
    printf("\nArtikelnummer (Dateiende = 0): ");scanf_s("%d",&p_artikel->nummer);
    if (p_artikel->nummer == 0)
        return 0;
    printf("Artikelbezeichnung: "); scanf_s("%s",p_artikel->bezeichnung, (int)sizeof(p_artikel->bezeichnung)-1);
    printf("Artikelpreis: "); scanf_s("%f",&p_artikel->preis);
    return 1;
}

/* schreibt Artikeldaten in Datei im Anfuegemodus */
void schreibe_artikel(char datei[], ARTIKEL *p_artikel)
{
    FILE *fp;

    if (fopen_s(&fp, datei,"a+") != 0)
    {
        printf("\nDatei %s nicht zum Anhaengen zu oeffnen",datei);
        PAUSE;
        exit(1);
    }

    fprintf(fp,"%d %s %.2f ",
            p_artikel->nummer,p_artikel->bezeichnung,p_artikel->preis);
    fclose(fp);
}

/* erstellt Artikelliste am Bildschirm */
void erstelle_artikelliste(char datei[])
{
    FILE *fp;
    ARTIKEL artikel;
    int i = 0;

    if (fopen_s(&fp, datei,"r") != 0)
    {
        printf("\nDatei %s nicht zum Lesen zu oeffnen",datei);
        PAUSE;
        exit(1);
    }

    printf("\n\nArtikelliste\nArtikelnummer  Artikelbezeichnung  Artikelpreis");

    while (fscanf_s(fp,"%d %s %f ",
            &artikel.nummer,artikel.bezeichnung, (int)sizeof(artikel.bezeichnung)-1,&artikel.preis) != EOF)
    {
           printf("\n%-15d%-20s%.2f",
                   artikel.nummer,artikel.bezeichnung,artikel.preis);
           if (++i%10==0)
               PAUSE;
    }

    fclose(fp);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Erweitern Sie den Strukturtyp fuer Artikel um zusaetzliche Komponenten und
    ergaenzen Sie die obigen Funktionen entsprechend.
  - Modifizieren Sie das Programm wie folgt:
  - Einbau einer Abfrage am Ende von main, ob die angelegte
    Artikeldatei geloescht werden soll.
  - Falls ja, wird der Funktionsaufruf
            remove(artikeldatei);
    abgesetzt.
    Die in stdio.h vereinbare Funktion
            int remove(char *filename);
    loescht eine Datei. remove gibt im Fehlerfall einen
    Wert ungleich 0 zurueck, sonst 0.
  - Die ebenfalls in stdio.h vereinbarte Funktion
            int rename(char *from_datei, char *to_datei);
    aendert den Dateinamen von from_datei in to_datei. Die Funktion
     gibt ebenfalls im Fehlerfall einen Wert ungleich 0, sonst 0 zurueck.
    Erweitern Sie das Programm um die Moeglichkeit der abschliessenden
    Umbenennung der Artikeldatei.

******************************************************************************/
