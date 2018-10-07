#include "stdafx.h"
#include <iostream>
#include "IP.h"


void Split(char *str, int *a)//раздел маску и IP в отдел числа
{
	int i, j, k;

	for(k = 0; k < 4; k++)
	{
		a[k] = atoi(str);                 //Функция atoi() преобразует строку, адресуемую параметром str, в значение типа int.
		                                 //Эта строка должна содержать допустимое целое число. 
		for(i = 0; str[i] != '.'; i++);
		for (j = i; str[j] != '\0'; j++){
			str[j - i] = str[j + 1];
		}
	}
}

void IDN(int *ip, int *mask, int *subNet)//id подсети
{
	for(int k = 0; k < 4; k++)
	{
		subNet[k] = ip[k] & mask[k];
	}
}

void IDH(int *ip, int *subNet, int *Host)//id хоста
{
	for(int k = 0; k < 4; k++)
	{
		Host[k] = ip[k] - subNet[k];
	}
}


void BroadcastRass(int* ip, int* mask, int *ipRes){
	for (int i = 0; i < 4; i++){
		uint8 temp = (uint8)~mask[i];
		ipRes[i] = ip[i] | temp;
	}
}

