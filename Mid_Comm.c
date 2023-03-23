#include "Mid_Comm.h"

void Sys_Null_Func(void)
{
;
}

//����������ѯ, ���Ҳ�����Ϊ 0
//���� _value = 123456, _index = 1, �򷵻� 5 
char Sys_Number_Index_Query(unsigned int _value, char _index)
{
	char re;
	char i;
	for (i = 0; i < _index; i++)
		_value /= 10;
	
	re = _value % 10;
	return re;
}

//buf�Ƚ�, ����ͬ���� 1, ��ͬ���� 0
char Sys_Buf_Cmpare(char *_buf1, char *_buf2, unsigned short int _len)
{
	char re = 0;
	unsigned short int i;
	for (i = 0; i < _len; i++)
	{
		if (_buf1[i] != _buf1[2])
		{
			re = 1;
			break;
		}
	}
	return re;
}

//���ַ�Χ, �ڸ����ķ�Χ�ڷ��� 1, ���򷵻� 0
char Sys_Number_Range(int _num, int _max, int _min)
{
	char re = 1;
	if (_num >_max) re = 0;
	else if (_num < _min) re = 0;
	
	return re;
}

/*
 * A�����B
 * ��Χ��B - _diff, B + _diff��
 * ���ڴ˷�Χ���� 1 , ���ڴ˷�Χ���� 2 , �ڴ˷�Χ֮�ڷ��� 0  
 */
unsigned char Sys_A_Within_B(unsigned short int A, unsigned short int B, unsigned short int _diff)
{
	if (A > (B + _diff))
	{
		return 1;
	}
	else if ((A + _diff) < B)
	{
		return 2;
	}
	return 0;
}

//����һ�������ڵ�����ֵ
unsigned int Sys_Array_Max_DiffValue (unsigned int b[], unsigned char num)
{
	unsigned char i, j = 0, k = 0;
	for (i = 1; i < num; i++) 
	{
		if (b[j] < b[i])	//���ֵ
			j = i;
	
		if (b[k] > b[i])	//��Сֵ
			k = i;
	}
	return (b[j] - b[k]);	//��ֵ
}

/**
 * ������	Sys_Sort_Small_To_Large
 * ��������	������, ��С����
 * ����		b[] ���飬 num ���鳤��
 * ����ֵ	����
 */
void Sys_Sort_Small_To_Large(unsigned short int b[], unsigned char num)
{
	unsigned char i, j, k;
	unsigned short int  temp;

	for (i = 0; i < num - 1; i++)
	{
		k = i;
		for (j = i + 1; j < num; j++)
		{
			if (b[k] > b[j])
				k = j;
		}
		if (i != k)
		{
			temp = b[i];
			b[i] = b[k];
			b[k] = temp;
		}
	}
}

void Sys_Sort_Small_To_Large_32(unsigned int b[], unsigned char num)
{
	unsigned char i, j, k;
	unsigned int  temp;

	for (i = 0; i < num - 1; i++)
	{
		k = i;
		for (j = i + 1; j < num; j++)
		{
			if (b[k] > b[j])
				k = j;
		}
		if (i != k)
		{
			temp = b[i];
			b[i] = b[k];
			b[k] = temp;
		}
	}
}

void Sys_Delay_Us(unsigned short int _us)
{
	unsigned short int i=0, j=0;
	for (i = 0; i < _us; i++)
	{
		for (j = 1; j>0; j--);
	}
}

void Sys_Delay_Ms(unsigned short int _ms)
{
	unsigned short int i=0;
	for (i = 0; i < _ms; i++)
	{
		Sys_Delay_Us(3000);
	}
}


