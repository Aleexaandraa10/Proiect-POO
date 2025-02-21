#ifndef MENIU_H
#define MENIU_H

#include "Restaurant.h"

class Meniu{
private:
    Meniu() = default;
public:
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;

    static Meniu& get_meniu();
    static void ControlPanel();
};

#endif //MENIU_H
