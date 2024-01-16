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
   cout << "\033[1;31mECHEC\n\033[0m";
}

void printREUSSI()
{
   cout << "\033[1;32mREUSSI\n\033[0m";
}

void tests_unitaires_rectangle()
{
   cout << espace1 << "TEST_UNITAIRES_RECTANGLE : " << endl;

   //taille normale
   cout << espace2 << "Creation de forme de taille normale et verification des paramètres par défauts: ";
   Rectangle rectangle1 {0, 0, 2, 1};
   Coordonnee r_ancrage1 = rectangle1.getAncrage();

   if(rectangle1.getLargeur() != 2 || rectangle1.getHauteur() != 1 || r_ancrage1.x != 0 || r_ancrage1.y != 0)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {0,0, 2, 1}" << endl;
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
   Rectangle rectangle2 {0,0,-1, -1};

   if(rectangle2.getHauteur() != 1 || rectangle2.getLargeur() != 1)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {0,0,-1,-1}" << endl;
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
   Rectangle rectangle3 {0,0,2, 4};

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

   //point d'ancrage

   cout << espace2 << "Verification point d'ancrage : ";
   Rectangle rectangle4 {3, 6, 3, 1};

   Coordonnee r_ancrage4 = rectangle4.getAncrage();
   if(r_ancrage4.x != 3 || r_ancrage4.y != 6)
   {
      printECHEC();
      cout << espace2 <<"-Encrage attendu : {x=3,y=6}" << endl;
      cout << espace2 << "-";
      rectangle4.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   cout << espace2 << "Changer dimension et point d'ancrage : ";
   Rectangle rectangle5 {4, 6, 3, 1};

   Coordonnee r_ancrage5 = rectangle5.getAncrage();
   if(r_ancrage5.x != 4 || r_ancrage5.y != 6 || rectangle5.getLargeur() != 3 || rectangle5.getHauteur() != 1)
   {
      printECHEC();
      cout << espace2 <<"-Dimension : {x1=4,y2=6,l=3,h=1,}" << endl;
      cout << espace2 << "-";
      rectangle5.afficher(cout);
      cout << "\n" << endl;
   }

   rectangle5.changeSize(1,2);
   rectangle5.setAncrage({3,4});

   r_ancrage5 = rectangle5.getAncrage();
   if(r_ancrage5.x != 3 || r_ancrage5.y != 4 || rectangle5.getLargeur() != 1 || rectangle5.getHauteur() != 2)
   {
      printECHEC();
      cout << espace2 <<"-Dimension : {x1=3,y2=4,x=1,y=2,}" << endl;
      cout << espace2 << "-";
      rectangle5.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
}

void tests_unitaires_carre()
{
   //Carre

   cout << espace1 << "TEST_UNITAIRES_CARRE : " << endl;

   //taille normale
   cout << espace2 << "Creation de forme de taille normale et verification des paramètres par défauts: ";
   Carre carre1 {0,0,2};
   Coordonnee c_ancrage1 = carre1.getAncrage();

   if(carre1.getLargeur() != 2 || carre1.getHauteur() != 2 || c_ancrage1.x != 0 || c_ancrage1.y != 0)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {0,0,2,2}" << endl;
      cout << espace2 << "-";
      carre1.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //taille negative
   cout << espace2 << "Creation de taille négative ou nulle : ";
   Carre carre2 {0,0,-3};

   if(carre2.getHauteur() != 1 || carre2.getLargeur() != 1)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {1,1}" << endl;
      cout << espace2 << "-";
      carre2.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //calcul d'airs
   cout << espace2 << "Calcul d'aire : ";
   Carre carre3 {0,0,6};

   if(carre3.aire() != 36)
   {
      printECHEC();
      cout << espace2 <<"-Aire attendu : 36" << endl;
      cout << espace2 << "-";
      carre3.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //point d'ancrage

   cout << espace2 << "Verification point d'ancrage : ";
   Carre carre4 {4, 3, 3};

   Coordonnee c_ancrage4 = carre4.getAncrage();
   if(c_ancrage4.x != 4 || c_ancrage4.y != 3)
   {
      printECHEC();
      cout << espace2 <<"-Encrage attendu : {x=4,y=3}" << endl;
      cout << espace2 << "-";
      carre4.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
   
   //Changer dimension et point d'ancrage
   cout << espace2 << "Changer dimension et point d'ancrage : ";
   Carre carre5 {4, 6, 3};

   Coordonnee c_ancrage5 = carre5.getAncrage();
   if(c_ancrage5.x != 4 || c_ancrage5.y != 6 || carre5.getLargeur() != 3 || carre5.getHauteur() != 3)
   {
      printECHEC();
      cout << espace2 <<"-Dimension : {4, 6, 3}" << endl;
      cout << espace2 << "-";
      carre5.afficher(cout);
      cout << "\n" << endl;
   }

   carre5.changeSize(1);
   carre5.setAncrage({3,4});

   c_ancrage5 = carre5.getAncrage();
   if(c_ancrage5.x != 3 || c_ancrage5.y != 4 || carre5.getLargeur() != 1 || carre5.getHauteur() != 1)
   {
      printECHEC();
      cout << espace2 <<"-Dimension : {x1=3,y2=4, l=1}" << endl;
      cout << espace2 << "-";
      carre5.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
}

void tests_unitaires_cercle()
{
   //Cercle

   cout << espace1 << "TEST_UNITAIRES_CERCLE : " << endl;

   //taille normale
   cout << espace2 << "Creation de forme de taille normale et verification des paramètres par défauts: ";
   Cercle cercle1 {0,0,2};
   Coordonnee ce_ancrage1 = cercle1.getAncrage();

   if(cercle1.getRayon()  != 2 || ce_ancrage1.x != 0 || ce_ancrage1.y != 0)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {x1=0,y1=0,r=2}" << endl;
      cout << espace2 << "-";
      cercle1.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //taille negative
   cout << espace2 << "Creation de taille négative ou nulle : ";
   Cercle cercle2 {0,0,-3};

   if(cercle2.getRayon() != 1)
   {
      printECHEC();
      cout << espace2 <<"-taille attendu : {x1=0,y1=0,r=-3}" << endl;
      cout << espace2 << "-";
      cercle2.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //calcul d'airs
   cout << espace2 << "Calcul d'aire : ";
   Cercle cercle3 {0,0,2};

   if(cercle3.aire() != 4*(M_PI))
   {
      printECHEC();
      cout << espace2 <<"-Aire attendu : 12.56637" << endl;
      cout << espace2 << "-";
      cercle3.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }

   //point d'ancrage

   cout << espace2 << "Verification point d'ancrage : ";
   Cercle cerlce4 {4, 3, 3};

   Coordonnee ce_ancrage4 = cerlce4.getAncrage();
   if(ce_ancrage4.x != 4 || ce_ancrage4.y != 3)
   {
      printECHEC();
      cout << espace2 <<"-Encrage attendu : {x=4,y=3}" << endl;
      cout << espace2 << "-";
      cerlce4.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
   
   //Changer dimension et point d'ancrage
   cout << espace2 << "Changer dimension et point d'ancrage : ";
   Cercle cercle5 {4, 6, 3};

   Coordonnee ce_ancrage5 = cercle5.getAncrage();
   if(ce_ancrage5.x != 4 || ce_ancrage5.y != 6 || cercle5.getRayon() != 3)
   {
      printECHEC();
      cout << espace2 <<"-Dimension : {x1=4, y1=6, r=3}" << endl;
      cout << espace2 << "-";
      cercle5.afficher(cout);
      cout << "\n" << endl;
   }

   cercle5.changeSize(1);
   cercle5.setAncrage({3,4});

   ce_ancrage5 = cercle5.getAncrage();
   if(ce_ancrage5.x != 3 || ce_ancrage5.y != 4 || cercle5.getRayon() != 1)
   {
      printECHEC();
      cout << espace2 <<"-Dimension : {x1=3,y2=4,r=1}" << endl;
      cout << espace2 << "-";
      cercle5.afficher(cout);
      cout << "\n" << endl;
   }

   else
   {
      printREUSSI();
   }
}


void Tests::tests_unitaires_formes()
{  
   cout << "TEST_UNITAIRES_FORMES" << endl;

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
   cout << "TESTS APPLICATION (CAS 01)" << endl;
   
   cout << espace1 << "ETAPE1-creation de trois formes et activation couche 2: " << endl;

   Canevas canevas1;


   canevas1.activerCouche(2);
   
   Cercle cercle1 {0,1,5};
   Cercle *p_cercle1 = &cercle1;
   Carre carre1 {1,2,6};
   Carre *p_carre1 = &carre1; 
   Rectangle rectangle1 {2,3,4,9};
   Rectangle *p_rectangle1 = &rectangle1;
  
   canevas1.ajouterForme(p_cercle1);
   canevas1.ajouterForme(p_carre1);
   canevas1.ajouterForme(p_rectangle1);
   
   cout << "=================================" << endl;
   cout <<  "\najouts de formes:" << endl;
   cout << "cercle1 {0,1,5}" << endl;
   cout << "carre1 {1,2,6}" << endl;
   cout << "rectangle1 {2,3,4,9}\n" << endl;
   canevas1.afficher(cout);
   cout << endl; 
   cout << "=================================" << endl;

   cout << espace1 << "\nETAPE2 et ETAPE3-activer la couche 1 et y ajouter une forme: " << endl;

   canevas1.activerCouche(1);
   
   Rectangle rectangle2 {0,0,12,3};
   Rectangle *p_rectangle2 = &rectangle2;


   canevas1.ajouterForme(p_rectangle2);
   
   cout << "=================================" << endl;
   cout <<  "\najouts de formes:" << endl;
   cout << "rectangle2 {0,0,12,3}\n" << endl;
   canevas1.afficher(cout);
   cout << endl;
   cout << espace1 << "\nETAPE4-afficher l'aire: " << endl;
   cout << canevas1.aire() << endl;
   cout << "=================================" << endl;
   

   cout << espace1 << "\nETAPE5-activer la couche 0 et y ajouter trois forme : " << endl;

   canevas1.activerCouche(0);
   
   Cercle cercle3 {0,0,1};
   Cercle *p_cercle3 = &cercle3;
   Carre carre3 {0,0,1};
   Carre *p_carre3 = &carre3; 
   Rectangle rectangle3 {0,0,1,1};
   Rectangle *p_rectangle3 = &rectangle3;


   canevas1.activerCouche(0);

   canevas1.ajouterForme(p_rectangle3);
   canevas1.ajouterForme(p_carre3);
   canevas1.ajouterForme(p_cercle3);

   cout << espace1 << "\nETAPE6-activer la couche 2 et faire une translation de (x=2, y=1) : " << endl;

   canevas1.activerCouche(2);

   canevas1.translater(2,1);

   cout << espace1 << "\nETAPE7-afficher le canevas : " << endl;

   cout << "=================================" << endl;
   cout <<  "\najouts de formes dans couche 0 et translation dans couche 2 :" << endl;
   cout << "cercle1 {0,0,1}" << endl;
   cout << "carre1 {0,0,1}" << endl;
   cout << "rectangle1 {0,0,1,1}\n" << endl;
   canevas1.afficher(cout);
   cout << endl;
   cout << espace1 << "\nETAPE4-afficher l'aire: " << endl;
   cout << canevas1.aire() << endl; 
   cout << "=================================" << endl;

   cout << espace1 << "\nETAPE9-activer la couche 0 et retirer la deuxième forme de la couche : " << endl;

   canevas1.retirerForme(1);

   cout << espace1 << "\nETAPE10-réinitialiser la couche 1 : " << endl;
   canevas1.reinitialiserCouche(1);

   cout << espace1 << "\nETAPE11-Activer la couche 4 : " << endl;
   canevas1.activerCouche(4);

   cout << espace1 << "\nETAPE12-Afficher le canevas : " << endl;
   canevas1.afficher(cout);

   cout << espace1 << "\nETAPE13-afficher l'aire: " << endl;
   cout << canevas1.aire() << endl;

   cout << espace1 << "\nETAPE14-Réinitialiser le canevas: " << endl;
   canevas1.reinitialiser();

   cout << espace1 << "\nETAPE15-Afficher le canevas : " << endl;
   canevas1.afficher(cout);

   cout << espace1 << "\nETAPE16-afficher l'aire: " << endl;
   cout << canevas1.aire() << endl;

   cout << espace1 << "\nETAPE17-activer la couche 3 et ajouter deux formes: " << endl;
   cout << canevas1.aire() << endl;

   cout <<  "\najouts de formes dans couche 3 :" << endl;
   cout << "carre1 {0,0,1}" << endl;
   cout << "Forme NULL" << endl;

   Carre carre4 {10,10,10};
   Carre *p_carre4 = &carre4;

   canevas1.ajouterForme(p_carre3);
   canevas1.ajouterForme(NULL);


   cout << espace1 << "\nETAPE18-activer la couche 6: " << endl;
   canevas1.activerCouche(6);

   cout << espace1 << "\nETAPE19-afficher le canevas: " << endl;
   canevas1.afficher(cout);

   cout << espace1 << "\nETAPE20-afficher l'aire: " << endl;
   cout << canevas1.aire() << endl;
   
   
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
   
   

   
}
