#include "rectangle.h"
#include <stdio.h>


Rectangle::Rectangle(int largeur = 1, int hauteur = 1, int x1 = 0, int y1 = 0) 
: l(largeur), h(hauteur), Forme(x1, y1)
{
    
}

Rectangle::~Rectangle(){}

void Rectangle::afficher(ostream &s)
{
    printf("Rectangle (x=%d,y=%d, l=%d, h=%d, aire=%f)\n", ancrage.x, ancrage.y, l, h, aire());
}

double Rectangle::aire()
{
    return (h*l);
}