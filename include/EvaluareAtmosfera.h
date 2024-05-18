#ifndef EVALUAREATMOSFERA_H
#define EVALUAREATMOSFERA_H

#include "Evaluare.h"
#include <iostream>

template<typename T>
class EvaluareAtmosfera : public Evaluare<T> {
    T rating;
public:
    explicit EvaluareAtmosfera(T r);
    void info() const override;
    T getRating() const override;
};

#endif // EVALUAREATMOSFERA_H