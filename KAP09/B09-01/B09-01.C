
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       09-01, Personendaten und Altersbestimmung
/*
/*      Konzepte/       Strukturen, Typvereinbarung, Zugriff
/*      Sprachelemente: auf Strukturen und deren Komponenten
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <time.h>			/* fuer Datumsabfrage */

/*****************************************************************************/
/* Konstanten und Makros definieren
/*****************************************************************************/

#define MAXPERSONEN 10      /* Laenge Strukturfeld */

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

/* Definition der Strukturtypen DATUM und PERSON */
typedef struct
{
    int tag;
    int monat;				/* hier numerisch */
    int jahr;
} DATUM_N;

typedef struct
{
    char    name[16];
    DATUM_N geburtsdatum;
    int     alter;
    char    geschlecht;     /* 'm' = maennlich, 'w' = weiblich */
} PERSON;

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

/* globales Strukturfeld vom Typ PERSON */
PERSON personen[MAXPERSONEN];

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

PERSON einlesen_person(void);
void ausgeben_person(PERSON person);
void ermittle_alter(int i);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    unsigned int i;
    PERSON       aktuelle_person; 
    unsigned int anz_personen;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 09-01, Personendaten und Alter ------------\n\n");
    printf("\nDas Programm liest und zeigt Personendaten und bestimmt");
    printf("\ndas Alter von Personen.");

    /* Eingabe */
    printf("\nBitte Personenzahl eingeben (<= %d): ", MAXPERSONEN);
    scanf_s("%u", &anz_personen);
    if (anz_personen < 1 || anz_personen > MAXPERSONEN)
    {
          printf("\nUnzulaessige Anzahl!");
        PAUSE;
        return;
    }

    /* Verarbeitung, Altersbestimmung */
    for (i = 0; i < anz_personen; i++)
    {
        personen[i] = einlesen_person();
        ermittle_alter(i);
    }

    /* Ausgabe */
    for (i = 0; i < anz_personen; i++)
    {
        /* Zuweisung einer kompletten Struktur */
        aktuelle_person = personen[i];
        /* aktueller Parameter ist komplette Struktur */
        ausgeben_person(aktuelle_person);
    }
    PAUSE;
}

/* liest Personendaten ein, beachte: Rueckgabewert vom Strukturtyp PERSON */
PERSON einlesen_person(void)
{
  PERSON person_ein;

  printf("\nName (max. 15 Zeichen): ");
  scanf_s("%s", person_ein.name, (int)sizeof(person_ein.name)-1);
  printf("Geschlecht (m/w): ");
  scanf_s("%1s", &person_ein.geschlecht, (int)sizeof(person_ein.geschlecht));
  printf("Tag der Geburt (tt): ");
  scanf_s("%d", &person_ein.geburtsdatum.tag);
  printf("Monat der Geburt (mm): ");
  scanf_s("%d", &person_ein.geburtsdatum.monat);
  printf("Jahr der Geburt (jj): ");
  scanf_s("%d", &person_ein.geburtsdatum.jahr);
  return person_ein;
}

/* gibt Personendaten aus, beachte: formaler Parameter vom Typ PERSON */
void ausgeben_person(PERSON person_aus)
{
    printf("\nName: %-15s", person_aus.name);
    printf("  Geschlecht: %1c", person_aus.geschlecht);
    printf("  Geburtstag: %2d.%02d.%2d", person_aus.geburtsdatum.tag,
                person_aus.geburtsdatum.monat, person_aus.geburtsdatum.jahr);
    printf("  Alter: %3d", person_aus.alter);
}

/* ermittelt Alter aus Geburtsdatum und aktuellem (Maschinen-)Datum */
void ermittle_alter(int i)
{
    int tag_akt, monat_akt, jahr_akt;   /* aktuelles Datum */
	struct tm init_akt_datum;			/* Strukturtyp aus time.h */
    struct tm *p_akt_datum;             /* Strukturtyp aus time.h */
    time_t akt_zeit;					/* aktuelle Kalenderzeit */

	p_akt_datum = &init_akt_datum;		/* Zeiger initialisierung */

    /* aktuelles (Maschinen-)Datum abfragen mit 2 Bibliotheksfunktionen:
       - time liefert Anzahl Sekunden seit gewissem Stichtag (Kalenderzeit)
       - localtime wandelt Kalenderzeit um; dabei wird eine in time.h
         definierte Struktur (tm) gefuellt u. a. mit Tag, Monat, Jahr
         wie unten angegeben
       - Zeigerzugriffe werden spaeter erlaeutert, siehe Kap. 10
    */

    time(&akt_zeit);						/* erst Kalenderzeit bestimmen */
    localtime_s(p_akt_datum, &akt_zeit);	/* dann Datumsangaben erzeugen */

    jahr_akt = p_akt_datum->tm_year;     /* Jahre seit 1900 */
    monat_akt = p_akt_datum->tm_mon + 1; /* Monate seit Januar,
                                            0 bis 11, daher +1*/
    tag_akt = p_akt_datum->tm_mday;      /* Tag im Monat, 1 bis 31 */

    /* Alter bestimmen und eintragen */

    /* soviele Jahre jedenfalls alt */
    personen[i].alter = jahr_akt - personen[i].geburtsdatum.jahr - 1;
    if (monat_akt >  personen[i].geburtsdatum.monat ||
        monat_akt == personen[i].geburtsdatum.monat &&
        tag_akt >= personen[i].geburtsdatum.tag)
        personen[i].alter++;             /* noch ein Jaehrchen dazu...*/
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Gestalten Sie die Ausgabe als Tabelle mit einer Kopfzeile.
  - Ergaenzen Sie den Strukturtyp PERSON um weitere Daten wie z.B.
    Adresse und Telefonnummer; die Adresse sollte wieder ein Strukturtyp
    sein. Die Funktionen zur Ein- und Ausgabe sind entsprechend zu ergaenzen.
  - Die Funktion ermittle_alter arbeitet mit Zeigern; kehren Sie
    nach dem Durcharbeiten des Kapitels 10 nochmals hierher zurueck
    und bearbeiten Sie folgendes Problem.
    Die Bestimmung des (Maschinen-)Datums erscheint umstaendlich.
    Tatsaechlich bieten Compiler auch andere Varianten des Zugriffs.
    Diese sind jedoch nicht einheitlich, waehrend die gezeigte Form
    dem ANSI-Standard entspricht und stets moeglich sein sollte.
    Machen Sie weitere Zugriffsvarianten auf das Maschinendatum bei
    Ihrem Compiler ausfindig und implementieren Sie diese in der
    Routine fuer die Altersbestimmung. Hinweis: Definitionsdatei
    dos.h der Standardbibliothek.

******************************************************************************/
