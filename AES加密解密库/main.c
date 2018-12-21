#include <stdio.h>
#include <string.h>
#include <stdint.h>


#include "aes.h"









void main()
{
	uint32_t i,txx;
	txx = 16;
	printf("%x\r\n",txx);
	uint8_t jack[] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x31,0x32,0x33,0x34};
	uint8_t jackxx[32];
	PKCS5Padding(jack,jackxx,14);
	test_encrypt_cbc(jackxx,16);
	test_decrypt_cbc(jackxx,16);
}




