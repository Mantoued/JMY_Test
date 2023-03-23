#include "Mid_Comm.h"

void Sys_Null_Func(void)
{
;
}

//数字索引查询, 最右侧索引为 0
//例： _value = 123456, _index = 1, 则返回 5 
char Sys_Number_Index_Query(unsigned int _value, char _index)
{
	char re;
	char i;
	for (i = 0; i < _index; i++)
		_value /= 10;
	
	re = _value % 10;
	return re;
}

//buf比较, 不相同返回 1, 相同返回 0
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

//数字范围, 在给定的范围内返回 1, 否则返回 0
char Sys_Number_Range(int _num, int _max, int _min)
{
	char re = 1;
	if (_num >_max) re = 0;
	else if (_num < _min) re = 0;
	
	return re;
}

/*
 * A相对于B
 * 范围（B - _diff, B + _diff）
 * 高于此范围返回 1 , 低于此范围返回 2 , 在此范围之内返回 0  
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

//计算一个数组内的最大差值
unsigned int Sys_Array_Max_DiffValue (unsigned int b[], unsigned char num)
{
	unsigned char i, j = 0, k = 0;
	for (i = 1; i < num; i++) 
	{
		if (b[j] < b[i])	//最大值
			j = i;
	
		if (b[k] > b[i])	//最小值
			k = i;
	}
	return (b[j] - b[k]);	//差值
}

/**
 * 函数名	Sys_Sort_Small_To_Large
 * 函数作用	：排序, 从小到大
 * 参数		b[] 数组， num 数组长度
 * 返回值	：无
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


