#ifndef FORME_H
#include "forme.h"
#endif

#define RECTANGLE_H

class Rectangle:public Forme
{
    public:
        Rectangle(int x1 = 0, int y1 = 0, int largeur = 1, int hauteur = 1);
        ~Rectangle();
        virtual void afficher(std::ostream &s) override;
        double aire() override;
        bool changeSize(int largeur, int hauteur);
        double getLargeur();
        double getHauteur();
    protected:
        int *l;
        int *h;
};