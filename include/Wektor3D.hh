#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH


#include "Wektor.hh"
#include "Macierz3x3.hh"
/*!
 * \brief Klasa Wektor3D ma być instancją szablonu Wektor<>
 *
 *  Instancja szablonu wektor. Modeluje wektor w trzech wymiarach
 */
typedef Wektor<3> Wektor3D;

Wektor3D operator* (Wektor3D vec, Macierz3x3 mtx);


#endif
