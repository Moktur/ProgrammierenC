
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       12-03, Praeprozessoranweisungen
/*
/*      Konzepte/       Konstanten, Makros, bedingte Uebersetzung
/*      Sprachelemente: und weitere Praeprozessoranweisungen
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt Beispiele fuer Makros und
/*                      fuer eine bedingte Uebersetzung
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>        /* Enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Konstanten / Typen / Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/* Der Name DEBUG_PHASE wird definiert. Es handelt sich hier nicht um eine
   Variable oder Konstante, da dieser Name keinen Wert repraesentiert */
#define DEBUG_PHASE

/* Hier wird die Konstante TEXT definiert, die den Wert "Alpha" besitzt */
#define TEXT "Alpha"

/* Makro MIN ermittelt das kleinere Argument */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
/* Makro MAX ermittelt das groessere Argument */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
/* Ein langes Makro, das in mehrere Zeilen geschrieben wird */

#define IST_NULL(a) if ((a) == 0)                                     \
                      printf("\n\nDer Parameter ist gleich Null.");   \
                    else                                              \
                      printf("\n\nDer Parameter ist ungleich Null."); \

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int a = 6, b = 2, c;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("-----Beispiel: 12-03, Praeprozessoranweisungen ------------\n\n");
    printf("\nDas Programm zeigt Beispiele fuer Makros und");
    printf(" bedingte Uebersetzung.\n");

    /**********/
    /* Makros */
    /**********/
    printf("\nIch berechne nun das Minimum von a und b");
    /* Berechne das Minimum mit dem Makro MIN */
    c = MIN(a, b);
    printf("\na: %d, b: %d, Minimum: %d", a, b, c);
    
    printf("\n\nIch berechne nun das Maximum von a und b, nachdem ich a um ");
    printf("eins erhoeht habe.");
    ++a;
    /* Berechne das Maximum mit dem Makro MAX */
    c = MAX(a, b);
    printf("\na: %d, b: %d, Maximum: %d", a, b, c);

    /* Ueberpruefe, ob b gleich Null ist, und gib entsprechende Meldung
       aus */
    IST_NULL(b);

    /***************************************/
    /* Loeschen und umdefinieren von Namen */
    /***************************************/

    printf("\n\nDer Text lautet: %s", TEXT);
    /* Loesche den Namen TEXT */
    #undef TEXT
    /* Definiere den Namen TEXT */
    #define TEXT "Beta"
    printf("\nDer Text lautet: %s", TEXT);
    
    /*************************/
    /* Bedingte Uebersetzung */
    /*************************/
    printf("\n\nIch berechne nun a + b");
    c = a + b;
    /* Ausgabe der Werte von a und b nur, wenn in der Debug-Phase,
       ansonsten nur das Ergebnis ausgeben */
    #ifdef DEBUG_PHASE  /* Prueft, ob angegebener Name definiert ist, und
                           fuehrt die Anweisungen gegebenenfalls aus */
        printf("\na: %d,\tb: %d,\tc=a+b: %d", a, b, c);
    #else               /* Alternativzweig: diese Anweisungen werden ausge-
                           fuehrt, wenn der Name nicht definiert war */
        printf("\nErgebnis: %d", c);
    #endif

    printf("\n\nIch berechne nun a * b");
    c = a * b;
    /* Entsprechend kann auch geprueft werden, ob ein Name nicht definiert
       ist */
    #ifndef DEBUG_PHASE
        printf("\nErgebnis: %d", c);
    #else
        printf("\na: %d,\tb: %d,\tc=a*b: %d", a, b, c);
    #endif
    printf("\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgaben:
/******************************************************************************

  1) Abschnitt Makros: Erhoehen Sie a INNERHALB des Makros MAX mit dem
     Inkrementoperator. Wie aendert sich das Ergebnis und warum?
  2) Abschnitt Loeschen von Namen: Loeschen sie die define-Anweisung, die nach
     dem Loschen des Namens TEXT diesen gleich wieder definiert. Was passiert
     bei der Uebersetzung des Programms?
  3) Abschnitt Bedingte Uebersetzung: Loeschen Sie die Definition des Namens
     DEBUG_PHASE und uebersetzen Sie das Programm neu. Was aendert sich?

******************************************************************************/
