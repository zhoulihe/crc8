/***************************************************************************

[文件名] CRC32.H
[功能]　生成32位CRC表，计算数据串的32位CRC值
[版本] 2.0
[作者] 张雪奇
[最后修改时间] 2007年8月30日

***************************************************************************/
#include <stdio.h>
#include "crc32.h"

// 构造 32 位 CRC 表 
void BuildTable32(unsigned long* Table_CRC, unsigned long key)
{
	unsigned long i, j;
	unsigned long nData;
	unsigned long nAccum;

	for (i = 0; i < 256; i++)
	{
		nData = (unsigned long)(i << 24);
		nAccum = 0;
		for (j = 0; j < 8; j++)
		{
			if ((nData ^ nAccum) & 0x80000000)
				nAccum = (nAccum << 1) ^ key;
			else
				nAccum <<= 1;
			nData <<= 1;
		}
		*(Table_CRC + i) = nAccum;
	}
}


// 计算 32 位 CRC-32 值 
unsigned long CRC32(unsigned char * aData, 
					unsigned long aSize, 
					unsigned long* Table_CRC)
{
	unsigned long i;
	unsigned long nAccum = 0;

	for (i = 0; i < aSize; i++)
		nAccum = (nAccum << 8) ^ *(Table_CRC + ((nAccum >> 24) ^ *aData++));
	return nAccum;
}
