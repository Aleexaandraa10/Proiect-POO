#include "Rezervare.h"

int Rezervare::count = 0;

Rezervare::Rezervare(int nr_persoane, std::string ora, std::string data, std::string zona_restaurant,
                     std::string nume_rezervare) :
        Nr_Persoane(nr_persoane), Ora(std::move(ora)), Data(std::move(data)), Zona_Restaurant(std::move(zona_restaurant)),
        Nume_Rezervare(std::move(nume_rezervare)) {count++;}

Rezervare::Rezervare(const Rezervare& masa) :
        Nr_Persoane(masa.Nr_Persoane), Ora(masa.Ora), Data(masa.Data), Zona_Restaurant(masa.Zona_Restaurant),
        Nume_Rezervare(masa.Nume_Rezervare) {}

Rezervare& Rezervare::operator=(Rezervare const& masa) {
    this->Nume_Rezervare = masa.Nume_Rezervare;
    this->Nr_Persoane = masa.Nr_Persoane;
    this->Ora = masa.Ora;
    this->Data = masa.Data;
    this->Zona_Restaurant = masa.Zona_Restaurant;
    return *this;
}

Rezervare::~Rezervare() {
    Nume_Rezervare = "";
    Nr_Persoane = 0;
    Ora = "";
    Data = "";
    Zona_Restaurant = "";
}

void Rezervare::afisare(std::ostream& out) const {
    out << "Numele pe care a fost facuta rezervarea este: " << Nume_Rezervare << std::endl;
    out << "Nr de persoane care participa este: " << Nr_Persoane << std::endl;
    out << "Ora la care masa a fost rezervata este: " << Ora << std::endl;
    out << "Data rezervarii este: " << Data << std::endl;
    out << "Zona restaurantului aleasa este: " << Zona_Restaurant << std::endl;
}

void Rezervare::citire(std::istream& in) {
    std::cout << "Numele pe care a fost facuta rezervarea este: " << std::endl;
    in >> Nume_Rezervare;
    std::cout << "Nr de persoane care participa este: " << std::endl;
    in >> Nr_Persoane;
    std::cout << "Ora la care masa a fost rezervata este: " << std::endl;
    in >> Ora;
    std::cout << "Data rezervarii este: " << std::endl;
    in >> Data;
    std::cout << "Zona restaurantului aleasa este: " << std::endl;
    in >> Zona_Restaurant;
}

int operator>(Rezervare& masa, const std::string& ora_limita) {
    if (masa.GetOra() > ora_limita) {
        return 0;
    } else {
        return 1;
    }
}

std::ostream& operator<<(std::ostream& out, const Rezervare& rezervare) {
    rezervare.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Rezervare& rezervare) {
    rezervare.citire(in);
    return in;
}

bool Rezervare::operator==(const Rezervare& masa) const {
    if (masa.Data == Data and Ora == masa.Ora)
        return true;
    else
        return false;
}

std::string Rezervare::GetData() {
    return Data;
}

std::string Rezervare::GetOra() {
    return Ora;
}

std::string Rezervare::GetZonaRestaurant() {
    return Zona_Restaurant;
}

std::string Rezervare::GetNumeRezervare() {
    return Nume_Rezervare;
}

int Rezervare::GetNrPersoane() const {
    return Nr_Persoane;
}

void Rezervare::SetNrPersoane(int nr) {
    Nr_Persoane = nr;
}

void Rezervare::SetOra(std::string ora) {
    Ora = std::move(ora);
}

void Rezervare::SetData(std::string data) {
    Data = std::move(data);
}

void Rezervare::ValidareIdRezervare() const {
    std::cout << "Rezervarea nu a fost facuta online, deci nu va putem verifica corectitudinea id-ului.\n";
}

double Rezervare::CalculeazaCostTotal(int numarPersoane, double pretPerPersoana) {
    return numarPersoane * pretPerPersoana;
}#include "Rezervare.h"

int Rezervare::count = 0;

Rezervare::Rezervare(int nr_persoane, std::string ora, std::string data, std::string zona_restaurant,
                     std::string nume_rezervare) :
        Nr_Persoane(nr_persoane), Ora(std::move(ora)), Data(std::move(data)), Zona_Restaurant(std::move(zona_restaurant)),
        Nume_Rezervare(std::move(nume_rezervare)) {count++;}

Rezervare::Rezervare(const Rezervare& masa) :
        Nr_Persoane(masa.Nr_Persoane), Ora(masa.Ora), Data(masa.Data), Zona_Restaurant(masa.Zona_Restaurant),
        Nume_Rezervare(masa.Nume_Rezervare) {}

Rezervare& Rezervare::operator=(Rezervare const& masa) {
    this->Nume_Rezervare = masa.Nume_Rezervare;
    this->Nr_Persoane = masa.Nr_Persoane;
    this->Ora = masa.Ora;
    this->Data = masa.Data;
    this->Zona_Restaurant = masa.Zona_Restaurant;
    return *this;
}

Rezervare::~Rezervare() {
    Nume_Rezervare = "";
    Nr_Persoane = 0;
    Ora = "";
    Data = "";
    Zona_Restaurant = "";
}

void Rezervare::afisare(std::ostream& out) const {
    out << "Numele pe care a fost facuta rezervarea este: " << Nume_Rezervare << std::endl;
    out << "Nr de persoane care participa este: " << Nr_Persoane << std::endl;
    out << "Ora la care masa a fost rezervata este: " << Ora << std::endl;
    out << "Data rezervarii este: " << Data << std::endl;
    out << "Zona restaurantului aleasa este: " << Zona_Restaurant << std::endl;
}

void Rezervare::citire(std::istream& in) {
    std::cout << "Numele pe care a fost facuta rezervarea este: " << std::endl;
    in >> Nume_Rezervare;
    std::cout << "Nr de persoane care participa este: " << std::endl;
    in >> Nr_Persoane;
    std::cout << "Ora la care masa a fost rezervata este: " << std::endl;
    in >> Ora;
    std::cout << "Data rezervarii este: " << std::endl;
    in >> Data;
    std::cout << "Zona restaurantului aleasa este: " << std::endl;
    in >> Zona_Restaurant;
}

int operator>(Rezervare& masa, const std::string& ora_limita) {
    if (masa.GetOra() > ora_limita) {
        return 0;
    } else {
        return 1;
    }
}

std::ostream& operator<<(std::ostream& out, const Rezervare& rezervare) {
    rezervare.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Rezervare& rezervare) {
    rezervare.citire(in);
    return in;
}

bool Rezervare::operator==(const Rezervare& masa) const {
    if (masa.Data == Data and Ora == masa.Ora)
        return true;
    else
        return false;
}

std::string Rezervare::GetData() {
    return Data;
}

std::string Rezervare::GetOra() {
    return Ora;
}

std::string Rezervare::GetZonaRestaurant() {
    return Zona_Restaurant;
}

std::string Rezervare::GetNumeRezervare() {
    return Nume_Rezervare;
}

int Rezervare::GetNrPersoane() const {
    return Nr_Persoane;
}

void Rezervare::SetNrPersoane(int nr) {
    Nr_Persoane = nr;
}

void Rezervare::SetOra(std::string ora) {
    Ora = std::move(ora);
}

void Rezervare::SetData(std::string data) {
    Data = std::move(data);
}

void Rezervare::ValidareIdRezervare() const {
    std::cout << "Rezervarea nu a fost facuta online, deci nu va putem verifica corectitudinea id-ului.\n";
}

double Rezervare::CalculeazaCostTotal(int numarPersoane, double pretPerPersoana) {
    return numarPersoane * pretPerPersoana;
}#include "Rezervare.h"

int Rezervare::count = 0;

Rezervare::Rezervare(int nr_persoane, std::string ora, std::string data, std::string zona_restaurant,
                     std::string nume_rezervare) :
        Nr_Persoane(nr_persoane), Ora(std::move(ora)), Data(std::move(data)), Zona_Restaurant(std::move(zona_restaurant)),
        Nume_Rezervare(std::move(nume_rezervare)) {count++;}

Rezervare::Rezervare(const Rezervare& masa) :
        Nr_Persoane(masa.Nr_Persoane), Ora(masa.Ora), Data(masa.Data), Zona_Restaurant(masa.Zona_Restaurant),
        Nume_Rezervare(masa.Nume_Rezervare) {}

Rezervare& Rezervare::operator=(Rezervare const& masa) {
    this->Nume_Rezervare = masa.Nume_Rezervare;
    this->Nr_Persoane = masa.Nr_Persoane;
    this->Ora = masa.Ora;
    this->Data = masa.Data;
    this->Zona_Restaurant = masa.Zona_Restaurant;
    return *this;
}

Rezervare::~Rezervare() {
    Nume_Rezervare = "";
    Nr_Persoane = 0;
    Ora = "";
    Data = "";
    Zona_Restaurant = "";
}

void Rezervare::afisare(std::ostream& out) const {
    out << "Numele pe care a fost facuta rezervarea este: " << Nume_Rezervare << std::endl;
    out << "Nr de persoane care participa este: " << Nr_Persoane << std::endl;
    out << "Ora la care masa a fost rezervata este: " << Ora << std::endl;
    out << "Data rezervarii este: " << Data << std::endl;
    out << "Zona restaurantului aleasa este: " << Zona_Restaurant << std::endl;
}

void Rezervare::citire(std::istream& in) {
    std::cout << "Numele pe care a fost facuta rezervarea este: " << std::endl;
    in >> Nume_Rezervare;
    std::cout << "Nr de persoane care participa este: " << std::endl;
    in >> Nr_Persoane;
    std::cout << "Ora la care masa a fost rezervata este: " << std::endl;
    in >> Ora;
    std::cout << "Data rezervarii este: " << std::endl;
    in >> Data;
    std::cout << "Zona restaurantului aleasa este: " << std::endl;
    in >> Zona_Restaurant;
}

int operator>(Rezervare& masa, const std::string& ora_limita) {
    if (masa.GetOra() > ora_limita) {
        return 0;
    } else {
        return 1;
    }
}

std::ostream& operator<<(std::ostream& out, const Rezervare& rezervare) {
    rezervare.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Rezervare& rezervare) {
    rezervare.citire(in);
    return in;
}

bool Rezervare::operator==(const Rezervare& masa) const {
    if (masa.Data == Data and Ora == masa.Ora)
        return true;
    else
        return false;
}

std::string Rezervare::GetData() {
    return Data;
}

std::string Rezervare::GetOra() {
    return Ora;
}

std::string Rezervare::GetZonaRestaurant() {
    return Zona_Restaurant;
}

std::string Rezervare::GetNumeRezervare() {
    return Nume_Rezervare;
}

int Rezervare::GetNrPersoane() const {
    return Nr_Persoane;
}

void Rezervare::SetNrPersoane(int nr) {
    Nr_Persoane = nr;
}

void Rezervare::SetOra(std::string ora) {
    Ora = std::move(ora);
}

void Rezervare::SetData(std::string data) {
    Data = std::move(data);
}

void Rezervare::ValidareIdRezervare() const {
    std::cout << "Rezervarea nu a fost facuta online, deci nu va putem verifica corectitudinea id-ului.\n";
}

double Rezervare::CalculeazaCostTotal(int numarPersoane, double pretPerPersoana) {
    return numarPersoane * pretPerPersoana;
}#include "Rezervare.h"

int Rezervare::count = 0;

Rezervare::Rezervare(int nr_persoane, std::string ora, std::string data, std::string zona_restaurant,
                     std::string nume_rezervare) :
        Nr_Persoane(nr_persoane), Ora(std::move(ora)), Data(std::move(data)), Zona_Restaurant(std::move(zona_restaurant)),
        Nume_Rezervare(std::move(nume_rezervare)) {count++;}

Rezervare::Rezervare(const Rezervare& masa) :
        Nr_Persoane(masa.Nr_Persoane), Ora(masa.Ora), Data(masa.Data), Zona_Restaurant(masa.Zona_Restaurant),
        Nume_Rezervare(masa.Nume_Rezervare) {}

Rezervare& Rezervare::operator=(Rezervare const& masa) {
    this->Nume_Rezervare = masa.Nume_Rezervare;
    this->Nr_Persoane = masa.Nr_Persoane;
    this->Ora = masa.Ora;
    this->Data = masa.Data;
    this->Zona_Restaurant = masa.Zona_Restaurant;
    return *this;
}

Rezervare::~Rezervare() {
    Nume_Rezervare = "";
    Nr_Persoane = 0;
    Ora = "";
    Data = "";
    Zona_Restaurant = "";
}

void Rezervare::afisare(std::ostream& out) const {
    out << "Numele pe care a fost facuta rezervarea este: " << Nume_Rezervare << std::endl;
    out << "Nr de persoane care participa este: " << Nr_Persoane << std::endl;
    out << "Ora la care masa a fost rezervata este: " << Ora << std::endl;
    out << "Data rezervarii este: " << Data << std::endl;
    out << "Zona restaurantului aleasa este: " << Zona_Restaurant << std::endl;
}

void Rezervare::citire(std::istream& in) {
    std::cout << "Numele pe care a fost facuta rezervarea este: " << std::endl;
    in >> Nume_Rezervare;
    std::cout << "Nr de persoane care participa este: " << std::endl;
    in >> Nr_Persoane;
    std::cout << "Ora la care masa a fost rezervata este: " << std::endl;
    in >> Ora;
    std::cout << "Data rezervarii este: " << std::endl;
    in >> Data;
    std::cout << "Zona restaurantului aleasa este: " << std::endl;
    in >> Zona_Restaurant;
}

int operator>(Rezervare& masa, const std::string& ora_limita) {
    if (masa.GetOra() > ora_limita) {
        return 0;
    } else {
        return 1;
    }
}

std::ostream& operator<<(std::ostream& out, const Rezervare& rezervare) {
    rezervare.afisare(out);
    return out;
}

std::istream& operator>>(std::istream& in, Rezervare& rezervare) {
    rezervare.citire(in);
    return in;
}

bool Rezervare::operator==(const Rezervare& masa) const {
    if (masa.Data == Data and Ora == masa.Ora)
        return true;
    else
        return false;
}

std::string Rezervare::GetData() {
    return Data;
}

std::string Rezervare::GetOra() {
    return Ora;
}

std::string Rezervare::GetZonaRestaurant() {
    return Zona_Restaurant;
}

std::string Rezervare::GetNumeRezervare() {
    return Nume_Rezervare;
}

int Rezervare::GetNrPersoane() const {
    return Nr_Persoane;
}

void Rezervare::SetNrPersoane(int nr) {
    Nr_Persoane = nr;
}

void Rezervare::SetOra(std::string ora) {
    Ora = std::move(ora);
}

void Rezervare::SetData(std::string data) {
    Data = std::move(data);
}

void Rezervare::ValidareIdRezervare() const {
    std::cout << "Rezervarea nu a fost facuta online, deci nu va putem verifica corectitudinea id-ului.\n";
}

double Rezervare::CalculeazaCostTotal(int numarPersoane, double pretPerPersoana) {
    return numarPersoane * pretPerPersoana;
}
