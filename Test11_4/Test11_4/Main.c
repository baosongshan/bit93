#include<stdio.h>

#define ROW 3
#define COL 4
void main()
{
	//˼�� ��ά����� ������ ������ʲô������������
	//int ar[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int ar[ROW][COL] = {1,2,3}; //������

	for(int i=0; i<3; ++i)   //
	{
		for(int j=0; j<4; ++j) //
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
}

/*
void main()
{
	int ar[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	printf("ar size = %d\n", sizeof(ar));

	for(int i=0; i<3; ++i)   //
	{
		for(int j=0; j<4; ++j) //
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
}

/*
void  main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("ar size = %d\n", sizeof(ar));

	printf("%p", ar); //��������ֵ����Ԫ�صĵ�ַ
}

/*
//int Br[10];
void main()
{
	int Ar[10];
	int Br[10] = {1,2,3,4,5,6,7,8,9,10};//��ȫ��ʼ��
	int Cr[10] = {1,2,3,4,5}; //δ��ȫ��ʼ��

	int Dr[] = {1,2,3,4,5,6,7,8,9};

	int n = 1000000001;
	int Er[100000000];  //����  malloc
}

/*
size_t Fib(int n)
{
	if(n <= 2)
		return 1;
	else
		return Fib(n-1) + Fib(n-2);
}

void main()
{
	//1 1 2 3 5 8 13 21 34 .....
	int n = 80;
	size_t result = Fib(n);
	printf("result = %u\n", result);
}

/*
size_t Fib(int n)
{
	if(n <= 2)
		return 1;
	int fib1 = 1;
	int fib2 = 1;
	int fib;

	//����  �ž�ջ�����
	for(int i=3; i<=n; ++i)
	{
		fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib;
	}
	return fib;
}

void main()
{
	//1 1 2 3 5 8 13 21 34 .....
	int n = 80;
	size_t result = Fib(n);
	printf("result = %u\n", result);
}

/*
int Fac(int n)
{
	if(n == 1)
		return 1;
	else
		return n * Fac(n-1);
}

void main()
{
	int n = 50;
	int result = Fac(n);
	printf("result = %d\n", result);

}


/*
int Fac(int n)
{
	int result = 1;
	for(int i=1; i<=n; ++i)
	{
		result *= i;
	}
	return result;
}

void main()
{
	int n = 5;
	int result = Fac(n);
	printf("result = %d\n", result);

}

/*
//n! //����  ѭ��
void main()
{
	int n = 5;
	int result = 1;
	for(int i=1; i<=n; ++i)
	{
		result *= i;
	}
	printf("result = %d\n", result);
}

/*
//�ݹ�  --> ��������
void Print(int value)
{
	if(value > 9)
		Print(value / 10);
	printf("%d ", value % 10);
}
void main()
{
	int value = 1234; //1 2 3 4 
	Print(value);
}

/*
#include"Test.h"   //����ͷ�ļ�


int main()
{
	int a = 100;
	int b = 200;
	int c = 150;
	int max_value = MyMax(a, b);
	printf("max value = %d\n", max_value);

	//max_value = fun(a, b, c);
	return 0;
}
*/