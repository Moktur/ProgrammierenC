
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-10, Pascalsches Dreieck
/*
/*      Konzepte/       Programm mit mehreren Funktionen, Vektoren,
/*      Sprachelemente: Rekursion
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Bei der Berechnung der Potenzen (a+b)**n nach
/*                      dem binomischen Lehrsatz treten sog. Binomial-
/*                      koeffizienten auf; ** bezeichne die Potenzierung.
/*
/*         Es gilt: (a+b)**0 =                    1
/*                  (a+b)**1 =               1*a  +  1*b
/*                  (a+b)**2 =       1*a**2  +   2*ab   +   1*b**2
/*                  (a+b)**3 = 1*a**3 +    3*a**2*b  +  3*a*b**2 +  1*b**3
/*
/*         Wie man sieht, sind die aeusseren Koeffizienten stets 1, waehrend
/*         die inneren sich als Summe darueberstehender Koeffizienten
/*         gewinnen lassen (z.B. 3 = 1 + 2); diese Gesetzmaessigkeit wird
/*         in dem nach dem franzoesischen Mathematiker Blaise Pascal benannten
/*         "Pascalschen Dreieck" dargestellt. Siehe z.B.
/*         Bronstein/Semendjajew: Taschenbuch der Mathematik, Teubner, Leipzig
/*         1979, S. 104.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>                    /* wg. exit() */
#include <conio.h>                     /* wg. getch() */

/*****************************************************************************/
/* Konstanten und Makros definieren
/*****************************************************************************/

#define  MAXZ 13             /* max. Zeilenzahl des Pascalschen Dreiecks*/
                             
#define  PAUSE {printf("\nRETURN!\n");fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void compute_pd_zeile(int i, int max);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

unsigned int pd_zeile[MAXZ+1];

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    /* lokale Variablen */
    int maxzeilen, i;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 08-10, Pascalsches Dreieck ----------------\n\n");
    printf("\n\tProgramm berechnet PASCALsches Dreieck - d.h. die "
           "\n\tBinomialkoeffizienten n ueber i := n!/((n-i)!*i!) "
           "\n\tfuer i = 0,...,n, wobei n = 0,...,maxzeilen - 1"
           "\n=======================================================================");

    /* Eingabe */
    printf("\nBitte gewuenschte Zeilenanzahl (1 <= maxzeilen <= 13) angeben: ");
    scanf_s("%d",&maxzeilen);

    if (maxzeilen < 1 || maxzeilen > MAXZ)
    {
		printf("\nUnzulaessige Zeilenzahl"); exit(1);
	}

    printf("\n--------------- Pascalsches Dreieck mit %2d Zeile(n) -------------------",
           maxzeilen);

    printf("\n     i=");
    for (i = 0; i <= maxzeilen - 1; i++)
         i == 0 ? printf("%4d",i) : printf("%5d",i);

    /* Berechnung und Ausgabe durch Aufruf rekursiver Funktion */
    compute_pd_zeile(0, maxzeilen-1);

    printf("\n-----------------------------------------------------------------------");
    PAUSE;
}

/* Funktion berechnet n-te Zeile des Pascalschen Dreiecks */
void compute_pd_zeile(int n, int max)
{
    /* lokale Variablen */
    int i, oben_links, oben_rechts;

    /* Anweisungen */
    /* neue Zeile berechnen und ausgeben */
    printf("\nn=%2d ->", n);
    oben_links = 0;                      /* Koeff. oben-links init. */
    for (i = 0; i <= n; i++)             /* fuer alle i ab 0 bis n */
    {
       if (i < n)                      /* nicht letzter Koeff. */
       {
           oben_rechts = pd_zeile[i];  /* Koeff. oben-rechts sichern */
                                       /* neuen Koeff. n ueber i ermitteln */
           pd_zeile[i] = oben_links + oben_rechts;
           oben_links = oben_rechts;   /* Koeff. oben-links aktual. */
       }
       else pd_zeile[i] = 1;           /* letzter Koeff. n ueber n = 1 */
           printf(" %3d ", pd_zeile[i]);
    }

    /* ggf. naechste Zeile berechnen */
    if (n < max)                         /* wenn noch eine Zeile zu berechnen*/
        compute_pd_zeile(n+1,max);       /* rekursiver Aufruf */
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************
   - Verbessern Sie die Ausgabe des Pascalschen Dreiecks, so dass
     dieses gleichschenklig wird.
   - Warum muss der Fall i = 0 bzw. n ueber 0 (=1) bei der Berechnung
     nicht gesondert betrachtet werden?
******************************************************************************/
