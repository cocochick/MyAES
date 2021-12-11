#include "aes_128_base.h"

aes_128_base::aes_128_base(FILE* i, FILE* o, byte* c, mode m) :aes(c), in(i), out(o), inmode(m)
{
}

void aes_128_base::set_plain()
{
	for (int i = 0; i < 16 && !flag; i++) {
		switch (inmode) {
			case bin: {
				if (fscanf(in, "%2hhx", plain + i) == EOF) {
					for (int j = i; j < 16; j++) {
						plain[j] = 16 - i;
					}
					flag = true;
					break;
				}
				break;
			}
			case str: {
				if (fscanf(in, "%c", plain + i) == EOF) {
					for (int j = i; j < 16; j++) {
						plain[j] = 16 - i;
					}
					flag = true;
					break;
				}
				break;
			}
		}
	}
}
