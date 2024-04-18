#ifndef REZERVARE_TELEFONICA_H
#define REZERVARE_TELEFONICA_H

#include "Rezervare.h"
#include <stdexcept>

class RezervareTelefonica : public Rezervare {
private:
    std::string NumarTelefon;

public:
    explicit RezervareTelefonica(int nr_persoane = 0, const std::string& ora = "", const std::string& data = "",
                                 const std::string& zona_restaurant = "", const std::string& nume_rezervare = "",
                                 const std::string& numar = "");

    std::string GetTelefon() const;
    RezervareTelefonica& operator=(const RezervareTelefonica& telefon);
    bool operator==(const RezervareTelefonica& rezervare) const;
    ~RezervareTelefonica() override;

    void afisare(std::ostream& out) const override;
    void citire(std::istream& in) override;
    void Schimba_NumarTelefon(const std::string& noulNumar);
};

#endif // REZERVARE_TELEFONICA_H