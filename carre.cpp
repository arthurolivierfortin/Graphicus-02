#include "carre.h"
#include <stdio.h>

Carre::Carre(int largeur, int x1, int y1)
: Rectangle(largeur, largeur, x1, y1)
{

}

Carre::~Carre()
{

}

bool Carre::changeSize(int largeur)
{
    if(largeur < 0)
    {
        return false;
    }

    *l = largeur;
    *h = largeur;

    return true;
}


void Carre::afficher(std::ostream & s)
{
    printf("Carre (x=%d,y=%d, l=%d, aire=%f)\n", ancrage.x, ancrage.y, *l, aire());
}