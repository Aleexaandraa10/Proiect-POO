#include "Exceptii.h"

const char* DataInvalidaException::what() const noexcept {
    return "Data introdusa nu este valida!";
}