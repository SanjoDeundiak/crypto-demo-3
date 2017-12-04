//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_RSAKEYGENERATOR_H
#define LAB3_RSAKEYGENERATOR_H

#include "PrimeGenerator.h"
#include "gmpxx.h"
#include "RSAPrivateKey.h"
#include "RSAPublicKey.h"

class RSAKeyGenerator {
public:
    explicit RSAKeyGenerator(const PrimeGenerator &primeGenerator);

    std::pair<RSAPrivateKey, RSAPublicKey> generate();

private:
    PrimeGenerator primeGenerator;
};


#endif //LAB3_RSAKEYGENERATOR_H
