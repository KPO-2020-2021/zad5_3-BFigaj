#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH


#include <iostream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"

/*!
 * \brief Klasa figury geometrycznej
 *
 *  Modeluje pojecie figury geometrycznej.
 */
class BrylaGeometryczna {
  std::string NazwaPliku_BrylaWzorcowa;
  std::string NazwaPliku_BrylaFinalna;
  Wektor3D Skala;
  public:
  Wektor3D& StworzSkale(Wektor3D skala);
  Wektor3D Skaluj(const Wektor3D& Wierz)const;
  const std::string& WezNazwePliku_BrylaWzorcowa()const;
  const std::string& WezNazwePliku_BrylaFinalna()const;
  void NazwaplikuW(int nazwa,int ktory);
  void NazwaplikuF(int nazwa,int ktory);
  void NazwaplikuW(std::string nazwa);
  void NazwaplikuF(std::string nazwa);
  virtual bool Tworz(Wektor3D polozenie,Wektor3D skala)
  {
    std::cout << polozenie << " , " << skala << std::endl;
    return false;
  }
  virtual bool Pokrywanie(Wektor3D polozenie1, double promien)
  {
    std::cout << polozenie1 << " , " << promien << std::endl;
    return false;
  }
};

#endif