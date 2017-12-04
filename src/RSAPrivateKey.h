//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_RSAPRIVATEKEY_H
#define LAB3_RSAPRIVATEKEY_H

#include "gmpxx.h"

class RSAPrivateKey {
public:
    explicit RSAPrivateKey(const mpz_class &d, const mpz_class &n);

    const mpz_class &d() const { return _d; }
    const mpz_class &n() const { return _n; }

private:
    mpz_class _d, _n;
};


#endif //LAB3_RSAPRIVATEKEY_H
