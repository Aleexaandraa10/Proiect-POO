#include "EvaluareServire.h"

template<typename T>
EvaluareServire<T>::  EvaluareServire(T r): rating(r) {}

template<typename T>
void EvaluareServire<T>::info() const{
    std::cout << "Evaluarea servirii: " << rating << std::endl;
}

template<typename T>
T EvaluareServire<T>::getRating() const {
    return rating;
}

template class EvaluareServire<int>;
