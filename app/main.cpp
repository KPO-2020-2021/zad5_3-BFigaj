#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "Scena.hh"




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
using namespace std;

int main()
{
  Scena Scena;
  PzG::LaczeDoGNUPlota  Lacze;
  char wybor[2]=" ";
  int i,p,s,g,ktory;
  Lacze.DodajNazwePliku("bryly_wzorcowe/plaszczyzna.dat");
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_KORPUS);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR4);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_KORPUS);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON2_ROTOR4);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__PLASKOWYZ);
  p=1;
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__SZCZYTOGORA);
  s=1;
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__GRANIOGORA);
  g=1;
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 120);


  Lacze.UstawRotacjeXZ(64,65); // Tutaj ustawiany jest widok

 
       Scena.UstawLacze(Lacze);
       Scena.Poczatek();
       while(wybor[0]!='E')/*Warunek zakonczenia programu*/
       {
              
              Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
              cout << "Jakiego Drona chcesz wybrac do przelotu" << endl;
              cout << "A - Dron Alfa" << endl;
              cout << "B - Dron Beta" << endl;
              cout << "U - Usun elementy powieszchni" << endl;
              cout << "E - Exit" << endl;
              cin >> wybor;
              switch(wybor[0])
              {
                     case 'A':i=0;
                     Scena.WezAktywnegoDrona(i);
                     Scena.UzyjAktynegoDrona(i);
                     break;
                     case 'B':i=1;
                     Scena.WezAktywnegoDrona(i);
                     Scena.UzyjAktynegoDrona(i);
                     break;
                     case 'U':cout << "Jaki element usunac" << endl;
                     if(p==1)
                            cout << "1 - Plaskowyz" << endl;
                     if(g==1)
                            cout << "2 - Gora z dluga gran" << endl;
                     if(s==1)
                            cout << "3 - Gora z ostry szczyt" << endl;
                     
                     cout << "4 - Zaden" << endl;
                     cin >> ktory;
                     if(ktory==1)
                     {
                            Lacze.UsunNazwePliku(PLIK_WLASCIWY__PLASKOWYZ);
                            p=0;
                     }
                     if(ktory==2)
                     {
                            Lacze.UsunNazwePliku(PLIK_WLASCIWY__GRANIOGORA);
                            g=0;
                     }
                     if(ktory==3)
                     {
                            Lacze.UsunNazwePliku(PLIK_WLASCIWY__SZCZYTOGORA);
                            s=0;
                     }
                     Scena.UstawLacze(Lacze);
                     break;
                     case 'E':
                     break;
                     default:cerr << "Nie poprawny wybor opcji";break;
       }
    }



}