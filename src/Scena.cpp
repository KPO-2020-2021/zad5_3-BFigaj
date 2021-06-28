

#include "Scena.hh"
#include <memory>

using namespace std;
/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Scena
 */
/*!
 * \brief Funkcja zwracajaca aktywnego drona
 * 
 *  Funkcja zwraca aktywnego drona
 *  \param[in] i zmienna int do wyboru drona
 *  \param[out] TabDronow[i] referencja do zmiennej typu Dron
 */
Dron& Scena::WezAktywnegoDrona(int i)
{
    return TabDronow[i];
}

/*!
 * \brief Funkcja uzycia drona
 * 
 *  Funkcja animuje caly lot drona w sekwencji. Zakancza sie jezeli uzytkownik
 *  wpisze "N".
 *  \param[in] i zmienna int do wyboru drona
 *  \param[out] true jezeli wszystko zadzialalo poprawnie
 */
bool Scena::UzyjAktynegoDrona(int i)
{
    Wektor3D przemieszczenie,polozenie,stareprzemieszczenie;
    Dron AktywnyDron;
    std::vector<Wektor3D> wierz_trasy;
    double dlugosclotu=40,promien;
    Wektor3D przeskok;
    
    AktywnyDron=WezAktywnegoDrona(i);
    AktywnyDron.KtoryDron(i);
    if(!AktywnyDron.Oblicz_i_Zapisz_WspGlbDrona()) return false;
    //AktywnyDron.TworzDrona();
    Lacze.Rysuj();
    char wybor[2]=" ";
    while(wybor[0]!='N')
    {
        cout << "Podaj wektor o jaki ma sie przesunac dron (na koniec wpisz 0)";
        cin >> przemieszczenie;
        cout << "Nacisnij ENTER, aby pokazac sciezke przelotu drona " << flush;
        cin.ignore(10000,'\n');
        AktywnyDron.PlanujPoczatkowaSciezke(dlugosclotu,przemieszczenie,wierz_trasy,Lacze);
        Lacze.Rysuj();
        cout << "Nacisnij ENTER, aby wykonac ruch drona " << flush;
        cin.ignore(10000,'\n');
        
        
        if(!AktywnyDron.WykonajPionowyLot(dlugosclotu,Lacze)) return false;
        if(!AktywnyDron.WykonajPoziomyLot(dlugosclotu,przemieszczenie,Lacze)) return false;
        polozenie=AktywnyDron.WezPolozenie();
        promien=AktywnyDron.WezPromien();
        
        while(CzyMoznaLadowac(polozenie,promien)!=true)
        {
            przeskok[0]=przemieszczenie[0]/10;
            przeskok[1]=przemieszczenie[1]/10;
            stareprzemieszczenie=przemieszczenie;
            przemieszczenie=przemieszczenie+przeskok;
            AktywnyDron.PlanujPuzniejszaSciezka(stareprzemieszczenie,dlugosclotu,przemieszczenie,wierz_trasy,Lacze);
            Lacze.Rysuj();
            AktywnyDron.WykonajPoziomyLot(dlugosclotu,przeskok,Lacze);
            polozenie=AktywnyDron.WezPolozenie();
            promien=AktywnyDron.WezPromien();
        }
        if(!AktywnyDron.WykonajPionowyLot(dlugosclotu,Lacze)) return false;
        
        Lacze.Rysuj();
        cout << "Jezeli nie chcesz kontynuowac wpisz N";
        cin >> wybor;
    }
    TabDronow[i]=AktywnyDron;
    return true;
}
/*!
 * \brief Funkcja ustawia zeminna Lacze
 * 
 *  Funkcja ustawia Lacze do gnuplota
 *  \param[in] Lacze referencja do PzG::LaczeDoGNUPlota
 */
void Scena::UstawLacze(PzG::LaczeDoGNUPlota& Lacze)
{
    this->Lacze=Lacze;
}
/*!
 * \brief Funkcja inicjuje stan poczatkowy na scenie
 * 
 *  Funkcja ustawia parametry poczatkowe dronow oraz je wyswietla.
 */
void Scena::Poczatek()
{
    Dron AktywnyDron;
    Wektor3D pol,skal;
    std::shared_ptr<Plaskowyz> plaskowyz = std::make_shared<Plaskowyz>();
    std::shared_ptr<Szczytogora> szczytogora = std::make_shared<Szczytogora>();
    std::shared_ptr<Graniogora> graniogora = std::make_shared<Graniogora>();
    unsigned int n=0;
    //const char* cos=TabPlask[0].WezNazwePliku_BrylaFinalna();
    for(unsigned int index;index<2;++index)
    {
        AktywnyDron=WezAktywnegoDrona(index);
        AktywnyDron.KtoryDron(index);
        AktywnyDron.Oblicz_i_Zapisz_WspGlbDrona();
        Lacze.Rysuj();
    }

    Lst.push_back(plaskowyz);
    Lst.push_back(szczytogora);
    Lst.push_back(graniogora);
    for(std::shared_ptr<BrylaGeometryczna> wsk : Lst)
    {
        n+=1;
        if(n==1)
        {
            pol[0]=150;
            pol[1]=105;
            pol[2]=0;
            skal[0]=50;
            skal[1]=60;
            skal[2]=15;
        }
        else if(n==2)
        {
            pol[0]=60;
            pol[1]=120;
            pol[2]=0;
            skal[0]=20;
            skal[1]=45;
            skal[2]=35;
        }
        else
        {
            pol[0]=100;
            pol[1]=90;
            pol[2]=0;
            skal[0]=20;
            skal[1]=80;
            skal[2]=30;
        }
        if(!wsk->Tworz(pol,skal))
            cout << "dizasta" << endl;
    }
    
    
    Lacze.Rysuj();
}


bool Scena::CzyMoznaLadowac(Wektor3D polozenie, int promien)const
{
  for (const std::shared_ptr<BrylaGeometryczna> &WObScn : WezListeObScn())
  {
    if (WObScn->Pokrywanie(polozenie,promien)) 
    {
      return false;
    }  
  }
  return true;
}