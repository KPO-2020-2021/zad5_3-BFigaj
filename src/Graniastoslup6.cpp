#include "Graniastoslup6.hh"

/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Graniastoslup6
 */

/*!
 * \brief Funkcja transformujaca wspolrzedne do ukladu rodzica
 * 
 *  Funkcja transformuje wspolrzedne wierzcholkow do ukladu rodzica
 *  \param[in] Wierz wektor3D ktory chcemy transformowac
 *  \param[out] Nowy_polozenie wektor3D przetranformowany
 */
Wektor3D Graniastoslup6::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    mtx=rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}
/*!
 * \brief Funkcja ustawiajaca polozenie Graniastoslupa6
 * 
 *  Funkcja ustawia zmienna Polozenie.
 *  \param[in] polozenieD const wektor3D ktory chcemy ustawic jako polozenie
 *  \param[out] Polozenie wektor3D zamieniony z wejsciowego wektora3D
 */
Wektor3D& Graniastoslup6::polozenie(const Wektor3D polozenieD)
{
    Polozenie=polozenieD;
    return Polozenie;
}

/*!
 * \brief Funkcja zmieniajaca kat 
 * 
 *  Funkcja zmienia kat orientacji. Funkcja dziala do krecenia sie rotorow.
 *  \param[in] kat double ktory chcemy dodac do poprzedniego konta orientacji
 *  \param[out] KatOrientacji_stopnie double zamieniony 
 */
double& Graniastoslup6::kat(double kat)
{
    if (kat>0)
        KatOrientacji_stopnie+=kat;
    else
        KatOrientacji_stopnie+=kat;
    return KatOrientacji_stopnie;
}
/*!
 * \brief Funkcja osylajaca kat 
 * 
 *  Funkcja osyla kat
 *  \param[out] KatOrientacji_stopnie double kat orientacji
 */
double Graniastoslup6::kat()const
{
    return KatOrientacji_stopnie;
}