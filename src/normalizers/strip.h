#ifndef STRIP_H
#define STRIP_H

#include "normalizer.h"
#include <string>

class Strip : public Normalizer {
public:
    Strip(bool stripLeft, bool stripRight);
    virtual void normalize(std::string& input) override;
private:
    bool stripLeft;
    bool stripRight;
    void stripWhitespaces(std::string& str, bool stripLeft);
};

#endif // STRIP_H
