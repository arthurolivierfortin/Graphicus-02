#include "rectangle.h"


Rectangle::Rectangle(int largeur = 1, int hauteur = 1, int x1 = 0, int y1 = 0)
{
    
}

Rectangle::~Rectangle(){}

void Rectangle::afficher(ostream &s)
{
    s << "Rectangle (x=%d,y=%d, l=%d, h=%d, aire=%f)\n" << ancrage.x << ancrage.y << largeur << hauteur << aire() << std::endl;
}

double Rectangle::aire()
{
    return (hauteur*largeur);
}