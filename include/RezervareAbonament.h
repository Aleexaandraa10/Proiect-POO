#ifndef REZERVAREABONAMENT_H
#define REZERVAREABONAMENT_H

#include "Rezervare.h"

class RezervareAbonament : public Rezervare {
    bool areAbonament;
public:
    explicit RezervareAbonament(int nr_persoane = 0, const std::string& ora = "", const std::string& data = "",
                             const std::string& zona_restaurant = "", const std::string& nume_rezervare = "",
                             bool areAbonament = false);
    ~RezervareAbonament() override;
    void ValidareIdRezervare() const override;
};

#endif // REZERVAREABONAMENT_H