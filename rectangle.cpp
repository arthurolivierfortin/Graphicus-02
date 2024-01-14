#include "rectangle.h"
#include <stdio.h>


Rectangle::Rectangle(int largeur = 1, int hauteur = 1, int x1 = 0, int y1 = 0) 
:Forme(x1, y1)
{
    l = new int;
    *l = largeur;

    h = new int;
    *h = hauteur;
}

Rectangle::~Rectangle()
{
    delete l;
    delete h;
}

bool Rectangle::changeSize(int largeur, int hauteur)
{
    if(largeur < 0 || hauteur < 0)
    {
        return false;
    }

    *l = largeur;
    *h = hauteur;

    return true;
}

void Rectangle::afficher(std::ostream &s)
{
    printf("Rectangle (x=%d,y=%d, l=%d, h=%d, aire=%f)\n", ancrage.x, ancrage.y, *l, *h, aire());
}

double Rectangle::aire()
{
    return ((*h)*(*l));
}