#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <vector>
#include <stdexcept>

#include "Rezervare.h"
#include "RezervareOnline.h"
#include "RezervareTelefonica.h"
#include "RezervareAbonament.h"
#include "Mancare.h"
#include "Exceptii.h"

#include "Evaluare.h"
#include "EvaluareMancare.h"
#include "EvaluareAtmosfera.h"
#include "EvaluareServire.h"

class Restaurant {
private:
    std::vector<Rezervare*> Detalii_Rezervari;
    std::vector<Mancare> Detalii_Preparate;
    static int count;

public:
    Restaurant();
    ~Restaurant();
    void Creare_Rezervare();
    void Modificare_Detalii_Rezervare();
    void OreDisponibile() const;
    void Recomandari_Culinare() const;
    void Numara_Rezervari(const std::string& ora) const;
    void Anuleaza_Rezervare() const;
    static void aruncaExceptie();
    static void prindeExceptie();
    void Evaluare_Clienti(std::string& nume, std::string& data);
    void Medie_Evaluari() const;
};

#endif // RESTAURANT_H
