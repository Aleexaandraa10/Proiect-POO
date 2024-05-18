#include "EvaluareMancare.h"


template<typename T>
EvaluareMancare<T>::EvaluareMancare(T r): rating(r) {}

template<typename T>
void EvaluareMancare<T>::info() const{
    std::cout << "Evaluarea servirii: " << rating << std::endl;
}

template<typename T>
T EvaluareMancare<T>::getRating() const {
    return rating;
}

// Instanțierea explicită a template-ului pentru int
template class EvaluareMancare<int>;