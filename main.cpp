#include<iostream>
#include "aes.h"
#include "aes_128_ecb.h"
#include "aes_128_cbc.h"
#include "aes_128_cfb.h"
#include "aes_128_ofb.h"
#include "aes_128_ctr.h"
#include<string>

void read_key(FILE* file, byte key[16]){
	for(int i = 0; i < 16; ++i){
		fscanf(file, "%2hhx", key + i);
	}
}

int main() {
	
	byte iv[16] = { 0x36,0xf1,0x83,0x57,0xbe,0x4d,0xbd,0x77,0xf0,0x50,0x51,0x5c,0x73,0xfc,0xf9,0xf2 };
	byte key[16];
	FILE* in = fopen("./in", "r");
	FILE* out = fopen("./out", "w");
	FILE* key_f = fopen("./key", "r");
	read_key(key_f, key);
	fclose(key_f);
	//aes_128_ecb temp(in, out, key);
	aes_128_cbc temp(in, out, key, iv, bin);
	temp.decrypt();
	fclose(in);
	fclose(out);
	return 0;
}