#ifndef FORME_H
#include "forme.h"
#endif

#define CERLCE_H


class Cercle:public Forme
{
    public:
        Cercle(int x1 = 0, int y1 = 0, int rayon = 1);
        ~Cercle();
        double aire() override;
        void afficher(std::ostream & s) override;
        bool changeSize(int rayon);
        int getRayon();
    private:
        int *r;
};