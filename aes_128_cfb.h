#pragma once
#include "aes_128_base.h"
class aes_128_cfb :
    public aes_128_base
{
public:
    aes_128_cfb(FILE* i, FILE* o, byte* c, byte* iv, mode m = str);
    virtual void encrypt();
    virtual void decrypt();
protected:
    byte tIV[16];
};

