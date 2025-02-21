#ifndef EVALUARE_H
#define EVALUARE_H

//nu s-a mai creat un fisier Evaluare.cpp deoarece toate fct sunt virtuale si nu mai aveam nevoie de alta implementare
template<typename T>
class Evaluare{
public:
    virtual ~Evaluare()= default;
    virtual void info() const = 0;
    virtual T getRating() const = 0;
};

#endif //EVALUARE_H
