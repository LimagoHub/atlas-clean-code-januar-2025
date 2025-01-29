//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

#include <chrono>

namespace atlas::time {

    class Stopwatch {
    public:
        virtual ~Stopwatch()=default;

        virtual void start() noexcept = 0;
        virtual void stop()  noexcept = 0;
        [[nodiscard]]
        virtual std::chrono::milliseconds getDurationToMilliseconds() const noexcept = 0;
    };

} // time
