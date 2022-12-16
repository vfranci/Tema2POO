//
// Created by ASUS ROG on 16.12.2022.
//

#ifndef TEMA2OOP_INVALIDINPUTEXCEPTION_H
#define TEMA2OOP_INVALIDINPUTEXCEPTION_H

#include <string>
#include <exception>
using namespace std;

class InvalidInputException : public exception {

    string msg;

public:

    InvalidInputException(const string &msg);

    const char* what() const noexcept override;
};

#endif //TEMA2OOP_INVALIDINPUTEXCEPTION_H
