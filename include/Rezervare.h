#ifndef REZERVARE_H
#define REZERVARE_H

#include<iostream>

class Rezervare {
private:
    int Nr_Persoane;
    std::string Ora;
    std::string Data;
    std::string Zona_Restaurant;
    std::string Nume_Rezervare;

public:
    explicit Rezervare(int nr_persoane = 0, std::string ora = "", std::string data = "",
                       std::string zona_restaurant = "", std::string nume_rezervare = "");

    Rezervare(const Rezervare& masa);

    Rezervare& operator=(Rezervare const& masa);

    virtual ~Rezervare();

    friend int operator>(Rezervare& masa, const std::string& ora_limita);

    virtual void afisare(std::ostream& out) const;

    virtual void citire(std::istream& in);

    friend std::ostream& operator<<(std::ostream& out, const Rezervare& rezervare);

    friend std::istream& operator>>(std::istream& in, Rezervare& rezervare);

    bool operator==(const Rezervare& masa) const;

    std::string GetData();

    std::string GetOra();

    std::string GetZonaRestaurant();

    std::string GetNumeRezervare();

    [[nodiscard]] int GetNrPersoane() const;

    void SetNrPersoane(int nr);

    void SetOra(std::string ora);

    void SetData(std::string data);

    virtual void ValidareIdRezervare() const;

    static double CalculeazaCostTotal(int numarPersoane, double pretPerPersoana);
};

#endif // REZERVARE_H
