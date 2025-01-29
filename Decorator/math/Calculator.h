//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

namespace math {

    class Calculator {
    public:
        virtual ~Calculator() = default;

        virtual double add(double a, double b) = 0;
    };

} // math
