
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs
/*
/*      Beispiel:       04-05, Ausgabe mit der printf II
/*
/*      Konzepte/       Funktion printf, Formatspezifikationen
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
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
/* Konstanten definieren
/*****************************************************************************/

const double PI = 3.14159;

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int   zahl    = 12345;
    char  *zk     = "FernUni Hagen";
    char  zeichen = '*';

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 04-05, Ausgabe mit printf II --------------\n\n");

    printf("\nDas Programm demonstriert die Ausgabe mit printf.\n");
    /* Ausgabe mit bestimmter Feldbreite */
    printf("\n1. Darstellungsmoeglichkeiten von Zahlen\n");
    /* Ausgabe einer int Zahl */
    printf("\n <%d>", zahl);
    /* siebenstellige Ausgabe der Variablen zahl mit fuehrenden Nullen */
    printf("\n <%07d>", zahl);
    /* siebenstellige Ausgabe; rechtsbuendig */
    printf("\n <%7d>", zahl);
    /* siebenstellige Ausgabe; linksbuendig */
    printf("\n <%-7d>", zahl);
    /* siebenstellige Ausgabe der Zahl mit Vorzeichen auch wenn positiv */
    printf("\n <%+7d>", zahl);
    /* siebenstellige Ausgabe der Zahl mit Vorzeichen und fuehrenden Nullen */
    printf("\n <%+07d>", zahl);
    /* Ausgabe der 5-stelligen Zahl in einem mindestens drei Zeichen breitem
       Feld: Die Zahl wird komplett ausgegeben und nicht abgeschnitten */
    printf("\n <%3d>", zahl);
    /* Ausgabe mit einer Genauigkeit von drei Stellen: funktioniert nicht bei
       ganzzahligen Variablen */
    printf("\n <%.3d>", zahl);
    /* Ausgabe einer gebrochenen Zahl mit einer Genauigkeit von zwei
       Nachkommastellen */
    printf("\n <%.2f>", PI);
    /* Ausgabe mit einer Genauigkeit von zwei Nachkommastellen und einer
       Breite von mindestens sieben Stellen mit Nachkommastellen und Punkt */
    printf("\n <%7.2f>", PI);
    /* linksbuendige Ausgabe mit einer Genauigkeit von zwei Nachkommastellen
       und einer Breite von mindestens sieben Stellen */
    printf("\n <%-7.2f>", PI);
    /* Begrenzung der Genauigkeit kann Rundungsfehler bewirken! */
    printf("\n <%7.5f>", 5.9999999999);

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\n2. Darstellungsmoeglichkeiten von Zeichenketten\n");
    /* Ausgabe einer Zeichenkette */
    printf("\n <%s>", zk);
    /* Ausgabe einer Zeichenkette in einem mind. 10 Zeichen breiten Bereich:
       die Zeichenkette wird komplett ausgegeben und nicht abgeschnitten */
    printf("\n <%10s>", zk);
    /* Ausgabe in einem mindestens 20 Zeichen breiten Bereich */
    printf("\n <%20s>", zk);
    /* linksbuendige Ausgabe in einem mindestens 20 Zeichen breiten Bereich */
    printf("\n <%-20s>", zk);
    /* Ausgabe mit maximal 10 Zeichen */
    printf("\n <%.10s>", zk);
    /* Ausgabe in einem mindestens 20 Zeichen breiten Bereich mit maximal 10
       Zeichen der Zeichenkette */
    printf("\n <%20.10s>", zk);
    /* linksbuendige Ausgabe in einem mindestens 20 Zeichen breiten Bereich
       mit maximal 10 Zeichen der Zeichenkette */
    printf("\n <%-20.10s>", zk);
    /* Ausgabe eines einzelnen Zeichens */
    printf("\n <%c>", zeichen);
    /* Ausgabe eines einzelnen Zeichens im 5 Zeichen breiten Feld */
    printf("\n <%5c>", zeichen);
    /* linksbuendige Ausgabe eines einzelnen Zeichens */
    printf("\n <%-5c>", zeichen);

    /* Warte auf Tastendruck */
    PAUSE;

    /* Verschiedene Ausgaben von Zahlenwerten */
    zahl = 237;
    printf("\n\n3. Ausgabemoeglichkeiten von ganzen Zahlen\n");
    /* Ausgabe einer signed Variablen */
    printf("\n %d", zahl);
    /* ebenso */
    printf("\n %i", zahl);
    /* Ausgabe einer unsigned Variablen */
    printf("\n %u", zahl);
    /* Zahl wird  oktal dargestellt */
    printf("\n %o", zahl);
    /* hexadezimale Ausgabe mit kleinen Buchstaben */
    printf("\n %x", zahl);
    /* hexadezimal Ausgabe mit grossen Buchstaben */
    printf("\n %X", zahl);

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\n4. Ausgabemoeglichkeiten von Gleitkommazahlen\n");
    /* Ausgabe von PI als Gleitkommazahl */
    printf("\n %f", PI);
    /* Wissenschaftliche Notation mit e */
    printf("\n %e", PI);
    /* Wissenschaftliche Notation mit E */
    printf("\n %E", PI);

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\n5. Ausgabe von Konstanten\n");
    /* 123 wird dezimal ausgegeben */
    printf("\n %d", 123);
    /* ebenso */
    printf("\n %i", 123);
    /* dezimale Ausgabe von 0xa */
    printf("\n %u", 0xa);
    /* oktale Ausgabe von 0xA */
    printf("\n %o", 0xA);
    /* hexadezimale Ausgabe von 255 */
    printf("\n %x", 255);
    /* ebenso mit grossen A B C...*/
    printf("\n %X", 255);

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\n6. Steuerzeichen\n");
    /* '\t'  horizontale Tabulatoren */
    printf("\n Dies\tsind\thorizontale\tTabulatoren");
    /* '\r'  Wagenruecklauf: ueberschreibt schon geschriebenes */
    printf("\n Dies \r ist \r ein \r Wagenruecklauf \r !!!!");
    /* '\a'  Klingelzeichen */
    printf("\n Dies ist ein Klingelzeichen: \a");
    /* '\"'  doppelte Anfuehrungszeichen */
    printf("\n Dies sind \"doppelte\" Anfuehrungszeichen");
    /* '\''  einfache Anfuehrungszeichen */
    printf("\n Dies sind \'einfache\' Anfuehrungszeichen");
    /* '\\'  Gegenstrich (Backslash) */
    printf("\n Um ein \\ zu erhalten, muss in die printf-Anweisung ein \\\\");
    /* "%%"  Prozentzeichen */
    printf("\n Um ein %% zu erhalten, muss in die printf-Anweisung ein %%%%");
    /* '\n'  Zeilenvorlauf */
    printf("\n");

    /* Warte auf Tastendruck */
    PAUSE;

    printf("\n\n7. Mehrfache Ausgabe\n");
    /* Ausgabe mehrerer Variablen in einer Anweisung */
    printf("\n Dies %s die Zahl Pi%c %.4f\n\n", "ist", ':', PI);
    PAUSE;
}
