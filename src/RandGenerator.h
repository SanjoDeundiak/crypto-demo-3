//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_RANDGENERATOR_H
#define LAB3_RANDGENERATOR_H

#include "gmpxx.h"

class RandGenerator {
public:
    RandGenerator();

    mpz_class generate();

private:
    gmp_randstate_t state;
};


#endif //LAB3_RANDGENERATOR_H
