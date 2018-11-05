
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       15-04, time.h
/*
/*      Konzepte/       Standard-Bibliothek, Funktionen aus time.h
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm stellt Funktionen zur Feststellung der
/*                      Uhrzeit bzw. der verstrichenen Zeit vor.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>        /* Enthaelt Ein- und Ausgabefunktionen */
#include <time.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void delay(unsigned long sekunden);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    clock_t   rechenkernzeit;
    time_t    kalenderzeit;
    struct tm *ortszeit;

    float   sekunden;
    char    zeitstring[80];

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 15-04, time.h -----------------------------\n\n");
    printf("\nDas Programm zeigt die Anwendung von time.h-Zeitfunktionen.\n");
    printf("Es wartet zu Beginn 15 Sekunden mit der delay-Funktion, dann");
    printf("\ngibt es die aktuelle Zeit in verschiedenen Formen aus.\n");

    printf("\nEinen Augenblick bitte...\n");
    delay(15);

    /* time() liefert die aktuelle Kalenderzeit */
    time(&kalenderzeit);

    /* localtime() wandelt die Kalenderzeit in die Lokalzeit */
    ortszeit = localtime(&kalenderzeit);

    /* asctime() konstruiert ein Zeitangabe in Kurzform */
    printf("\nZeitangabe:                       %s",
            asctime(ortszeit));

    /* gmtime() wandelt die Zeit in Coordinated Universal Time (UTC) */
    printf("Coordinated Universal Time (UTC): %s",
            asctime(gmtime(&kalenderzeit)));

    /* clock() bestimmt die Rechenkernzeit seit Anfang des Programms */
    rechenkernzeit = clock();
    printf("\nDie Rechenkernzeit ist: %d", rechenkernzeit);

    /* CLOCKS_PER_SEC ist die Anzahl der Rechenkerneinheiten pro Sekunde */
    sekunden = (float) rechenkernzeit / (float) CLOCKS_PER_SEC;
    printf("\nDas Programm laeuft seit %.2f Sekunden.", sekunden);

    /* strftime() erzeugt einen String mit Zeitangaben */
    strftime(zeitstring, 80,
             "Heute ist %A, der %d.%b.%Y. Es ist der %j. Tag im Jahr.",
             ortszeit);
    printf("\n\n%s\n\n", zeitstring);
    PAUSE;
}

/* Funktion delay
   wartet mit der Fortsetzung des Programmes eine bestimmte
   Anzahl Sekunden. */
void delay(unsigned long sekunden)
{
    /* Lokale Variablen definieren */
    time_t anfang, aktuell;

    /* Anweisungen */
    /* Halte die Zeit am Anfang der Pause fest */
    time(&anfang);

    /* Warte uebergebene Anzahl von Sekunden */
    do
        time(&aktuell);
    /* difftime liefert die Sekunden zwischen aktuell und anfang) */
    while (difftime(aktuell, anfang) <= sekunden);
}
