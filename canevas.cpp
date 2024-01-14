/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
   couches[0].changeState(ACTIVE);

   for(int i=1; i<MAX_COUCHES; i++)
   {
      couches[i].changeState(INITIALISE);
   }
   
   etatCouche = new int[MAX_COUCHES];
   etatCouche[0] = ACTIVE;
   for (int i=1; i<5; i++) {
      etatCouche[i] = INITIALISE;
   }
}

Canevas::~Canevas()
{
}

bool Canevas::reinitialiser()
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      couches[i].reset();
   }

   etatCouche[0] = ACTIVE;
   for (int i=1; i<5; i++) {
      etatCouche[i] = INITIALISE;
   }
   
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   
   if(index < 0 || index > MAX_COUCHES-1)
   {
      return false;
   }

   if(etatCouche[index] != ACTIVE)
   {
      couches[index].reset();
      etatCouche[index] = INITIALISE;
   }

   else
   {
      couches[index].reset();
      couches[index].changeState(ACTIVE);
   }
   
   return true;
}

bool Canevas::activerCouche(int index)
{
   if(index < 0 || index > MAX_COUCHES-1)
   {
      return false;
   }

   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(etatCouche[i] == ACTIVE)
      {
         if(index == i)
         {
            return true;
         }

         couches[i].changeState(INACTIVE);
         etatCouche[i] = INACTIVE;
         break;
      }
   }

   couches[index].changeState(ACTIVE);
   etatCouche[index] = ACTIVE;
   
   return true;
}

bool Canevas::desactiverCouche(int index)
{
   //En ce moment c'est possible de ne pas avoir de couche active
   if(index < 0 || index > MAX_COUCHES-1)
   {
      return false;
   }

   if(etatCouche[index] == ACTIVE)
   {
      couches[index].changeState(INACTIVE);
   }
   
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(etatCouche[i] = ACTIVE)
      {
         couches->addForme(p_forme);
         break;
      }

      if(i == MAX_COUCHES-1)
      {
         return false;
      }
   }

   return true;
}

bool Canevas::retirerForme(int index)
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(etatCouche[i] = ACTIVE)
      {
         if(couches->getForme(index) == NULL)
         {
            return false;
         }
         couches->rmForme(index);
         break;
      }

      if(i == MAX_COUCHES-1)
      {
         return false;
      }
   }
   return true;
}

double Canevas::aire()
{
   float totalArea = 0;

   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(etatCouche[i] != INITIALISE)
      {
         totalArea += couches[i].totalArea();
      }
   }
}

bool Canevas::translater(int deltaX, int deltaY)
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(etatCouche[i] == ACTIVE)
      {
         couches[i].translate(deltaX, deltaY);
      }

      if(i == MAX_COUCHES-1)
      {
         return false;
      }
   }
   
   return true;
}

void Canevas::afficher(ostream & s)
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      couches[i].printCouche();
   }
   
}
