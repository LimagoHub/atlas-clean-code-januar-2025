//
// Created by JoachimWagner on 28.01.2025.
//

#pragma once

#include <string>

namespace io {

    class Writer {
    public:
        virtual ~Writer() = default;
        virtual void write(std::string message) = 0;
    };

} // io
