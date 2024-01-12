
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
    tableau = new Vecteur*[*capacite];

    taille = 0;
}

Vecteur::~Vecteur()
{
    delete tableau;
}

void Vecteur::cpyTableau(Vecteur **p, Vecteur **tableau)
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
    Vecteur **p_t = new Vecteur*[*capacite*2];

    for(int i=0; i<*capacite*2; i++)
    {
        p_t[i] = NULL;
    }

    cpyTableau(tableau, p_t);

    *capacite *= 2;

}

void  Vecteur::vider()
{
    for(int i=0; i<*taille; i++)
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
    for(int i=0; i<*capacite; i++)
    {
        if(tableau[i] != NULL)
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
        *tableau[i]->afficher(s);
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

double *Vecteur::getForme(int index)
{
    Forme *p = NULL;
    
    if(tableau[index] == NULL || index < 0 || index > *capacite-1)
    {
        return p;
    }

    p = tableau[index];

    return p;
}

bool Vecteur::addForme(double *p)
{
    if(*taille == *capacite)
    {
        doubler();
    }

    tableau[*taille+1] = p;

    taille++;

    return true;
}

double *Vecteur::rmForme(int index)
{
    Forme *p = NULL;
    if(index < 0 || index > *capacite-1)
    {
        return p;
    }

    p = tableau[index];

    delete tableau[index];
    tableau[index] = NULL;

    double **pt = new double*[*capacite];
    
    int y = 0;
    for(int i=0; i<*capacite; i++)
    {
        if(tableau[i] == NULL)
        {
            continue;
        }

        pt[y++] = tableau[i];
    }

    cpyTableau(pt, tableau);

    taille--;

    return p;
}


