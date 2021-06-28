#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>

#include "Macierz.hh"

/*!
 * \brief Instancja macierzy jako Macierz3x3
 *
 *  Modeluje pojecie macierzy 3x3 jej główną cechą jest określony wymiar
 *  czyli 3. Z racji tego że chcemy pracować w 3 wymiarach w programie.
 */
typedef Macierz<3>  Macierz3x3;

Macierz3x3 rotmtxx(double angle, Macierz3x3 mtx);
Macierz3x3 rotmtxy(double angle, Macierz3x3 mtx);
Macierz3x3 rotmtxz(double angle, Macierz3x3 mtx);

#endif
