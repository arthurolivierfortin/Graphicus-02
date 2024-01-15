#include "carre.h"
#include <stdio.h>

Carre::Carre(int x1, int y1, int largeur)
: Rectangle(x1, y1,largeur, largeur)
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
    printf("Carre (x=%d,y=%d, l=%d, aire=%f)", ancrage.x, ancrage.y, *l, aire());
}