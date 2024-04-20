#ifndef REZERVARE_ONLINE_H
#define REZERVARE_ONLINE_H

#include "Rezervare.h"


class RezervareOnline : public Rezervare {
private:
    std::string Id_Rezervare;

public:
    explicit RezervareOnline(int nr_persoane = 0, const std::string& ora = "", const std::string& data = "",
                             const std::string& zona_restaurant = "", const std::string& nume_rezervare = "",
                             const std::string& id = "");

    [[nodiscard]] std::string GetId() const;
    RezervareOnline& operator=(const RezervareOnline& online);
    bool operator==(const RezervareOnline& rezervare) const;
    ~RezervareOnline() override;

    void afisare(std::ostream& out) const override;
    void citire(std::istream& in) override;
    void ValidareIdRezervare() const override;
};

#endif // REZERVARE_ONLINE_H
