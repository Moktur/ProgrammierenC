
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       11-05, Artikeldatei verwalten III
/*
/*      Konzepte/       Umgang mit Binaerdateien, direkter Zugriff auf
/*      Sprachelemente: Datensaetze, Positionierungsfunktionen fseek, ftell
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm verwaltet eine binaere Artikeldatei mit direktem
/*          Zugriff. Hierzu erfolgt Positionierung des Dateizeigers mittels
/*          der Funktionen fseek, ftell.
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
void artikel_zeigen(char datei[], int satznummer);
void artikel_aendern_1(char datei[], int satznummer);
void artikel_aendern_2(char datei[], int artikelnummer);

/*****************************************************************************/
/* Funktionen definieren
/****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    char artikeldatei[30];
    ARTIKEL artikel;
    int nr;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 11-05, Artikeldatei verwalten III ---------\n\n");

    printf("\nDas Programm verwaltet binaere Artikeldatei mit direktem Zugriff.\n");
    printf("\nArtikelnamen umfassen max. 15 Zeichen und duerfen keine");
    printf("\nLeerzeichen enthalten. Artikelnummern werden als int-Werte,");
    printf("\nPreise als float-Werte erwartet.\n");

    printf("\nDOS-Name der Artikeldatei: "); gets_s(artikeldatei, (int)sizeof(artikeldatei)-1);

    while (lies_artikel(&artikel) != 0)
        schreibe_artikel(artikeldatei, &artikel);

    erstelle_artikelliste(artikeldatei);
    printf("\n\nBitte Satznummer eingeben (ab 0): "); scanf_s("%d", &nr);
    artikel_zeigen(artikeldatei, nr);
    printf("\n\nBitte nochmals Satznummer eingeben: "); scanf_s("%d", &nr);
    artikel_aendern_1(artikeldatei, nr);
    printf("\n\nBitte Artikelnummer eingeben: "); scanf_s("%d", &nr);
    artikel_aendern_2(artikeldatei, nr);
    erstelle_artikelliste(artikeldatei);
    PAUSE;
}

/* liest Artikeldaten ein */
int lies_artikel(ARTIKEL *p_artikel)
{
    printf("\nArtikelnummer (Dateiende = 0): ");scanf_s("%d",&p_artikel->nummer);
    if (p_artikel->nummer == 0)
        return 0;
    printf("Artikelbezeichnung: ");scanf_s("%s",p_artikel->bezeichnung, (int)sizeof(p_artikel->bezeichnung)-1);
    printf("Artikelpreis: ");scanf_s("%f",&p_artikel->preis);
    return 1;
}

/* schreibt Artikeldaten in Binaerdatei im Anfuegemodus */
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

/* erstellt Artikelliste am Bildschirm */
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

    do
    {
        fread(&artikel, sizeof(ARTIKEL), 1, fp);
        if (feof(fp))
            break;
        printf("\n%-15d%-20s%.2f", artikel.nummer,
                artikel.bezeichnung,artikel.preis);
        if (++i%10==0)
            PAUSE;
    } while (1);

    fclose(fp);
}

/* zeigt Artikeldaten fuer gegebene Satznummer */
void artikel_zeigen(char datei[], int satznummer)
{
    FILE *fp;
    ARTIKEL artikel;
    long offset;
    int max_satz_nr;

    if (fopen_s(&fp, datei,"rb") != 0)
    {
        printf("\nDatei %s nicht zum Lesen zu oeffnen",datei);
        PAUSE;
        exit(1);
    }

    /* max. Satznummer feststellen und ggf. Fehlermeldung geben */
    fseek(fp,0L,SEEK_END);
    max_satz_nr = (int)(ftell(fp)/sizeof(ARTIKEL) - 1);

    if (satznummer < 0 || satznummer > max_satz_nr)
    {
          printf("\nSatz Nr. %d nicht vorhanden",satznummer);
          PAUSE;
    }
    else
    {
          offset = (long)(satznummer*sizeof(ARTIKEL));

          if (fseek(fp,offset,SEEK_SET) == 0)
          {
            printf("\n\nArtikelnummer  Artikelbezeichnung  Artikelpreis");
            fread(&artikel, sizeof(ARTIKEL), 1, fp);
            printf("\n%-15d%-20s%.2f", artikel.nummer,
                      artikel.bezeichnung,artikel.preis);
          }
          else
          {
            printf("\nSatz Nr. %d mit fseek nicht einstellbar",satznummer);
            PAUSE;
          }
    }
    fclose(fp);
}

/* aendert Artikeldaten (Preis) fuer gegebene Satznummer */
void artikel_aendern_1(char datei[], int satznummer)
{
    FILE *fp;
    ARTIKEL artikel;
    long offset;
    int max_satz_nr;

    if (fopen_s(&fp, datei,"r+b") != 0)
      {
          printf("\nDatei %s nicht zum Lesen und Schreiben zu oeffnen",datei);
          PAUSE;
          exit(1);
      }

    /* max. Satznummer feststellen und ggf. Fehlermeldung geben */
    fseek(fp,0L,SEEK_END);
    max_satz_nr = (int)(ftell(fp)/sizeof(ARTIKEL) - 1);

    if (satznummer < 0 || satznummer > max_satz_nr)
    {
          printf("\nSatz Nr. %d nicht vorhanden",satznummer);
          PAUSE;
    }
    else
    {
          offset = (long)(satznummer*sizeof(ARTIKEL));

          if (fseek(fp,offset,SEEK_SET) == 0)
          {
            printf("\n\nArtikelnummer  Artikelbezeichnung  Artikelpreis");
            fread(&artikel, sizeof(ARTIKEL), 1, fp);
            printf("\n%-15d%-20s%.2f", artikel.nummer,
                    artikel.bezeichnung,artikel.preis);
            printf("\nNeuer Preis: "); scanf_s("%f", &artikel.preis);
            fseek(fp,satznummer*sizeof(ARTIKEL),SEEK_SET);
            fwrite(&artikel, sizeof(ARTIKEL), 1, fp);
          }
          else
          {
            printf("\nSatz Nr. %d mit fseek nicht einstellbar",satznummer);
            PAUSE;
          }
    }
    fclose(fp);
}

/* aendert Artikeldaten (Preis) fuer gegebene Artikelnummer */
void artikel_aendern_2(char datei[], int artikelnummer)
{
    FILE *fp;
    ARTIKEL artikel;
    long pos;

    if (fopen_s(&fp, datei,"r+b") != 0)
    {
        printf("\nDatei %s nicht zum Lesen zu oeffnen",datei);
        PAUSE;
        exit(1);
    }

    do fread(&artikel, sizeof(ARTIKEL), 1, fp);
    while (feof(fp) == 0 && artikel.nummer != artikelnummer);

    if (artikel.nummer == artikelnummer)
    {
        printf("\n\nArtikelnummer  Artikelbezeichnung  Artikelpreis");
        printf("\n%-15d%-20s%.2f", artikel.nummer,
               artikel.bezeichnung,artikel.preis);
        printf("\nNeuer Preis: "); scanf_s("%f", &artikel.preis);
        pos = ftell(fp) - sizeof(ARTIKEL);
        fseek(fp,pos,SEEK_SET);
        fwrite(&artikel, sizeof(ARTIKEL), 1, fp);
    }
    else
        printf("\nSatz mit Artikelnr. %d nicht gefunden",artikelnummer);
    fclose(fp);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Verdeutlichen Sie sich die Vorgehensweise der letzten drei Funktionen,
    die einen direkten Zugriff auf einzelne Saetze der Datei realisieren.
  - Erweitern Sie die Aenderungsfunktionen um die Aenderung der
    Artikelbezeichnung.
  - Erstellen Sie eine Suchfunktion, die einen Satz mit gegebener
    Artikelbezeichnung ermittelt und anzeigt. Setzen Sie hierzu die
    Funktion strcmp aus string.h ein.

******************************************************************************/
