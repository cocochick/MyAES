#pragma once
#include "aes_128_base.h"
#include <stdio.h>
class aes_128_ecb :
    public aes_128_base
{
public:
    aes_128_ecb(FILE* i, FILE* o, byte* c, mode m = str);
    virtual void encrypt();
    virtual void decrypt();
};

