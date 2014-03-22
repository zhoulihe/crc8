/***************************************************************************

[�ļ���] CRC64.H
[����]������64λCRC���������ݴ���64λCRCֵ
[�汾] 2.0
[����] ��ѩ��
[����޸�ʱ��] 2007��8��30��

***************************************************************************/
#include <stdio.h>
#include "crc64.h"

// ���� 64 λ CRC �� 
void BuildTable64(unsigned long* TableCRCHigh, 
				unsigned long* TableCRCLow, 
				unsigned long key_H, 
				unsigned long key_L)
{
	unsigned long i, j;
	unsigned long nData[2];
	unsigned long nAccum[2];

	nData[0] = 0;
	nData[1] = 0;

	for (i = 0; i < 256; i++)
	{
		nAccum[0] = 0;
		nAccum[1] = 0;
		nData[1] = i;

		nData[0] = nData[1] << 24;
		nData[1] = 0;

		for (j = 0; j < 8; j++)
		{
			if ((nData[0] ^ nAccum[0]) & 0x80000000)
			{
				nAccum[0] = ((nAccum[0] << 1) | ((nAccum[1] & 0x80000000) >> 31)) ^ key_H;
				nAccum[1] = (nAccum[1] << 1) ^ key_L;
			}
			else
			{
				nAccum[0] = (nAccum[0] << 1) | ((nAccum[1] & 0x80000000) >> 31);
				nAccum[1] = nAccum[1] << 1;
			}
			nData[0] = (nData[0] << 1) | ((nData[1] & 0x80000000) >> 31);
			nData[1] = nData[1] << 1;
		}

		*(TableCRCHigh + i) = nAccum[0];
		*(TableCRCLow + i) = nAccum[1];
	}
}

// ���� 64 λ CRC-64 ֵ 
unsigned long* CRC64(unsigned char* aData, 
					  unsigned long aSize, 
					  unsigned long* TableCRCHigh, 
					  unsigned long* TableCRCLow)
{
	unsigned long i;
	unsigned long nAccum[2];
	unsigned long temp;
	unsigned long index;

	nAccum[0] = 0;
	nAccum[1] = 0;

	for (i = 0; i < aSize; i++)
	{
		temp = nAccum[0];
		index = (temp >> 24) ^ *aData++;

		nAccum[0] = ((nAccum[0] << 8) | ((nAccum[1] & 0xff000000) >> 24)) ^ (*(TableCRCHigh + index));
		nAccum[1] = (nAccum[1] << 8) ^ (*(TableCRCLow + index));
	}

	return nAccum;
}
