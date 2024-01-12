#ifndef FORME_H
#include "forme.h"
#endif

class Rectangle:public Forme
{
    public:
        Rectangle(int largeur, int hauteur, int x1, int y1);
        ~Rectangle();
        void afficher(std::ostream &s) override;
        double aire() override;
        int l;
        int h;
};