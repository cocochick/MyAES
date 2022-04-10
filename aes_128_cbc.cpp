#include "aes_128_cbc.h"

aes_128_cbc::aes_128_cbc(FILE* i, FILE* o, byte* c, byte* iv, mode m):aes_128_base(i, o, c, m)
{
	memcpy(IV, iv, 16);
}

void aes_128_cbc::encrypt()
{
	set_plain();
	for (int i = 0; i < 16; i++) {
		cipher[i] = plain[i] ^ IV[i];
	}
	aes::encrypt();
	for (int i = 0; i < 16; i++) {
		fprintf(out, "%02hhx", cipher[i]);
	}
	while (!flag) {
		set_plain();
		for (int i = 0; i < 16; i++) {
			cipher[i] ^= plain[i];
		}
		aes::encrypt();
		for (int i = 0; i < 16; i++) {
			fprintf(out, "%02hhx", cipher[i]);
		}
	}
}

void aes_128_cbc::decrypt()
{
	byte cipher_old[16];
	set_plain();
	memcpy(IV, plain, 16);
	memcpy(cipher_old, plain, 16);
	while (!flag) {
		set_plain();
		memcpy(cipher, plain, 16);
		aes::decrypt();
		for (int i = 0; i < 16; i++) {
			plain[i] ^= cipher_old[i];
		}
		memcpy(cipher_old, cipher, 16);
		for (int i = 0; i < 16; i++) {
			fprintf(out, "%c", plain[i]);
		}
	}
}
