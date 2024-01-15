#ifndef RECTANGLE_H
#include "rectangle.h"
#endif


class Carre:public Rectangle
{
    public:
        Carre(int x1 = 0, int y1 = 0, int largeur = 1);
        ~Carre();
        void afficher(std::ostream & s) override;
        bool changeSize(int largeur);



};