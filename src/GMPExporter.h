//
// Created by Oleksandr Deundiak on 12/4/17.
//

#ifndef LAB3_GMPEXPORTER_H
#define LAB3_GMPEXPORTER_H

#include "gmpxx.h"

class GMPExporter {
public:
    static mpz_class importNumber(const std::vector<unsigned char> &data);
    static std::vector<unsigned char> exportNumber(const mpz_class &number);
};


#endif //LAB3_GMPEXPORTER_H
