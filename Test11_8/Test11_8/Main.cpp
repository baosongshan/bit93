#include<stdio.h>
#include"Test.h"

int Sum(int a, int b)
{
	int v = a + b;
	return v;
}

void main()
{
	int a = 10;
	int b = 20;
	int result = Sum(a, b);
	printf("result = %d\n", result);
}
/*
void main()
{
	int a;
	double d = 12.34;
	a = d;   //隐示转换   类型不同不能复制
	printf("a = %d\n", a);
}

/*
void main()
{
	int ar[100] = {0};
	int item;
	int i = 0;
	while(1)
	{
		printf("input data(以-1结束):>");
		while(scanf("%d", &item), item!=-1)
		{
			ar[i++] = item;
		}
	}
}

/*
void main()
{
	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);
	printf("c = %d\n", c);
}
/*
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
	return 0;
}

/*
void test1(int arr[])
{
	printf("%d\n", sizeof(arr));//
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch));//(4)
}
int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//(1)
	printf("%d\n", sizeof(ch));//(3)
	test1(arr);
	test2(ch);
	return 0;
}

/*
//sizeof 不是函数， 是运算符
void fun(int a)
{

}
void main()
{
	int a = 10;
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof a);
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(int));
	//unsigned int
	fun(a);
}

//效率尽可能快
/*
int GetCount(unsigned char ch)
{
	//0000 0011

	int count[] = {0, 1, 1,2,1,2,2,3,1,2,2,3, ....... 8};
	return count[ch];
}

void main()
{
	//100=>0110 0100
	//255=>1111 1111
	unsigned char ch = 255;
	int count = GetCount(ch);
	printf("count = %d\n",count); //8
}



int GetCount(unsigned char ch)
{
	int count = 0;
	while(ch)
	{
		count++;
		ch &= (ch - 1);
	}
	return count;
}

void main()
{
	//100=>0110 0100
	//255=>1111 1111
	unsigned char ch = 255;
	int count = GetCount(ch);
	printf("count = %d\n",count); //8
}

/*
int GetCount(unsigned char ch)
{
	int count = 0;
	for(int i=0; i<8; ++i)
	{
		if(ch & 0x01 != 0)
			count++;
		ch >>= 1;
	}
	return count;
}

void main()
{
	//100=>0110 0100
	//255=>1111 1111
	unsigned char ch = 1;
	int count = GetCount(ch);
	printf("count = %d\n",count); //8
}


/*
int GetCount(unsigned char ch)
{
	int count = 0;
	while(ch != 0)
	{
		if(ch % 2 == 1)
			count++;
		ch /= 2;
	}
	return count;
}

void main()
{
	//100=>0110 0100
	//255=>1111 1111
	unsigned char ch = 100;
	int count = GetCount(ch);
	printf("count = %d\n",count); //8
}

/*
int fun(int ar[], int n)
{
	int ret = ar[0];
	for(int i=1; i<n; ++i)
	{
		ret ^= ar[i];
	}
	return ret;
}

void main()
{
	int ar[] = {1,2,3,4,5,6,5,7,8,9,9,8,7,6,4,3,2,1,11,22};
	int n = sizeof(ar) / sizeof(ar[0]);
	int ret = fun(ar, n);
	printf("ret = %d\n", ret);
}

/*
void main()
{
	int a = 10;
	int b = 20;
	printf("a = %d, b = %d\n", a, b);

	//
	//int tmp = a;
	//a = b;
	//b = tmp;
	//a = a + b;  //a = 30
	//b = a - b;  //b = 10
	//a = a - b;  //a = 20

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("a = %d, b = %d\n", a, b);
}

/*
int main()
{
	int num1 = 1;
	int num2 = 2;
	//0000 0001
	//0000 0010
	num1 & num2;    //0
	num1 | num2;    //3
	num1 ^ num2;    //3
	return 0;
}

/*
void main()
{
	int a = 2;
	int value = a << -30;   //左移  n * 2^x
	printf("value = %d\n", value);
}

/*
void main()
{
	int a = -10;

	//0000 0000 0000 0000 0000 0000 0000 1010
	//int value = a >> 2; //右移  n / 2^x
	int value = a << 29;   //左移  n * 2^x

	printf("value = %d\n", value);
}

/*
void main()
{
	int a = 9;
	float b = 2.0f;
	float value = a / b;
}


/*
#define ROW 5
#define COL 5
void main()
{
	int ar[ROW][COL] = {0};
	
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			ar[i][j] = i+j;
		}
	}

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}

}
/*
void main()
{
	int ar[] = {1,2,3,4,5};
	printf("%p\n", ar);
	printf("%p\n", &ar[0]);
	printf("%p\n", &ar);

	int *p = &ar[0];
	int *p1 = ar;
	int (*p2)[5] = &ar;
}

/*
void bubble_sort(int arr[], int n)
{
	for(int i=0; i<n-1; ++i)
	{
		for(int j=0; j<n-i-1; ++j)
		{
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 3, 1, 7, 5, 8, 9, 0, 2, 4, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for(int i=0; i<10; ++i)
		printf("%d ",arr[i]);
	printf("\n");
	bubble_sort(arr, n);
	
	for(int i=0; i<10; ++i)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

/*
#define ROW 3
#define COL 3

void main()
{
	int ar[ROW][COL] = {0};
	
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			ar[i][j] = i+j;
		}
	}
	
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
}


/*
void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);
	//动态开辟 malloc free
	int *p = (int *)malloc(sizeof(int) * n);
	for(int i=0; i<n; ++i)
	{
		p[i] = i+1; //1 2 3 ......
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ", p[i]);
	}
	free(p);
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);

	for(int i=0; i<n; ++i)
	{
		printf("%p\n", &ar[i]);
	}

}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);

	int a = 100;
	printf("%d\n", a);
	printf("%c\n", a);  //d 100
	//printf("%s\n", a);
	printf("%u\n", a);
	printf("0x%x\n", a);
	printf("0x%p\n", a);
}


/*
int main()
{
	int a = 10;
	int b = 20;

	int max_value = Max(a, b);

	return 0;
}
*/