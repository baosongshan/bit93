#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main()
{
	printf("%d\n", strlen("abcdef"));
	//printf("%d\n", sizeof("abcdef"));

	printf("%d\n", strlen("c:\test\328\test.c")); //?????
	return 0;
}

/*
void main()
{
	//char str[] = "C:\Bit\bit_kejian\\C\\C���Կμ�-���°�\\����";
	char str[] = "  \'abcxyz\'  "; //"abcxyz"
	printf("str = %s\n", str);
}

/*
int main()
{
	char arr1[] = "bit";
	char arr2[] = { 'b', 'i', 't' };
	char arr3[] = { 'b', 'i', 't', '\0' };

	printf("%s\n", arr1); //bit
	printf("%s\n", arr2); //bit
	printf("%s\n", arr3); //bit
	return 0;
}


/*
void main()
{
	char str[] = {'a'};
	printf("size = %d\n", sizeof(str));

	char str1[] = "a";  //a \0
	printf("size = %d\n", sizeof(str1));
}

/*
void main()
{
	char str2[] = {'a','\0','b','c'};
	printf("str2 = %s\n", str2);

	char *str = "Hello Bit.";
	printf("str = %s\n", str);
}


/*
//C����û���ַ�������
void main()
{
	char *str = "Hello Bit.";
	printf("str = %s\n", str);

	char str1[] = "Hello CPP.";
	printf("str1 = %s\n", str1);

	char str2[] = {'a','b','c','\0'};
	printf("str2 = %s\n", str2);

}

//���� scanf  printf

/*
void main()
{
	int a = 10;
	//����
	{
		int b = 20;
		printf("a = %d\n", a);
		printf("b = %d\n", b);
	}
	//printf("b = %d\n", b);
	printf("a = %d\n", a);
}

/*
void main()
{
	int a, b;
	printf("input a and b:>");
	scanf("%d,%d", &a, &b);
	int sum = a + b;
	printf("sum = %d\n", sum);
}

/*
void main()
{
	int a = 10;
	printf("%d\n", a);
	printf("%p\n", &a); //0x
}


/*
void main()
{
	int a, b;
	printf("input a and b:>");
	scanf("%d", &a, &b);
}

/*
//ȫ�ֱ���
int g_size = 1000;

void main()
{
	int g_size = 10;
	printf("g_size = %d\n", g_size);
}

/*
void fun()
{
	printf("in fun g_size = %d\n", g_size);
	printf("in fun a = %d\n", a);
}

void main()  //����
{
	//�ֲ�����
	int a = 10;
	printf("a = %d\n", a);
	printf("g_size = %d\n", g_size);
	fun();
}

/*
void main()
{
	const int a = 10; //����
	a = 100;
}

/*
void main()
{
	int a;   //δ��ʼ��
	a = 100; //��ֵ
	printf("a = %d\n", a);
	a = 200;
	printf("a = %d\n", a);
}

/*
void main()
{
	char ch = 'a'; //"a" �ַ���
	int a = 100;
	float f = 12.34f;
}

/*
void main()
{
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(bool));
}

/*
int main()
{
	//�������
	char ch = 'A';  //
	int a = 10;     //
	double d = 12.34; //
	
	return 0;
}


/*
#include<stdio.h> //��׼�������

void main()
{
	printf("Hello World.\n");
	printf("Change World.\n");
}
*/