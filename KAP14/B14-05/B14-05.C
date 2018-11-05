
/*****************************************************************************/
/*
/*      FernUni Hagen, Lehrstuhl EvIS
/*
/*      C-Kurs 810
/*
/*      Beispiel:       14-05, Binaerer Baum
/*
/*      Konzepte/       Implementierung eines binaeren Suchbaums
/*      Sprachelemente: 
/*
/*      Aufgabenteil:   ja, siehe unten
/*
/*      Beschreibung:   Das Programm implementiert einige Funktionen fuer
/*                      einen binaeren Suchbaum und wendet diese an.
/*
/*****************************************************************************/

/*****************************************************************************/
/* Include-Dateien laden
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************/
/* Makros definieren
/*****************************************************************************/

/* Makro: warten auf Return */
#define  PAUSE {printf("\nRETURN!\n");fflush(stdin);getchar();}

/*****************************************************************************/
/* Datentypen definieren
/*****************************************************************************/

typedef struct element *ELEM_ZGR;      /* Zeigertyp fuer Baum-Element */
struct element                         /* Knotentyp fuer Baum-Element */
{
    int            wert;      /* einziges Nutzdatum */
    ELEM_ZGR       left;      /* Zeiger auf linken Nachfolger */
    ELEM_ZGR       right;     /* Zeiger auf rechten Nachfolger */
};

/*****************************************************************************/
/* Globale Variablen definieren
/*****************************************************************************/

ELEM_ZGR root;                         /* externer Zeiger auf Wurzel */

/*****************************************************************************/
/* Funktionen deklarieren
/*****************************************************************************/

void init_tree(void);
void reinit_tree(void);
void reinit_tree_rek(ELEM_ZGR curr);
int  add_elem(int wert);
void show_tree(int order);
void show_tree_in(ELEM_ZGR curr, int start);
void show_tree_pre(ELEM_ZGR curr, int start);
void show_tree_post(ELEM_ZGR curr, int start);
void show_tree_level(void);
void traverse_level(int target, int ncurr, ELEM_ZGR curr);

/*****************************************************************************/
/* Funktionen definieren
/*****************************************************************************/

void main(void)
{
    unsigned int  nelem,                 /* gewuenschte Anzahl Elemente */
                  seed,                  /* Wurzel Zufallszahlenerzeugung */
                  i,                     /* Zaehler Elemente */
                  wert,                  /* Elementwert */
                  mod;                   /* Traversierungsmodus */

    /* Information */
    printf("\nFernUni Hagen, Lehrstuhl EvIS, C-Kurs 810\n");
    printf("----- Beispiel: 14-05, Binaerer Baum ----------------------\n\n");
    printf("\nDemonstrationsprogramm fuer binaeren Suchbaum\n");

    /* Eingabe Baumumfang */
    printf("\nGewuenschter Knotenumfang (<=50): "); scanf_s("%u",&nelem);
    if (nelem <= 0 || nelem > 50)       /* gegebenenfalls Korrektur */
        nelem = 50;
    printf("Wurzel Zufallszahlen (>= 0): "); scanf_s("%u",&seed);
    srand(seed);                        /* Initialisierung Zufallszahlen */

    init_tree();                        /* Baum initialisieren */

    for (i = 0; i < nelem; i++)         /* Baum aufbauen mit nelem Elementen */
    {
        wert = rand()%100;              /* Zufallszahlen < 100 */
        if (!add_elem(wert))            /* 1 Element mit wert einfuegen */
        {
            printf("\nElement nicht einfuegbar - Abbruch");
            PAUSE;
            exit(1);
        }
    }
    printf("\nBaum mit %d Elementen aufgebaut.\n", nelem);

    for (mod = 0; mod <= 3; mod++)       /* Traversierung mit Anzeige */
    {                                    /* aller Knoten in 4 Varianten */
        show_tree(mod);
        PAUSE;
    }

    for (i = 0; i < nelem/2; i++)        /* nochmals nelem/2 Elemente einfuegen */
    {
        wert = rand()%100;
        if (!add_elem(wert))
        {
            printf("\nElement nicht einfuegbar - Abbruch");
            PAUSE;
            exit(1);
        }
    }
    printf("\n\nBaum um %d Elemente erweitert.\n", nelem/2);

    for (mod = 0; mod <= 3; mod++)       /* Traversierung mit Anzeige */
    {                                    /* aller Knoten in 4 Varianten */
        show_tree(mod);
        PAUSE;
    }

    reinit_tree();                       /* Baum aufloesen */
    PAUSE;
}

/* initialisiert externen Zeiger root mit Nullwert */
void init_tree(void)
{
    root = NULL;
}

/* loest den Baum auf */
void reinit_tree(void)
{
    reinit_tree_rek(root);              /* rekursive Funktion aufrufen */
    init_tree();                        /* Wurzel wieder auf Nullwert setzen */
}

void reinit_tree_rek(ELEM_ZGR curr)
{
    /* Vorgehen:
       - ausgehend von der Wurzel root wird zu einem Knoten curr stets
         zuerst der linke, dann der rechte Teilbaum und dann der Knoten
         curr entfernt (Postorder-Traversierung)
       - daher werden stets alle Nachfolger eines Knotens vor dem Knoten
         selbst an den Heap zurueckgegeben und es kommt nicht zu einem
         Zugriff auf bereits geloeschte Knoten
    */

    if (curr != NULL)                 /* wenn Teilbaum nicht leer */
    {
        reinit_tree_rek(curr->left);  /* erst linken Teilbaum entfernen ...*/
        reinit_tree_rek(curr->right); /* dann rechten Teilbaum entfernen... */
        free(curr);                   /* dann Wurzel des Teilbaumes loeschen */
    }
}

/* - fuegt neues Element mit Wert wert sortiert in Baum ein,
   - gibt 1 zurueck, wenn Einfuegen erfolgreich, 0 sonst */
int add_elem(int wert)
{
    ELEM_ZGR temp,                       /* Zeiger auf neues Element */
             curr;                       /* Zeiger auf aktuelles Element */

    /* neues Element im Heap allokieren und fuellen */
    temp = (ELEM_ZGR)malloc(sizeof(struct element));
    if (temp == NULL)                    /* wenn malloc versagt abbrechen */
        return 0;
    temp->wert = wert;                   /* neuen Wert eintragen und ...*/
    temp->left = temp->right = NULL;     /* Nachfolger-Zeiger mit NULL fuellen */

    /* neues Element einfuegen */
    /* Sonderfall: leerer Baum, neuer Knoten wird Wurzel */
    if (root == NULL)
        root = temp;
    else
    /* allgemeiner Fall: Baum nicht leer, Vorgehen:
       - Suche nach Einfuegestelle beginnt bei Wurzel;
       - abhaengig davon, ob Wert des neuen Knotens kleiner oder groesser
         gleich dem Wert im aktuellen Knoten ist, wird jeweils
         Einfuegestelle im linken bzw. rechten Teilbaum weiter gesucht;
       - muss links weiter gesucht werden, ohne dass ein linker
         Nachfolger vorhanden ist, wird der neue Knoten linker Nachfolger
         des aktuellen Knotens; analog bei Suche weiter rechts.
    */
    {
        for (curr = root;;)             /* Einfuegestelle ab Wurzel suchen */
        {
            if (wert < curr->wert)      /* neuer Wert < aktueller Wert */
            {
                if  (curr->left != NULL)/* wenn  linker Nachfolger vorhanden */
                     curr = curr->left; /*       weiter links suchen */
                else
                  {
                     curr->left = temp;     /* sonst wird neuer Knoten */
                     break;                 /* linker Nachfolger von curr */
                  }
            }
            else                            /* neuer Wert >= aktueller Wert */
            {
                if  (curr->right != NULL)   /* analog fuer rechten Teilbaum */
                    curr = curr->right;     /* von curr */
                else
                {
                    curr->right = temp;
                    break;
                }
            }                              /* end neuer Wert >= ... */
        }                                  /* end for */
    }                                      /* end allgemeiner Fall */
    return 1;                              /* Einfuegen erfolgreich */
}

/* zeigt alle Baumelemente in einer der folgenden Anordnungen:
   order = 0 : symmetrische Ordnung, aufsteigende Sortierung
   order = 1 : Praeordnung, Wurzel Teilbaum vor Nachfolger-Teilbaeumen
   order = 2 : Postordnung, Wurzel Teilbaum nach Nachfolger-Teilbaeumen
   order = 3 : Niveauordnung, pro Niveau von links nach rechts
*/

void show_tree(int order)
{
    printf("\nAktueller binaerer Suchbaum / ");
    switch(order)
    {
        case 0: printf("Symmetrische Ordnung (sortiert)\n");
                show_tree_in(root,1); break;
        case 1: printf("Praeordnung, Teilbaum-Wurzel zuerst\n");
                show_tree_pre(root,1); break;
        case 2: printf("Postordnung, Teilbaum-Wurzel zuletzt\n");
                show_tree_post(root,1); break;
        case 3: printf("Niveauordnung, pro Niveau von links nach rechts\n");
                show_tree_level(); break;
    }
}

/* zeigt alle Elemente eines Teilbaumes in symmetrischer Ordnung */
void show_tree_in(ELEM_ZGR curr, int start)
{
    static int i;                        /* Elementzaehler */

    /* Vorgehen:
       - ausgehend von der Wurzel root wird zu einem Knoten curr stets
         zuerst der linke Teilbaum, dann der Knoten selbst und schliesslich
         der rechte Teilbaum zum Knoten gezeigt (Inorder-Traversierung)
       - da alle Nachfolger im linken Teilbaum eines Knotens curr kleinere Werte
         als curr und alle Nachfolger im rechten Teilbaum von curr groessere Werte
         als curr besitzen, wird jeder Teilbaum, daher auch der gesamte Baum
         sortiert ausgegeben
    */

    i = start ? 0 : i;                   /* Zaehler init. */
    if (curr != NULL)                    /* wenn Teilbaum nicht leer */
    {
        show_tree_in(curr->left,0);      /* erst linken Teilbaum zeigen ...*/
        if (++i%15 == 1 && i > 1)
            printf("\n");
        printf(" %2d ",curr->wert);      /* dann Wurzel des Teilbaumes ...*/
        show_tree_in(curr->right,0);     /* dann rechten Teilbaum zeigen */
    }
}

/* zeigt alle Elemente eines Teilbaumes in Praeordnung */
void show_tree_pre(ELEM_ZGR curr, int start)
{
    /* zum Vorgehen vgl. show_tree_in */
    static int i;                        /* Elementzaehler */

    i = start ? 0 : i;                   /* Zaehler init. */
    if (curr != NULL)                    /* wenn Teilbaum nicht leer */
    {
        if (++i%15 == 1 && i > 1)
            printf("\n");
        printf(" %2d ",curr->wert);      /* zuerst Wurzel des Teilbaumes ...*/
        show_tree_pre(curr->left,0);     /* dann linken Teilbaum ...*/
        show_tree_pre(curr->right,0);    /* dann rechten Teilbaum zeigen */
    }
}

/* zeigt alle Elemente eines Teilbaumes in Postordnung */
void show_tree_post(ELEM_ZGR curr, int start)
{
    /* zum Vorgehen vgl. show_tree_in */
    static int i;                        /* Elementzaehler */

    i = start ? 0 : i;                   /* Zaehler init. */
    if (curr != NULL)                    /* wenn Teilbaum nicht leer */
    {
        show_tree_post(curr->left,0);    /* zuerst linken Teilbaum ...*/
        show_tree_post(curr->right,0);   /* dann rechten Teilbaum ... */
        if (++i%15 == 1 && i > 1)
            printf("\n");
        printf(" %2d ",curr->wert);      /* dann Wurzel des Teilbaumes zeigen*/
    }
}

/* Globale fuer niveauweise Baumausgabe */
int level_nodes_found;    /* Anzahl gefundene Knoten auf Zielniveau*/

void show_tree_level(void)
{
    /* fuehrt niveauweise Traversierung mittels wiederholter
       Praeorder-Traversierung bis zu jeweils aktuellem Zielniveau durch

       Niveau eines Knotens:
            - Wurzel hat Niveau 0,
            - Nachfolger eines Knotens hat Niveau i+1, wenn Knoten Niveau i hat

       niveauweise Traversierung:
       beginnend ab Niveau 0 werden stets alle Knoten eines Niveaus bearbeitet,
       bevor mit Knoten des naechsthoeheren Niveaus fortgesetzt wird
    */
    int target_level; /* aktuelles Zielniveau bei niveauweiser Traversierung */

    printf("\nNiveau  Knoten (linker Nachfolger, rechter Nachfolger)    (# = ohne Nachfolger)");
    printf("\n-------------------------------------------------------------------------------");

    for(target_level = 0;1;)    /* ab Zielniveau 0 (Wurzel) */
    {
        level_nodes_found = 0;  /* init.: keine Knoten auf Zielniveau */
                                /* Traversierung fuer Zielniveau target_level*/
                                         /* ab Niveau 0, mit Wurzel */
        traverse_level(target_level, 0, root);

        if(!level_nodes_found)  /* keine Knoten auf Zielniveau */
            break;              /* -> Traversierung abbrechen */
        target_level++;         /* naechstes Zielniveau */
    }
}

/* rekursive Funktion, untersucht Knoten curr auf Niveau ncurr */
void traverse_level(int target, int ncurr, ELEM_ZGR curr)
{
    if (curr == NULL)                 /* kein Knoten da - zurueck */
        return;
    else if (ncurr == target)         /* Knoten auf Zielniveau */
    {
        if (level_nodes_found%6==0)   /* neue Zeile */
            printf("\n%3d     ",target);
        level_nodes_found++;          /* Zielniveauknoten inkrementieren */

        printf("%2d(",curr->wert);    /* Knoten ausgeben */
        if (curr->left != NULL)       /* Nachfolger ausgeben */
            printf("%2d,",curr->left->wert);
        else
            printf(" #,");
        if (curr->right != NULL)
            printf("%2d); ",curr->right->wert);
        else
            printf(" #); ");

        /* hoehere Niveaus als (aktuelles) Zielniveau target nicht beachten
           -> keine rekursiven Aufrufe mehr */
    }
    else if (ncurr < target)          /* unterhalb Zielniveau -> klettern */
    {
        traverse_level(target, ncurr+1, curr->left);   /* erst links */
        traverse_level(target, ncurr+1, curr->right);  /* dann rechts */
    }
}

/*****************************************************************************/
/* Aufgabe
/******************************************************************************

  - Vollziehen Sie anhand von Tests mit kleineren Binaerbaeumen die
    realisierten Traversierungsformen nach. Die niveauweise
    Traversierung soll in der hier implementierten Form lediglich als
    Hilfe fuer ein besseres Verstaendnis der drei Standardformen
    der Traversierung dienen.

  - Vollziehen Sie im einzelnen das Einfuegen von Knoten in den
    Baum nach. Verwenden Sie gegebenenfalls zusaetzliche
    Zwischendrucke (aktueller Wert, Weg des neuen Knotens bis
    zur Einfuegestelle).

  - Schreiben Sie folgende zusaetzliche Funktionen und testen Sie
    diese, nachdem Sie die main-Funktion geeignet modifiziert haben:

    (1) Die Funktion count_binbaum soll die Anzahl aller Knoten des
        Baumes rekursiv ermitteln und als Funktionswert zurueckgeben.

        Prototyp: int count_binbaum(ELEM_ZGR curr);
        Aufruf in main: anzahl_knoten = count_binbaum(root);

        Hinweis: Fuer jeden Teilbaum gilt, dass die Anzahl seiner
        Knoten gleich der Summe aus der Knotenanzahlen des linken
        und des rechten Teilbaumes plus eins ist.

    (2) Die Funktion hoehe_binbaum soll das maximale Niveau eines
        Binaerbaumes rekursiv ermitteln und als Funktionswert
        zurueckgeben. Vgl. Erlaeuterung zur Funktion
        show_tree_level.

        Prototyp: int hoehe_binbaum(ELEM_ZGR curr);
        Aufruf in main: max_niveau = hoehe_binbaum(root);

        Hinweis: Fuer jeden Teilbaum gilt, dass das hoechste Niveau
        gleich dem Maximum der hoechsten Niveaus des linken bzw.
        rechten Teilbaumes plus eins ist. Da das Niveau der Wurzel
        eines (Teil-)Baumes gleich Null festgelegt ist, ist zu beachten,
        dass das hoechste Niveau eines leeren Teilbaumes gleich minus
        eins ist.

******************************************************************************/
