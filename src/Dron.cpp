
#include <iostream>
#include <fstream>
#include <math.h>
#include "Dron.hh"

#define PLIK_TRASY_PRZELOTU "dat/trasa_przelotu.dat"

using namespace std;
/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Dron
 */

/*!
 * \brief Funkcja okreslajaca ktory to dron
 * 
 *  Funkcja przypisuje parametry poczatkowe w zaleznosci
 *  ktory to dron.
 *  \param[in] i zmienna int jako index okreslajacy drona
 */
void Dron::KtoryDron(int i)
{
  this->i=i;
  if(i==0)
  {
    Polozenie[0]=20;
    Polozenie[1]=20;
    Polozenie[2]=0;
  }
  if(i==1)
  {
    Polozenie[0]=80;
    Polozenie[1]=40;
    Polozenie[2]=0;
  }
}
/*!
 * \brief Funkcja planujaca poczatkowa sciezke drona
 * 
 *  Funkcja wyrysowuje droge jaka dron ma przebyc
 *  \param[in] DlugoscLotu double jako wysokosc lotu drona
 *  \param[in] Przemieszczenie wektor3D okreslajacy gdzie mamy przemiescic drona
 *  wpisywany przez uzytkownika
 *  \param[in] kontener szablon vectora z biblioteki std
 *  \param[in] Lacze referencja PzG::LaczeDoGNUPlota 
 */
void Dron::PlanujPoczatkowaSciezke(
                              double DlugoscLotu,
                              Wektor3D Przemieszczenie,
                              std::vector<Wektor3D> kontener,
                              PzG::LaczeDoGNUPlota& Lacze)
{
  Wektor3D wierz_trasy;
  ofstream StrmWy(PLIK_TRASY_PRZELOTU);

  if (!StrmWy.is_open()) {
    cerr << endl
	 << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << endl
	 << endl;
  }

  kontener.reserve(4);
  wierz_trasy=Polozenie;
  kontener.push_back(wierz_trasy);
  wierz_trasy[2]+=DlugoscLotu;
  kontener.push_back(wierz_trasy);
  wierz_trasy=wierz_trasy+Przemieszczenie;
  kontener.push_back(wierz_trasy);
  wierz_trasy[2]-=DlugoscLotu;
  kontener.push_back(wierz_trasy);
  if(Przemieszczenie[2]==0)
  {
    StrmWy << kontener[0] << endl
    << kontener[1] << endl;
    StrmWy << kontener[2] << endl
    << kontener[3] << endl;
    Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU);
  }
  
  for(unsigned int index;index<4;++index)
  {
    kontener.pop_back();
  }
  
}
/*!
 * \brief Funkcja obliczajaca wspolrzedne globalne drona
 * 
 *  Funkcja oblicza wspolrzedne globalne drona. Wykorzystujac funkcje
 *  olbiczania wspolrzedne globalnych korpusu i obliczania wspolrzedne globalne rotorow.
 *  \param[out] true jesli zarowno zostana poprawnie obliczone wsp. korpusu
 *  jak i rotorow
 *  \param[out] false jezeli wystapi jakikolwiek blad
 */
bool Dron::Oblicz_i_Zapisz_WspGlbDrona()
{
  if(!Oblicz_i_Zapisz_WspGlbKorpusu())
  {
    cerr << ":(  Operacja obliczania i zapisywania wspolrzednych globalnych korpusu nie powiodla sie." << endl;
    return false;
  }
  for(unsigned int j=0;j<4;++j)
  {
    if(!Oblicz_i_Zapisz_WspGlbRotora(RotorDrona[j],j))
    {
      cerr << ":(  Operacja obliczania i zapisywania wspolrzednych globalnych rotora nie powiodla sie." << endl;
      return false;
    }
  }
  return true;
}
/*!
 * \brief Funkcja obliczajaca wspolrzedne globalne korpusu
 * 
 *  Funkcja oblicza wspolrzedne globalne korpusu.
 *  \param[out] true jesli zostana poprawnie otwarte pliki
 *  \param[out] false jezeli wystapi jakikolwiek blad z otwarciem pliku
 */
bool Dron::Oblicz_i_Zapisz_WspGlbKorpusu()
{
  Wektor3D vec,skala,trans;
  ofstream  Strumien_plikowy_wy;
  ifstream Strumien_plikowy_wej;
  int LicznikWierzcholkow;
  skala[0]=10;
  skala[1]=8;
  skala[2]=4;
  trans[0]=0;
  trans[1]=0;
  trans[2]=2;
  KorpusDrona.StworzSkale(skala);
  KorpusDrona.polozenie(trans);
  KorpusDrona.NazwaplikuW(i,0);
  KorpusDrona.NazwaplikuF(i,0);
  /*KorpusDrona.WezNazwePliku_BrylaWzorcowa()*/
  Strumien_plikowy_wej.open(KorpusDrona.WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy_wej.is_open())  {
    cerr << ":(  Operacja otwarcia do wczytania korupusu \"" << KorpusDrona.WezNazwePliku_BrylaWzorcowa() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wy.open(KorpusDrona.WezNazwePliku_BrylaFinalna());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << KorpusDrona.WezNazwePliku_BrylaFinalna() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wej >> vec;
  while (!Strumien_plikowy_wej.fail()) 
  {
    LicznikWierzcholkow=0;
    for(;LicznikWierzcholkow<4;++LicznikWierzcholkow)
    {
      
      //std::cout << vec << endl;
      vec=KorpusDrona.Skaluj(vec);
      //std::cout <<"po skalowaniu korp"<< vec << endl;
      vec=KorpusDrona.TransfDoUklWspRodzica(vec);
      //std::cout <<"po rot.trans korp"<< vec << endl;
      vec=TransfDoUklWspRodzica(vec);
      //std::cout <<"po trans korp"<< vec << endl;
      Strumien_plikowy_wy << vec << endl;
      Strumien_plikowy_wej >> vec;
    }
    Strumien_plikowy_wy << endl;
  }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  return true;
}
/*!
 * \brief Funkcja obliczajaca wspolrzedne globalne rotora
 * 
 *  Funkcja oblicza wspolrzedne globalne rotora
 *  \param[out] true jesli zostana poprawnie otwarte pliki
 *  \param[out] false jezeli wystapi jakikolwiek blad z otwarciem pliku
 */
bool Dron::Oblicz_i_Zapisz_WspGlbRotora(const Graniastoslup6& Rotor,int k)
{
  Wektor3D vec,skala,trans;
  ofstream  Strumien_plikowy_wy;
  ifstream Strumien_plikowy_wej;
  int LicznikWierzcholkow;
  skala[0]=8;
  skala[1]=8;
  skala[2]=2;
  if(k==0)
  {
    trans[0]=5;
    trans[1]=4;
    trans[2]=5;
  }
  if(k==1)
  {
    trans[0]=5;
    trans[1]=-4;
    trans[2]=5;
  }
  if(k==2)
  {
    trans[0]=-5;
    trans[1]=4;
    trans[2]=5;
  }
  if(k==3)
  {
    trans[0]=-5;
    trans[1]=-4;
    trans[2]=5;
  }
  RotorDrona[k].StworzSkale(skala);
  RotorDrona[k].polozenie(trans);
  RotorDrona[k].NazwaplikuW(i,k+1);
  RotorDrona[k].NazwaplikuF(i,k+1);
  Strumien_plikowy_wej.open(Rotor.WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy_wej.is_open())  {
    cerr << ":(  Operacja otwarcia do wczytania rotora" << Rotor.WezNazwePliku_BrylaWzorcowa() 
    << "" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  
  Strumien_plikowy_wy.open(Rotor.WezNazwePliku_BrylaFinalna());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << Rotor.WezNazwePliku_BrylaFinalna() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wej >> vec;
  while (!Strumien_plikowy_wej.fail()) 
  {
    LicznikWierzcholkow=0;
    for(;LicznikWierzcholkow<4;++LicznikWierzcholkow)
    {
      
      //std::cout << vec << endl;
      vec=Rotor.Skaluj(vec);
      //std::cout <<"po skalowaniu rotora"<< vec << endl;
      vec=Rotor.TransfDoUklWspRodzica(vec);
      //std::cout <<"po rot.trans rotora"<< vec << endl;
      vec=TransfDoUklWspRodzica(vec);
      //std::cout <<"po trans rotora"<< vec << endl;
      Strumien_plikowy_wy << vec << endl;
      Strumien_plikowy_wej >> vec;
    }
    Strumien_plikowy_wy << endl;
  }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  return true;
}
/*!
 * \brief Funkcja wykonujaca pionowy lot
 * 
 *  Funkcja animuje lot w gore lub w dol drona.
 *  \param[in] DlugoscLotu zmienna double oznaczajaca wysokosc lotu 
 *  \param[in] Lacze referencja do PzG::LaczeDoGNUPlota
 *  \param[out] true jesli jest poprawna wysokosc
 *  \param[out] false jezeli nie jest poprawna wysokosc
 */
bool Dron::WykonajPionowyLot(double DlugoscLotu,PzG::LaczeDoGNUPlota& Lacze)
{
  
  if(Polozenie[2]==0)
  {
    std::cout << endl << "Wznoszenie ... " << endl;
    //std::cout << Polozenie;
    for (; Polozenie[2] < DlugoscLotu; Polozenie[2] += 2)
    {
      //std::cout << Polozenie<< endl;
      if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
      
      
      for(unsigned index=0;index<4;++index)
      {
        if(index%2==0)
        {
          RotorDrona[index].kat(10);
        }
        else
        {
          RotorDrona[index].kat(-10);
        }
      }
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();

    }
    if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
    for(unsigned index=0;index<4;++index)
    {
      if(index%2==0)
      {
        RotorDrona[index].kat(10);
      }
      else
      {
        RotorDrona[index].kat(-10);
      }
    }
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
    return true;
  }
  else if(Polozenie[2]==DlugoscLotu)
  {
    std::cout << endl << "Ladowanie ... " << endl;
    for (; Polozenie[2] > 0; Polozenie[2] -= 2)
    {
      if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
      for(unsigned index=0;index<4;++index)
      {
        if(index%2==0)
        {
          RotorDrona[index].kat(10);
        }
        else
        {
          RotorDrona[index].kat(-10);
        }
      }
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
      //std::cout << Polozenie[2] <<"==?" << DlugoscLotu << endl;
    }
    if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
    for(unsigned index=0;index<4;++index)
    {
      if(index%2==0)
      {
        RotorDrona[index].kat(10);
      }
      else
      {
        RotorDrona[index].kat(-10);
      }
    }
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
    //std::cout << Polozenie[2] <<"==?" << DlugoscLotu << endl;
    return true;
  }
  return false;
}
/*!
 * \brief Funkcja wykonujaca poziomy lot
 * 
 *  Funkcja animuje lot poziomy drona.
 *  \param[in] DlugoscLotu zmienna double oznaczajaca wysokosc lotu
 *  \param[in] Przemieszczenie zmienna typu wektor3D potrzebna do animowania
 *  \param[in] Lacze referencja do PzG::LaczeDoGNUPlota
 *  \param[out] true jesli jest poprawna wysokosc
 *  \param[out] false jezeli nie jest poprawna wysokosc
 */
bool Dron::WykonajPoziomyLot(double DlugoscLotu,Wektor3D Przemieszczenie,PzG::LaczeDoGNUPlota& Lacze)
{
  std::vector<Wektor3D> wierz_trasy;
  double j=0,KatSzukany;
  //std::cout << Polozenie[2] <<"==?" << DlugoscLotu << endl;
  KatSzukany=atan((Przemieszczenie[1]/Przemieszczenie[0]));
  for (;KatOrientacji_stopnie<((180*KatSzukany)/(M_PI));KatOrientacji_stopnie+=(((180*KatSzukany)/(M_PI))/20))
  {
    //std::cout << KatSzukany << "katO"<< KatOrientacji_stopnie << endl;
    if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }
  //std::cout << Polozenie[2] <<"==?" << DlugoscLotu << endl;
  
  if(Polozenie[2]==DlugoscLotu)
  {
    std::cout << endl << "Lot do miejsca docelowego ... " << endl;
    for (double i=0;i<50;i=i+1)
    {
      j=j+1;
      Polozenie[0]=Polozenie[0]+(Przemieszczenie[0]/50);
      Polozenie[1]=Polozenie[1]+(Przemieszczenie[1]/50);
      if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
      for(unsigned index=0;index<4;++index)
      {
        if(index%2==0)
        {
          RotorDrona[index].kat(10);
        }
        else
        {
          RotorDrona[index].kat(-10);
        }
      }
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
      
    }
    if (!Oblicz_i_Zapisz_WspGlbDrona()) return false;
    for(unsigned index=0;index<4;++index)
    {
      if(index%2==0)
      {
        RotorDrona[index].kat(10);
      }
      else
      {
        RotorDrona[index].kat(-10);
      }
    }
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
    //std::cout << Polozenie << endl;
    return true;
  }
  cerr << "Nie poprawna wysokosc lotu" << endl;
  return false;
}
/*!
 * \brief Funkcja transformujaca wspolrzedne do ukladu rodzica
 * 
 *  Funkcja transformuje wspolrzedne wierzcholkow do ukladu rodzica
 *  \param[in] Wierz wektor3D ktory chcemy transformowac
 *  \param[out] Nowy_polozenie wektor3D przetranformowany
 */
Wektor3D Dron::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    mtx=rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}
/*!
 * \brief Funkcja planujaca poczatkowa sciezke drona
 * 
 *  Funkcja wyrysowuje droge jaka dron ma przebyc
 *  \param[in] Stareprzemieszczenie Wektor3D stareprzemieszczenie po to by okreslic polozenie
 *  poczatkowe drona
 *  \param[in] DlugoscLotu double jako wysokosc lotu drona
 *  \param[in] Przemieszczenie wektor3D okreslajacy gdzie mamy przemiescic drona
 *  wpisywany przez uzytkownika
 *  \param[in] kontener szablon vectora z biblioteki std
 *  \param[in] Lacze referencja PzG::LaczeDoGNUPlota 
 */
void Dron::PlanujPuzniejszaSciezka(Wektor3D Stareprzemieszczenie,
                              double DlugoscLotu,
                              Wektor3D Przemieszczenie,
                              std::vector<Wektor3D> kontener,
                              PzG::LaczeDoGNUPlota& Lacze)
{
  Wektor3D wierz_trasy;
  ofstream StrmWy(PLIK_TRASY_PRZELOTU);

  if (!StrmWy.is_open()) {
    cerr << endl
	 << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << endl
	 << endl;
  }

  kontener.reserve(4);
  wierz_trasy=Polozenie-Stareprzemieszczenie;
  wierz_trasy[2]=0;
  kontener.push_back(wierz_trasy);
  wierz_trasy[2]+=DlugoscLotu;
  kontener.push_back(wierz_trasy);
  wierz_trasy=wierz_trasy+Przemieszczenie;
  kontener.push_back(wierz_trasy);
  wierz_trasy[2]-=DlugoscLotu;
  kontener.push_back(wierz_trasy);
  if(Przemieszczenie[2]==0)
  {
    StrmWy << kontener[0] << endl
    << kontener[1] << endl;
    StrmWy << kontener[2] << endl
    << kontener[3] << endl;
    Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU);
  }
  for(unsigned int index;index<4;++index)
  {
    kontener.pop_back();
  }
  
}