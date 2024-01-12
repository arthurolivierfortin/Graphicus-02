/********
 * Fichier: forme.h
 * Auteurs: C.-A. Brunet
 * Date: 04 janvier 2024 (creation)
 * Description: Declaration des classes de formes geometriques. La
 *    classe Forme ne doit pas etre modifiee. Ce fichier fait partie de
 *    la distribution de Graphicus.
********/

#define FORME_H


#include <iostream>
#include "coordonnee.h"

class Forme
{
public:
  Forme(int x = 0, int y = 0);
  virtual ~Forme();
  void translater(int deltaX, int deltaY);
  Coordonnee getAncrage();
  void setAncrage(Coordonnee c);
  virtual double aire() = 0;
  virtual void afficher(std::ostream & s) = 0;
protected:
  Coordonnee ancrage;
};

