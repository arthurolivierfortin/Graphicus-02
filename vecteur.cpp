#include "vecteur.h"
#include <iostream>


Vecteur::Vecteur(int c)
: capacite(c)
{
    tableau = new Forme*[capacite];

    taille = 0;
}

Vecteur::~Vecteur()
{
    delete tableau;
}

void Vecteur::cpyTableau(Forme **p, Forme **tableau)
{
    for(int i=0; i<capacite; i++)
    {
        tableau[i] = p[i];
    }

    delete tableau;
    tableau = p;
}

void Vecteur::doubler()
{
    Forme **p_t = new Forme*[capacite*2];

    for(int i=0; i<capacite*2; i++)
    {
        p_t[i] = NULL;
    }

    cpyTableau(tableau, p_t);

    capacite *= 2;

}

void  Vecteur::vider()
{
    for(int i=0; i<taille; i++)
    {   
        if(tableau[i] != NULL)
        {
            delete tableau[i];
            tableau[i] = NULL;
        }
        
    }

    taille = 0;
}

bool Vecteur::estVide()
{
    for(int i=0; i<capacite; i++)
    {
        if(tableau[i] != NULL)
        {
            return false;
        }
    }

    return true;
}



void Vecteur::afficher(ostream &s)
{
    for(int i=0; i<capacite; i++)
    {
        tableau[i]->afficher(s);
    }
}

int Vecteur::getCapacite()
{
   return capacite;
}

int Vecteur::getTaille()
{
   return taille;
}


