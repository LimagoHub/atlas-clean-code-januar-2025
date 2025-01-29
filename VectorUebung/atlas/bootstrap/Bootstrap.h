//
// Created by JoachimWagner on 29.01.2025.
//

#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h"
#include "../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../container/impl/builder/VectorFactoryBuilder.h"

namespace atlas::bootstrap {

    class Bootstrap {
        using VECTOR_FACTORY_BUILDER = atlas::container::VectorFactoryBuilder<int>;
        using VECTOR_FACTORY = std::unique_ptr<atlas::container::VectorFactory<int>>;
        using GENERATOR = std::unique_ptr<generator::Generator<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;



    public:
        auto startApplication() const->void{
            auto generator = createGenerator();
            auto vectorFactory = createVectorFactory(std::move(generator));
            auto client = createClient(std::move(vectorFactory));
            client->doSomethingWithLargeVector();
        }

    private:
        static GENERATOR createGenerator() {
            GENERATOR generator = std::make_unique<atlas::generator::MersenneTwisterNumberGenerator>();
            return generator;
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR generator) {

            VECTOR_FACTORY_BUILDER::setSecure(true);
            VECTOR_FACTORY_BUILDER::setBenchmark(true);
            VECTOR_FACTORY_BUILDER::setLogger(true);
            VECTOR_FACTORY vectorFactory = VECTOR_FACTORY_BUILDER::createWithGenerator(std::move(generator));
            return vectorFactory;
        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }


    };

} // bootstrap
