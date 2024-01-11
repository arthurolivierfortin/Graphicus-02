#include "carre.h"
#include <stdio.h>

Carre::Carre(int largeur, int x1, int y1)
: l(largeur), Rectangle(l, l, x1, y1)
{

}

Carre::~Carre()
{

}

double Carre::aire()
{
    return (l*l);
}

void Carre::afficher(ostream & s)
{
    printf("Carre (x=%d,y=%d, l=%d, aire=%f)\n", ancrage.x, ancrage.y, l, aire());
}