#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t convert(char *filename){
	FILE *fd = fopen(filename, "rb");
	uint8_t buffer[4];
	fread(buffer, 1, 4, fd);
	uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
        uint32_t n = ntohl(*p);
	return n;
}

int main(int argc, char* argv[]){
	uint32_t a, b;
	a = convert(argv[1]);
	b = convert(argv[2]);
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)",a,a,b,b,a+b,a+b);
	return 0;
}
