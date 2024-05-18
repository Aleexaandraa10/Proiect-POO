#ifndef OOP_BURGER_H
#define OOP_BURGER_H

#include <iostream>

class Burger{
    std::string Branza;
    std::string Carne;
    std::string Sos;
    std::string Legume;
public:
    Burger() = default;

    friend class Burger_builder;
    friend std::ostream& operator<<(std::ostream& out, const Burger& b);
};

class Burger_builder{
private:
    Burger b;
public:
    Burger_builder() = default;
    Burger_builder& tip_branza(const std::string& tip);
    Burger_builder& tip_carne(const std::string& tip);
    Burger_builder& tip_sos(const std::string& tip);
    Burger_builder& tip_legume(const std::string& tip);
    Burger build();

};
#endif //OOP_BURGER_H
