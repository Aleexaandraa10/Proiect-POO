#ifndef MANCARE_H
#define MANCARE_H

#include <iostream>
#include<string>
#include <utility>
#include<vector>

class Mancare {
private:
    std::string Nume_Preparat;
    std::string Categorie_Preparat;
    int Gramaj;
    int Pret;

public:
    Mancare(std::string nume, std::string categorie, int gramaj, int pret);

    [[nodiscard]] std::string GetNume() const;
    [[nodiscard]] std::string GetCategorie() const;
    [[nodiscard]] int GetGramaj() const;
    [[nodiscard]] int GetPret() const;
};

#endif // MANCARE_H
