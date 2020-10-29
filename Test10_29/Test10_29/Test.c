#include<stdio.h>

extern int Hello;

void main()
{
	printf("Hello = %d\n", Hello);
}

/*
int fun()
{
	int i = 0; //局部变量
	i += 10;
	return i;
}

void main()
{
	int a = fun();
	printf("a = %d\n", a);
	int b = fun();
	printf("b = %d\n", b);

}

/*
typedef unsigned int u_int;
#define u_int_32 unsigned int

void main()
{
	unsigned int a = 100;
	size_t b = 200;
	u_int c = 200;
	u_int_32 d = 300;
}

/*
void main()
{
	int a = 0;
	int b = 2;
	int v = a && ++b;  //短路求值
	printf("v = %d\n", v);
	printf("b = %d\n", b);
}

/*
void main()
{
	int a = 0;
	int b = 7;

	//int v = a && b;
	//int v = a || b;
	int v = !a; 
	//int v = ~a;
	printf("v = %d\n", v);
}

/*
void main()
{
	int a = 10;
	int b = 7;

	//int v = a & b;
	//int v = a | b;
	//int v = a ^ b;   //异或
	int v = ~a;
	//0000 0000 0000 0000 0000 0000 0000 1010
	//0000 0111 &
	printf("v = %d\n", v);
}

/*
//int ar[10]; // 0

void main()
{
	//未初始化
	//完全初始化
	//未完全初始化 用 0填充
	int ar[10] = {1,2,3,4,5}; //
	for(int i=0; i<10; ++i)
	{
		printf("%d\n", ar[i]);
		//1 2 3 4 5 0 0 0 0 0
	}
}

/*
//函数名
//返回值
//参数
//函数体
int MaxValue(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	int a, b, max_value;
	printf("input a and b:>");
	scanf("%d %d", &a, &b);
	max_value = MaxValue(a,b);
	printf("max value = %d\n", max_value);
}
/*
void main()
{
	int sum = 0;
	int i = 1;
	do
	{
		sum += i;
		i++;
	}while(i<=10);
	printf("sum = %d\n", sum);
}

/*
void main()
{
	int sum = 0;
	int i = 1;
	while(i<=10)
	{
		sum += i;
		i++;
	}
	printf("sum = %d\n", sum);
}

/*
void main()
{
	int i = -1;
	printf("i = %u\n", i);
}

/*
void main()
{
	char ch = 1; //char
	for(; ch < 128; ++ch)
		printf("ch = %d\n", ch);
}

/*
void main()
{
	int sum = 0;
	//int i;
	for(int i = 1; i<=10; ++i) 
	{
		sum += i;
	}
	printf("sum = %d\n", sum);
}


/*
void main()
{
	int sum = 0;
	int i = 1;
	for(; i<=10; ++i) 
	{
		sum += i;
	}
	printf("sum = %d\n", sum);
}

/*
void main()
{
	int sum = 0;
	int i;
	for(i = 1; i<=10; ++i) 
	{
		sum += i;
	}
	printf("sum = %d\n", sum);
}

/*
void main()
{
	int a = 0;

	printf("%d %d %d %d\n", a++, ++a, a++, ++a);
          // 2 2  1  1
	printf("a = %d\n", a);
	      //4
}

/*
//++ --

int add_pre(int *a)
{
	*a = *a + 1;
	return *a;
}
int add_post(int *a)
{
	int tmp = *a;
	*a = *a + 1;
	return tmp;
}

void main()
{
	int a = 1;
	//int v = a++;
	//int v = add_pre(&a); //++a
	int v = add_post(&a);
	printf("a = %d\n", a); //2
	printf("v = %d\n", v); //
}

/*
void main()
{
	int sum = 0;
	int i;
	for(i = 1; i<=10; ++i) //
	{
		//sum += i; // sum = sum + i;
		sum = sum + i;
	}
	printf("sum = %d\n", sum);
}

/*
void main()
{
	int grade = 66;
	if(grade >= 50)
		printf("A"); 
	else if(grade>=80 && grade<90)
		printf("B");
	else if(grade>=60 && grade<80)
		printf("C");
	else 
		printf("D");
}

/*
void main()
{
	int a, b, max_value;
	printf("input a and b:>");
	scanf("%d %d", &a, &b);
	if(a > b)
		max_value = a;
	else 
		max_value = b;
	printf("max value = %d\n", max_value);
}


/*
void main()
{
	int a, b, max_value;
	printf("input a and b:>");
	scanf("%d %d", &a, &b);
	if(a > b)
	{
		max_value = a;
	}
	else 
	{
		max_value = b;
	}
	printf("max value = %d\n", max_value);
}


/*
void main()
{
	int a, b;
	printf("input a and b:>");
	scanf("%d %d", &a, &b);
	if(a > b)
	{
		printf("max value = %d\n", a);
	}
	else 
	{
		printf("max value = %d\n", b);
	}
}

/*
void main()
{
	int line = 0;
	printf("input line:>");
	scanf("%d", &line);

	if(line >= 20000)
	{
		printf("获得好的offer.\n");
	}
	else
	{
		printf("继续努力.\n");
	}
}

#if 0   //条件编译
void main()
{
	/*JFLAJFLAJFLAJFL
	char ch = "\x25";
	//char ch = 88;
	//char ch = 'X';
	printf("ch = %c\n", ch);
}

/*
int main()
{
	printf("%d\n", strlen("abcdef"));
	//printf("%d\n", sizeof("abcdef"));
	printf("%d\n", strlen("c:\test\x25\test.c"));
	                    //c:*est
	return 0;
}

/*
void main()
{
	char *str = "C:\\Bit\\bit_kejian\\C\\C语言课件-最新版\\初阶";
	printf("str = %s\n", str);
}

/*
int main()
{
	char *str = "Hello"; //
	printf("str = %s\n", str);
	return 0;
}#endif
*/

