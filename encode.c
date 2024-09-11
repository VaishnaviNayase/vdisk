#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mask(a) 1ULL << (63-a)
unsigned long long* encode_seq(long length, unsigned long long* in, unsigned long long* out)
{
	long* arr = (long *)malloc(length * sizeof(long));
	long size = 0;
	long sum = 0;
	long index = 0;
	long position = 0;
	long num;
	long temp;
	long len = length;
	arr[size++] = length;
	while(len > 2)
	{
		arr[size] = ceil(log2(len + 1));
		len = arr[size];
		sum += arr[size];
		size++;
	}
	for(long i = 0; i < size; i++)
		printf("%ld ->",arr[i]);
	out = (unsigned long long*)calloc((ceil((sum + size + length + 1)/64)),sizeof(unsigned long long));
	long temp_size = ceil((sum + size + length + 1)/64);

	for(long i = size -2; i >= 0; i--)
	{
		num = arr[i];
		temp = arr[i+1] - 1;
		index += arr[i+1] + 1;
		while(position < index)
		{	
			if(pow(2.0, temp) <= num && num != 0)
			{
				out[position / 64] |= 1ULL << (63 - (position % 64));
				num -= pow(2.0, temp);
			}	
			temp--;
			position++;
		}
	}	
	index += length;
	long i=0;
	while(!(in[i/64] & (1ULL<<(63-i))))
		i++;
	length+=i;
	while(position < index)
	{
		for(; i < length; i++)
		{	
			temp = (in[i/64] >> (63 - (i % 64))) & 1 ;	
			if(temp)
			{
				out[position/64] |= 1ULL << (63- (position % 64));
			}
			position++;
		}
	}
	out[position/64] |= 1ULL << (63- (position % 64));
	return out;
}


