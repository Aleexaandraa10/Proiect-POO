#ifndef EVALUAREMANCARE_H
#define EVALUAREMANCARE_H

#include "Evaluare.h"
#include<iostream>

template<typename T>
class EvaluareMancare: public Evaluare<T>{
    T rating;
public:
    explicit EvaluareMancare(T r);
    void info() const override;
    T getRating() const override;
};

#endif //EVALUAREMANCARE_H
