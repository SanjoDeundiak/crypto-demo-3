//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include <cassert>
#include "RSAKeyGenerator.h"
#include "gmpxx.h"

RSAKeyGenerator::RSAKeyGenerator(const PrimeGenerator &primeGenerator) : primeGenerator(primeGenerator) {}

std::pair<RSAPrivateKey, RSAPublicKey> RSAKeyGenerator::generate() {
    auto e = mpz_class(65537);

    auto p(primeGenerator.generate()), q(primeGenerator.generate());
    mpz_class n;
    mpz_mul(n.get_mpz_t(), p.get_mpz_t(), q.get_mpz_t());

    auto pm1 = p;
    pm1 -= 1;

    auto qm1 = q;
    qm1 -= 1;

    mpz_class lambda;
    mpz_mul(lambda.get_mpz_t(), pm1.get_mpz_t(), qm1.get_mpz_t());

    mpz_class gcdRes;
    mpz_gcd(gcdRes.get_mpz_t(), lambda.get_mpz_t(), e.get_mpz_t());

    assert(gcdRes.get_ui() == 1);

    mpz_class d;
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(), lambda.get_mpz_t());

    RSAPrivateKey privateKey(d, n);
    RSAPublicKey publicKey(e, n);

    return std::make_pair(privateKey, publicKey);
}