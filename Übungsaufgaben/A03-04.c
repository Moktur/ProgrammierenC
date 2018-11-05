#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar();}

void main(void)
{
    const int MAX = 100;
    const float PI = 3.14159;
    const float Radius = Druchmesser / 2;
    const float MwSt = 16;
    const float Durchmesser = 20.7;
    const float Temperatur = 37.0;
    const char Satz[] = "Hallo da bin ich.";

    /* Berechnungen laut Aufgabe*/
    float kreisumfang = PI * Durchmesser;
    float kreisflaeche = PI * (Radius *Radius);
    float artikel = 16 * 100 / 100;



    printf("Kreisumfang= %1.f, kreisflaeche= %.3f, artikel= %f",
            kreisumfang, kreisflaeche, artikel);
    printf("\nEs ist genau %.2f warm.\n", Temperatur);
    printf("\n%s", Satz);


    PAUSE;







}
