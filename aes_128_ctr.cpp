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
	std::reverse(std::begin(plain), std::end(plain));
	memcpy(&count, plain, 16);
	while (!flag) {
		memcpy(plain, &count, 16);
		std::reverse(std::begin(plain), std::end(plain));
		aes::encrypt();
		set_plain();
		
		for (int i = 0; i < 16; i++) {
			plain[i] ^= cipher[i];
		}
		for (int i = 0; i < 16; i++) {
			fprintf(out, "%c", plain[i]);
		}
		count.high += 1;
		if(count.high == 0){
			count.low += 1;
		}
	}
}