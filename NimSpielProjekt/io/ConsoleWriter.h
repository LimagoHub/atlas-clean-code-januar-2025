//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <iostream>
#include "Writer.h"
namespace io {

    class ConsoleWriter:public Writer {
    public:
        void write(std::string message) override {
            std::cout << message << std::endl;
        }
    };

} // io
