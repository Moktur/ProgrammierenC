
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-06, Abbruch der Bewertung logischer Ausdruecke
/*
/*      Konzepte/       if-Abfrage, logische Operatoren && und ||,
/*      Sprachelemente: Bewertung logischer Ausdruecke
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm zeigt, wann C die Bewertung von
/*                      Ausdruecken mit den logischen Operatoren  && und ||
/*                      abbricht. Abgebrochen wird, sobald das Ergebnis schon
/*                      feststeht.
/*                      
/*                      Das Beispiel benutzt die if-else-Anweisung und den
/*                      Kommaoperator, die in Kap 6. behandelt werden.
/*                      Der Ausdruck
/*                          (printf("1. Bedingung wird getestet"), z++, a == 3)
/*                      mit Kommaoperator "," z.B. vor dem Vergleich a == 3 wird
/*                      z. B. wie folgt bearbeitet:
/*                      - Ausgabe des Textes am Bildschirm,
/*                      - z wird inkrementiert,
/*                      - Test der Bedingung a == b,
/*                      - Ergebnis 1 (wahr), wird zurueckgeliefert, wenn
/*                        a = b ist,
/*                      - sonst wird 0 (falsch) zurueckgegeben.
/*                      Analog wird bei aehnlich gebauten Ausdruecken
/*                      mit Kommaoperator vorgegangen.
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    int a = 3;
    int b = 7;
    int c = 9;
    int z;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-06,  Abbruch logischer Ausdruecke ------\n\n");

    printf("\nDas Programm zeigt die unvollstaendige Auswertung logischer");
    printf(" Ausdruecke.");
    printf("\nGetestet wird ein Ausdruck mit drei Bedingungen.");
    printf("\nDer Abbruch bei der Bewertung wird veranschaulicht,");
    printf(" indem nur die");
    printf("\ngetesteten Bedingungen ausgegeben werden.\n");

    /* 
    Erlaeuterung: Abbruch der Ueberpruefung einer UND-Verknuepfung testen.
    
    Getestet wird, ob gilt (a==3) && (b!=7) && (c==9). Damit diese Bedingung
    wahr ist, muessen alle Teilbedingungen (a==3), (b!=7) und (c==9) wahr
    sein. Ueberprueft wird von links nach rechts. Da schon bei (b!=7)
    feststeht, dass diese Teilbedingung und somit die gesamte Bedingung nicht
    wahr ist, wird die Teilbedingung (c==9) nicht mehr getestet. Dies wird
    daran sichtbar, dass die Texte zu 2. und 3. nicht ausgegeben werden!
    */
    printf("\nlogisches UND\n");
    z = 0; /* zaehlt getestete Bedingungen */
    if (   (printf("\n1. Bedingung getestet."), z++, a == 3)
          && (printf("\n2. Bedingung getestet."), z++, b != 7)
          && (printf("\n3. Bedingung getestet."), z++, c == 9))
    {
       printf("\nUND-Verknuepfung wahr, denn alle Bedingungen erfuellt");
        printf(" sind.\n");
    }
    else
    {
       printf("\nUND-Verknuepfung falsch, denn mindestens eine Bedingung ist");
        printf(" nicht erfuellt.");
        printf("\nHier: Bereits Bedingung -%d- war NICHT erfuellt!\n",z);
    }
        
    /* 
    Erlaeuterung: Abbruch der Ueberpruefung einer ODER-Verknuepfung testen.
    
    Getestet wird, ob gilt (a!=3) || (b==7) || (c!=9). Damit diese Bedingung
    wahr ist, muss mindestens eine der Teilbedingungen (a!=3), (b==7) und
    (c!=9) wahr sein. Ueberprueft wird von links nach rechts. Da schon bei
    (b==7) schon feststeht, dass diese Teilbedingung und somit die gesamte
    Bedingung wahr ist, wird die Teilbedingung (c!=9) nicht mehr getestet.
    Dies wird daran sichtbar, dass der Text zu 3. nicht ausgegeben wird!
    */
    printf("\nlogisches ODER\n");
    z = 0; /* zaehlt wieder getestete Bedingungen */
    if (   (printf("\n1. Bedingung getestet."), z++, a != 3)
          || (printf("\n2. Bedingung getestet."), z++, b == 7)
          || (printf("\n3. Bedingung getestet."), z++, c != 9))
    {
       printf("\nODER-Verknuepfung wahr, denn mindestens eine Bedingung ist");
        printf(" erfuellt.");
        printf("\nHier: Bereits Bedingung -%d- war erfuellt!\n",z);
    }
    else
    {
       printf("\nODER-Verknuepfung falsch, denn keine Bedingung ist");
        printf(" erfuellt.\n");
    }
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

Experimentieren Sie mit den Bedingungen in den beiden if-Abfragen, um den
Abbruch der Bewertung zu testen. Verwenden Sie hierfuer geeignete Werte
der Variablen a, b und c.
Ueberpruefen Sie, wie weit und in welcher Reihenfolge eine kompliziertere
(geklammerte) Bedingung getestet wird. Eine solche kompliziertere Bedingung
koennte z.B. lauten:

   ( (a == 7) && (b != 9) ) || ( (c == 4) && (a == b) )

******************************************************************************/
