//定义或实现
/*
int MyMax(int a, int b)
{
	return a > b ? a : b;
}

/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

void fun1();
void fun2();

void fun1()
{
	fun2();
	printf("Hello C.\n");
}
void fun2()
{
	printf("Hello Cpp.\n");
}

void main()
{
	fun1();
}

/*
int main()
{
	char arr[20] = "hello";
	int ret = strlen(strcat(arr, "bit"));//这里介绍一下strlen函数
	printf("%d\n", ret);
	return 0;
}

/*
int main()
{
	char arr[20] = "hello";
	printf("arr = %s\n", arr);
	strcat(arr, "bit");
	printf("arr = %s\n", arr);  //hellobit
	
	int ret = strlen(arr);
	printf("%d\n", ret);

	return 0;
}

/*
void fun1()
{
	printf("Hello C.\n");
}
void fun2()
{
	fun1();
	printf("Hello Cpp.\n");
}
void fun3()
{
	fun2();
	printf("Hello Linux.\n");
}

void main()
{
	fun3();

}

/*
//写一个函数，每调用一次这个函数，就会将num的值增加1
void fun(int *pnum)
{
	(*pnum)++;
}

int main()
{
	int num = 0;
	printf("num = %d\n", num);
	fun(&num);
	printf("num = %d\n", num);

	return 0;
}



/*
//写一个函数判断一年是不是闰年
bool IsLeap(int year)
{
	return ((year%4==0)&&(year%100!=0)) || (year%400==0);
}
void main()
{
	int year;
	printf("input year:>");
	scanf("%d", &year);
	if(IsLeap(year))
		printf("Is Leap.\n");
	else
		printf("Is not Leap.\n");
}

/*
//写一个函数可以判断一个数是不是素数
int IsPrime(int value)
{
	for(int i=2; i<value-1; ++i)
	{
		if(value % i == 0)
			return -1;
	}
	return 0;
}
void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);
	if(IsPrime(n) == 0)
		printf("Is Prime.\n");
	else
		printf("Is not Prime.\n");
}


/*
bool IsPrime(int value)
{
	for(int i=2; i<value-1; ++i)
	{
		if(value % i == 0)
			return false;
	}
	return true;
}
void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);
	if(IsPrime(n))
		printf("Is Prime.\n");
	else
		printf("Is not Prime.\n");
}

/*
void PrintArray(int ar[], int n)
{
	for(int i=0; i<n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
//
int Find(int ar[], int n, int key)
{
	for(int i=0; i<n; ++i)
	{
		if(key == ar[i])
			return i;
	}
	return -1;
}

int FindMax(int ar[], int n)
{
	int max = ar[0];
	for(int i=1; i<n; ++i)
	{
		if(ar[i] > max)
			max = ar[i];
	}
	return max;
}

int FindSecond(int ar[], int n)
{
	int first, second;
	if(ar[0] > ar[1])
	{
		first = ar[0];
		second = ar[1];
	}
	else
	{
		first = ar[1];
		second = ar[0];
	}

	for(int i=2; i<n; ++i)
	{
		if(ar[i] > first)
		{
			second = first;
			first = ar[i];
		}
		else if(ar[i] > second)
		{
			second = ar[i];
		}
	}
	return second;
}

void Sort(int ar[], int n)
{
	for(int i=0; i<n-1; ++i) //用于控制比较的趟数
	{
		for(int j=0; j<n-i-1; ++j) //用于控制每一趟的排序
		{
			if(ar[j] > ar[j+1])
			{
				//交换两个数
				int tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
	}
}
void Reverse(int ar[], int n)
{
	int low = 0;
	int high = n-1;
	while(low < high)
	{
		int tmp = ar[low];
		ar[low] = ar[high];
		ar[high] = tmp;

		low++;
		high--;
	}
}
void main()
{
	int ar[] = {4,700,9,200,1,55,120,43,21,67,54,100};
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintArray(ar, n);
	Reverse(ar, n);
	//Sort(ar, n);
	PrintArray(ar, n);
}

/*
void main()
{
	int ar[] = {4,7,9,200,1,5,120,43,21,67,54,100};
	int n = sizeof(ar) / sizeof(ar[0]);

	int max_value = FindMax(ar, n);
	printf("max value = %d\n", max_value);
	int second_value = FindSecond(ar, n);
	printf("second value = %d\n", second_value);

	Sort(ar, n);
}

/*
void main()
{
	int ar[] = {4,7,9,2,0,1,5,12,43,21,67,54,100};
	int n = sizeof(ar) / sizeof(ar[0]);

	int key;
	printf("input key:>");
	scanf("%d", &key);

	//int index = Find(ar, n, key);
	if(index == -1)
		printf("不存在.\n");
	else
		printf("index = %d\n", index);
}

/*
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void main()
{
	//实际参数
	int a = 100;
	int b = 200;
	printf("Swap before a = %d, b = %d\n", a, b);
	Swap(&a, &b);
	printf("Swap After a = %d, b = %d\n", a, b);
}

/*
         //形式参数
void Swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void main()
{
	//实际参数
	int a = 100;
	int b = 200;
	printf("Swap before a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("Swap After a = %d, b = %d\n", a, b);
}

/*
int fun(int a, int b)
{
	int v = a + b;
	//printf("s = %d\n", a + b);
	return v;
}

void main()
{
	int a = 100;
	int b = 200;
	int result;
	result = fun(a, b);
}

/*
void main()
{
	int x = -10;
	int v = abs(x);
	printf("v = %d\n", v);
}

/*
void main()
{
	char *str = "Hellonalfl";
	int len = strlen(str);   //库函数
	printf("len = %d\n", len);

	char str1[20] = "Hello ";
	char *str2 = "Bit.";
	strcat(str1, str2); //
	printf("str1 = %s\n", str1);

	char str3[20] = "Hello";
	char *str4 = "World";
	strcpy(str3, str4);
	printf("str3 = %s\n", str3);

	char *str5 = "Hello";
	char *str6 = "Xello";
	int flag = strcmp(str5, str6);
	if(flag == 0)
		printf("str5 == str6\n");
	else if(flag < 0)
		printf("str5 < str6\n");
	else
		printf("str5 > str6\n");
}

/*
//编写代码，演示多个字符从两端移动，向中间汇聚
int main()
{
	char arr1[] = "welcome to bit...";
	char arr2[] = "#################";

	int i = 0;
	int j = strlen(arr1) - 1;
	while(i <= j)
	{
		printf("%s\n", arr2);
		arr2[i] = arr1[i];
		arr2[j] = arr1[j];
		i++;
		j--;
		Sleep(1000);
		system("cls");
	}
	printf("%s\n", arr2);

	return 0;
}

/*
int main()
{
	char arr1[] = "welcome to bit...";
	char arr2[] = "#################";
	int left = 0;
	int right = strlen(arr1) - 1;
	printf("%s\n", arr2);
	//while循环实现
	while (left <= right)
	{
		Sleep(1000);
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("%s\n", arr2);
	}
	return 0;
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,90,100, 120,150,200, 1234};
	int n = sizeof(ar) / sizeof(ar[0]);
	int key;
	printf("input key:>");
	scanf("%d", &key);

	/////////////////////////////////////////////////////////
	//二分查找
	int low = 0;
	int high = n-1;
	int mid, index = -1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(key == ar[mid])
		{
			index = mid;
			break;
		}
		else if(key < ar[mid])
			high = mid-1;
		else 
			low = mid + 1;
	}
	if(index == -1)
		printf("要查找的%d不存在.....\n", key);
	else
		printf("要查找的%d在: %d\n",key, index);
	/////////////////////////////////////////////////////////
}

/*
//计算 1!+2!+3!+……+10!
//1 + 2 + 6 + 24 + 120
void main()
{
	size_t result = 0;
	int tmp;
	for(int i=1; i<=10; ++i)
	{
		tmp = 1;
		for(int j=1; j<=i; ++j)  //i!
		{
			tmp *= j;
		}
		result += tmp;
	}
	printf("result = %u\n", result);

}

/*
//计算n的阶乘
void main()
{
	//n! = 1 * 2 * 3 * .....*n
	int n;
	size_t result = 1;
	printf("input n:>");
	scanf("%d", &n);

	for(int i=1; i<=n; ++i)
	{
		result *= i; //result = result * i;
	}
	printf("%d! = %u\n", n, result);
}
*/