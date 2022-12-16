//
// Created by ASUS ROG on 16.12.2022.
//

#ifndef TEMA2POO_MENU_H
#define TEMA2POO_MENU_H

#include <string>
#include <vector>
#include "Entertainment.h"
using namespace std;

class Menu {
    vector<Entertainment*> ent;

public:
    Menu();

    Menu(const vector<Entertainment*> &ent);

    int option();

    void option1();

    void option2();

    void option3();

    void option4();

    void interactiveMenu();

    virtual ~Menu();

};

#endif //TEMA2POO_MENU_H
