#include "forme.h"
#include "couche.h"

class Vecteur : public Couche
{
    public:
        Vecteur(int c = 1);
        ~Vecteur();
        int getCapacite();
        int getTaille();
        void doubler();
        void vider();
        bool estVide();
        void cpyTableau(Forme **p, Forme **tableau);
        void afficher(ostream &s);

        Forme **tableau;
        int capacite;
        int taille;
};