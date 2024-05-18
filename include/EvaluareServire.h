#ifndef EVALUARESERVIRE_H
#define EVALUARESERVIRE_H

#include<Evaluare.h>
#include<iostream>

template<typename T>
class EvaluareServire: public Evaluare<T>{
private:
    T rating;
public:
    explicit EvaluareServire(T r);
    void info() const override;
    T getRating() const override;

};



#endif //EVALUARESERVIRE_H
