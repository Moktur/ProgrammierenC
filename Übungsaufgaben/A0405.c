#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

void main(void)
{
    int zahl = 12345;

    printf("\n %d", zahl);

    /* Ausgabe der Zahl 12345 */
    /* mit führenden Nullen */
    printf("\n <%07d>", zahl);

    /* siebenstellige Ausgabe rechtsbündig */
    printf("\n <%7i>", zahl);

    /* siebenstellige Ausgabe linksbündig */
    printf("\n <%-7i>", zahl);

    /* Ausgabe mit Vorzeichen */
    printf("\n <%+7i>", zahl);


    const float PI = 3.14159;

    /*Ausgabe der Konstante PI, 7 stellig mit 2 Nachkommastellen*/
    /*Ausgabe mit führenden Nullen*/
    printf("\n <%07.2f>", PI);

    /*Ausgabe rechtsbündig*/
    printf("\n <%7.2f>", PI);

    /*Ausgabe linksbündig*/
    printf("\n <%-7.2f>", PI);

    /*Ausgabe wissenschaftlich*/
    printf("\n <%e>", PI);
    printf("\n <%E.2F>", PI);

    /*Ausgabe der Zahl 5.99999999*/
    float peins = 5.99999999;
    printf("\n <%.2f>", peins);

    printf("\nEs folgen Ausgaben von Strings");
    PAUSE;

    /*Ausgabe von String*/



    char string[] = "FernUni Hagen";
    printf("\n <%s>", string);
    printf("\n <%10s>", string);
    /* links udn dann rechtsbündig */
    printf("\n <%-20s>", string);
    printf("\n <%20s>", string);
    /* Ausgabe in einem 20 Zeichen breiten Bereich mit maximal 10 Zeichen der
     * Zeichenkette */
    printf("\n <%20.10s>", string);


    printf("\n Ausgabe des Zeichens \"*\"");

    char star = '*';
    printf("\n <%5.c>", star);
    /* nun linksbündig */
    printf("\n <%-5.c>", star);

    PAUSE;

    printf("\nAusgabe der Zahl 123 als:");
   printf("\nint, uint, float, oktal und hex mit");
           printf("\nGross- und Kleinbuchstaben\n");
    printf("\nAusgabe als int: %i", 123);
    printf("\nAusgabe als unsigned int: %u", 123);
    printf("\nAusgabe als float: %f", 123);
    printf("\nAusgabe als Oktalzahl: %o", 123);
    printf("\nAusgabe als Hexadezimalzahl: %x", 123);
    printf("\nAusgabe als Hexadezimalzahl: %X", 123);

    PAUSE;
    /* Ausgabe von Steuerzeichen */
    printf("\nTabulator: <\t>");
    printf("\nKlingelzeichen: <\a>");
    printf("\nWagenruecklauf: <\r>");
    printf("\nEinfache und doppelte Anfuehrungszeichen: \', \"");
    printf("\nGegenstrich (Backslash): \\");
    printf("\nProzentzeichen %%.");
    printf("\nZeilenvorlauf \n test");

    /*Satzbildung */
    char test[] = "ist";
    char zeichen = ':';

    printf("\nDies %s die Zahl Pi %c%f.",test , zeichen, PI);







    PAUSE;






}
