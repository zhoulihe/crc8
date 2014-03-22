/***************************************************************************

[�ļ���] CRC16.H
[����]������16λCRC���������ݴ���16λCRCֵ
[�汾] 2.0
[����] ��ѩ��
[����޸�ʱ��] 2007��8��30��
***************************************************************************/
#include <stdio.h>
#include "crc16.h"


// ���� 16 λ CRC �� 
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


// ���� 16 λ CRC ֵ��CRC-16 �� CRC-CCITT 
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

