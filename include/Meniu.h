#ifndef MENIU_H
#define MENIU_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Rezervare.h"
#include "RezervareOnline.h"
#include "RezervareTelefonica.h"
#include "RezervareAbonament.h"
#include "Mancare.h"
#include "Exceptii.h"

#include "Evaluare.h"
#include "EvaluareMancare.h"
#include "EvaluareAtmosfera.h"
#include "EvaluareServire.h"

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
