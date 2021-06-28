#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "BrylaGeometryczna.hh"

#define X_bok 100
#define Y_bok 50
#define Z_bok 50
/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Prostopadloscian
 *   
 *  Klasa dziedziczy klase BrylaGeometryczna. Jako dane prywatne
 *  mamy polozenie w formie wektora3D oraz konta orientacji w formie
 *  double.
 */
class Prostopadloscian:public BrylaGeometryczna{
  Wektor3D Polozenie;
  double KatOrientacji_stopnie;
  public:
  //Prostopadloscian(Wektor3D polozenieD);
  Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
  Wektor3D& polozenie(const Wektor3D polozenieD);
};

#endif
