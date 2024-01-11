#include "forme.h"

class Vecteur
{
    public:
        Vecteur(int c = 1);
        ~Vecteur();
        int getCapacite();
        int getTaille();
        void doubler();
        void vider();
        bool estVide();
        bool ajouter(Forme *p);
        Forme *retirer(int index);
        Forme *obtenir(int index);
        void cpyTableau(Forme **p, Forme **tableau);
        void afficher(ostream &s);

        Forme **tableau;
        int capacite;
        int taille;
};