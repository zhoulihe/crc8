/***************************************************************************
	日期：2014/03/13
	vincent
	简介：crc8头文件
/***************************************************************************/
#ifndef CRC8_H_
#define CRC8_H_

//#define GP  0x107   /* x^8 + x^2 + x + 1 */
//#define DI  0x07
//CRC8 http://en.wikipedia.org/wiki/Cyclic_redundancy_check
#define CRC8_N	0xd5	//normal 
#define CRC8_R	0xab	//Reversed
#define CRC8_RR	0xea	//Reversed reciprocal
//CRC8-CCITT
#define CRC8_CCITT_N	0x07	//normal 
#define CRC8_CCITT_R	0xe0	//Reversed
#define CRC8_CCITT_RR	0x83	//Reversed reciprocal

void CRC8Table(unsigned char * Table_CRC, unsigned char key);
void BuildTable8(unsigned char* Table_CRC, unsigned char key);
unsigned char CRC8(unsigned char * aData, unsigned short aSize, unsigned char* Table_CRC);


#endif