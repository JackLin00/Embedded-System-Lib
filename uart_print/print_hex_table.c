#include <string.h>
#include <stdint.h>



#define        HALFHEX2ASCII(buf,hex)         do{ 								\
												if((hex) > 9){ 					\
													buf = (hex) - 0x0A + 'A'; 	\
												}else{							\
													buf = (hex) + '0';			\
												}								\
											}while(0)


void print_hex(uint8_t hex){
	uint8_t hex_ascii[3];
	uint8_t tmp;
	HALFHEX2ASCII(hex_ascii[0],hex >> 4);
	HALFHEX2ASCII(hex_ascii[1],hex & 0x0F);
	hex_ascii[2] = 0x00;
	printf("%s",hex_ascii);
}


void print_hex_table(uint8_t *hex_table,uint8_t len){
	for(uint8_t i = 0;i < len;i++){
		print_hex(hex_table[i]);
		printf(" ");
	}
	printf("\r\n");
}