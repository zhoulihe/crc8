/***************************************************************************
	日期：2014/03/13
	vincent
	简介：crc16头文件
/***************************************************************************/
#ifndef CRC16_H_
#define CRC16_H_

//http://en.wikipedia.org/wiki/Cyclic_redundancy_check
//CRC16-IBM
// CRC-16 = X16 + X15 + X2 + X0 注意：因最高位一定为“1”，故略去 
#define CRC16_IBM_N		0x8005	//normal 
#define CRC16_IBM_R		0xA001	//Reversed 
#define CRC16_IBM_RR	0xC002	//Reversed reciprocal

//CRC16-CCITT
#define CRC16_CCITT_N		0x1021	//normal 
#define CRC16_CCITT_R		0x8408	//Reversed 
#define CRC16_CCITT_RR		0x8810	//Reversed reciprocal
#define cnCRC_16	0x8005



// 构造 16 位 CRC 表，用查表方式访问
void BuildTable16(unsigned short* Table_CRC, unsigned short key);

// 计算 16 位 CRC 值，CRC-16(0x8005)
// 这里aData是欲计算CRC值的数据数组，aSize是数据长度，Table_CRC是CRC表
unsigned short CRC16(unsigned char * aData, unsigned short aSize, unsigned short* Table_CRC);


#endif