#include "forme.h"

class Rectangle:public Forme
{
    public:
        Rectangle(int largeur, int hauteur, int x1, int y1);
        ~Rectangle();
        void afficher(ostream &s) override;
        double aire() override;
        int largeur;
        int hauteur;
};