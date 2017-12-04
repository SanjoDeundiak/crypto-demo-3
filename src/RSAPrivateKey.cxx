//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include "RSAPrivateKey.h"

RSAPrivateKey::RSAPrivateKey(const mpz_class &d, const mpz_class &n) : _d(d), _n(n) {}