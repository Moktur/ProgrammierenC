
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-02, Einfacher Taschenrechner
/*
/*      Konzepte/       switch-Auswahl
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
    char   operator;                       /* Operation: +, - und * */
    float  operand1, operand2, resultat;   /* Operanden und Resultat */

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-02, Taschenrechner ---------------------\n\n");

    /* Eingabe */
    printf("\nDas Programm fuehrt einige Taschenrechneroperationen aus.\n");
    printf("\nBitte Eingaben fuer Taschenrechner vornehmen!");
    printf("\n\nOperation (+,-,*):   "); scanf_s("%c",&operator, 1);
    printf("Erster float-Operand:  ");   scanf_s("%f",&operand1);
    printf("Zweiter float-Operand: ");   scanf_s("%f",&operand2);

    /* Berechnung und Ausgabe */
    switch(operator)
    {
          case '+': printf("\n %f + %f = %f",
                    operand1,operand2,resultat = operand1+operand2); break;

          case '-': printf("\n %f - %f = %f",
                    operand1,operand2,resultat = operand1-operand2); break;

          case '*': printf("\n %f * %f = %f",
                    operand1,operand2,resultat = operand1*operand2); break;

          default: printf("\nUnbekannte Operation!"); break;
    }
    printf("\n");
    PAUSE;
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

- Entfernen Sie die break-Anweisungen und testen Sie, wie das Programm dann
  reagiert.

- Erweitern Sie das Programm um die Operation Division ("/"). Vermeiden Sie
  dabei eine Division durch Null. Pruefen Sie hierzu bei dem Operator "/", ob
  der zweite Operand von Null verschieden ist. Diese Pruefung kann bei
  float-Zahlen wie folgt vorgenommen werden:
    - die Zahl wird betragsmaessig mit einer hinreichend kleinen Konstanten
      verglichen, z.B. mit 1E-12,
    - fuer die Ermittlung des Betrages kann die Funktion fabs verwendet werden,
      als Definitionsdatei ist zusaetzlich math.h mit #include einzufuegen:
            #include <math.h>
    - faellt der Betrag des Operanden kleiner als die Konstante aus,
      wird das Programm nach einer Meldung mit der Anweisung return
      (vgl. Kap. 7) verlassen,
    - die Pruefung lautet also etwa:
            if (fabs(operand2) < 1E-12)
              {  printf("\nmeldung");  return; }

******************************************************************************/
