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
    etat = INITIALISE;
    vecteur = new Vecteur;
}

Couche::~Couche()
{

}


float Couche::totalArea()
{
    float totalArea = 0;

    for(int i=0; i<vecteur->capacite;i++)
    {
        if(vecteur->tableau[i] != NULL)
        {
            totalArea += vecteur->tableau[i]->aire();
        }    
        
    }

    return totalArea;
}

