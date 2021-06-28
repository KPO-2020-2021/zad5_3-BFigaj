


#include "BrylaGeometryczna.hh"


#define PLIK_ROBOCZY__DRON1_KORPUS  "bryly_wzorcowe/szescian.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR1  "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR2  "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR3  "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR4  "bryly_wzorcowe/graniastoslup6.dat"

#define PLIK_ROBOCZY__DRON2_KORPUS  "bryly_wzorcowe/szescian.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR1  "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR2  "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR3  "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR4  "bryly_wzorcowe/graniastoslup6.dat"


#define PLIK_WLASCIWY__DRON1_KORPUS  "dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "dat/PlikWlasciwy_Dron1_Rotor4.dat"

#define PLIK_WLASCIWY__DRON2_KORPUS  "dat/PlikWlasciwy_Dron2_Korpus.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR1  "dat/PlikWlasciwy_Dron2_Rotor1.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR2  "dat/PlikWlasciwy_Dron2_Rotor2.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR3  "dat/PlikWlasciwy_Dron2_Rotor3.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR4  "dat/PlikWlasciwy_Dron2_Rotor4.dat"
/*!
 * \file
 * \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa BrylaGeometryczna
 */


/*!
 * \brief Funkcja skalujaca bryly geometrycznej
 * 
 *  Funkcja skaluje wektor, ktory pojawia sie jako parametr
 *  \param[in] Wierz wektor3D ktory chcemy zeskalowac
 *  \param[out] Nowy_Wierz wektor3D zeskalowany
 */
Wektor3D BrylaGeometryczna::Skaluj(const Wektor3D& Wierz)const
{
    Wektor3D Nowy_Wierz;
    Nowy_Wierz=Wierz*Skala;
    return Nowy_Wierz;
}
/*!
 * \brief Funkcja tworzaca skale bryly geometrycznej
 * 
 *  Funkcja ustawia skale
 *  \param[in] Wierz wektor3D by ustawic jako skale
 *  \param[out] Nowy_Wierz wektor3D jako jeden ze zmiennych prywatnych klasy
 */
Wektor3D& BrylaGeometryczna::StworzSkale(Wektor3D skala)
{
    Skala=skala;
    return Skala;
}
/*!
 * \brief Funkcja odsylajaca jedna z danych prywatnych klasy bryly geometrycznej
 * 
 *  Funkcja odsyla zmienna NazwaPliku_BrylaWzorcowa
 *  \param[out] NazwaPliku_BrylaWzorcowa referencja do zmiennej typu std::string
 */
const std::string& BrylaGeometryczna::WezNazwePliku_BrylaWzorcowa()const
{
    return NazwaPliku_BrylaWzorcowa;
}
/*!
 * \brief Funkcja odsylajaca jedna z danych prywatnych klasy bryly geometrycznej
 * 
 *  Funkcja odsyla zmienna NazwaPliku_BrylaFinalna
 *  \param[out] NazwaPliku_BrylaFinalna referencja do zmiennej typu std::string
 */
const std::string&  BrylaGeometryczna::WezNazwePliku_BrylaFinalna()const
{
    return NazwaPliku_BrylaFinalna;
}
/*!
 * \brief Funkcja tworzaca nazwe pliku wejsciowego bryly geometrycznej
 * 
 *  Funkcja ustawia nazwe pliku wejsciowego
 *  \param[in] nazwa zmienna int ktora mowi nam o tym jakiego drona wybralismy
 *  \param[in] ktory zmienna int ktora mowi nam jaka to czesc drona 0 to korpus 1-4 to rotory 
 */
void BrylaGeometryczna::NazwaplikuW(int nazwa,int ktory)
{
    if(nazwa==0)
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_KORPUS;
        }   
        if(ktory==1)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR4;
        }
    }
    else
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_KORPUS;
        }
        if(ktory==1)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR4;
        }
    }
}
/*!
 * \brief Funkcja tworzaca nazwe pliku finalnego bryly geometrycznej
 * 
 *  Funkcja nazwe pliku finalnego
 *  \param[in] nazwa zmienna int ktora mowi nam o tym jakiego drona wybralismy
 *  \param[in] ktory zmienna int ktora mowi nam jaka to czesc drona 0 to korpus 1-4 to rotory 
 */
void BrylaGeometryczna::NazwaplikuF(int nazwa,int ktory)
{
    if(nazwa==0)
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_KORPUS;
        }
        if(ktory==1)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR4;
        }
    }
    else
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_KORPUS;
        }
        if(ktory==1)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR4;
        }
    }
}
void BrylaGeometryczna::NazwaplikuW(std::string nazwa)
{
    this->NazwaPliku_BrylaWzorcowa=nazwa;
}
void BrylaGeometryczna::NazwaplikuF(std::string nazwa)
{
    this->NazwaPliku_BrylaFinalna=nazwa;
}