#pragma once

#include <stdint.h>

typedef uint8_t uint8;

void Split(char *str, int *a); //раздел маски и IP на 4 отдельных числа
void IDN(int *ip, int *mask, int *subNet); //формир ID подсети
void IDH(int *ip, int *subNet, int *Host); //формир ID хоста
void BroadcastRass(int* ip, int* mask, int *ipRes); // 0широковещательная рассылка