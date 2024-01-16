
#include <iostream>

#ifndef VECTEUR_H
#define VECTEUR_H
#include "vecteur.h"
#endif

#ifndef FORME_H
#include "forme.h"
#endif

template <class T>
Vecteur<T>::Vecteur(int c)
{
    capacite = new int;
    *capacite = c;
    taille = new int;

    tableau = new T*[*capacite];

    *taille = 0;
}

template <class T>
Vecteur<T>::~Vecteur()
{
    //delete tableau;
    //delete capacite;
    //delete taille;
}

template <class T>
void Vecteur<T>::cpyTableau(T **p, T **tableau)
{
    for(int i=0; i<*capacite; i++)
    {
        tableau[i] = p[i];
    }

    delete tableau;
    tableau = p;
}

template <class T>
void Vecteur<T>::doubler()
{
    
    T **p_t = new T*[*capacite*2];

    for(int i=0; i<*capacite*2; i++)
    {
        p_t[i] = nullptr;
    }

    cpyTableau(tableau, p_t);

    *capacite *= 2;

}

template <class T>
void  Vecteur<T>::vider()
{
    for(int i=0; i<*taille; i++)
    {   
        if(tableau[i] != nullptr)
        {
            delete tableau[i];
            tableau[i] = nullptr;
        }
        
    }

    taille = 0;
}

template <class T>
bool Vecteur<T>::estVide()
{
    for(int i=0; i<*capacite; i++)
    {
        if(tableau[i] != nullptr)
        {
            return false;
        }
    }

    return true;
}


template <class T>
void Vecteur<T>::afficher(std::ostream &s)
{
    for(int i=0; i<*capacite; i++)
    {
        tableau[i]->afficher(s);
    }
}

template <class T>
int Vecteur<T>::getCapacite()
{
   return *capacite;
}

template <class T>
int Vecteur<T>::getTaille()
{
   return *taille;
}

template <class T>
T *Vecteur<T>::getForme(int index)
{
    T *p = nullptr;
    
    if(tableau[index] == nullptr || index < 0 || index > *capacite-1)
    {
        return p;
    }

    p = tableau[index];

    return p;
}

template <class T>
bool Vecteur<T>::addForme(T *p)
{
    if(*taille == *capacite)
    {
       doubler();
    }

    tableau[(*taille)+1] = p;
    
    *taille += 1;
    
    return true;
}

template <class T>
T *Vecteur<T>::rmForme(int index)
{
    T *p = nullptr;
    if(index < 0 || index > *capacite-1)
    {
        return p;
    }

    p = tableau[index];

    delete tableau[index];
    tableau[index] = nullptr;

    T **pt = new T*[*capacite];
    
    int y = 0;
    for(int i=0; i<*capacite; i++)
    {
        if(tableau[i] == nullptr)
        {
            continue;
        }

        pt[y++] = tableau[i];
    }

    cpyTableau(pt, tableau);

    taille--;

    return p;
}


