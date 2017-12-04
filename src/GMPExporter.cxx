//
// Created by Oleksandr Deundiak on 12/4/17.
//

#include <cassert>
#include <vector>
#include "GMPExporter.h"

std::vector<unsigned char> GMPExporter::exportNumber(const mpz_class &number) {
    size_t size = (mpz_sizeinbase(number.get_mpz_t(), 2) + CHAR_BIT - 1) / CHAR_BIT;
    std::vector<unsigned char> data(size);
    mpz_export(data.data(), &size, 1, 1, 0, 0, number.get_mpz_t());
    data.resize(size);

    return data;
}

mpz_class GMPExporter::importNumber(const std::vector<unsigned char> &data) {
    mpz_class m;
    mpz_import(m.get_mpz_t(), data.size(), 1, 1, 0, 0, data.data());

    return m;
}