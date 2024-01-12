#include <iostream>
#include <string>
#include "vecteur.h"


#ifndef COUCHE_H
#define COUCHE_H

#define INITIALISE -1
#define ACTIVE 1
#define INACTIVE 0

class Couche
{
   public:   
      Couche(int capacite);
      ~Couche();
      Forme *Couche::getForme(int index);
      bool Vecteur::addForme(Forme *p);
      Forme *Couche::rmForme(int index);
   private:
      int etat;
      Vecteur vecteur;
      float totalArea();
      
};


#endif
