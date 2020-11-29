#include<stdio.h>
#include<vld.h>
#include<limits.h>

typedef struct Test
{
	char a;
	double b;
	int c;
	int d;
	char ptr[0]; //柔性数组成员   不占空间
	//char *ptr;
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
	char str[] = "hello Bithflkafkjak";
	Test t;
	
	//t.ptr = str;
	printf("str = %s\n", t.ptr);
}

/*
void Test(void)
{
	char *str = (char *)malloc(100);
	strcpy(str, "hello");
	free(str);
	str = NULL;

	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}
void main()
{
	Test();
}

/*
void GetMemory(char **p, int num)
{
	*p = (char *)malloc(num);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
	//free(str);
}
void main()
{
	Test();
}

/*
char *GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}
void main()
{
	Test();
}

/*
int fun(int a, int b)
{
	int v = a + b;
	return v;
}

void main()
{
	int result = fun(10, 20);
	printf("result = %d\n", result);
}


/*
char *GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}
void main()
{
	Test();
}

/*
void GetMemory(char *p)
{
	p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}

void main()
{
	Test();
}

/*
//void *malloc( size_t size );
//void *calloc( size_t num, size_t size );
//void *realloc( void *memblock, size_t size );

void main()
{
	int a = 10;
	int b = 20;
	a = 100;
	int *p = (int *)malloc(100);
	memset(p, 0, 100);
	p++;
	free(p);//p不再指向动态内存的起始位置
}

/*
void main()
{
	int i = 0;
	int *p = (int *)malloc(10 * sizeof(int));
	if (NULL == p)
	{
		exit(1);
	}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;//当i是10的时候越界访问
	}
	free(p);
}

/*
void main()
{
	int *p = (int *)malloc(536870911479299529);
	if(NULL == p)
	{
		printf("Out Of Memory.\n");
		return;
	}


	*p = 20;//如果p的值是NULL，就会有问题
	free(p);
}

/*
void main()
{
	int n = 5;
	int *p = (int *)malloc(sizeof(int) * n);
	if(NULL == p)
	{
		printf("Out Of Memory.\n");
		return;
	}
	

	free(p);  //内存泄漏
}

/*
void main()
{
	int n = 10;
	int *p = (int *)realloc(NULL, sizeof(int) *n); //malloc
	if(NULL == p)
		return;
	for(int i=0; i<n; ++i)
	{
		p[i] = i + 1;  //1 2 3 4 5 x x x x x
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ",p[i]);  //1 2 3 4 5
	}
	printf("\n");

	n = 5;
	p = (int *)realloc(p, sizeof(int) * n);
	for(int i=0; i<n; ++i)
	{
		printf("%d ",p[i]);  //1 2 3 4 5
	}
	printf("\n");

	free(p);
}

/*
void main()
{
	int n = 5;
	int *p = (int *)malloc(sizeof(int) * n);
	if(NULL == p)
	{
		printf("Out Of Memory.\n");
		return;
	}

	for(int i=0; i<n; ++i)
	{
		p[i] = i + 1;  //1 2 3 4 5
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ",p[i]);  //1 2 3 4 5
	}
	printf("\n");
	//////////////////////////////////////////////////////////

	//1 2 3 4 5 6 7 8 9 10
	n = 1000000;
	int*p = (int*)realloc(p, sizeof(int) * n); //模拟实现
	if(NULL == p)
	{
		printf("Out Of Memory.\n");
		return;
	}

	for(int i=5; i<n; ++i)
	{
		p[i] = i + 1;  //1 2 3 4 5 x x x x x
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ",p[i]);  //1 2 3 4 5
	}
	printf("\n");

}

/*
void main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	if(NULL == p)
		return;
	memset(p, 0, sizeof(int) *10);

	int *p1 = (int *)calloc(10, sizeof(int)); //用0初始化
	if(NULL == p1)
		return;
}

/*
void main()
{
	int n = 5;
	int *p = (int *)malloc(sizeof(int) * n);
	if(NULL == p)
	{
		printf("Out Of Memory.\n");
		return;
	}

	for(int i=0; i<n; ++i)
	{
		p[i] = i + 1;  //1 2 3 4 5
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ",p[i]);  //1 2 3 4 5
	}
	printf("\n");

	//1 2 3 4 5 6 7 8 9 10
	n = 10;
	p = (int *)realloc(p, sizeof(int) * n); //模拟实现
	if(NULL == p)
	{
		printf("Out Of Memory.\n");
		return;
	}

	for(int i=5; i<n; ++i)
	{
		p[i] = i + 1;  //1 2 3 4 5 x x x x x
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ",p[i]);  //1 2 3 4 5
	}
	printf("\n");

}

/*
void main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	if(NULL == p)
		return;

	int *p1 = (int *)calloc(10, sizeof(int));
	if(NULL == p1)
		return;
}

/*
void main()
{
	int a = 10;
	int *p = &a;

	//free(p);
}

/*
void main()
{
	int *p = (int*)malloc(sizeof(int) *25); //
	free(p);  //释放空间

	p = NULL;

	free(p); 
	free(p); 
	
}

/*
void main()
{
	int *p = NULL;
	free(p);
	free(p);
	free(p);
	free(p);
	free(p);
	free(p);
}

/*
void main()
{
	int *p = (int*)malloc(sizeof(int) *25); //
	free(p);  //释放空间
	p = NULL; //释放指针

	//int *q = (int*)malloc(sizeof(int) *25);

	for(int i=0; i<25; ++i)
	{
		p[i] = i;
	}
}

/*
void main()
{
	int n;
	printf("input n:>");
	scanf("%d", &n);

	//动态内存开辟
	int *ar = (int *)malloc(sizeof(int) * n);  //n  int
	if(NULL == ar)
	{
		printf("Out Of Memory.\n");
		return;
	}

	for(int i=0; i<n; ++i)
	{
		ar[i] = i + 1;
	}

	for(int i=0; i<n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");

	free(ar);
}


/*
int g = 0;

void fun(int x, int y)
{
	int m;  //局部变量
	int n;
}

void main()
{
	//静态开辟  栈区
	int a = 10;
	int b = 20;
	char *str = "Hello"; //
	int ar[10] = {0};
}

/*
int main()
{
	char *p = "zhangpengwei@bitedu.tech";  //20
	const char* sep = ".@";

	int n = strlen(p) + 1;

	char arr[n];
	char *str = NULL;
	
	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
	
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
}

/*
void main()
{
	char str[] = "-, This, a sample-string.";
	char *sep = " ,-";
	char *pch = strtok(str,  sep);
	
	while(pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, sep);
	}
}

/*
void fun(char *str)
{
	while(*str != '\0')
	{
		*str -= 32;
		str++;
	}
}

void main()
{
	char str[] = "hello";
	printf("%s\n", str);
	fun(str);
	printf("%s\n", str);
}
*/