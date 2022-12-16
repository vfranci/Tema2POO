//
// Created by ASUS ROG on 16.12.2022.
//

#ifndef TEMA2POO_OUTOFBOUNDSEXCEPTION_H
#define TEMA2POO_OUTOFBOUNDSEXCEPTION_H

#include <string>
#include <exception>
using namespace std;

class OutOfBoundsException : public exception {

    string msg;

public:

    OutOfBoundsException(const string &msg);

    const char* what() const noexcept override;
};

#endif //TEMA2POO_OUTOFBOUNDSEXCEPTION_H
