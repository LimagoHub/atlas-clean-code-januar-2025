//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once
#include "Calculator.h"
namespace math {

    class CalculatorImpl: public Calculator {
    public:
        double add(double a, double b) override {
            return a + b;
        }
    };

} // math
