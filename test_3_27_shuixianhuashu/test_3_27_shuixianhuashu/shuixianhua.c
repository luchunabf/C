#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	printf("请输入要查找的范围：\n");
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++)
	{
		int count = 0;//求数字的长度
		int tmp = i;
		while (tmp)
		{
			tmp /= 10;
			count++;
		}
		/*printf("%d", count);*/
		
		int sum = 0;
		int n = i;//i不变,i在循环中变化,所以转接一下
		
		while (n)
		{
			//if (i >= 10)
			//{
			//	i /= 10;
			//	
		 //   }

			//else if (i >= 0 && i < 10)
			//{
			//	i %= 10;
			//	count--;
			//	/*sum += pow(i,count);*/
			//	
			//	/*break;*/
			//}
			int num = n % 10;//每位上的数字
			sum += pow(num, count);
			n /= 10;
		}
		if (i==sum)
		printf("%d\n",i);
		/*break;*/
	}



	system("pause");
	return 0;
}