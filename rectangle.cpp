#include "rectangle.h"
#include <stdio.h>


Rectangle::Rectangle(int largeur, int hauteur, int x1, int y1) 
:Forme(x1, y1)
{
    if(largeur <= 0)
    {
        largeur = 1;
        std::cout << "Une largeur négative a été entré, la largeur de la forme à donc été initié à 1.\n" << std::endl;
    }

    if(hauteur <= 0)
    {
        largeur = 1;
        std::cout << "Une hauteur négative a été entré, la hauteur de la forme à donc été initié à 1.\n" << std::endl;
    }

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

double Rectangle::getLargeur()
{
    return *l;
}

double Rectangle::getHauteur()
{
    return *h;
}