#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Prostopadloscian.hh"
using namespace std;

/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Prostopadloscian
 */


/*!
 * \brief Funkcja transformujaca wspolrzedne do ukladu rodzica
 * 
 *  Funkcja transformuje wspolrzedne wierzcholkow do ukladu rodzica
 *  \param[in] Wierz wektor3D ktory chcemy transformowac
 *  \param[out] Nowy_polozenie wektor3D przetranformowany
 */
Wektor3D Prostopadloscian::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    mtx=rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}
/*!
 * \brief Funkcja ustawiajaca polozenie Prostopadloscianu
 * 
 *  Funkcja ustawia zmienna Polozenie.
 *  \param[in] polozenieD const wektor3D ktory chcemy ustawic jako polozenie
 *  \param[out] Polozenie wektor3D zamieniony z wejsciowego wektora3D
 */
Wektor3D& Prostopadloscian::polozenie(const Wektor3D polozenieD)
{
    Polozenie=polozenieD;
    return Polozenie;
}