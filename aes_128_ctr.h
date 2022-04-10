#pragma once
#include "aes_128_base.h"
class aes_128_ctr :
    public aes_128_base
{
public:
    aes_128_ctr(FILE* i, FILE* o, byte* c, byte* iv, mode m = str);
    virtual void encrypt();
    virtual void decrypt();
protected:
    struct u128i {
        byte high[8];
        byte low[8];
    } count;
};

