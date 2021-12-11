#include "aes_128_cfb.h"

aes_128_cfb::aes_128_cfb(FILE* i, FILE* o, byte* c, byte* iv, mode m) :aes_128_base(i, o, c, m)
{
	memcpy(IV, iv, 16);
}

void aes_128_cfb::encrypt()
{
	memcpy(tIV, IV, 16);
	while (!flag) {
		memcpy(cipher, tIV, 16);
		aes::encrypt();
		switch (inmode) {
			case str: {
				for (int i = 0; i < 16; i++) {
					if (fscanf(in, "%c", tIV + i) == EOF) {
						flag = true;
						break;
					}
					tIV[i] ^= cipher[i];
					fprintf(out, "%02hhx", tIV[i]);
				}
				break;
			}
			case bin: {
				for (int i = 0; i < 16; i++) {
					if (fscanf(in, "%2hhx", tIV + i) == EOF) {
						flag = true;
						break;
					}
					tIV[i] ^= cipher[i];
					fprintf(out, "%02hhx", tIV[i]);
				}
				break;
			}
		}
	}
}

void aes_128_cfb::decrypt()
{

}