/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include <iostream>
#include "tests.h"
#include "rectangle.h"

#ifndef COUCHE_H
#include "couche.h"
#endif

#ifndef VECTEUR_H
#include "vecteur.h"
#endif



using namespace std;

int main()
{
   Tests test;

   //test.tests_unitaires_formes();
   test.tests_application_cas_01();

   return 0;
}



