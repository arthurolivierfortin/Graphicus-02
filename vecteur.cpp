
#include <iostream>

#ifndef VECTEUR_H
#define VECTEUR_H
#include "vecteur.h"
#endif

#ifndef FORME_H
#include "forme.h"
#endif



Vecteur::Vecteur(int c)
{
    capacite = new int;
    *capacite = c;
    taille = new int;
    tableau = new Forme*[*capacite];

    taille = 0;
}

Vecteur::~Vecteur()
{
    delete tableau;
}

void Vecteur::cpyTableau(Forme **p, Forme **tableau)
{
    for(int i=0; i<*capacite; i++)
    {
        tableau[i] = p[i];
    }

    delete tableau;
    tableau = p;
}

void Vecteur::doubler()
{
    Forme **p_t = new Forme*[*capacite*2];

    for(int i=0; i<*capacite*2; i++)
    {
        p_t[i] = nullptr;
    }

    cpyTableau(tableau, p_t);

    *capacite *= 2;

}

void  Vecteur::vider()
{
    for(int i=0; i<*taille; i++)
    {   
        if(tableau[i] != nullptr)
        {
            delete tableau[i];
            tableau[i] = nullptr;
        }
        
    }

    taille = 0;
}

bool Vecteur::estVide()
{
    for(int i=0; i<*capacite; i++)
    {
        if(tableau[i] != nullptr)
        {
            return false;
        }
    }

    return true;
}



void Vecteur::afficher(std::ostream &s)
{
    for(int i=0; i<*capacite; i++)
    {
        tableau[i]->afficher(s);
    }
}

int Vecteur::getCapacite()
{
   return *capacite;
}

int Vecteur::getTaille()
{
   return *taille;
}

Forme *Vecteur::getForme(int index)
{
    Forme *p = nullptr;
    
    if(tableau[index] == nullptr || index < 0 || index > *capacite-1)
    {
        return p;
    }

    p = tableau[index];

    return p;
}

bool Vecteur::addForme(Forme *p)
{
    if(*taille == *capacite)
    {
        doubler();
    }

    tableau[*taille+1] = p;

    taille++;

    return true;
}

Forme *Vecteur::rmForme(int index)
{
    Forme *p = nullptr;
    if(index < 0 || index > *capacite-1)
    {
        return p;
    }

    p = tableau[index];

    delete tableau[index];
    tableau[index] = nullptr;

    Forme **pt = new Forme*[*capacite];
    
    int y = 0;
    for(int i=0; i<*capacite; i++)
    {
        if(tableau[i] == nullptr)
        {
            continue;
        }

        pt[y++] = tableau[i];
    }

    cpyTableau(pt, tableau);

    taille--;

    return p;
}


