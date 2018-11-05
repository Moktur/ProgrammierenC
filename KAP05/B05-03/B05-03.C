
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       05-03, Bitoperatoren
/*
/*      Konzepte/       Bitoperatoren <<, >>, &, |, ^
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Bemerkung:      ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
/*						Es werden die sicheren Funktionen z.B. scanf_s(...)
/*                      anstatt scanf(...) genutzt. Die _s Versionen der bekannten
/*						Funktionen bieten �mehr Sicherheit� als ihre Vorg�nger.
/*
/*						Warnings wie:
/*						"<<: Umschaltanzahl ist negativ oder zu gro�, Verhalten undefiniert"
/*						sind Ziel dieses Beispiels. Erklaerung aus Kontext.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */
#include <stdlib.h>     /* Definition der Funktion _ultoa */

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktion deklarieren
/*****************************************************************************/

void bin_outp(int wert);    /* wird benoetigt fuer Aufruf, vgl. Kap. 7 */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main (void)
{
    /* lokale Variablen */
    int a, b;

    /* Anweisungen */
    /* Bem.: main ruft wiederholt die Funktion bin_outp, um
       binaere Darstellungen von ermitelten Zahlen auszugeben */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 05-03, Bitoperatoren ----------------------\n\n");

    printf("\nDas Programm zeigt den Einsatz von Bitoperatoren.\n");

    /*  
    bitweiser Linksshift << n, entspricht Multiplikation mit 2 ** n
        0 Bit, z.B. zahl << 0  -=>  Multiplikation mit 2 hoch 0 = 1
        1 Bit, z.B. zahl << 1  -=>  Multiplikation mit 2 hoch 1 = 2
        2 Bit, z.B. zahl << 2  -=>  Multiplikation mit 2 hoch 2 = 4
    */
    printf("\nLinksshift, bitte int-Wert eingeben: ");
    scanf_s("%d", &a);
    printf("%d <<  0 = %10d\t", a, a<<0); bin_outp(a<<0);
    printf("%d <<  1 = %10d\t", a, a<<1); bin_outp(a<<1);
    printf("%d <<  2 = %10d\t", a, a<<2); bin_outp(a<<2);
    printf("%d <<  3 = %10d\t", a, a<<3); bin_outp(a<<3);
    printf("%d <<  4 = %10d\t", a, a<<4); bin_outp(a<<4);
    printf("%d <<  5 = %10d\t", a, a<<5); bin_outp(a<<5);
    /* sinnlos! n > 0 waehlen */
    printf("%d << -0 = %10d\t", a, a<<-0); bin_outp(a<<-0);
    printf("%d << -1 = %10d\t", a, a<<-1); bin_outp(a<<-1);
    printf("%d << -2 = %10d\t", a, a<<-2); bin_outp(a<<-2);

    /*
    bitweiser Rechtsshift >> n, entspricht Division durch 2 ** n
        0 Bit, z.B. zahl >> 0  -=>  Division durch 2 hoch 0 = 1
        1 Bit, z.B. zahl >> 1  -=>  Division durch 2 hoch 1 = 2
        2 Bit, z.B. zahl >> 2  -=>  Division durch 2 hoch 2 = 4
    
    Ob ein Nullbit oder das Vorzeichenbit nachgeschoben wird,
    ist maschinenabhaengig.
    */
    printf("\nRechtsshift, bitte int-Wert eingeben: ");
    scanf_s("%d", &a);
    printf("%d >>  0 = %10d\t", a, a>>0); bin_outp(a>>0);
    printf("%d >>  1 = %10d\t", a, a>>1); bin_outp(a>>1);
    printf("%d >>  2 = %10d\t", a, a>>2); bin_outp(a>>2);
    printf("%d >>  3 = %10d\t", a, a>>3); bin_outp(a>>3);
    printf("%d >>  4 = %10d\t", a, a>>4); bin_outp(a>>4);
    printf("%d >>  5 = %10d\t", a, a>>5); bin_outp(a>>5);
    /* sinnlos! n > 0 waehlen */
    printf("%d >> -0 = %10d\t", a, a>>-0); bin_outp(a>>-0);
    printf("%d >> -1 = %10d\t", a, a>>-1); bin_outp(a>>-1);
    printf("%d >> -2 = %10d\t", a, a>>-2); bin_outp(a>>-2);

    /* Bit-Operatoren*/
    printf("\n\nBinaere Bitoperatoren, bitte zwei int-Werte eingeben.");
    printf("\nErster int-Wert:  ");
    scanf_s("%d",&a);
    printf("Zweiter int-Wert: ");
    scanf_s("%d",&b);

    /*
    bitweises logisches UND, d. h. bitweise wird durchgefuehrt:
       1&1 = 1, 1&0 = 0, 0&1 = 0, 0&0 = 0
    */
    printf("\n\nbitweises logisches UND:\n");
    printf("a     = %10d\t", a); bin_outp(a);
    printf("b     = %10d\t", b); bin_outp(b);
    printf("a & b = %10d\t", a&b); bin_outp(a & b);

    /* 
    bitweises logisches ODER, d. h. bitweise wird durchgefuehrt:
        1|1 = 1, 1|0 = 1, 0|1 = 1, 0|0 = 0
    */
    printf("\n\nbitweises logisches ODER:\n");
    printf("a     = %10d\t", a); bin_outp(a);
    printf("b     = %10d\t", b); bin_outp(b);
    printf("a | b = %10d\t", a|b); bin_outp(a | b);

    /*
    bitweises logisches exklusiv-ODER (XOR), d. h. bitweise wird
    durchgefuehrt:
        1^1 = 0, 1^0 = 1, 0^1 = 1, 0^0 = 0
    */
    printf("\n\nbitweises logisches exlusiv-ODER:\n");
    printf("a     = %10d\t", a); bin_outp(a);
    printf("b     = %10d\t", b); bin_outp(b);
    printf("a ^ b = %10d\t", a^b); bin_outp(a ^ b);

    /*
    Bit-Komplement, d. h. bitweise wird durchgefuehrt:
        ~1 = 0, ~0 = 1
    */
    printf("\n\nBit-Komplement:\n");
    printf("a     = %10d\t", a); bin_outp(a);
    printf("~a    = %10d\t", ~a); bin_outp(~a);
    
    PAUSE;
}

/* Funktion bin_outp
   gibt die binaere Darstellung einer Zahl am Bildschirm aus. */
void bin_outp(int wert)
{
    /* lokale Variablen */
    char string[20], bitstring[40];
    
    /* Anweisungen */
    /* wg. sprintf vgl. Standardbibliothek stdio.h */
    sprintf_s(string, 20, "%%0%us\n", sizeof (int) * 8);
	// ! Aenderungen/Anmerkungen fuer MS Visual Studio 2008 !
	// Die _s Version von sprintf kann waerend der Comilierung nicht wissen wie viel
	// Speicher sie f�r "string" reservieren soll da wir waerend der Laufzeit
	// die Groesse des Arrays bestimmen. Daher m�ssen wir explizit die Groesse mit angeben.
	_itoa_s(wert, bitstring, 39, 2);
    printf(string, bitstring);
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  Geben Sie auch negative Zahlen ein, um deren Binaerformat kennenzulernen.
  Beim Rechts-Shift-Operator haengt das Resultat bei negativen Zahlen vom
  benutzten Computer ab.

******************************************************************************/
