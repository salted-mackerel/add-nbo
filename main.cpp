#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t func(char *filename){
	FILE *fd = fopen(filename, "rb");
	uint8_t buffer[4];
	fread(buffer, 1, 4, fd);
	uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
        uint32_t n = ntohl(*p);
	return n;
}

int main(int argc, char* argv[]){
	uint32_t a, b;
	a = func(argv[1]);
	b = func(argv[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",a,a,b,b,a+b,a+b);
	return 0;
}
