#include <string>
#include "InvalidInputException.h"
using namespace std;

// Clasa InvalidInputException a fost creata pentru ca atunci cand user-ul adauga un film in lista, acesta sa fie
// obligat sa introduca un an valid pentru atributul releaseYear (un an dinaintea lui 2023)

InvalidInputException::InvalidInputException(const std::string &msg) : msg(msg) {}

const char* InvalidInputException::what() const noexcept {
    return msg.c_str();
}
