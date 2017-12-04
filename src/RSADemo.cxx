//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include <iostream>
#include <cassert>
#include "RSADemo.h"
#include "RandGenerator.h"
#include "PrimeGenerator.h"
#include "RSAKeyGenerator.h"
#include "RSACrypto.h"
#include "GMPExporter.h"

void RSADemo::runDemo() const {
    RandGenerator randGenerator;
    PrimeGenerator primeGenerator(randGenerator);
    RSAKeyGenerator keyGenerator(primeGenerator);

    std::cout << "GENERATING FIRST KEYPAIR" << std::endl;
    auto keyPair1 = keyGenerator.generate();

    std::cout << "Private key1: " << keyPair1.first.d().get_str(16) << std::endl;
    std::cout << "Public key1: " << keyPair1.second.e().get_str(16) << std::endl;
    std::cout << "Modulus1: " << keyPair1.first.n().get_str(16) << std::endl;

    std::cout << "GENERATING SECOND KEYPAIR" << std::endl;
    auto keyPair2 = keyGenerator.generate();

    std::cout << "Private key2: " << keyPair2.first.d().get_str(16) << std::endl;
    std::cout << "Public key2: " << keyPair2.second.e().get_str(16) << std::endl;
    std::cout << "Modulus2: " << keyPair2.first.n().get_str(16) << std::endl;

    assert(mpz_cmp(keyPair1.second.n().get_mpz_t(), keyPair2.second.n().get_mpz_t()) > 0);

    RSACrypto crypto;

    mpz_class plainText = randGenerator.generate();
    auto plainTextData = GMPExporter::exportNumber(plainText);
    std::cout << "Plain text: " << plainText.get_str(16) << std::endl;
    auto encryptedData1 = crypto.encrypt(plainTextData, keyPair2.second);
    std::cout << "Cipher text1: " << GMPExporter::importNumber(encryptedData1).get_str(16) << std::endl;
    auto signature1 = crypto.generateSignature(plainTextData, keyPair1.first);
    std::cout << "Signature1: " << GMPExporter::importNumber(signature1).get_str(16) << std::endl;
    auto decryptedData1 = crypto.decrypt(encryptedData1, keyPair2.first);
    std::cout << "Decrypted text1: " << GMPExporter::importNumber(decryptedData1).get_str(16) << std::endl;
    std::cout << "Verified1: " << crypto.verifySignature(decryptedData1, signature1, keyPair1.second) << std::endl;

    auto encryptedData2 = crypto.encrypt(plainTextData, keyPair1.second);
    std::cout << "Cipher text2: " << GMPExporter::importNumber(encryptedData2).get_str(16) << std::endl;
    auto signature2 = crypto.generateSignature(plainTextData, keyPair2.first);
    std::cout << "Signature2: " << GMPExporter::importNumber(signature2).get_str(16) << std::endl;
    auto decryptedData2 = crypto.decrypt(encryptedData2, keyPair1.first);
    std::cout << "Decrypted text2: " << GMPExporter::importNumber(decryptedData2).get_str(16) << std::endl;
    std::cout << "Verified2: " << crypto.verifySignature(decryptedData2, signature2, keyPair2.second) << std::endl;


    std::cout << "Generating random symmetric key" << std::endl;
    auto key = randGenerator.generate();
    std::cout << "Symmetric key: " << key.get_str(16) << std::endl;

    auto keySignature = crypto.generateSignature(GMPExporter::exportNumber(key), keyPair2.first);
    std::cout << "Signature1: " << GMPExporter::importNumber(keySignature).get_str(16) << std::endl;

    auto encryptedKeySignature = crypto.encrypt(keySignature, keyPair1.second);
    std::cout << "Encrypted key signature1: " << GMPExporter::importNumber(encryptedKeySignature).get_str(16) << std::endl;

    auto encryptedKey = crypto.encrypt(GMPExporter::exportNumber(key), keyPair1.second);
    std::cout << "Encrypted key1: " << GMPExporter::importNumber(encryptedKey).get_str(16) << std::endl;

    auto decryptedKey = crypto.decrypt(encryptedKey, keyPair1.first);
    std::cout << "Decrypted key1: " << GMPExporter::importNumber(decryptedKey).get_str(16) << std::endl;

    auto decryptedKeySignature = crypto.decrypt(encryptedKeySignature, keyPair1.first);
    std::cout << "Decrypted key signature1: " << GMPExporter::importNumber(decryptedKeySignature).get_str(16) << std::endl;

    auto verifiedSignature = crypto.verifySignature(GMPExporter::exportNumber(key), decryptedKeySignature, keyPair2.second);
    std::cout << "Verified key signature1: " << verifiedSignature << std::endl;
}