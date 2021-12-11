#include "aes_128_ecb.h"

aes_128_ecb::aes_128_ecb(FILE* i, FILE* o, byte* c, mode m) :aes_128_base(i, o, c, m)
{
}

void aes_128_ecb::encrypt()
{
	while (!flag) {
		set_plain();
		memcpy(cipher, plain, 16);
		aes::encrypt();
		for (int i = 0; i < 16; i++) {
			fprintf(out, "%02hhx", cipher[i]);
		}
	}
}

void aes_128_ecb::decrypt()
{

}
