#include "forme.h"


class Cercle:public Forme
{
    public:
        Cercle(int rayon, int x1, int y1);
        ~Cercle();
        double aire() override;
        void afficher(std::ostream & s) override;

        int r;
};