/***************************************************************************
���ڣ�2014/03/13
vincent
��飺crc64ͷ�ļ�
/***************************************************************************/
#ifndef CRC64_H_
#define CRC64_H_

//CRC-64-ECMA-182 x64 + x62 + x57 + x55 + x54 + x53 + x52 + x47 + x46 + x45 + 
//x40 + x39 + x38 + x37 + x35 + x33 + x32 + x31 + x29 + x27 + x24 + x23 + x22 
//+ x21 + x19 + x17 + x13 + x12 + x10 + x9 + x7 + x4 + x + 1 
//(as described in ECMA-182 p.63)  or 0xC96C5795D7870F42 (0x92D8AF2BAF0E1E85) 
#define CRC_64ECMA_N	0x42F0E1EBA9EA3693	//normal 
#define CRC_64ECMA_R	0xC96C5795D7870F42	//Reversed  
#define CRC_64ECMA_RR	0xA17870F5D4F51B49	//Reversed reciprocal 

#define CRC_64_H	0x42F0E1EB
#define CRC_64_L	0xA9EA3693

//CRC-64-ISO
#define CRC_64ISO_N		0x000000000000001B	//normal 
#define CRC_64ISO_R		0xD800000000000000	//Reversed  
#define CRC_64ISO_RR	0x800000000000000D	//Reversed reciprocal 




// ���� 64 λ CRC ���ò��ʽ����
void BuildTable64(unsigned long* TableCRCHigh,unsigned long* TableCRCLow,
					unsigned long key_H, unsigned long key_L);

// ���� 64 λ CRC ֵ��CRC-64��0x42F0E1EBA9EA3693��
// ����aData��������CRCֵ���������飬aSize�����ݳ��ȣ�TableCRCHigh��TableCRCLow��CRC���Ժ�����ò��ʽ����
unsigned long* CRC64(unsigned char* aData, unsigned long aSize, 
				unsigned long* TableCRCHigh, unsigned long* TableCRCLow);




#endif