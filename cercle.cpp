#include "cercle.h"
#include <stdio.h>
#include <math.h>


Cercle::Cercle(int rayon, int x1, int y1)
: Forme(x1,y1) 
{
    r = new int;
    *r = rayon;
}

Cercle::~Cercle()
{
    delete r;
}

double Cercle::aire()
{
    return (M_PI*(*r)*(*r));
}

bool Cercle::changeSize(int rayon)
{
    *r = rayon;
    return true;
}

void Cercle::afficher(std::ostream & s)
{
    printf("Cercle (x=%d,y=%d, r=%d, aire=%f)\n", ancrage.x, ancrage.y, *r, aire());
}