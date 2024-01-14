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
      double totalArea();
      bool translate(int x2, int y2);
      bool reset();
      bool changeState(int state);
      void printCouche();
      Forme *getForme(int index);
      bool addForme(Forme *p);
      Forme *rmForme(int index);
   
   private:
      Vecteur<Forme> *vecteur;
      int *etat;
      
};



