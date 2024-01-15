#ifndef FORME_H
#include "forme.h"
#endif

#define RECTANGLE_H

class Rectangle:public Forme
{
    public:
        Rectangle(int largeur, int hauteur, int x1 = 0, int y1 = 0);
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