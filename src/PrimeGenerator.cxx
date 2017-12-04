//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include <iostream>
#include "PrimeGenerator.h"

PrimeGenerator::PrimeGenerator(const RandGenerator &randGenerator) : randGenerator(randGenerator) {}

void PrimeGenerator::printFalsePrime(const mpz_class &falsePrime) const {
    std::cout << "PrimeGenerator: found false prime: " << falsePrime.get_str(16) << std::endl;
}

void PrimeGenerator::printPrime(const mpz_class &prime) const {
    std::cout << "PrimeGenerator: found prime: " << prime.get_str(16) << std::endl;
}

mpz_class PrimeGenerator::generate() {
    auto rand = randGenerator.generate();
    auto c = rand;
    c %= 2;

    if (c == 0) {
        printFalsePrime(rand);
        rand += 1;
    }

    while (true) {
        if (mpz_probab_prime_p(rand.__get_mp(), 40)) {
            printPrime(rand);
            return rand;
        }

        printFalsePrime(rand);
        rand += 2;
    }
}