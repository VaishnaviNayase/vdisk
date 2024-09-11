#include "header.h"
#define mask(a) 1ULL << (63-a)
void main()
{
	unsigned long long in[] =  {0b11111111};
	unsigned long long* out;

	long length = 8;
	out = encode_seq(length, in, out);
	printf("\n");
	for(long i = 0; i < (sizeof(out) * 8); i++){
		if(out[i / 64] & mask(i % 64))
			printf("1");
		else 
			printf("0");
	}
	decode_seq(out);
	free(out);
}


