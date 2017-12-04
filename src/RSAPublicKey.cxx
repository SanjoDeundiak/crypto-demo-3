//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include "RSAPublicKey.h"

RSAPublicKey::RSAPublicKey(const mpz_class &e, const mpz_class &n) : _e(e), _n(n) {}