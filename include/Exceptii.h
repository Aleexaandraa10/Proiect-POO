#ifndef RESTAURANT_EXCEPTION_H
#define RESTAURANT_EXCEPTION_H

#include <exception>

class RestaurantException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override = 0;
};

class DataInvalidaException : public RestaurantException {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

#endif // RESTAURANT_EXCEPTION_H
