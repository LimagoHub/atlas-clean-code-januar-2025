//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

#include <iostream>
#include "math/Calculator.h"
namespace client {

    class Client {
        math::Calculator &calc;

    public:
        explicit Client(math::Calculator &calc) : calc(calc) {}

        void go() {
            std::cout << calc.add(3,4) << std::endl;

        }
    };

} // client
