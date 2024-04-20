#include "Mancare.h"
#include <iostream>
#include<string>
#include <utility>
#include<vector>

Mancare::Mancare(std::string nume, std::string categorie, int gramaj, int pret)
        : Nume_Preparat(std::move(nume)), Categorie_Preparat(std::move(categorie)), Gramaj(gramaj), Pret(pret) {}

std::string Mancare::GetNume() const {
    return Nume_Preparat;
}

std::string Mancare::GetCategorie() const {
    return Categorie_Preparat;
}

int Mancare::GetGramaj() const {
    return Gramaj;
}

int Mancare::GetPret() const {
    return Pret;
}