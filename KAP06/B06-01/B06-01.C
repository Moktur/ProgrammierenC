
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-01, Klassifizierung von ASCII-Zeichen
/*
/*      Konzepte/       Verschachtelte if-else-Auswahlanweisung
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
    int   z;    /* Zeichen */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-01, Zeichenklassifizierung -------------\n\n");

    /* Eingabe Zeichen, Klassifizierung und Ausgabe */
    printf("\nDas Programm klassifiziert ASCII-Zeichen.\n");
    printf("\nBitte ein Zeichen gefolgt von Return eingeben: ");
    z = getchar();
    printf("\nEingegebenes Zeichen: %c ASCII-Nr.: %d",z,z);

    if (0 <= z && z <= 31)
        printf("\nZeichen ist ein Steuerzeichen!");
    else if (48 <= z && z <= 57)
        printf("\nZeichen ist eine Ziffer!");
    else if (65 <= z && z <= 90)
        printf("\nZeichen ist ein Grossbuchstabe!");
    else if (97 <= z && z <= 122)
        printf("\nZeichen ist ein Kleinbuchstabe!");
    else printf("\nZeichen ist ein sonstiges Zeichen!");
    printf("\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Erweitern Sie die Pruefung der eingegebenen Zeichen. Testen Sie
    zusaetzlich, ob das eingegebene Zeichen
        - ein Blank (Leerzeichen),
        - ein Komma oder
        - ein Ausrufezeichen ist.
  - Wandeln Sie einen eingegebenen Grossbuchstaben in einen Kleinbuchstaben
    um und geben Sie diesen wieder aus. Wandeln Sie analog einen eingegebenen
    Kleinbuchstaben in einen Grossbuchstaben um und geben Sie diesen an-
    schliessend aus. Benutzen Sie hierzu jeweils eine Verbundanweisung, die
    den bisher einzelnen printf-Aufruf eines if-else-Zweiges ersetzt. Zur
    Umwandlung von Kleinbuchstaben in Grossbuchstaben bzw. umgekehrt nutzen
    Sie die Struktur des ASCII-Codes aus.

******************************************************************************/

