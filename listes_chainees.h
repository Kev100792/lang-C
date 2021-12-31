#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

Liste *initialisation();
Element *creerElement(int i);
void insertionVide(Liste *liste, Element *element);
void insertionDebut(Liste *liste, Element *element);
void insertionFin(Liste *liste, Element *element);
void insertionAvant(Liste *liste, Element *element, int position);
void insertionApres(Liste *liste, Element *element, int position);
void suppressionPremierElement(Liste *liste);
void suppressionDernierElement(Liste *liste);
void suppressionElement(Liste *liste, int position);
void suppressionListe(Liste *liste);
void afficherListe(Liste *liste);