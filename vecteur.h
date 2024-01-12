

#ifndef FORME_H
#include "forme.h"
#endif

#define VECTEUR_H

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
        void cpyTableau(Forme **p,Forme **tableau);
        void afficher(std::ostream &s);
        Forme *getForme(int index);
        bool addForme(Forme *p);
        Forme *rmForme(int index);

        Forme **tableau;
        int *taille;
        int *capacite;
};