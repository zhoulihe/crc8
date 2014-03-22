/***************************************************************************
	���ڣ�2014/03/13
	vincent
	��飺crc8 crc16��crc16-ccitt crc32 crc64 �����ʾ����
	���д����������internet�� ����ֻ�ǽ���������������ʹ��
/***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "crc8.h"
#include "crc16.h"
#include "crc32.h"
#include "crc64.h"

unsigned char test8[3] = { 0x02, 0x03, 0x34 };
unsigned char test16[3] = { 0x02, 0x80, 0x0f };    //ʵ������
unsigned char test32[5] = { 0x02, 0x09, 0x82, 0x1b, 0x6e };
unsigned char test64[11] = { 0x01, 0x02, 0x03, 0xf8, 0x05, 0x60, 0x9e, 0xce, 0x1e, 0xcb, 0xf3 };

int main()
{
	unsigned int i;
	
	unsigned short crc8 = 0;
	unsigned short crc16 = 0;           //CRCֵ
	unsigned char Table8[256];
	unsigned short Table16[256];         //���CRC��

	CRC8Table(Table8, 0x98);
	for (i = 0; i < 256; i++)
	{
		if (!(i % 8))
			printf("\n");
		printf("0x%x , ", Table8[i]);
	}
	printf("\n");
	BuildTable8(Table8, CRC8_N);
	for (i = 0; i < 256; i++)
	{
		if (!(i % 8))
			printf("\n");
		printf("0x%x , ", Table8[i]);
	}

	crc8 = CRC8(test8, 3, Table8);
	printf("\nThe CRC8 is:%x\n", crc8);

	BuildTable16(Table16, CRC16_IBM_N);             //����CRC������ʾ
	for (i=0;i<256;i++)
	{
		if (!(i % 8))
			printf("\n");
		printf("0x%x , ", Table16[i]);
	}

	crc16 = CRC16(test16, 3, Table16);      //����CRCֵ������ʾ
	printf("\nThe CRC16 is:%x\n", crc16);


	
	unsigned long crc32 = 0;
	unsigned long Table32[256];

	BuildTable32(Table32, CRC32_N);              //����CRC������ʾ
	for (i=0;i<256;i++)
	{
		if (!(i % 6))
			printf("\n");
		printf("0x%x , ", Table32[i]);
	}

	crc32 = CRC32(test32,5,Table32);	//����CRCֵ������ʾ
	printf("\nThe CRC32 is:%x\n", crc32);

	

	
	unsigned long* crc64;				//CRC���
	unsigned long Table32H[256];		//���CRC��
	unsigned long Table32L[256];

	BuildTable64(Table32H, Table32L, CRC_64_H, CRC_64_L);	//����CRC������ʾ
	for (i = 0; i<256; i++)
	{
		if (!(i % 3))
			printf("\n");
		printf("0x%x %x , ", Table32H[i], Table32L[i]);
	}

	crc64 = CRC64(test64, 11, Table32H, Table32L);		//����CRCֵ������ʾ
	printf("\nThe CRC64 is:%x , %x\n", *crc64, *(crc64 + 1));

	
	system("pause");
	return 0;
}
