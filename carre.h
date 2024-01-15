#ifndef RECTANGLE_H
#include "rectangle.h"
#endif


class Carre:public Rectangle
{
    public:
        Carre(int largeur, int x1 = 0, int y1 = 0);
        ~Carre();
        void afficher(std::ostream & s) override;
        bool changeSize(int largeur);



};