#include "EvaluareAtmosfera.h"
#include<iostream>

template<typename T>
EvaluareAtmosfera<T>::EvaluareAtmosfera(T r) : rating(r) {}

template<typename T>
void EvaluareAtmosfera<T>::info() const {
    std::cout << "Evaluare Atmosfera: " << rating << std::endl;
}

template<typename T>
T EvaluareAtmosfera<T>::getRating() const {
    return rating;
}

template class EvaluareAtmosfera<int>;
