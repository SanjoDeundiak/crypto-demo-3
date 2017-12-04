//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_RSAPUBLICKEY_H
#define LAB3_RSAPUBLICKEY_H

#include "gmpxx.h"

class RSAPublicKey {
public:
    explicit RSAPublicKey(const mpz_class &e, const mpz_class &n);

    const mpz_class &e() const { return _e; }
    const mpz_class &n() const { return _n; }

private:
    mpz_class _e, _n;
};


#endif //LAB3_RSAPUBLICKEY_H
