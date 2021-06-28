
#include "doctest.h"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh" 
#define PRECISION 0.0000000001

TEST_CASE("Transfuzja do układu wsp. rodzica prostopadloscianu i graniastoslupa"){
    Prostopadloscian Pr;
    Graniastoslup6 Gr;
    Macierz3x3 mtx;
    Wektor3D vec,vec2,wierz,wierz2;
    vec[0]=0;
    vec[1]=0;
    vec[2]=2;//jezeli prostopadloscian jest przesuniety o wektor 0 0 2
    Pr.polozenie(vec);
    vec2[0]=2;
    vec2[1]=2;
    vec2[2]=8;
    Gr.polozenie(vec2);
    wierz[0]=4;
    wierz[1]=4;
    wierz[2]=4;
    wierz=Pr.TransfDoUklWspRodzica(wierz);
    //macierz w srodku bo kat 0
    /*
    | 1 0 0 |
    | 0 1 0 |
    | 0 0 1 |
    */
    //powinno wyjsc [4,4,6] bo [4,4,6]= [4,4,4]*I+[0,0,2]
    wierz2[0]=3;
    wierz2[1]=3;
    wierz2[2]=5;
    wierz2=Gr.TransfDoUklWspRodzica(wierz2);
    //macierz w srodku bo kat 0
    /*
    | 1 0 0 |
    | 0 1 0 |
    | 0 0 1 |
    */
    //powinno wyjsc [5,5,13] bo [5,5,13]= [3,3,5]*I+[2,2,8]

    CHECK(wierz[0] == 4);
    CHECK(wierz[1] == 4);
    CHECK(wierz[2] == 6);

    CHECK(wierz2[0] == 5);
    CHECK(wierz2[1] == 5);
    CHECK(wierz2[2] == 13);

}
