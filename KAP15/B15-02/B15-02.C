
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       15-02, ctype.h
/*
/*      Konzepte/       Standard-Bibliothek, Zeichenfunktionen aus ctype.h
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Das Programm zeigt den Umgang mit Funktionen aus der
/*                      Bibliothek ctype.h
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>        /* Enthaelt Ein- und Ausgabefunktionen */
#include <string.h>
#include <ctype.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* Lokale Variablen definieren */
    char text_mixed[80] = "";
    char text_upper[80] = "";
    char text_lower[80] = "";
    char *buchstabe;
    char kleinbuchstabe[2] = {'\0', '\0'};
    char grossbuchstabe[2] = {'\0', '\0'};
    unsigned int alnum  = 0;
    unsigned int alpha  = 0;
    unsigned int cntrl  = 0;
    unsigned int digit  = 0;
    unsigned int graph  = 0;
    unsigned int lower  = 0;
    unsigned int upper  = 0;
    unsigned int print  = 0;
    unsigned int punct  = 0;
    unsigned int space  = 0;
    unsigned int xdigit = 0;

    /* Anweisungen */
    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 15-02, ctype.h ----------------------------\n\n");
    printf("\nDas Programm zeigt den Umgang mit ctype.h-Zeichenfunktionen.\n");
    printf("Es analysiert den von Ihnen eingegebenen Text, zaehlt die\n");
    printf("Zeichen, trennt sie nach Zeichengruppen und wandelt sie wenn\n");
    printf("moeglich in Gross- bzw. Kleinbuchstaben um.\n\n");

    /* Eingabe */
    printf("\nBitte geben Sie einen beliebigen Text ein und schliessen\n");
    printf("Sie ihn mit Return ab:\n\n");
    gets_s(text_mixed, 79);

    /* Untersuchen des Textes */
    buchstabe = text_mixed;
    while (*buchstabe != '\0')
    {
        /* isalnum() prueft, ob das uebergebene Zeichen alphanummerisch ist */
        if (isalnum(*buchstabe)) alnum++;
        /* isalpha() prueft, ob das Zeichen aphabetisch ist */
        if (isalpha(*buchstabe)) alpha++;
        /* iscntl() prueft, ob das Zeichen ein Steuerzeichen ist */
        if (iscntrl(*buchstabe)) cntrl++;
        /* isdigit() prueft, ob das Zeichen eine dezimale Ziffer ist */
        if (isdigit(*buchstabe)) digit++;
        /* isgraph() prueft, ob das Zeichen ein sichtbares Zeichen ist, 
           ohne Leerzeichen */
        if (isgraph(*buchstabe)) graph++;
        /* islower() prueft, ob das Zeichen ein Kleinbuchstabe ist */
        if (islower(*buchstabe)) lower++;
        /* isupper() prueft, ob das Zeichen ein Grossbuchstabe ist */
        if (isupper(*buchstabe)) upper++;
        /* isprint() prueft, ob das Zeichen sichtbar ist (auch Leerzeichen) */
        if (isprint(*buchstabe)) print++;
        /* ispunct() prueft, ob das Zeichen sichtbar ist, mit Aussnahme von
           Leerzeichen, Buchstaben und Ziffern */
        if (ispunct(*buchstabe)) punct++;
        /* isspace() prueft, ob das Zeichen ein 'Whitespace' ist. Ein
           Whitescape ist ein nicht darstellbares Zeichen, wie ein Leerzeichen
           oder ein Tabulator */
        if (isspace(*buchstabe)) space++;
        /* isxdigit() prueft, ob das Zeichen eine hexadezimale Ziffer ist */
        if (isxdigit(*buchstabe)) xdigit++;

        /* tolower() wandelt Grossbuchstaben in Kleinbuchstaben */
          *kleinbuchstabe = (char) tolower(*buchstabe);
        strcat_s(text_lower, 79, kleinbuchstabe);
        /* tolower() wandelt Kleinbuchstaben in Grossbuchstaben */
          *grossbuchstabe = (char) toupper(*buchstabe);
        strcat_s(text_upper, 79, grossbuchstabe);

        /* Ueberpruefe den naechsten Buchstaben */
        buchstabe++;
    }

    /* Ergebnis ausgeben */
    printf("\nalphanummerische Zeichen: %d", alnum);
    printf("\nalphabetische Zeichen:    %d", alpha);
    printf("\nSteuerzeichen:            %d", cntrl);
    printf("\ndezimale Ziffer:          %d", digit);

    printf("\ngraphische Zeichen:       %d", graph);
    printf("\nKleinbuchstaben:          %d", lower);
    printf("\nGrossbuchstaben:          %d", upper);
    printf("\nsichtbare Zeichen:        %d", print);
    printf("\nSonderzeichen:            %d", punct);
    printf("\nWhitespaces:              %d", space);
    printf("\nhexadezimale Ziffern:     %d", xdigit);
    printf("\n\nText in Kleinbuchstaben:\n%s", text_lower);
    printf("\n\nText in Grossbuchstaben:\n%s\n\n", text_upper);
    PAUSE;
}
