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

bool Vecteur::ajouter(Forme *p)
{
    if(taille == capacite)
    {
        doubler();
    }

    tableau[taille+1] = p;

    taille++;

    return true;
}

Forme *Vecteur::retirer(int index)
{
    Forme *p = NULL;
    if(index < 0 || index > capacite-1)
    {
        return p;
    }

    p = tableau[index];

    delete tableau[index];
    tableau[index] = NULL;

    Forme **pt = new Forme*[capacite];
    
    int y = 0;
    for(int i=0; i<capacite; i++)
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

Forme *Vecteur::obtenir(int index)
{
    Forme *p = NULL;
    
    if(tableau[index] == NULL || index < 0 || index > capacite-1)
    {
        return p;
    }

    p = tableau[index];

    return p;
}

void Vecteur::afficher(ostream &s)
{
    for(int i=0; i<capacite; i++)
    {
        tableau[i]->afficher(s);
    }
}

