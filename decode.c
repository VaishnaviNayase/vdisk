#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mask(a) 1ULL << (63-a)
struct decode
{
	unsigned long long decoded;
	long position;
};
struct decode decode_seq(unsigned long long* out)
{
	long position = 0; // related out bits
	long temp_num = 2; // to store how many next bits to read
	long flag = 0;
	long bits = 0;
	struct decode output; 
	unsigned long long temp; 
	while(!flag)
	{
		output.decoded = 0;
		while(bits < temp_num)
		{
			temp = out[position / 64];
			temp <<= (position % 64);
			temp >>= 63;
			output.decoded = (output.decoded << 1ULL) | temp;
			position++;
			bits++;
		}
		temp_num = output.decoded;
		temp = out[position / 64];
		temp <<= (position % 64);
		temp >>= 63;
	       	flag = temp & 1;	
		position++;
		bits = 0;
	}
	output.position = position;
	printf("\noutput: %lld",output.decoded);
	printf("\noutput: %b",output.decoded);
	printf("\nposition: %ld",output.position);
	return output;
}
