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

#include "vecteur.cpp"

Couche::Couche()
{
    etat = new int;
    *etat = INITIALISE;
    vecteur = new Vecteur<Forme>;
}

Couche::~Couche()
{
    //delete etat;
    //delete vecteur;
}


double Couche::totalArea()
{
    float totalArea = 0;

    for(int i=0; i<vecteur->getCapacite();i++)
    {
        if(vecteur->getForme(i) != nullptr)
        {
            totalArea += vecteur->getForme(i)->aire();
        }    
        
    }

    return totalArea;
}

bool Couche::translate(int x2, int y2)
{
    for(int i=0; i<vecteur->getCapacite();i++)
    {
        if(vecteur->getForme(i) != nullptr)
        {
            vecteur->getForme(i)->translater(x2, y2);
        }    
    }

    return true;
}

bool Couche::reset()
{
    for(int i=0; i<vecteur->getCapacite();i++)
    {
        if(vecteur->getForme(i) != nullptr)
        {
            delete vecteur->getForme(i);
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
    for(int i=0; i<vecteur->getCapacite();i++)
    {
        if(vecteur->getForme(i) != nullptr)
        {
            vecteur->getForme(i)->afficher(std::cout);std::cout<<std::endl;
        }    
    }
}

int Couche::getState()
{
    return *etat;
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




