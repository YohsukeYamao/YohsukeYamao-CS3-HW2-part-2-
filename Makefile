all:
	g++ -Wall -g power-digit-sum.cpp -o pds

run: 
	./pds 

try: all run