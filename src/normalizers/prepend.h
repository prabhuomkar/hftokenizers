#ifndef PREPEND_H
#define PREPEND_H

#include "normalizer.h"
#include <string>

class Prepend : public Normalizer {
public:
    Prepend(std::string& prepend);
    virtual void normalize(std::string& input) override;
private:
    std::string& prepend;
};

#endif // PREPEND_H
