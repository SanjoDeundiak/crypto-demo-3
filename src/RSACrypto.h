//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_RSACRYPTO_H
#define LAB3_RSACRYPTO_H

#include <vector>

class RSAPublicKey;
class RSAPrivateKey;

class RSACrypto {
public:
    std::vector<unsigned char> encrypt(const std::vector<unsigned char> &message, const RSAPublicKey &publicKey) const;
    std::vector<unsigned char> decrypt(const std::vector<unsigned char> &message, const RSAPrivateKey &privateKey) const;
    std::vector<unsigned char> generateSignature(const std::vector<unsigned char> &message, const RSAPrivateKey &privateKey) const;
    bool verifySignature(const std::vector<unsigned char> &message, const std::vector<unsigned char> &signature,
                         const RSAPublicKey &publicKey) const;
};


#endif //LAB3_RSACRYPTO_H
