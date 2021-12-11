#include<iostream>
#include "aes.h"
#include "aes_128_ecb.h"
#include "aes_128_cbc.h"
#include "aes_128_cfb.h"
#include "aes_128_ofb.h"
#include<string>
int main() {
	byte key[16] = { 'p','a','s','s','w','o','r','d'};
	byte iv[16] = { 'p','a','s','s','w','o','r','d','p','a','s','s','w','o','r','d' };
	FILE* in = fopen("G:/in.txt", "r");
	FILE* out = fopen("G:/out.txt", "w");
	//aes_128_ecb temp(in, out, key);
	aes_128_ofb temp(in, out, key, iv);
	temp.encrypt();
	fclose(in);
	fclose(out);
	return 0;
}