#ifndef NORMALIZER_H
#define NORMALIZER_H

#include <string>

class Normalizer {
public:
    virtual ~Normalizer() {};
    virtual void normalize(std::string& input) = 0;
};

#endif // NORMALIZER_H
