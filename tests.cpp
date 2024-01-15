/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
#include "math.h"


#ifndef RECTANGLE_H
#include "rectangle.h"
#endif

#include "carre.h"

#ifndef CERLCE_H
#include "cercle.h"
#endif

string espace1 = "     ";
string espace2 = "          ";

using namespace std;
void printECHEC()
{
   std::cout << "\033[1;31mECHEC\n\033[0m";
}

void printREUSSI()
{
   std::cout << "\033[1;32mREUSSI\n\033[0m";
}

void tests_unitaires_rectangle()
{
   std::cout << espace1 << "TEST_UNITAIRES_RECTANGLE : " << endl;

   //taille normale
   std::cout << espace2 << "Creation de forme de taille normale et verification des paramètres par défauts: ";
   Rectangle rectangle1 {2, 1};
   Coordonnee r_ancrage1 = rectangle1.getAncrage();

   if(rectangle1.getLargeur() != 2 || rectangle1.getHauteur() != 1 || r_ancrage1.x != 0 || r_ancrage1.y != 0)
   {
      printECHEC();
      std::cout << espace2 <<"-taille attendu : {2,1, 0, 0}" << endl;
      std::cout << espace2 << "-";
      rectangle1.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //taille negative
   std::cout << espace2 << "Creation de taille négative ou nulle : ";
   Rectangle rectangle2 {-1, -1};

   if(rectangle2.getHauteur() != 1 || rectangle2.getLargeur() != 1)
   {
      printECHEC();
      std::cout << espace2 <<"-taille attendu : {1,1}" << endl;
      std::cout << espace2 << "-";
      rectangle2.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //calcul d'airs
   std::cout << espace2 << "Calcul d'aire : ";
   Rectangle rectangle3 {2, 4};

   if(rectangle3.aire() != 8)
   {
      printECHEC();
      std::cout << espace2 <<"-Aire attendu : 8" << endl;
      std::cout << espace2 << "-";
      rectangle3.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //point d'ancrage

   std::cout << espace2 << "Verification point d'ancrage : ";
   Rectangle rectangle4 {3, 1, 3, 6};

   Coordonnee r_ancrage4 = rectangle4.getAncrage();
   if(r_ancrage4.x != 3 || r_ancrage4.y != 6)
   {
      printECHEC();
      std::cout << espace2 <<"-Encrage attendu : {x=3,y=6}" << endl;
      std::cout << espace2 << "-";
      rectangle4.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   std::cout << espace2 << "Changer dimension et point d'ancrage : ";
   Rectangle rectangle5 {3, 1, 4, 6};

   Coordonnee r_ancrage5 = rectangle5.getAncrage();
   if(r_ancrage5.x != 4 || r_ancrage5.y != 6 || rectangle5.getLargeur() != 3 || rectangle5.getHauteur() != 1)
   {
      printECHEC();
      std::cout << espace2 <<"-Dimension : {x=3,y=1,x1=4,y2=6}" << endl;
      std::cout << espace2 << "-";
      rectangle5.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   rectangle5.changeSize(1,2);
   rectangle5.setAncrage({3,4});

   r_ancrage5 = rectangle5.getAncrage();
   if(r_ancrage5.x != 3 || r_ancrage5.y != 4 || rectangle5.getLargeur() != 1 || rectangle5.getHauteur() != 2)
   {
      printECHEC();
      std::cout << espace2 <<"-Dimension : {x=1,y=2,x1=3,y2=4}" << endl;
      std::cout << espace2 << "-";
      rectangle5.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
}

void tests_unitaires_carre()
{
   //Carre

   std::cout << espace1 << "TEST_UNITAIRES_CARRE : " << endl;

   //taille normale
   std::cout << espace2 << "Creation de forme de taille normale et verification des paramètres par défauts: ";
   Carre carre1 {2};
   Coordonnee c_ancrage1 = carre1.getAncrage();

   if(carre1.getLargeur() != 2 || carre1.getHauteur() != 2 || c_ancrage1.x != 0 || c_ancrage1.y != 0)
   {
      printECHEC();
      std::cout << espace2 <<"-taille attendu : {2,2,0,0}" << endl;
      std::cout << espace2 << "-";
      carre1.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //taille negative
   std::cout << espace2 << "Creation de taille négative ou nulle : ";
   Carre carre2 {-3};

   if(carre2.getHauteur() != 1 || carre2.getLargeur() != 1)
   {
      printECHEC();
      std::cout << espace2 <<"-taille attendu : {1,1}" << endl;
      std::cout << espace2 << "-";
      carre2.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //calcul d'airs
   std::cout << espace2 << "Calcul d'aire : ";
   Carre carre3 {6};

   if(carre3.aire() != 36)
   {
      printECHEC();
      std::cout << espace2 <<"-Aire attendu : 36" << endl;
      std::cout << espace2 << "-";
      carre3.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //point d'ancrage

   std::cout << espace2 << "Verification point d'ancrage : ";
   Carre carre4 {3, 4, 3};

   Coordonnee c_ancrage4 = carre4.getAncrage();
   if(c_ancrage4.x != 4 || c_ancrage4.y != 3)
   {
      printECHEC();
      std::cout << espace2 <<"-Encrage attendu : {x=4,y=3}" << endl;
      std::cout << espace2 << "-";
      carre4.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
   
   //Changer dimension et point d'ancrage
   std::cout << espace2 << "Changer dimension et point d'ancrage : ";
   Carre carre5 {3, 4, 6};

   Coordonnee c_ancrage5 = carre5.getAncrage();
   if(c_ancrage5.x != 4 || c_ancrage5.y != 6 || carre5.getLargeur() != 3 || carre5.getHauteur() != 3)
   {
      printECHEC();
      std::cout << espace2 <<"-Dimension : {x=3,y=3,x1=4,y2=6}" << endl;
      std::cout << espace2 << "-";
      carre5.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   carre5.changeSize(1);
   carre5.setAncrage({3,4});

   c_ancrage5 = carre5.getAncrage();
   if(c_ancrage5.x != 3 || c_ancrage5.y != 4 || carre5.getLargeur() != 1 || carre5.getHauteur() != 1)
   {
      printECHEC();
      std::cout << espace2 <<"-Dimension : {x=1,y=1,x1=3,y2=4}" << endl;
      std::cout << espace2 << "-";
      carre5.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
}

void tests_unitaires_cercle()
{
   //Cercle

   std::cout << espace1 << "TEST_UNITAIRES_CERCLE : " << endl;

   //taille normale
   std::cout << espace2 << "Creation de forme de taille normale et verification des paramètres par défauts: ";
   Cercle cercle1 {2};
   Coordonnee ce_ancrage1 = cercle1.getAncrage();

   if(cercle1.getRayon()  != 2 || ce_ancrage1.x != 0 || ce_ancrage1.y != 0)
   {
      printECHEC();
      std::cout << espace2 <<"-taille attendu : {r=2,x1=0,y1=0}" << endl;
      std::cout << espace2 << "-";
      cercle1.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //taille negative
   std::cout << espace2 << "Creation de taille négative ou nulle : ";
   Cercle cercle2 {-3};

   if(cercle2.getRayon() != 1)
   {
      printECHEC();
      std::cout << espace2 <<"-taille attendu : {r=-3,x1=0,y1=0}" << endl;
      std::cout << espace2 << "-";
      cercle2.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //calcul d'airs
   std::cout << espace2 << "Calcul d'aire : ";
   Cercle cercle3 {2};

   if(cercle3.aire() != 4*(M_PI))
   {
      printECHEC();
      std::cout << espace2 <<"-Aire attendu : 12.56637" << endl;
      std::cout << espace2 << "-";
      cercle3.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //point d'ancrage

   std::cout << espace2 << "Verification point d'ancrage : ";
   Cercle cerlce4 {3, 4, 3};

   Coordonnee ce_ancrage4 = cerlce4.getAncrage();
   if(ce_ancrage4.x != 4 || ce_ancrage4.y != 3)
   {
      printECHEC();
      std::cout << espace2 <<"-Encrage attendu : {x=4,y=3}" << endl;
      std::cout << espace2 << "-";
      cerlce4.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
   
   //Changer dimension et point d'ancrage
   std::cout << espace2 << "Changer dimension et point d'ancrage : ";
   Cercle cercle5 {3, 4, 6};

   Coordonnee ce_ancrage5 = cercle5.getAncrage();
   if(ce_ancrage5.x != 4 || ce_ancrage5.y != 6 || cercle5.getRayon() != 3)
   {
      printECHEC();
      std::cout << espace2 <<"-Dimension : {r=3,x1=4,y2=6}" << endl;
      std::cout << espace2 << "-";
      cercle5.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   cercle5.changeSize(1);
   cercle5.setAncrage({3,4});

   ce_ancrage5 = cercle5.getAncrage();
   if(ce_ancrage5.x != 3 || ce_ancrage5.y != 4 || cercle5.getRayon() != 1)
   {
      printECHEC();
      std::cout << espace2 <<"-Dimension : {r=1,x1=3,y2=4}" << endl;
      std::cout << espace2 << "-";
      cercle5.afficher(std::cout);
      std::cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
}


void Tests::tests_unitaires_formes()
{  
   std::cout << "TEST_UNITAIRES_FORMES" << endl;

   tests_unitaires_rectangle();
   tests_unitaires_carre();
   tests_unitaires_cercle();
    
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
   std::cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   std::cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
