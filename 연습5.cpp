﻿#include <stdio.h>

int main()
{
	float moon, weight;
	moon, weight = 0;
	printf("몸무게를 입력하시오");
	scanf("%f", &weight);
	moon = 0.17 * weight;
	printf("달에서 당신의 몸무게는 %f", moon);
	
	return 0;

}
