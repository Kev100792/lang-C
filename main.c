#include <stdlib.h>
#include <stdio.h>
#include "listes_chainees.h"

int main(int argc, char *argv[])
{
    Liste *maListe = initialisation();
    int i;
    Element *nouveau = NULL;
    for(i = 0; i<10; i++)
    {
    nouveau = creerElement(i);
    insertionFin(maListe, nouveau);
    }

    afficherListe(maListe);

    suppressionElement(maListe, 5);

    afficherListe(maListe);


    return 0;

}