//
// Created by chicha-man on 14.10.2021.
//

#ifndef LAB3_3_MENU_H
#define LAB3_3_MENU_H


#include <iostream>
#include <limits>

#include "PCB_d.h"

template <class T>
int get_num(T& a) {
    std::cin >> a;

    while (!std::cin.good()) {
        if (std::cin.bad()) throw std::runtime_error("Fatal error");
        if (std::cin.eof()) return 1;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid input. Please, try again." << std::endl;
        std::cin >> a;
    }
    return 0;
}
int dialog();



#endif //LAB3_3_MENU_H
