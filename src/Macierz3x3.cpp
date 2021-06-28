#include "Macierz3x3.hh"
#include <math.h>

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz3x3, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
/*!
 *  \brief Konstruktor macierzy potrzebnej do obrotu wokół OX
 * 
 *  Wypełnia macierz3x3 czyli składowa prostokata 
 *  potrzebnymi danymi by powstała macierz obrotu
 *  Przyjmuje:
 *  \param[in] angle liczba double czytli kąt w stopniach
 */
Macierz3x3 rotmtxx(double angle, Macierz3x3 mtx)
{
    double katrad;
    katrad=(angle*M_PI)/180;
    mtx(0,0)=1;
    mtx(0,1)=0;
    mtx(0,2)=0;
    mtx(1,0)=0;
    mtx(1,1)=cos(katrad);
    mtx(1,2)=(-sin(katrad));
    mtx(2,0)=0;
    mtx(2,1)=sin(katrad);
    mtx(2,2)=cos(katrad);
    //std::cout << mtx << std::endl;
    return mtx;
}
/*!
 *  \brief Konstruktor macierzy potrzebnej do obrotu wokół OY
 * 
 *  Wypełnia macierz3x3 czyli składowa prostokata 
 *  potrzebnymi danymi by powstała macierz obrotu
 *  Przyjmuje:
 *  \param[in] angle liczba double czytli kąt w stopniach
 */
Macierz3x3 rotmtxy(double angle, Macierz3x3 mtx)
{
    double katrad;
    katrad=(angle*M_PI)/180;
    mtx(0,0)=cos(katrad);
    mtx(0,1)=0;
    mtx(0,2)=sin(katrad);
    mtx(1,0)=0;
    mtx(1,1)=1;
    mtx(1,2)=0;
    mtx(2,0)=(-sin(katrad));
    mtx(2,1)=0;
    mtx(2,2)=cos(katrad);
    //std::cout << mtx << std::endl;
    return mtx;
}
/*!
 *  \brief Konstruktor macierzy potrzebnej do obrotu wokół OZ
 * 
 *  Wypełnia macierz3x3 czyli składowa prostokata 
 *  potrzebnymi danymi by powstała macierz obrotu
 *  Przyjmuje:
 *  \param[in] angle liczba double czytli kąt w stopniach
 */
Macierz3x3 rotmtxz(double angle, Macierz3x3 mtx)
{
    double katrad;
    katrad=(angle*M_PI)/180;
    mtx(0,0)=cos(katrad);
    mtx(0,1)=(-sin(katrad));
    mtx(0,2)=0;
    mtx(1,0)=sin(katrad);
    mtx(1,1)=cos(katrad);
    mtx(1,2)=0;
    mtx(2,0)=0;
    mtx(2,1)=0;
    mtx(2,2)=1;
    //std::cout << mtx << std::endl;
    return mtx;
}