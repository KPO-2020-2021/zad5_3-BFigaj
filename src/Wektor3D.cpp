#include "Wektor3D.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor3D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Wektor3D operator* (Wektor3D vec, Macierz3x3 mtx)
{
    int i;
    Wektor3D vec2;
    vec2=vec;
    for(i=0;i<3;++i)
    {
        vec[i]=((vec2[0])*(mtx(i,0)))+((vec2[1])*(mtx(i,1)))+((vec2[2])*(mtx(i,2)));
        //std::cout << vec[i] << std::endl;
    }
        
        
    return vec;
}