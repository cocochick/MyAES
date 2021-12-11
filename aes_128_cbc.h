#pragma once
#include "aes_128_base.h"
class aes_128_cbc :
    public aes_128_base
{
public:
    aes_128_cbc(FILE* i, FILE* o, byte* c, byte* iv, mode m = str);
    virtual void encrypt();
    virtual void decrypt();
};

