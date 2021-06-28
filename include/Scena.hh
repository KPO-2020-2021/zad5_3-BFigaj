#ifndef SCENA_HH
#define SCENA_HH

#include <memory>
#include <iostream>
#include "Dron.hh"
#include "GoraZDlugaGran.hh"
#include "GoraZOstrymSzytem.hh"
#include "Plaskowyz.hh"

/*!
 * \brief Klasa Scena
 *
 *  Modeluje pojecie Sceny. Jako atrybuty jest lista wskaznikow wspoldzielonych
 *  obiektow na powieszczni tytana. Dodatkowo tablice dronow jak i referencje lacza
 *  do gnuplota. Metody z tym zwazane a szczegolnie przelot drona.
 */
class Scena {
    std::list<std::shared_ptr<BrylaGeometryczna>> Lst;
    Dron TabDronow[2];
    PzG::LaczeDoGNUPlota Lacze;
    public:
    Dron& WezAktywnegoDrona(int i);
    bool UzyjAktynegoDrona(int i);
    void UstawLacze(PzG::LaczeDoGNUPlota& Lacze);
    void Poczatek();
    bool CzyMoznaLadowac(Wektor3D polozenie,int promien)const;
    const  std::list<std::shared_ptr<BrylaGeometryczna>> & WezListeObScn() const { return Lst; }
};

#endif
