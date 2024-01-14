/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H
#include "couche.h"
#endif

Couche::Couche()
{
    etat = new int;
    *etat = INITIALISE;
    vecteur = new Vecteur;
}

Couche::~Couche()
{

}


double Couche::totalArea()
{
    float totalArea = 0;

    for(int i=0; i<*vecteur->capacite;i++)
    {
        if(vecteur->tableau[i] != nullptr)
        {
            totalArea += vecteur->tableau[i]->aire();
        }    
        
    }

    return totalArea;
}

bool Couche::translate(int x2, int y2)
{
    for(int i=0; i<*vecteur->capacite;i++)
    {
        if(vecteur->tableau[i] != nullptr)
        {
            vecteur->tableau[i]->translater(x2, y2);
        }    
    }

    return true;
}

bool Couche::reset()
{
    for(int i=0; i<*vecteur->capacite;i++)
    {
        if(vecteur->tableau[i] != nullptr)
        {
            delete vecteur->tableau[i];
        }    
    }

    *etat = INITIALISE;

    return true;
}

bool Couche::changeState(int state)
{
    *etat = state;
    return true; 
}

void Couche::printCouche()
{
    for(int i=0; i<*vecteur->capacite;i++)
    {
        if(vecteur->tableau[i] != nullptr)
        {
            vecteur->tableau[i]->afficher(std::cout);
        }    
    }
}

Forme *Couche::getForme(int index)
{
    return vecteur->getForme(index);
}

bool Couche::addForme(Forme *p)
{
    vecteur->addForme(p);
    return true;
}

Forme *Couche::rmForme(int index)
{
    return vecteur->rmForme(index);
}




