#include "RezervareAbonament.h"

RezervareAbonament::RezervareAbonament(int nr_persoane, const std::string& ora, const std::string& data,
                                 const std::string& zona_restaurant, const std::string& nume_rezervare,
                                 bool abonament) :
        Rezervare(nr_persoane, ora, data, zona_restaurant, nume_rezervare), areAbonament(abonament) {}

RezervareAbonament::~RezervareAbonament() = default;

void RezervareAbonament::ValidareIdRezervare() const {
    std::cout<<"In cazul clientilor care au abonament la lantul nostru de restaurante, nr. abonamentului va deveni id-ul lor de identificare in baza noastra de date.\n";
    std::cout<<"In plus, acestia beneficiaza de reducere de 10% daca nota de plata depaseste suma de 150 de lei.\n";

}

