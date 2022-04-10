#include "aes_128_ctr.h"
#include <algorithm>

aes_128_ctr::aes_128_ctr(FILE* i, FILE* o, byte* c, byte* iv, mode m) :aes_128_base(i, o, c, m)
{
	memcpy(IV, iv, 16);
}

void aes_128_ctr::encrypt()
{

}

void aes_128_ctr::decrypt()
{
	set_plain();
	std::reverse(plain, plain + 16);
	memcpy(&count, plain, 16);
	while (!flag) {
		memcpy(cipher, &count, 16);
		std::reverse(cipher, cipher + 16);
		aes::encrypt();
		set_plain();
		
		for (int i = 0; i < 16; i++) {
			plain[i] ^= cipher[i];
		}
		for (int i = 0; i < 16; i++) {
			fprintf(out, "%c", plain[i]);
		}
		unsigned long long int temp = *reinterpret_cast<unsigned long long int*>(count.high) + 1;
		memcpy(count.high, &temp, 8);
		if(temp == 0){
			temp = *reinterpret_cast<unsigned long long int*>(count.low) + 1;
			memcpy(count.high, &temp, 8);
		}
	}
}