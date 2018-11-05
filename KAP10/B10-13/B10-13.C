
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       10-13, Wertetabellen fuer Polynome
/*
/*      Konzepte/       Funktionszeiger
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   
/*          Das Programm erzeugt Wertetabellen fuer drei verschiedene
/*          Polynome. Demonstriert wird die Anwendung von Funktionszeigern.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

#define PAUSE {printf("\nRETURN!\n");fflush(stdin);getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

float f1(float x);      /* 5x + 3 */
float f2(float x);      /* x**2 + 10 */
float f3(float x);      /* x**3 + 2x + 3 */
void  generiere_wertetab(char *fbez, int anz, float (* funk)(float));

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int akt_anz;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 10-13, Polynomwertetabellen ---------------\n\n");
    printf("\nDas Programm berechnet Wertetabellen dreier Polynome.\n");

    /* Eingabe */
    printf("\nBitte Argumentanzahl anz eingeben (1<=anz<=10) ");
    scanf_s("%d",&akt_anz);

    /* Verarbeitung und Ausgabe:  */
    /* Dreimaliger Aufruf der Funktion generiere_wertetab;
     als Argument wird neben Funktionsbezeichnung (Zeichenkette)
     und Werteanzahl jeweils der Funktionsname der zu berechnenden
     (math.) Funktion als aktueller Parameter uebergeben. */

    generiere_wertetab("5x+3", akt_anz, f1);
    PAUSE;
    generiere_wertetab("x**2+10", akt_anz, f2);
    PAUSE;
    generiere_wertetab("x**3+2x+3", akt_anz, f3);
    PAUSE;
}

/* Polynom 1 */
float f1(float x)
{ return 5*x + 3; }

/* Polynom 2 */
float f2(float x)
{ return x*x + 10;}

/* Polynom 3 */
float f3(float x)
{ return x*x*x + 2*x + 3;}

/* Funktion erstellt Wertetabelle fuer gewisse math. Funktion, deren
   (Programm-)Funktion im Funktionszeiger funk uebergeben wurde */
void  generiere_wertetab(char *fbez, int anz, float (* funk)(float))
{
    float untergrenze = 0.0, obergrenze = 5.0, delta;
    float akt_arg, akt_res;

    printf("\nFunktion: %s",fbez);
    delta = (obergrenze - untergrenze)/anz;
    for (akt_arg = untergrenze; akt_arg <= obergrenze; akt_arg += delta)
    {
        /* hier Aufruf der uebergebenen Funktion:
           - Zeiger wird mit Inhalt-von-Operator angesprochen
           - Argument akt_arg wird uebergeben entspechend Prototyp */

        akt_res = (* funk)(akt_arg);
        printf("\nArgument: %.2f Funktionswert: %.2f",akt_arg, akt_res);
    }

}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Kontrollieren Sie die Laenge der Wertetabelle (1<=anz<=10).
    Bisher kommt es noch zu einer Division durch 0, wenn als
    Wertanzahl 0 eingegeben wurde. Warum?
  - Gestalten Sie auch die Unter- und Obergrenze der Argumente
    der Wertetabelle variabel. Fuegen Sie weitere Aufrufe des
    Makros PAUSE ein (warten auf return), um alle Ausgaben
    lesbar zu machen (PAUSE nach n ausgegebenen Werten).
  - Schreiben Sie ein einfaches Programm mit einem Funktionszeiger
    funk, der in main wie folgt definiert ist:
                    int (* funk) (int, int);
    Dieser verweist also auf eine Funktion, die zwei int's als
    formale Parameter besitzt und einen int-Wert liefert.
  - Das Programm enthaelt neben main die zwei Funktionen:
                    int mult (int a, int b);
                    int divi (int a, int b);
    die je zwei int-Zahlen multiplizieren oder dividieren und
    das Resultat zurueckgeben.
  - In main solen beide Funktionen ueber den Funktionszeiger funk
    wie folgt aufgerufen werden:
    (1)    funk = mult;
    d.h. Zuweisung des Funktionsnamens mult (oder divi)
    an den Funktionszeiger funk, danach:
    (2)    res = (*funk) (op1,op2);
    d.h. Aufruf der Funktion mult mit Argumenten op1 und op2 und
    Rueckgabe an res; op1,op2,res sind Variablen, wobei op1 und
    op2 natuerlich vorher mit Werten versorgt werden muessen.

******************************************************************************/
