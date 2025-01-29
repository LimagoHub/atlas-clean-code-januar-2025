//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

#include <iostream>
#include "Calculator.h"
namespace math {

    class CalculatorLogger: public Calculator{

        Calculator & calculator;

    public:
        explicit CalculatorLogger(Calculator &calculator) : calculator(calculator) {}

        double add(double a, double b) override {
            std::cout << "Add wurde gerufen" << std::endl;
            return calculator.add(a,b);
        }
    };

} // math
