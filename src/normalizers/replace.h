#ifndef REPLACE_H
#define REPLACE_H

#include "normalizer.h"
#include <string>

class Replace : public Normalizer {
public:
    Replace(std::string& pattern, std::string& content);
    virtual void normalize(std::string& input) override;
private:
    std::string& pattern;
    std::string& content;
};

#endif // REPLACE_H
