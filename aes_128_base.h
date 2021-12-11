#pragma once
#include "aes.h"
#include <stdio.h>
enum mode { str, bin };
class aes_128_base :
    public aes
{
public:
    aes_128_base(FILE* i, FILE* o, byte* c, mode m = str);
    virtual void encrypt() = 0;
    virtual void decrypt() = 0;
protected:
    void set_plain();
    FILE* in;
    FILE* out;
    bool flag = false;
    mode inmode;
    byte IV[16];
};

