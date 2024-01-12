#include "cercle.h"
#include <stdio.h>
#include <math.h>


Cercle::Cercle(int rayon, int x1, int y1)
: r(rayon), Forme(x1,y1) 
{

}

Cercle::~Cercle()
{

}

double Cercle::aire()
{
    return (M_PI*r*r);
}

void Cercle::afficher(std::ostream & s)
{
    printf("Cercle (x=%d,y=%d, r=%d, aire=%f)\n", ancrage.x, ancrage.y, r, aire());
}