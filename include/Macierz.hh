#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include <assert.h>

/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Macierz<>
 *
 */




/*!
 * \brief  Ogólny szablon Macierz<>
 *  
 *  Modeluje pojecie macierzy o dowolnym rozmiarze.
 *  Przyjmuje wymiar jako int.
 *  Prywatne:
 *  -tablica zależna od wymiaru
 *  Publiczne:
 *  -konstruktor bezparametryczny
 *  -konstruktor parametryczny
 *  -przeciążenie operatora() wersja const
 *  -przeciążenie operatora() wersja z referencją
 */
template <int Wymiar>
class Macierz{
  private:
   double _Mat[Wymiar][Wymiar];
  public:
   Macierz();
   Macierz(double x);
   double operator()(unsigned int ver,unsigned int col) const
   {
    /*if(ver >= Wymiar || col >= Wymiar)
    {
      std::cerr << "Zly wybor parametrow" << std::endl;
      assert(ver < Wymiar || col < Wymiar);
      return _Mat[ver][col];
    }
    else*/
    return _Mat[ver][col];
   }
   double& operator()(unsigned int ver,unsigned int col)
   {
    /*if(ver >= Wymiar || col >= Wymiar)
    {
      std::cerr << "Zly wybor parametrow" << std::endl;
      assert(ver < Wymiar || col < Wymiar);
      return _Mat[ver][col];
    }
    else*/
    return _Mat[ver][col];
   }
};

/*!
 * \brief KOnstruktor bezparametryczny macierzy
 * 
 * Wypełnia macierz o zadanym wymiarze zerami
 */
template <int Wymiar>
Macierz<Wymiar>::Macierz()
{
  int i,j;
  for(i=0;i<Wymiar;++i)
  {
   for(j=0;j<Wymiar;++j)
    {
      this->_Mat[i][j]=0;
    }
  }
}

/*!
 * \brief KOnstruktor parametryczny macierzy
 * 
 * Wypełnia macierz o zadanym wymiarze przyjmowanymi liczbami
 * Przyjmuje:
 * \param[in] parametr typu double
 */
template <int Wymiar>
Macierz<Wymiar>::Macierz(double x)
{
  int i,j;
  for(i=0;i<Wymiar;++i)
  {
    for(j=0;j<Wymiar;++j)
    {
      this->_Mat[i][j]=x;
    }
  }
}


/*!
 * \brief Przeciażenie funkcji operatorowej dla macierzy
 * 
 * Przeciazenie funkcji operatorowej będąca także szablonem
 * wykonuje wypisanie zawartosci macierzy.
 * Przyjmuje:
 * -referencje do standarowego strumienia
 * -odwołanie sie do szablonu macierzy o zadanym wymiarze
 * Odsyła:
 * -strumień
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wymiar> &Wek)
{
  int i,j;
  i=0;
  j=0;
  while(i<Wymiar)
  {
    while(j<Wymiar)
    {
      Strm << Wek(i,j) << " ";
      j=j+1;
    }
    Strm << std::endl;
    i=i+1;
    j=0;
  }
  return Strm;
   
}


#endif
