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

using namespace std;

int main()
{
   Rectangle rectangle_1 = {5,4, 2,1};
   rectangle_1.afficher(std::cout);

   return 0;
}



