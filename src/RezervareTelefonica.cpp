#include "RezervareTelefonica.h"

#include <utility>

RezervareTelefonica::RezervareTelefonica(int nr_persoane, const std::string& ora, const std::string& data,
                                         const std::string& zona_restaurant, const std::string& nume_rezervare,
                                         std::string  numar) :
        Rezervare(nr_persoane, ora, data, zona_restaurant, nume_rezervare), NumarTelefon(std::move(numar)) {}

std::string RezervareTelefonica::GetTelefon() const {
    return NumarTelefon;
}

RezervareTelefonica& RezervareTelefonica::operator=(const RezervareTelefonica& telefon) {
    Rezervare::operator=(telefon);
    this->NumarTelefon = telefon.NumarTelefon;
    return *this;
}

RezervareTelefonica::RezervareTelefonica(const RezervareTelefonica& rt): Rezervare(rt), NumarTelefon(rt.NumarTelefon){}
bool RezervareTelefonica::operator==(const RezervareTelefonica& rezervare) const {
    return (Rezervare::operator==(rezervare) && NumarTelefon == rezervare.NumarTelefon);
}

RezervareTelefonica::~RezervareTelefonica() = default;

void RezervareTelefonica::afisare(std::ostream& out) const {
    Rezervare::afisare(out);
    out << "Iar: " << NumarTelefon << " este nr. de telefon de pe care a fost facuta rezervarea\n";
}

void RezervareTelefonica::citire(std::istream& in) {
    Rezervare::citire(in);
    std::cout << "In plus, va rugam introduceti si nr.de telefon de pe care ati facut rezervarea:\n";
    in >> NumarTelefon;
}

void RezervareTelefonica::Schimba_NumarTelefon(const std::string& noulNumar) {
    if (noulNumar.size() != 10) {
        throw std::invalid_argument("Numarul de telefon este invalid");
        //aruncă o excepție de tipul std::invalid_argument atunci când noul
        // număr de telefon nu are exact 10 caractere.
    }
    if (noulNumar != NumarTelefon) {
        std::cout << "Schimbarea numarului de telefon pentru rezervarea dvs se poate efectua!\n";
        NumarTelefon = noulNumar;
        std::cout << "-----------------------------------------------------------------------\n";
        std::cout << "Cerere efectuata!\n";
    } else {
        std::cout << "Numarul de telefon nou este identic cu cel vechi. Nu s-a realizat nicio modificare." << std::endl;
    }
}
