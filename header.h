#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct decode
{	
	unsigned long long* decoded;
	long position;
};

unsigned long long* encode_seq(long length, unsigned long long* in, unsigned long long* out);

struct decode decode_seq(unsigned long long* out);
