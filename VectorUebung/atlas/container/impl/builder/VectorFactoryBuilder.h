//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <iostream>
#include "../../VectorFactory.h"
#include "../sequential/VectorFactorySequentialImpl.h"
#include "../decorators/VectorFactoryBenchmarkDecorator.h"
#include "../decorators/VectorFactoryLoggerDecorator.h"
#include "../decorators/VectorFactorySecureDecorator.h"
#include "../../../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../../../time/impl/StopwatchImpl.h"

namespace atlas::container {
    template<class T>
    class VectorFactoryBuilder {

        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::container::VectorFactorySequentialImpl<int>;

        using VECTOR_FACTORY_BENCHMARK = atlas::container::VectorFactoryBenchmarkDecorator<int>;
        using VECTOR_FACTORY_LOGGER = atlas::container::VectorFactoryLoggerDecorator<int>;
        using VECTOR_FACTORY_SECURE = atlas::container::VectorFactorySecureDecorator<int>;

        using STOPWATCH = std::unique_ptr<atlas::time::Stopwatch>;
        using GENERATOR = std::unique_ptr<atlas::generator::Generator<T>>;

        inline static bool benchmark{false};
        inline static bool logger{false};
        inline static bool secure{false};


    public:

        static bool isLogger() {
            return logger;
        }

        static void setLogger(bool logger) {
            VectorFactoryBuilder::logger = logger;
        }

        static bool isBenchmark() {
            return benchmark;
        }

        static void setBenchmark(bool benchmark) {
            VectorFactoryBuilder::benchmark = benchmark;
        }

        static bool isSecure() {
            return secure;
        }

        static void setSecure(bool secure) {
            VectorFactoryBuilder::secure = secure;
        }


        static VECTOR_FACTORY createWithGenerator(GENERATOR generator) {
            VECTOR_FACTORY result;
            STOPWATCH watch = std::make_unique<atlas::time::StopwatchImpl>();
            result = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generator));

            if(logger) result = std::make_unique<VECTOR_FACTORY_LOGGER >(std::move(result));
            if(secure) result = std::make_unique<VECTOR_FACTORY_SECURE >(std::move(result));
            if(benchmark) result = std::make_unique<VECTOR_FACTORY_BENCHMARK>(std::move(result), std::move(watch));

            return result;
        }
    };
}
