#include "RezervareOnline.h"

#include <utility>

RezervareOnline::RezervareOnline(int nr_persoane, const std::string& ora, const std::string& data,
                                 const std::string& zona_restaurant, const std::string& nume_rezervare,
                                 std::string  id) :
        Rezervare(nr_persoane, ora, data, zona_restaurant, nume_rezervare), Id_Rezervare(std::move(id)) {}
        //apelarea constructorului din clasa de bază din constructori din derivate

std::string RezervareOnline::GetId() const {
    return Id_Rezervare;
}

RezervareOnline& RezervareOnline::operator=(const RezervareOnline& online) { //operatorul de atribuire
    Rezervare::operator=(online);
    this->Id_Rezervare = online.Id_Rezervare;
    return *this;
}

RezervareOnline::RezervareOnline( const RezervareOnline& ro): Rezervare(ro), Id_Rezervare(ro.Id_Rezervare){}


bool RezervareOnline::operator==(const RezervareOnline& rezervare) const {
    return (Rezervare::operator==(rezervare) && Id_Rezervare == rezervare.Id_Rezervare);
}

RezervareOnline::~RezervareOnline() = default;

void RezervareOnline::afisare(std::ostream& out) const {
    Rezervare::afisare(out);
    out << "Iar: " << Id_Rezervare << " este id-ul rezervarii\n";
}

void RezervareOnline::citire(std::istream& in) {
    Rezervare::citire(in);
    std::cout << "In plus, va rugam introduceti si id-ul rezervarii online:\n";
    in >> Id_Rezervare;
}

void RezervareOnline::ValidareIdRezervare() const{
    if (Id_Rezervare.length() >= 2 && Id_Rezervare.length() <= 10) {
        for (char c : Id_Rezervare) {
            if (!std::isalnum(c)) {
                std::cout << "Id-ul este format din caractere care nu sunt litere sau cifre.\n";
            }
        }
        std::cout << "Id-ul este corect!\n";
    } else {
        std::cout << "Id-ul nu se incadreaza in limitele noastre de lungime.\n";
    }
}
