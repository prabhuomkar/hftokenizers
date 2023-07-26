#ifndef LOWERCASE_H
#define LOWERCASE_H

#include "normalizer.h"
#include <string>

class Lowercase : public Normalizer {
public:
    Lowercase();
    virtual void normalize(std::string& input) override;
};

#endif // LOWERCASE_H
