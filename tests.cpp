/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
#include "rectangle.h"

string espace1 = "     ";
string espace2 = "          ";


void printECHEC()
{
   std::cout << "\033[1;31mECHEC\n\033[0m";
}

void printREUSSI()
{
   cout << "\033[1;32mREUSSI\n\033[0m";
}


using namespace std;

void Tests::tests_unitaires_formes()
{  
   cout << "TEST_UNITAIRES_FORMES" << endl;

   cout << espace1 << "TEST_UNITAIRES_RECTANGLE : " << endl;

   //taille normale
   cout << espace2 << "Creation de forme de taille normale : ";
   Rectangle rectangle1 {2, 1};

   if(rectangle1.getLargeur() != 2 || rectangle1.getHauteur() != 1)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {2,1}" << endl;
      cout << espace2 << "-";
      rectangle1.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //taille negative
   cout << espace2 << "Creation de taille négative ou nulle : ";
   Rectangle rectangle2 {-1, -1};

   if(rectangle2.getHauteur() != 1 || rectangle2.getLargeur() != 1)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {1,1}" << endl;
      cout << espace2 << "-";
      rectangle2.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //calcul d'airs
   cout << espace2 << "Calcul d'aire : ";
   Rectangle rectangle3 {2, 4};

   if(rectangle3.aire() != 8)
   {
      printECHEC();
      cout << espace2 <<"-Aire attendu : 8" << endl;
      cout << espace2 << "-";
      rectangle3.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   

   

   //Carre
   //Cercle
}

void Tests::tests_unitaires_vecteur()
{
   // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
