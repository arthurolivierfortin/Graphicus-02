#include <iostream>
#define COUCHE_H

#include "vecteur.h"






#define INITIALISE -1
#define ACTIVE 1
#define INACTIVE 0

class Couche
{
   public:
      Couche();
      virtual ~Couche();
      virtual Forme *getForme(int index);
      virtual bool addForme(Forme *p);
      virtual Forme *rmForme(int index);
      int etat;
      float totalArea();
      Vecteur *vecteur;
      
};



