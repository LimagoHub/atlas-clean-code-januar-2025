//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../generator/impl/random/MersenneTwisterNumberGeneratorFactory.h"
#include "../container/impl/builder/VectorFactoryBuilder.h"

namespace atlas::bootstrap {

    class Bootstrap {
        using VECTOR_FACTORY_BUILDER = atlas::container::VectorFactoryBuilder<int>;
        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;
        using GENERATOR_BUILDER = std::unique_ptr<generator::GeneratorBuilder<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;



    public:
        auto startApplication() const->void{
            const size_t availableProcessors = std::thread::hardware_concurrency();
            for(size_t threadCount = 0; threadCount <= availableProcessors + 1; ++threadCount){
                run(threadCount);
            }
        }

    private:

        static auto run(const size_t threadcount) -> void {
            auto generatorBuilder = createGeneratorBuilder();
            auto vectorFactory = createVectorFactory(std::move(generatorBuilder), threadcount);
            auto client = createClient(std::move(vectorFactory));
            client->doSomethingWithLargeVector();
        }

        static GENERATOR_BUILDER createGeneratorBuilder() {
            GENERATOR_BUILDER generatorBuilder = std::make_unique<atlas::generator::MersenneTwisterNumberGeneratorFactory>();
            return generatorBuilder;
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR_BUILDER generatorBuilder, size_t threadcount) {
            VECTOR_FACTORY_BUILDER::setThreadCount(threadcount);
            VECTOR_FACTORY_BUILDER::setSecure(true);
            VECTOR_FACTORY_BUILDER::setBenchmark(true);
            VECTOR_FACTORY_BUILDER::setLogger(true);
            VECTOR_FACTORY vectorFactory = VECTOR_FACTORY_BUILDER::createWithGeneratorBuilder(
                    std::move(generatorBuilder));
            return vectorFactory;
        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }


    };

} // bootstrap
