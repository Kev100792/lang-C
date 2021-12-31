#include "listes_chainees.h"

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));

    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    liste->premier  = NULL;
    liste->dernier = NULL;
    liste->nbElements = 0;

    return liste;

};

Element *creerElement(int i)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // printf("Quel nombre voulez-vous ajouter ?\n");
    // scanf("%i", &nouveau->nombre);
    nouveau->nombre = i;
    i++;

    nouveau->precedent = NULL;
    nouveau->suivant = NULL;

    return nouveau;

}

void insertionVide(Liste *liste, Element *element)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if(liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = element->nombre;
    nouveau->precedent = liste->premier;
    nouveau->suivant = liste->dernier;
    liste->premier = nouveau;
    liste->dernier = nouveau;
    
    liste->nbElements ++;
}

void insertionDebut(Liste *liste, Element *element)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau = element;

    if(liste->premier == NULL || liste->dernier == NULL)
    {
        liste->dernier = nouveau;
        liste->premier = nouveau;
    }

    else
    {
        nouveau->suivant = liste->premier;
        liste->premier->precedent = nouveau;
        liste->premier = nouveau;
    }

    liste->nbElements ++;
}

void insertionFin(Liste *liste, Element *element)
{
    Element *nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau = element;

    if(liste->premier == NULL || liste->dernier == NULL)
    {
        liste->dernier = nouveau;
        liste->premier = nouveau;
    }

    else
    {
        nouveau->precedent = liste->dernier;
        liste->dernier->suivant = nouveau;
        liste->dernier = nouveau;
    }

    liste->nbElements ++;
}

void insertionAvant(Liste *liste, Element *element, int position)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    Element *actuel = malloc(sizeof(*actuel));
    int i;

    if(nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau = element;

    actuel = liste->premier;
    for (i = 0; i < position; i++)
    {
        actuel = actuel->suivant;
    }
    nouveau->suivant = actuel;
    nouveau->precedent = actuel->precedent;

    if(actuel->precedent == NULL)
    {
        liste->premier = nouveau;
    }
    else
    {
        actuel->precedent->suivant = nouveau;
    }
    actuel->precedent = nouveau;
    liste->nbElements ++;
}

void insertionApres(Liste *liste, Element *element, int position)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    Element *actuel = malloc(sizeof(*actuel));
    int i;

    if(nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau = element;

    actuel = liste->premier;
    for (i = 0; i < position; i++)
    {
        actuel = actuel->suivant;
    }
    nouveau->suivant = actuel->suivant;
    nouveau->precedent = actuel;

    if(actuel->suivant == NULL)
    {
        liste->dernier = nouveau;
    }
    else
    {
        actuel->suivant->precedent = nouveau;
    }
    actuel->suivant = nouveau;
    liste->nbElements ++;
}

void suppressionPremierElement(Liste *liste)
{
    Element *aSupprimer = malloc(sizeof(*aSupprimer));
    
    if(liste == NULL || aSupprimer == NULL)
    {
        exit(EXIT_FAILURE);
    }

    aSupprimer = liste->premier;

    if(aSupprimer == liste->premier && aSupprimer == liste->dernier)
    {
        liste->premier = NULL;
        liste->dernier = NULL;
    }
    else if(aSupprimer == liste->premier && aSupprimer != liste->dernier)
    {
        liste->premier = aSupprimer->suivant;
        liste->premier->precedent = NULL;
    }
    else if (aSupprimer != liste->premier && aSupprimer == liste->dernier)
    {
        liste->dernier = aSupprimer->precedent;
        liste->dernier->suivant = NULL;
    }
    else
    {
        aSupprimer->precedent->suivant = aSupprimer->suivant;
        aSupprimer->suivant->precedent = aSupprimer->precedent;
    }

    liste->nbElements --;

    free(aSupprimer);
}

void suppressionDernierElement(Liste *liste)
{
    Element *aSupprimer = malloc(sizeof(*aSupprimer));
    
    if(liste == NULL || aSupprimer == NULL)
    {
        exit(EXIT_FAILURE);
    }

    aSupprimer = liste->dernier;

    if(aSupprimer == liste->premier && aSupprimer == liste->dernier)
    {
        liste->premier = NULL;
        liste->dernier = NULL;
    }
    else if(aSupprimer == liste->premier && aSupprimer != liste->dernier)
    {
        liste->premier = aSupprimer->suivant;
        liste->premier->precedent = NULL;
    }
    else if (aSupprimer != liste->premier && aSupprimer == liste->dernier)
    {
        liste->dernier = aSupprimer->precedent;
        liste->dernier->suivant = NULL;
    }
    else
    {
        aSupprimer->precedent->suivant = aSupprimer->suivant;
        aSupprimer->suivant->precedent = aSupprimer->precedent;
    }

    liste->nbElements --;

    free(aSupprimer);
}

void suppressionElement(Liste *liste, int position)
{
    Element *aSupprimer = malloc(sizeof(*aSupprimer));
    
    if(liste == NULL || aSupprimer == NULL)
    {
        exit(EXIT_FAILURE);
    }
    aSupprimer = liste->premier;
    int i;

    for(i=0 ; i<position ; i++)
    {
        aSupprimer = aSupprimer->suivant;
    }


    if(aSupprimer == liste->premier && aSupprimer == liste->dernier)
    {
        liste->premier = NULL;
        liste->dernier = NULL;
    }
    else if(aSupprimer == liste->premier)
    {
        liste->premier = liste->premier->suivant;
        liste->premier->precedent = NULL;
    }
    else if (aSupprimer == liste->dernier)
    {
        liste->dernier = liste->dernier->precedent;
        liste->dernier->suivant = NULL;
    }
    else
    {
        aSupprimer->precedent->suivant = aSupprimer->suivant;
        aSupprimer->suivant->precedent = aSupprimer->precedent;
    }

    liste->nbElements --;

    free(aSupprimer);
}

void suppressionListe(Liste *liste)
{
    while(liste->nbElements > 0)
    {
        suppressionElement(liste, 0);
    }
}

void afficherListe(Liste *liste)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
    int i = 0;

    while(actuel != NULL)
    {
        printf("Position %i => %d\n", i, actuel->nombre);
        actuel = actuel->suivant;
        i++;
    }
    printf("NULL \n");
    printf("Il y a %i élément(s) dans la liste\n", liste->nbElements);
}