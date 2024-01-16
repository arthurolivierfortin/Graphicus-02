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
   
}

Canevas::~Canevas()
{
   //delete etatCouche;
   //delete couches;
}

bool Canevas::reinitialiser()
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      couches[i].reset();
   }

   
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   
   if(index < 0 || index > MAX_COUCHES-1)
   {
      return false;
   }


   if(couches[index].getState() != ACTIVE)
   {
      couches[index].reset();

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
      if(couches[i].getState() == ACTIVE)
      {
         if(index == i)
         {
            return true;
         }


         couches[i].changeState(INACTIVE);
         break;
      }
   }

   couches[index].changeState(ACTIVE);

   
   return true;
}

bool Canevas::desactiverCouche(int index)
{
   //En ce moment c'est possible de ne pas avoir de couche active
   if(index < 0 || index > MAX_COUCHES-1)
   {
      return false;
   }

   if(couches[index].getState() == ACTIVE)
   {
      couches[index].changeState(INACTIVE);
   }
   
   return true;
}

bool Canevas::ajouterForme(Forme *p_forme)
{
   if(p_forme == NULL)
   {
      return false;
   }
   
   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(couches[i].getState() == ACTIVE)
      {
         couches[i].addForme(p_forme);
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
      if(couches[index].getState() == ACTIVE)
      {
         if(couches->getForme(index) == nullptr)
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
      if(couches[i].getState() != INITIALISE)
      {
         totalArea += couches[i].totalArea();
      }
   }

   return totalArea;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   for(int i=0; i<MAX_COUCHES; i++)
   {
      if(couches[i].getState() == ACTIVE)
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
      cout << "----- Couche " << i << " -----" << endl;
      cout << "État: ";

      if(couches[i].getState() == INITIALISE)
      {
         cout << "Initialisée" << endl;
      }

      if(couches[i].getState() == ACTIVE)
      {
         cout << "Active" << endl;
      }

      if(couches[i].getState() == INACTIVE)
      {
         cout << "Inactive" << endl;
      }
      couches[i].printCouche();
   }
   
}
