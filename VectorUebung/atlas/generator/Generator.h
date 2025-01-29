//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

namespace atlas::generator {

    template<class T>
    class Generator {
    public:
        virtual ~Generator() = default;
        [[nodiscard]]
        virtual T next() noexcept = 0;
    };

} // generator
