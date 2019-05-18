#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


int DigitSum(int n)
{
	/*int a, b, c, d, e;
	a = n / 10000;
	b =( n-a*10000 )/ 1000;
	c =( n - b * 1000 - a * 10000) / 100;
	d = (n - b * 1000 - a * 10000-c * 100) / 10;
	e = n % 10;
	return a + b + c + d + e;*/
	if (n < 10)
		return n;
	else
		return ((n % 10) + DigitSum(n / 10));

}

int main()
{
	int n = 0,ret=0;
	printf("ÇëÊäÈënµÄÖµ£º\n");
	scanf("%d", &n);
	ret = DigitSum(n);
	printf("%d\n", ret);

	system("pause");
	return 0;
}