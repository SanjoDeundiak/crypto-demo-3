//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_PRIMEGENERATOR_H
#define LAB3_PRIMEGENERATOR_H

#include "RandGenerator.h"
#include "gmpxx.h"

class PrimeGenerator {
public:
    explicit PrimeGenerator(const RandGenerator &randGenerator);

    mpz_class generate();

private:
    RandGenerator randGenerator;

    void printFalsePrime(const mpz_class &) const;
    void printPrime(const mpz_class &) const;
};


#endif //LAB3_PRIMEGENERATOR_H
