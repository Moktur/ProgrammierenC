
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-03, Sortierverfahren und Suchverfahren
/*
/*      Konzepte/       Sortieren von und Suchen in Vektoren, Funktion qsort,
/*      Sprachelemente: Funktionen fuer Erzeugung von Zufallszahlen und
/*                      Laufzeitmessung
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:
/*
/*          Das Programm behandelt das Sortieren und Suchen in einem Vektor.
/*          Sortiert wird alternativ mit:
/*              - dem einfachen Verfahren Sortieren durch Auswaehlen
/*                (Selectionsort) oder
/*              - dem qualifizierten und effizienten Verfahren Quicksort.
/*
/*          Ein Element (Wert) des sortierten Vektors wird alternativ gesucht
/*          mit:
/*              - sequentieller Suche oder
/*              - binaerer Suche.
/*
/*          Beide Suchfunktionen sind nur fuer den Fall eines sortierten
/*          Vektors geeignet. Vorgestellt werden die Bibliotheksfunktionen
/*          qsort sowie srand und rand fuer die Erzeugung von Zufalls-
/*          zahlen und die Funktionen time und difftime fuer Zeitmessungen.
/*
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>     /* fuer qsort, rand, srand */
#include <time.h>       /* fuer Zeitmessung mit time, difftime */

/*****************************************************************************/
/* Konstanten und Makros definieren
/*****************************************************************************/

#define MAXELEM 20000   /* Vektorlaenge, beachte Typen von Vektorindizes! */

#define PAUSE {printf("\nRETURN!\n");fflush(stdin);getchar();}

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

int vektor[MAXELEM+1];      /* Vektor mit int-Zahlen */
int anzelem;                /* vorgesehene Anzahl Werte */

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void vektor_fuellen(unsigned int seed);
void selectsort(void);
int  linsuche(int wert);
int  binsuche(int wert);
void vektor_ausgeben(void);
int  vergleiche_ints(const void *p_wert1, const void *p_wert2);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    unsigned int seed,            /* Wurzel Zufallszahlen */
                 sortmodus,       /* Sortierverfahren:
                                       0: Selectionsort,1: Quicksort */
                 suchmodus,       /* Suchverfahren:
                                       0: sequentiell, 1: binaer */
                 suchwert;        /* zu suchender Wert */
             int aus;             /* Schalter fuer Vektorausgabe */
             int pos;             /* Vektorindex */
             long t_anf, t_end;   /* Anfangszeit, Endzeit */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-03, Sortier- und Suchverfahren ---------\n\n");

    /* Eingabe, ggf. Abbruch mit return */
    printf("\nDas Programm sortiert und sucht Werte in einem int-Vektor.\n");
    printf("\nBitte Anzahl der Werte eingeben (<= %d): ", MAXELEM);
    scanf_s("%u",&anzelem);
    if (anzelem == 0 || anzelem > MAXELEM)
          {  printf("\nAnzahl Werte unzulaessig");
              PAUSE;
              return;
          }
  
    printf("Wurzel Zufallszahlenerzeugung (ganz, >= 0) eingeben: ");
    scanf_s("%u", &seed);
    printf("Sortierverfahren waehlen (0:Selectionsort,1:Quicksort): ");
    scanf_s("%d", &sortmodus);
    if (sortmodus != 0 && sortmodus != 1)
          {  printf("\nSortierverfahren unbekannt");
              PAUSE;
              return;
          }
    printf("Suchverfahren waehlen (0:Sequentiell,1:Binaer): ");
    scanf_s("%d",&suchmodus);
    if (suchmodus != 0 && suchmodus != 1)
          {  printf("\nSuchverfahren unbekannt");
              PAUSE;
              return;
          }

    /* Vektor mit zufaelligen ganzen Zahlen fuellen */
    printf("\nFuelle Vektor mit %d zufaelligen Werten.", anzelem);
    vektor_fuellen(seed);

    /* Vektor sortieren - Aufruf einer Sortierfunktion */
    printf("\nSortiere Vektor mit %d zufaelligen Werten...", anzelem);

    /* Startzeit messen */
    time((time_t*)&t_anf);
    if (sortmodus == 0)
        selectsort();
    else
        /* bei Quicksort-Aufruf mitgeben:
            - Name des Vektors, hier: vektor,
            - Anzahl Elemente im Vektor, hier: anzelem,
            - Groesse eines Elements in Bytes, hier: sizeof(int),
            - Name bzw. Zeiger auf eine (selbst implementierte)
            Vergleichsfunktion, hier: vergleiche_ints, s. unten
        */
        qsort((void *)vektor, (size_t)anzelem, sizeof(int), vergleiche_ints);

    /* Endezeit messen */
    time((time_t*)&t_end);
    printf("\nSortierzeit (in s) fuer %d Elemente: %lf",
        anzelem, difftime(t_end,t_anf)); /* Zeitdifferenz in s ausgeben */

    /* Suchen eines Wertes im Vektor - mit Aufruf Suchfunktion */
    printf("\nBitte ganzz. Wert fuer Suche im Intervall [0,%d] angeben: ",
              anzelem-1);
    scanf_s("%d", &suchwert);
    if (suchmodus == 0)
        pos = linsuche(suchwert);
    else
        pos = binsuche(suchwert);

    if (pos == -1)
        printf("\nGesuchter Wert %d nicht gefunden", suchwert);
    else
        printf("\nGesuchter Wert %d befindet sich an Position %d",
               suchwert,pos+1);

    /* Ausgabe des sortierten Vektors */
    printf("\nSortierten Vektor ausgeben (0:nein,sonst:ja)? ");
    scanf_s("%d",&aus);
    if (aus)
        vektor_ausgeben();
    PAUSE;
}

/* fuellt Vektor mit ganzzahligen Zufallszahlen */
void vektor_fuellen(unsigned int seed)
{
  int i;

  srand(seed);      /* Zufallszahlen initiieren */
  for (i = 0; i < anzelem; i++)
        vektor[i] = rand()%anzelem;     /* liefert naechste Zufallszahl */
                                        /* nur Werte im Bereich [0,anzelem-1]*/
}

/* sortiert Vektor nach Methode Selectionsort */
void selectsort(void)
{
    int i, j, temp, min;

    /* pro Durchlauf kleinstes Element im Indexbereich [i,anzelem-1]
       auf Platz i holen */

    for (i = 0; i < anzelem - 1; i++)
    {
        min = i;
        for (j = i+1; j < anzelem; j++)
        {
            if (vektor[j] < vektor[min])
                min = j;
        }       /* min. Element auf Platz i*/
        temp = vektor[i]; vektor[i] = vektor[min]; vektor[min] = temp;
    }
}

/* - fuehrt sequentielle Suche nach uebergebenem  Wert wert durch,
   - gibt bei Erfolg dessen (erste) Position im Vektor, sonst -1 zurueck
   - vorausgesetzt wird hier aufsteigende Sortierung des Vektors
   - angewendet wird die sog. Sentinel-Technik, bei der in ein kuenstlich
     hinzugefuegtes Vektorelement der zu suchende Wert eingetragen wird
*/
int  linsuche(int wert)
{
    int i;                              /* Laufindex */

    vektor[anzelem+1] = wert;           /* Eintrag Suchwert in Sentinel */
                                        /* am Ende des Vektors */

    for (i = 0; vektor[i] < wert; i++)  /* Suche solange */
     {  ;  }                            /* Vektorelement kleiner als Suchwert */

    /* Auswertung der Suche */
    if (i < anzelem &&                  /* Sentinel nicht erreicht und */
        vektor[i] == wert)              /* aktuelles Vektorelement enthaelt*/
       return i;                        /* Suchwert -> Suche erfolgreich */
    else    return (-1);                /* sonst: Suche nicht erfolgreich*/
}

/* - fuehrt binaere Suche nach uebergebenem  Wert wert durch,
   - gibt bei Erfolg dessen (erste) Position im Vektor, sonst -1 zurueck */
int  binsuche(int wert)
{
	 int anfang, ende, mitte;            /* Vektorindizes */

    anfang = 0;                         /* zunaechst ganzen Vektor betrachten*/
    ende = anzelem - 1;                 /* Suchbereich ist immer [anfang,ende]*/
    while (anfang <= ende)              /* solange Bereich mindestens 1 Element*/
                                        /* umfasst */
    {
        mitte = (int)(((long)anfang +   /* mittleres Element bestimmen */
	 	       (long)ende)/ 2); /* und Bereich teilen: */
        if (wert < vektor[mitte])       /* Wert liegt ggf. vor mitte */
            ende = mitte - 1;           /* -> vorn weitersuchen */
        else if (wert > vektor[mitte])  /* Wert liegt ggf. nach mitte */
            anfang = mitte + 1;         /* -> hinten weitersuchen */
        else                            /* Wert gefunden */
            return mitte;
    }
  return (-1);                          /* Wert nicht gefunden */
}

/* gibt Vektor vektor aus */
void vektor_ausgeben(void)
{
    int i;

    printf("\nVektor enthaelt:");
    for (i = 0; i < anzelem; i++)
    {
        if (i%10 == 0) printf("\n");
        printf("%6d",vektor[i]);
        if (i%100==99) PAUSE;
    }
}

/* - Hilfsfunktion fuer quicksort-Funktion,
   - vergleicht zwei (als Adressen) uebergebene int-Werte Wert1, Wert2
   - liefert zurueck:
        Wert < 0, falls Wert1 < Wert2
        Wert = 0, falls Wert1 = Wert2
        Wert > 0, falls Wert1 > Wert2
   - Bemerkung: hier angegebene Fassung der Funktion mit Parametern
     des Typs const void * ist auch fuer Compiler Borland C++ 5.0 geeignet
*/
int  vergleiche_ints(const void *p_wert1, const void *p_wert2)
{
    int w1, w2;

    w1 = *((int *)p_wert1);
    w2 = *((int *)p_wert2);
    return  (w1 - w2);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Fuehren Sie eigene Zeitmessungen fuer das Sortieren und Suchen auf
    Ihrem PC mittels der Funktionen time und difftime durch.
  - Modifizieren Sie hierzu das Programm derart, dass eine Suche
    n-mal durchgefuehrt und der Zeitverbrauch analog zum Sortieren
    bestimmt wird.
  - Modifizieren Sie die Funktion linsuche, indem Sie die Fortsetzungs-
    bedingung in der for-Schleife wie folgt ersetzen:
         for (...;vektor[i]!=wert;...)
    die Funktion ist dann fuer beliebige, auch unsortierte int-Vektoren
    geeignet. Wie stark waechst aber der Zeitverbrauch?
  - Eine binaere Suche kann auch mit der Bibliotheksfunktion
    bsearch (vereinbart in stdlib.h) durchgefuehrt werden, die einen
    aehnlichen Prototyp wie die Funktion qsort besitzt.
    Im Vergleich zu qsort gilt jedoch, dass
      - bsearch als zusaetzlichen Parameter die Adresse der Variablen
        suchwert erhaelt, die den Suchwert enthaelt,
      - bsearch die Adresse des gesuchten Elements suchwert im Vektor
        zurueckgibt, wenn suchwert gefunden wurde, sonst den Nullzeiger NULL.
    Informieren Sie sich anhand Ihres Compilerhandbuchs ueber die Funktion
    bsearch. Nutzen Sie bsearch fuer die binaere Suche anstelle der Funktion
    binsuche. Fuer bsearch kann dieselbe Vergleichsfunktion wie fuer
    qsort verwendet werden.

******************************************************************************/
