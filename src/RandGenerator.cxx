//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include <gmp.h>
#include <iostream>
#include "RandGenerator.h"

RandGenerator::RandGenerator() {
    FILE *f = fopen("/dev/urandom", "rb");
    if (!f)
        throw std::runtime_error("Error opening /dev/urandom");

    mpz_class seed = 0;
    for ( size_t i = 0; i < 32; ++i ) {
        int n = fgetc(f);
        seed = (seed << 8) | n;
    }
    fclose(f);

    gmp_randinit_default(state);
    gmp_randseed(state, seed.get_mpz_t());

    std::cout << "Random seed: " << seed.get_str(16) << std::endl;
}

mpz_class RandGenerator::generate() {
    mpz_class rand;
    mpz_urandomb(rand.get_mpz_t(), state, 256);

    return rand;
}