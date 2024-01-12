/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche(int capacite)
{
    etat = INITIALISE;
}

Couche::~Couche()
{

}

Forme *Couche::getForme(int index)
{
    Forme *p = NULL;
    
    if(tableau[index] == NULL || index < 0 || index > capacite-1)
    {
        return p;
    }

    p = tableau[index];

    return p;
}

bool Vecteur::addForme(Forme *p)
{
    if(taille == capacite)
    {
        doubler();
    }

    tableau[taille+1] = p;

    taille++;

    return true;
}

Forme *Couche::rmForme(int index)
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

float Couche::Couche()
{
    float totalArea = 0;

    for(int i=0; i<vecteur->capacite;i++)
    {
        totalArea += vecteur->
    }
}

