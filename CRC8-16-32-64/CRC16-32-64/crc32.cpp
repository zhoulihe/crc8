/***************************************************************************

[�ļ���] CRC32.H
[����]������32λCRC���������ݴ���32λCRCֵ
[�汾] 2.0
[����] ��ѩ��
[����޸�ʱ��] 2007��8��30��

***************************************************************************/
#include <stdio.h>
#include "crc32.h"

// ���� 32 λ CRC �� 
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


// ���� 32 λ CRC-32 ֵ 
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
