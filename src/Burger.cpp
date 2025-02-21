#include "Burger.h"

std::ostream& operator<<(std::ostream& out, const Burger& b){
    out << "Tip carne: " << b.Carne << std::endl;
    out << "Tip branza: " << b.Branza << std::endl;
    out << "Tip sos: " << b.Sos << std::endl;
    out << "Tip legume: " << b.Legume << std::endl;
    return out;
}

Burger_builder& Burger_builder::tip_branza(const std::string& tip) {
    b.Branza = tip;
    return *this;
}

Burger_builder& Burger_builder::tip_carne(const std::string& tip) {
    b.Carne = tip;
    return *this;
}

Burger_builder& Burger_builder::tip_sos(const std::string& tip) {
    b.Sos = tip;
    return *this;
}

Burger_builder& Burger_builder::tip_legume(const std::string& tip) {
    b.Legume = tip;
    return *this;
}

Burger Burger_builder::build() {
    return b;
}