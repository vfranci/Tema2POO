
#include <string>
#include "OutOfBoundsException.h"
using namespace std;

// Clasa OutOfBoundsException a fost creata pentru a impune un numar maxim de filme si seriale pe care user-ul le poate
// avea in lista sa.

OutOfBoundsException::OutOfBoundsException(const string &msg) : msg(msg) {}

const char* OutOfBoundsException::what() const noexcept {
    return msg.c_str();
}
