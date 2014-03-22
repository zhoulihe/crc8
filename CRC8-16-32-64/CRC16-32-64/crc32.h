/***************************************************************************
���ڣ�2014/03/13
vincent
��飺crc32ͷ�ļ�
/***************************************************************************/
#ifndef CRC32_H_
#define CRC32_H_

// http://en.wikipedia.org/wiki/Cyclic_redundancy_check
// CRC-32 = X32 + X26 + X23 + X22 + X16 + X11 + X10 + X8 + X7 + X5 + X4 + X2 + X1 + X0 
#define CRC32_N		0x04C11DB7	//normal 
#define CRC32_R		0xEDB88320	//Reversed
#define CRC32_RR	0x82608EDB	//Reversed reciprocal

//CRC-32C
#define CRC32C_N	0x1EDC6F41	//normal 
#define CRC32C_R	0x82F63B78	//Reversed
#define CRC32C_RR	0x8F6E37A0	//Reversed reciprocal

//CRC-32K
#define CRC32K_N	0x741B8CD7	//normal 
#define CRC32K_R	0xEB31D82E	//Reversed
#define CRC32K_RR	0xBA0DC66B	//Reversed reciprocal

//CRC-32Q
#define CRC32Q_N	0x814141AB	//normal 
#define CRC32Q_R	0xD5828281	//Reversed
#define CRC32Q_RR	0xC0A0A0D5	//Reversed reciprocal

#define cnCRC_32  0x04C10DB7
// ���� 32 λ CRC ���ò��ʽ����
void BuildTable32(unsigned long* Table_CRC, unsigned long key);

// ���� 32 λ CRC ֵ��CRC-32��0x04C10DB7��
// ����aData��������CRCֵ���������飬aSize�����ݳ��ȣ�Table_CRC��CRC��
unsigned long CRC32(unsigned char * aData, unsigned long aSize, unsigned long* Table_CRC);


#endif