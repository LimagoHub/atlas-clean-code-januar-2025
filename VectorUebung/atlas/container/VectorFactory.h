//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once
#include <vector>
#include <memory>

namespace atlas::container {

    template<class T>
    class VectorFactory {
        using VECTOR_POINTER = std::shared_ptr<std::vector<T>>;
    public:
        virtual ~VectorFactory() = default;
        virtual VECTOR_POINTER createAndFillVector(const size_t size) noexcept = 0;

    };

} // container
