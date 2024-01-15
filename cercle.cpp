#include "cercle.h"
#include <stdio.h>
#include <math.h>


Cercle::Cercle(int x1, int y1, int rayon)
: Forme(x1,y1) 
{
    if(rayon <= 0)
    {
        rayon = 1;
        //std::cout << "Une valeur de rayon négative a été entré, le rayon de la forme a donc été initié à 1.\n" << std::endl;
    }
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

int Cercle::getRayon()
{
    return *r;
}

bool Cercle::changeSize(int rayon)
{
    *r = rayon;
    return true;
}

void Cercle::afficher(std::ostream & s)
{
    printf("Cercle (x=%d,y=%d, r=%d, aire=%f)", ancrage.x, ancrage.y, *r, aire());
}