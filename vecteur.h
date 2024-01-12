#ifndef COUCHE_H
#include "couche.h"
#endif

#ifndef FORME_H
#include "forme.h"
#endif

#define VECTEUR_H

class Vecteur
{
    public:
        Vecteur(int c = 1);
        ~Vecteur();
        virtual double aire();
        int getCapacite();
        int getTaille();
        void doubler();
        void vider();
        bool estVide();
        void cpyTableau(Vecteur **p, Vecteur **tableau);
        void afficher(std::ostream &s);
        Forme *getForme(int index);
        bool addForme(Vecteur *p);
        Forme *rmForme(int index);

        Vecteur **tableau;
        int *taille;
        int *capacite;
};