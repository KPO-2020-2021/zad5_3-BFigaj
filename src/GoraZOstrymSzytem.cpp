
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include "GoraZOstrymSzytem.hh"



using namespace std;
/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Szczytogora
 */

/*!
 * \brief Funkcja transformujaca wspolrzedne do ukladu rodzica
 * 
 *  Funkcja transformuje wspolrzedne wierzcholkow do ukladu rodzica
 *  \param[in] Wierz wektor3D ktory chcemy transformowac
 *  \param[out] Nowy_polozenie wektor3D przetranformowany
 */
Wektor3D Szczytogora::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    mtx=rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}
/*!
 * \brief Funkcja tworzaca Szczytogore
 * 
 *  Funkcja tworzy szczytogore w zadanym polozeniu i o zadanej skali
 *  \param[in] polozenie wektor3D ktory traktujemy jako polozenie srodka bryly
 *  \param[in] skala wektor3D ktory traktujemy jako skale
 *  \param[out] true jezeli wszystko jest ok
 *  \param[out] false jezeli nie mozna bylo otworzyc pliku
 */
bool Szczytogora::Tworz(Wektor3D polozenie,Wektor3D skala)
{
    Wektor3D vec;
    ofstream  Strumien_plikowy_wy;
    ifstream Strumien_plikowy_wej;
    std::string Nazwa=PLIK_WLASCIWY__SZCZYTOGORA;
    int LicznikWierzcholkow;
    StworzSkale(skala);
    Polozenie=polozenie;
    this->NazwaplikuW("bryly_wzorcowe/szescian_na_powierzchni.dat");
    Strumien_plikowy_wej.open(WezNazwePliku_BrylaWzorcowa());
    if (!Strumien_plikowy_wej.is_open())  {
        cerr << ":(  Operacja otwarcia do wczytania korupusu \"" <<  WezNazwePliku_BrylaWzorcowa()
        << "\"" << endl << ":(  nie powiodla sie." << endl;
        return false;
    }
    //28
    //Nazwa[28]=ile;
    Strumien_plikowy_wy.open(Nazwa);
    if (!Strumien_plikowy_wy.is_open())  {
        cerr << ":(  Operacja otwarcia do zapisu " <<  Nazwa
        << "" << endl << ":(  nie powiodla sie." << endl;
        return false;
    }

    Strumien_plikowy_wej >> vec;
    while (!Strumien_plikowy_wej.fail()) 
    {
        LicznikWierzcholkow=0;
        for(;LicznikWierzcholkow<4;++LicznikWierzcholkow)
        {
            if (vec[2] > 0.5)
            { // Tutaj realizowana jest deformacja
	            vec[0] = vec[1] = 0;
            } 
            else if (vec[2] == 0.5) 
            {
                vec[0] /= 2;  vec[1] /= 2;
            }
            //std::cout << vec << endl;
            vec=Skaluj(vec);
            vec=TransfDoUklWspRodzica(vec);
            Strumien_plikowy_wy << vec << endl;
            Strumien_plikowy_wej >> vec;
        }
        Strumien_plikowy_wy << endl;
    }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  ile+=1;
  return true;
    
}
/*!
 * \brief Funkcja sprawdzajaca pokrywanie z Szczytogora
 * 
 *  Funkcja sprawdza pokrywanie drona z szczytogora
 *  \param[in] polozenie1 wektor3D ktory traktujemy jako polozenie drona
 *  \param[in] promien double ktory traktujemy jako promien
 *  \param[out] true jezeli sie pokrywa
 *  \param[out] false jezeli sie nie pokrywa
 */
bool Szczytogora::Pokrywanie(Wektor3D polozenie1, double promien)
{
    double roznicamiedzysrodkami;
    roznicamiedzysrodkami = sqrt(pow((polozenie1[0] - Polozenie[0]), 2) + pow((polozenie1[1] - Polozenie[1]), 2));
    if (roznicamiedzysrodkami < (20 / 1.5 + promien) || roznicamiedzysrodkami < (45 / 1.5 + promien))
    {
        cout << "\tWykryto gore z ostrym szczytem,zmiana toru lotu" << endl;
        return true;
    }
    return false;
}