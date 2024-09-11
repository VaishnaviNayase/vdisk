all : test.c ecdc.a
	gcc -o test test.c ecdc.a -lm

ecdc.a : encode.o decode.o
	ar -rcs ecdc.a encode.o 
	ar -rcs ecdc.a decode.o

encode.o : encode.c
	gcc -c encode.c 

decode.o : decode.c
	gcc -c decode.c 

