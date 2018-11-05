
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-11, Telefonbuch III
/*
/*      Konzepte/       binaerer Suchbaum, Modularisierung, ADT
/*      Sprachelemente:
/*
/*      Beschreibung:   Funktionsdatei fuer den ADT Telefonbuch III.
/*****************************************************************************/

/*****************************************************************************/
/* Header-Dateien einfuegen
/*****************************************************************************/

/* Standardbibliotheken einbinden */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Definitionsdatei fuer den ADT Telefonbuch III einbinden */
#include "B14-11-2.h"

/*****************************************************************************/
/* Statische Variable definieren
/*****************************************************************************/

/* Zeiger auf die Wurzel des Baums */
static pKNOTEN BaumWurzel = NULL;

/*****************************************************************************/
/* statische Funktionen deklarieren
/*****************************************************************************/

static pKNOTEN ErzeugeNeuenKnoten(char *name, char *telefon);
static pKNOTEN FuegeEin(pKNOTEN wurzel, char *name, char *telefon);
static void Praeorder(pKNOTEN wurzel);
static void Inorder(pKNOTEN wurzel);
static void Postorder(pKNOTEN wurzel);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   FuegeKnotenEin
/* Aufgabe:
/*   Fuegt einen Knoten mit den uebergebenen Daten in den Baum ein
/* Parameter:
/*   name:    Der zu speichernde Name
/*   telefon: Die zu speichernde Telefonnummer
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void FuegeKnotenEin(char *name, char *telefon)
{
    /* Rufe die statische rekursive Funktion auf */
    BaumWurzel = FuegeEin(BaumWurzel, name, telefon);
}

/*****************************************************************************/
/* Funktion:
/*   AusgabePraeorder
/* Aufgabe:
/*   Ruft die rekursive Funktion Praeorder auf.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void AusgabePraeorder(void)
{
    Praeorder(BaumWurzel);
}

/*****************************************************************************/
/* Funktion:
/*   AusgabeInorder
/* Aufgabe:
/*   Ruft die rekursive Funktion Inorder auf.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void AusgabeInorder(void)
{
    Inorder(BaumWurzel);
}

/*****************************************************************************/
/* Funktion:
/*   AusgabePostorder
/* Aufgabe:
/*   Ruft die rekursive Funktion Postorder auf.
/* Parameter:
/*   keine
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

void AusgabePostorder(void)
{
    Postorder(BaumWurzel);
}

/*****************************************************************************/
/* Statische Funktionen definieren
/*****************************************************************************/

/*****************************************************************************/
/* Funktion:
/*   ErzeugeNeuenKnoten
/* Aufgabe:
/*   Erzeugt einen neuen Knoten und initialisiert die Daten.
/* Parameter:
/*   name:    Der zu speichernde Name
/*   telefon: Die zu speichernde Telefonnummer
/* Rueckgabewert:
/*   Ein Zeiger auf den neuen Knoten
/*****************************************************************************/

static pKNOTEN ErzeugeNeuenKnoten(char *name, char *telefon)
{
    /* Lokale Variablen */
    pKNOTEN NeuerKnoten;

    /* Fordere Speicherplatz fuer den neuen Knoten an */
    NeuerKnoten = malloc(sizeof(KNOTEN));

    /* Schreibe die uebergebenen Daten in den Knoten */
    strncpy_s(NeuerKnoten->name, 29, name, 29);
    NeuerKnoten->name[29] = '\0'; /* Zeichenkette muss spaetestens an der 30.
                                     Stelle terminiert werden */
    strncpy_s(NeuerKnoten->telefon, 29, telefon, 29);
    NeuerKnoten->telefon[29] = '\0'; /* Zeichenkette muss spaetestens an der
                                        30. Stelle terminiert werden */

    /* Initialisiere die Zeiger auf den linken und rechten Unterbaum */
    NeuerKnoten->links = NULL;
    NeuerKnoten->rechts = NULL;

    /* Rueckgabewert liefern */
    return (NeuerKnoten);
}

/*****************************************************************************/
/* Funktion:
/*   FuegeEin()
/* Aufgabe:
/*   Eine rekursive Funktion, die den Knoten an der richtigen Stelle in den
/*   Baum einfuegt.
/* Parameter:
/*   wurzel:  Die Wurzel des Baums, in den der Knoten eingefuegt werden soll
/*   name:    Der zu speichernde Name
/*   telefon: Die zu speichernde Telefonnummer
/* Rueckgabewert:
/*   Liefert die Wurzel den neuen (Unter)Baums
/*****************************************************************************/

static pKNOTEN FuegeEin(pKNOTEN wurzel, char *name, char *telefon)
{
    /* Lokale Variablen definieren */
    pKNOTEN NeuerKnoten;

    /* Wenn die Wurzel auf NULL zeigt, ist dies der erste Knoten im
       Unterbaum */
    if (wurzel == NULL)
    {
        NeuerKnoten = ErzeugeNeuenKnoten(name, telefon);
        wurzel = NeuerKnoten;
    }
    /* Wenn der neue Knoten in den linken Unterbaum gehoert */
    else if (strcmp(name, wurzel->name) < 0)
        wurzel->links = FuegeEin(wurzel->links, name, telefon);
    /* Wenn der neue Knoten in den rechten Unterbaum gehoert */
    else if (strcmp(name, wurzel->name) > 0)
        wurzel->rechts = FuegeEin(wurzel->rechts, name, telefon);
    /* Ansonsten ist der Knoten schon im Baum vorhanden */
    return wurzel;
}

/*****************************************************************************/
/* Funktion:
/*   Praeorder()
/* Aufgabe:
/*   Gibt den Baum in Praeorder-Reihenfolge aus. Das heisst, dass erst der
/*   Knoten selbst, dann der linke und zuletzt der rechte Untebaum ausgegeben
/*   wird.
/* Parameter:
/*   wurzel: Die Wurzel des auszugebenden (Unter)Baums
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

static void Praeorder(pKNOTEN wurzel)
{
    /* Wenn der Baum nicht leer ist gib seinen Inhalt aus */
    if (wurzel != NULL)
    {
        printf("Name: %-25s    ", wurzel->name);
        printf("Telefonnummer: %-25s\n", wurzel->telefon);
        Praeorder(wurzel->links);
        Praeorder(wurzel->rechts);
    }
}

/*****************************************************************************/
/* Funktion:
/*   Inorder()
/* Aufgabe:
/*   Gibt den Baum in Inorder-Reihenfolge aus. Das heisst, dass erst der
/*   linke Unterbaum, dann der Knoten selbst und zuletzt der rechte Untebaum
/*   ausgegeben wird. Diese Version der Ausgabe liefert alle Elemente im Baum
/*   in sortierter Reihenfolge.
/* Parameter:
/*   wurzel: Die Wurzel des auszugebenden (Unter)Baums
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

static void Inorder(pKNOTEN wurzel)
{
    /* Wenn der Baum nicht leer ist gib seinen Inhalt aus */
    if (wurzel != NULL)
    {
        Inorder(wurzel->links);
        printf("Name: %-25s    ", wurzel->name);
        printf("Telefonnummer: %-25s\n", wurzel->telefon);
        Inorder(wurzel->rechts);
    }
}

/*****************************************************************************/
/* Funktion:
/*   Postorder()
/* Aufgabe:
/*   Gibt den Baum in Postorder-Reihenfolge aus. Das heisst, dass erst der
/*   linke, dann der rechte Untebaum und zuletzt der Knoten selbst ausgegeben
/*   wird.
/* Parameter:
/*   wurzel: Die Wurzel des auszugebenden (Unter)Baums
/* Rueckgabewert:
/*   keiner
/*****************************************************************************/

static void Postorder(pKNOTEN wurzel)
{
    /* Wenn der Baum nicht leer ist gib seinen Inhalt aus */
    if (wurzel != NULL)
    {
        Postorder(wurzel->links);
        Postorder(wurzel->rechts);
        printf("Name: %-25s    ", wurzel->name);
        printf("Telefonnummer: %-25s\n", wurzel->telefon);
    }
}
