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

    std::string GetNume() const;
    std::string GetCategorie() const;
    int GetGramaj() const;
    int GetPret() const;
};

#endif // MANCARE_H