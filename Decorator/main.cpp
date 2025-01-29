#include <iostream>
#include "math/CalculatorImpl.h"
#include "math/CalculatorLogger.h"
#include "math/CalculatorSecure.h"
#include "Client.h"

int main() {

    math::CalculatorImpl impl;
    math::CalculatorLogger logger{impl};
    math::CalculatorSecure secure{logger};

    client::Client c{secure};

    c.go();
    return 0;
}

