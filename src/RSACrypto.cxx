//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include <cassert>
#include "RSACrypto.h"
#include "RSAPublicKey.h"
#include "RSAPrivateKey.h"
#include "GMPExporter.h"
#include "gmpxx.h"

std::vector<unsigned char> RSACrypto::encrypt(const std::vector<unsigned char> &message, const RSAPublicKey &publicKey) const {
    mpz_class m = GMPExporter::importNumber(message);

    mpz_class res;
    mpz_powm_sec(res.get_mpz_t(), m.get_mpz_t(), publicKey.e().get_mpz_t(), publicKey.n().get_mpz_t());

    return GMPExporter::exportNumber(res);
}

std::vector<unsigned char> RSACrypto::decrypt(const std::vector<unsigned char> &message,
                                              const RSAPrivateKey &privateKey) const {
    mpz_class m = GMPExporter::importNumber(message);

    mpz_class res;
    mpz_powm_sec(res.get_mpz_t(), m.get_mpz_t(), privateKey.d().get_mpz_t(), privateKey.n().get_mpz_t());

    return GMPExporter::exportNumber(res);
}

std::vector<unsigned char> RSACrypto::generateSignature(const std::vector<unsigned char> &message,
                                                        const RSAPrivateKey &privateKey) const {
    mpz_class m = GMPExporter::importNumber(message);

    mpz_class res;
    mpz_powm_sec(res.get_mpz_t(), m.get_mpz_t(), privateKey.d().get_mpz_t(), privateKey.n().get_mpz_t());

    return GMPExporter::exportNumber(res);
}

bool RSACrypto::verifySignature(const std::vector<unsigned char> &message, const std::vector<unsigned char> &signature,
                                const RSAPublicKey &publicKey) const {
    mpz_class m = GMPExporter::importNumber(message);
    mpz_class s = GMPExporter::importNumber(signature);

    mpz_class res;
    mpz_powm_sec(res.get_mpz_t(), s.get_mpz_t(), publicKey.e().get_mpz_t(), publicKey.n().get_mpz_t());

    return mpz_cmp(res.get_mpz_t(), m.get_mpz_t()) == 0;
}