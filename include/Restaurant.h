#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Rezervare.h"
#include "RezervareOnline.h"
#include "RezervareTelefonica.h"
#include "Mancare.h"
#include "Exceptii.h"

class Restaurant {
private:
    std::vector<Rezervare*> Detalii_Rezervari;
    std::vector<Mancare> Detalii_Preparate;
    static int count;

public:
    Restaurant();
    void Creare_Rezervare();
    void Modificare_Detalii_Rezervare();
    void OreDisponibile();
    void Recomandari_Culinare();
    void Numara_Rezervari(const std::string& ora) const;
    void Anuleaza_Rezervare() const;
    static void aruncaExceptie();
    static void prindeExceptie();
};

#endif // RESTAURANT_H