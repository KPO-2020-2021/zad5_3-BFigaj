#ifndef DRON_HH
#define DRON_HH


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "Graniastoslup6.hh"
#include "Prostopadloscian.hh"

/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Dron
 *   
 *  Jako dane prywatne mamy polozenie w formie wektora3D oraz 
 *  konta orientacji w formie double. Dodatkowo wykorzystuje 
 *  klasy Prostopadloscian i Graniastoslup6 w celu zamodelowania
 *  pojecia drona. Prostopadloscian wykorzystany jako korpus,
 *  natomiast Graniastoslup6 jako rotory drona. Jest takze promien
 *  obrysu drona.
 */

class Dron {
    Wektor3D Polozenie;
    double KatOrientacji_stopnie;
    Prostopadloscian KorpusDrona;
    Graniastoslup6 RotorDrona[4];
    int promien=15;
    int i;
    public:
    void KtoryDron(int i);
    void PlanujPoczatkowaSciezke(
                                double DlugoscLotu,
                                Wektor3D Przemieszczenie,
                                std::vector<Wektor3D> kontener,
                                PzG::LaczeDoGNUPlota& Lacze);
    bool WykonajPionowyLot(double DlugoscLotu,PzG::LaczeDoGNUPlota& Lacze);
    bool WykonajPoziomyLot(double DlugoscLotu,Wektor3D Przemieszczenie,PzG::LaczeDoGNUPlota& Lacze);
    bool Oblicz_i_Zapisz_WspGlbDrona();
    Wektor3D WezPolozenie(){return Polozenie;}
    double WezPromien(){return promien;}
    void PlanujPuzniejszaSciezka(Wektor3D Stareprzemieszczenie,
                              double DlugoscLotu,
                              Wektor3D Przemieszczenie,
                              std::vector<Wektor3D> kontener,
                              PzG::LaczeDoGNUPlota& Lacze);
    protected:
    Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
    private:
    bool Oblicz_i_Zapisz_WspGlbKorpusu();
    bool Oblicz_i_Zapisz_WspGlbRotora(const Graniastoslup6& Rotor,int i);
    


};

#endif

