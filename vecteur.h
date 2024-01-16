

#ifndef FORME_H
#include "forme.h"
#endif

#define VECTEUR_H


template <class T>
class Vecteur
{
    public:
        Vecteur(int c = 2);
        ~Vecteur();
        int getCapacite();
        int getTaille();
        void doubler();
        void vider();
        bool estVide();
        void cpyTableau(T **p,T **tableau);
        void afficher(std::ostream &s);
        T *getForme(int index);
        bool addForme(T *p);
        T *rmForme(int index);

    private:
        T **tableau;
        int *taille;
        int *capacite;
};