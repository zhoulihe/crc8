/***************************************************************************

[文件名] CRC16.H
[功能]　生成16位CRC表，计算数据串的16位CRC值
[版本] 2.0
[作者] 张雪奇
[最后修改时间] 2007年8月30日
***************************************************************************/
#include <stdio.h>
#include "crc16.h"


// 构造 16 位 CRC 表 
void BuildTable16(unsigned short* Table_CRC, unsigned short key)
{
	unsigned short i, j;
	unsigned short nData;
	unsigned short nAccum;

	for (i = 0; i < 256; i++)
	{
		nData = (unsigned short)(i << 8);
		nAccum = 0;

		for (j = 0; j < 8; j++)
		{
			if ((nData ^ nAccum) & 0x8000)
				nAccum = (nAccum << 1) ^ key;
			else
				nAccum <<= 1;
			nData <<= 1;
		}

		*(Table_CRC + i) = (unsigned long)nAccum;
	}
}


// 计算 16 位 CRC 值，CRC-16 或 CRC-CCITT 
unsigned short CRC16(unsigned char * aData, 
					unsigned short aSize, 
					unsigned short* Table_CRC)
{
	unsigned long i;
	unsigned short nAccum = 0;

	for (i = 0; i < aSize; i++)
		nAccum = (nAccum << 8) ^ (unsigned short)*(Table_CRC + ((nAccum >> 8) ^ *aData++));
	return nAccum;
}

//END

