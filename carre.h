#include "rectangle.h"


class Carre:public Rectangle
{
    public:
        Carre(int largeur, int x1, int y1);
        ~Carre();
        double aire() override;
        void afficher(std::ostream & s) override;

        int l;


};