
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       06-10, Monitorkauf
/*
/*      Konzepte/       switch-case-Anweisung ohne break
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   nein
/*
/*      Beschreibung:   Sie geben einen Hoechstbetrag ein, den Sie fuer
/*                      einen Monitor ausgeben wollen, und das Programm
/*                      listet alle Monitore auf, die hoechstens so viel
/*                      kosten.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>      /* enthaelt Ein- und Ausgabefunktionen */

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
    int betrag;

    /* Anweisungen */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 06-10, Monitorkauf ------------------------\n\n");

    printf("\nDas Programm listet Monitorangebote auf.\n");
    printf("\nBitte Hoechstbetrag in DM fuer einen 17'' Monitor angeben.");
    printf("\nD.h. einen Betrag zwischen 1000 und 2300");
    printf(" in Fuenfzigerschritten: ");
    scanf_s("%d", &betrag);
    printf("\n A N G E B O T E: \n");

    /* je nachdem, welcher Betrag eingegeben wurde, steigt man mit case an der
       entsprechenden Alternative ein und die folgenden Alternativen werden
       auch abgearbeitet */
    switch (betrag)
    {
        case 2300 : printf("\nIBM P70:                  2254 DM");
        case 2250 : /* Hier gibt es zwar nichts zu tun, aber die Eingabe */
        case 2200 : /* war richtig und alle nachfolgenden case-Alternativen */
        case 2150 : /* werden abgearbeitet */
        case 2100 :
        case 2050 : printf("\nEizo T57S:                2039 DM");
        case 2000 : 
        case 1950 : printf("\nMitsubishi TFM8705KL:     1949 DM");
        case 1900 : printf("\nSampo KM 760:             1860 DM");
        case 1850 : printf("\nSony 17 se II:            1849 DM"); PAUSE;
        case 1800 : printf("\nCompaq QVision 172:       1799 DM");
                    printf("\nFormac ProNitron 17 600:  1799 DM");
                    printf("\nPhilips 17A:              1790 DM");
                    printf("\nPeacock 17 Pro XE:        1769 DM");
        case 1750 : printf("\nElsa Ecomo 17H96:         1749 DM");
        case 1700 : printf("\nApple 1710:               1700 DM");
                    printf("\nArtMedia TN-1885T:        1699 DM");
                    printf("\nEizo F56:                 1659 DM"); PAUSE;
        case 1650 : printf("\nSNI MCM 1704 (NTD):       1650 DM");
                    printf("\nSampo KDM 1789:           1635 DM");

        case 1600 : printf("\nMiro D1785TE:             1589 DM");
                    printf("\nSamsung 17GLsi:           1579 DM");
                    printf("\nNokia 447Xi:              1599 DM");
        case 1550 :
        case 1500 : printf("\nHitachi CM1711MET:        1478 DM");
        case 1450 : printf("\nCTX 1785 XA:              1449 DM"); PAUSE;
                    printf("\nNokia 447W:               1405 DM");
        case 1400 : printf("\nSamtron SC-726GLX:        1399 DM");
                    printf("\nIiyama MF-8617T:          1395 DM");
        case 1350 :
        case 1300 : printf("\nBelinea 10 55 95:         1298 DM");
                    printf("\nPC 2000 (Kaga) F1785T:    1279 DM");
        case 1250 : printf("\nCTX 1785 XE:              1239 DM");
        case 1200 : printf("\nMagic AT1782F:            1199 DM");
                    printf("\nDeawoo CMC-1704C:         1190 DM");
        case 1150 : printf("\nForefront TX-D1753NM:     1150 DM");
        case 1100 :
        case 1050 :
        case 1000 : printf("\n\nEnde der Angebote.");
                          break;

        /* Trifft keiner der case-Faelle zu, so wird nach default verzweigt */
        default : printf("\nSie haben etwas Falsches eingegeben!");
    }
    PAUSE;
}
