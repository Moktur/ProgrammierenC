#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}


void main(void)
{
    /*lokale Variablen*/
    float fahrenheit;
    float celsius;
    int t;

    int a, b, c, d;

    /* Fuer den Programmierer ASCII Werte von F und C*/
    /* C = 67*, F = 70*/




    printf("\nBitte die Höhe der Temperatur eingeben;\n");
    printf("\nIst die Temperaturangabe °C oder °F?");
    printf("\nTippe jeweils C oder F und Enter:\n");
    t = getchar();
    printf("\nBitte die Gradzahl eingeben:\n");
    scanf("%i", &a);

    if (t == 67)
    {
        /* Berechnung in °F*/
        celsius = a;
        fahrenheit = (9.f/5.f * celsius) + 32.f;

        printf("\n%.2f °C wurden in %.2f °F umgerechnet", celsius, fahrenheit);

    } else
    {

        /*Berechnung in °C*/
        fahrenheit = a;
        celsius = (fahrenheit * (5.f/9.f))- (32.f * (5.f/9.f));
        printf("\n%.2f °F wurden in %.2f °C umgerechnet", fahrenheit, celsius);

    }

    PAUSE;
}
