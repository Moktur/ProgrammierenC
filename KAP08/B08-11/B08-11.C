
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       08-11, Magisches Quadrat
/*
/*      Konzepte/       Programm mit mehreren Funktionen,
/*      Sprachelemente: 2D-Felder
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Test ob in einer quadratischen nxn-Matrix
/*                      - alle Zahlen von 1 bis n*n genau einmal vorkommen und
/*                      - alle Zeilensummen,
/*                      - alle Spaltensummen und
/*                      - die Summen der beiden Diagonalen (aus n Elementen)
/*                      denselben Wert besitzen
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

#define  MAXZS 7                       /* max. Reihenzahl der quadrat. Matrix*/

/* warten auf return */
#define  PAUSE {printf("\nRETURN!\n");fflush(stdin); getchar();}

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void input_quadrat(int maxreihen);
int  pruefe_zahlen(int maxreihen);
int compute_summe(int modus, int i, int maxreihen);
void output_quadrat(int maxreihen);

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

unsigned int quadrat[MAXZS][MAXZS];    /* qudratische Matrix, max. 7x7 */

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
/* lokale Variablen */
int maxreihen, anz, i, modus,
	 resultat;  /* 1: ja, magisches Quadrat, 0: nein, kein mag. Quadrat */
int mag_summe, wert;

/* Anweisungen */

/* Information */
printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
printf("----- Beispiel: 08-11, Magisches Quadrat ------------------\n\n");
printf("\nDas Programm testet ob eine quadratische Matrix ein");
printf(" magisches Quadrat ist.\n");

/* Eingabe */
printf("\nBitte gewuenschte Reihenzahl (2 <= maxreihen <= 7) angeben: ");
scanf_s("%d",&maxreihen);

if (maxreihen < 2 || maxreihen > MAXZS)
  {  printf("\nUnzulaessige Reihenzahl"); exit(1); }

/* Eingabe der Matrix */
input_quadrat(maxreihen);

/* Verarbeitung: Test auf magisches Quadrat */

/* Pruefung, ob alle Zahlen von 1 bis maxreihen^2 genau einmal vorkommen */
resultat = pruefe_zahlen(maxreihen);

if (resultat)
{
 /* modus: 0 = Zeilen, 1 = Spalten, 2 = Diagonalen */
 for (modus = 0; modus <= 2; modus++)
 {
     anz = (modus < 2 ? maxreihen : 2); /* nur 2 Diagonalen! */
     for (i = 0; i < anz; i++)
     {
         wert = compute_summe(modus,i, maxreihen);
         if (modus == 0 && i == 0)       /* erste Summation liefert */
           mag_summe = wert;           /* ggf. gemeinsame Summe */
         else if (wert != mag_summe)     /* Bedingung verletzt */
         {
            resultat = 0;               /* kein mag. Quadrat */
            break;
         }
     }
    if (!resultat)
      break;
 }
} /* end if */

/* Ergebnisausgabe */
if (resultat)
  {
     printf("\n---------------- JA - ein M A G I S C H E S  Quadrat! ---------------");
     printf("\n------------------------- magische Summe: %3d -----------------------",
            mag_summe);
     output_quadrat(maxreihen);
  }
else
     printf("\nNEIN - leider kein magisches Quadrat!");
PAUSE;
}

/* Funktion liest quadratische Matrix zeilenweise ein */
void input_quadrat(int maxreihen)
{
  int z,s;                             /* z - Zeile, s - Spalte */

  printf("\nBitte eine %dx%d-Matrix zeilenweise eingeben!\n",
         maxreihen,maxreihen);
  for (z = 0; z < maxreihen; z++)
    for (s = 0; s < maxreihen; s++)
       {   printf("Z: %d Sp: %d -> ",z+1,s+1); scanf_s("%d",&quadrat[z][s]); }
}

/* Funktion ermittelt, ob alle Zahlen von 1 bis maxreihen^2
	in quadrat. Matrix vorkommen;
	Funktion gibt 1 zurueck, falls ja, sonst 0 */
int  pruefe_zahlen(int maxreihen)
{
  unsigned int zahl,           /* zu pruefende Zahl */
					zahl_gefunden,  /* Schalter, ob Zahl gefunden (1) oder nicht (0) */
					anzahl_plaetze; /* groesste zu pruefendende Zahl */
			  int z, s;           /* z - Zeile, s - Spalte */

  anzahl_plaetze = maxreihen*maxreihen;
  for (zahl = 1; zahl <= anzahl_plaetze; zahl++)
  {
	 zahl_gefunden = 0;
	 for (z = 0; z < maxreihen; z++)
	 for (s = 0; s < maxreihen; s++)
	 {
		 if (quadrat[z][s] == zahl)
			  zahl_gefunden = 1;
	 }
	 if (!zahl_gefunden) /* aktuell gepruefte Zahl nicht vorhanden */
		  return 0;
  }

  return 1; /* alle Zahlen genau einmal vorhanden */
}

/* Funktion ermittelt Summen
   - von Zeilen, - Spalten und - Diagonalen einer quadrat. Matrix */
int  compute_summe(int modus, int i, int maxreihen)
{

  int j,          /* Index Zeile / Spalte */
		summe = 0;  /* Summe Zeile, Spalte, Diagonale */

  for (j = 0; j < maxreihen; j++)
  {
     if (modus == 0)                 /* i-te Zeile */
       summe += quadrat[i][j];
     else if (modus == 1)            /* i-te Spalte */
       summe += quadrat[j][i];
     else if (modus == 2 && i == 0)  /* Hauptdiagonale:
                                        links-oben -> rechts-unten */
       summe += quadrat[j][j];
     else if (modus == 2 && i == 1)  /* Nebendiagonale:
                                        links-unten -> rechts-oben */
       summe += quadrat[maxreihen-1-j][j];
   }
   return summe;
}

/* Funktion gibt eine quadratische Matrix aus */
void output_quadrat(int maxreihen)
{
  int z,s;                             /* z - Zeile, s - Spalte */

  for (z = 0; z < maxreihen; z++)
  {
     printf("\n\n\t\t");
     for (s = 0; s < maxreihen; s++)
       {   printf("%7d", quadrat[z][s]); }
  }
}
