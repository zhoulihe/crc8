/***************************************************************************
	ÈÕÆÚ£º2014/03/13
	vincent
	¼ò½é£ºcrc8
/***************************************************************************/
#include <stdio.h>
#include "crc8.h"

void BuildTable8(unsigned char* Table_CRC, unsigned char key)
{
	int i, j;
	unsigned char crc;


	for (i = 0; i<256; i++)
	{
		crc = i;
		for (j = 0; j<8; j++)
			crc = (crc << 1) ^ ((crc & 0x80) ? key : 0);
		Table_CRC[i] = crc & 0xFF;
	}
}
void CRC8Table(unsigned char * Table_CRC, unsigned char key)
{
	unsigned short i, j;
	unsigned short nData;
	unsigned char nAccum;

	//crc8
	/*for (i = 0; i < 256; i++)
	{
		nData = i;
		nAccum = 0;

		for (j = 0; j <8; j++)
		{
			if (nData & 0x80)
			{ 

				nData = (nData << 1) ^ key;
			}
				
			else
				nData <<= 1;
		}
		*(Table_CRC + i) = (unsigned char)nData;
	}*/
	//crc8-maxim
	for (i = 0; i < 256; i++)
	{
		nData = i;
		nAccum = 0;

		for (j = 0; j <8; j++)
		{
			if ((nData^nAccum) & 0x01)
			{
				nData ^= 0x18;
				nData >>= 1;
				nData |= 0x80;
			}
			else
				nData >>= 1;
			nAccum >>= 1;
		}
		*(Table_CRC + i) = (unsigned char)nData;
	}

}

/*unsigned char CRC8(unsigned char *crc,
		unsigned char m,
		unsigned char* Table_CRC)
{

	*crc = Table_CRC[(*crc) ^ m];
	*crc &= 0xFF;
	return *crc;
}*/

unsigned char CRC8(unsigned char * aData,
	unsigned short aSize,
	unsigned char* Table_CRC)
{
	unsigned short i;
	unsigned char nAccum = 0;

	for (i = 0; i < aSize; i++)
	{ 
		nAccum = Table_CRC [nAccum ^ *aData++];
		//nAccum = (unsigned char)*(Table_CRC + (nAccum ^ *aData++));
		printf("%x\n", nAccum);
	}
	return nAccum;
}