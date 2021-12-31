#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *precedent;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
    Element *dernier;
    int nbElements;
};
