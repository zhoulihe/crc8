/***************************************************************************
	���ڣ�2014/03/13
	vincent
	��飺crc16ͷ�ļ�
/***************************************************************************/
#ifndef CRC16_H_
#define CRC16_H_

//http://en.wikipedia.org/wiki/Cyclic_redundancy_check
//CRC16-IBM
// CRC-16 = X16 + X15 + X2 + X0 ע�⣺�����λһ��Ϊ��1��������ȥ 
#define CRC16_IBM_N		0x8005	//normal 
#define CRC16_IBM_R		0xA001	//Reversed 
#define CRC16_IBM_RR	0xC002	//Reversed reciprocal

//CRC16-CCITT
#define CRC16_CCITT_N		0x1021	//normal 
#define CRC16_CCITT_R		0x8408	//Reversed 
#define CRC16_CCITT_RR		0x8810	//Reversed reciprocal
#define cnCRC_16	0x8005



// ���� 16 λ CRC ���ò��ʽ����
void BuildTable16(unsigned short* Table_CRC, unsigned short key);

// ���� 16 λ CRC ֵ��CRC-16(0x8005)
// ����aData��������CRCֵ���������飬aSize�����ݳ��ȣ�Table_CRC��CRC��
unsigned short CRC16(unsigned char * aData, unsigned short aSize, unsigned short* Table_CRC);


#endif