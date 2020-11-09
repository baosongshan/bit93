#include<stdio.h>

//命令行参数
void main(int argc, char *argv[])
{
	//argc argv?
}

/*
void main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int ar[3] = {a, b, c};

	//存放指针的数组
	int *br[3] = {&a, &b, &c};

	int (*cr)[3]; //数组指针
}

/*
void main()
{
	int a = 100;
	int *p = &a;
	int **s = &p;
}

/*
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//int *p1 = &arr[0];
	int *p2 = arr;

	for(int i=0; i<10; ++i)
	{
		//printf("%d ", *(p2+i));
		//printf("%d ", p2[i]);
		printf("%d ", *(arr+i));
	}
	printf("\n");

	return 0;
}

/*
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr);
	return 0;
}

/*
void main()
{
	int values[SIZE];
	int *vp = &values[SIZE-1];  //&values[0]
	while(vp >= &values[0])
	{
		*vp = 0;
		vp--;
	}
}


/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	int *end = &ar[10];
	int *start = &ar[0];

	int n = end - start;
}

/*
void main()
{
	char ar[5] = {'a','b','c', 'd','e'};
	char *end = &ar[5];
	char *start = &ar[0];

	int len = end - start;
	printf("len = %d\n", len);
}

/*
#define SIZE 5

void main()
{
	int values[SIZE];
	int *vp = &values[SIZE-1];  //&values[0]
	while(vp >= &values[0])
	{
		*vp = 0;
		vp--;
	}
}

/*
void main()
{
	int values[SIZE];
	int *vp = values;  //&values[0]
	while(vp < &values[SIZE])
	{
		*vp = 0;
		vp++;
	}
}

/*
void main()
{
	int values[SIZE];
	int *vp;
	for (vp = &values[0]; vp < &values[SIZE];)
	{
		*vp = 0;
		vp++;
	}
}

/*
int mystrlen(char *str)
{
	if(str == NULL)  //assert 断言
		return -1;
	int len = 0;
	while(*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}
void main()
{
	char *str = ""; //NULL ""
	int len = mystrlen(str);
	printf("len = %d\n", len);
}

/*
void main()
{
	char ar[] = {'a','b','c'};
	char *str = "abc";
	printf("ar size = %d\n", sizeof(ar));
	printf("str size = %d\n", sizeof(str));

	printf("ar = %s\n", ar);
	printf("str = %s\n", str);
}

/*
void main()
{
	int *pa = (int *)malloc(sizeof(int) * 10);
	*pa = 10;
	free(pa);

	*pa = 200; //野指针
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(ar[0]);
	for(int i=0; i<n; ++i)
		printf("%d ", ar[i]);
	printf("\n");

	int *pa = ar;
	for(int i=0; i<=n; ++i)
		printf("%d ", *(pa+i));
	printf("\n");
}


/*
void main()
{
	int a = 10;
	int *pi; //野指针 --> 指针的指向不合法
}

/*
void main()
{

	int *pi = (int*)0x0012ff7c; //强制转换
	printf("%d\n", *pi);  //
}

/*
void main()
{
	int a =10;
	int *p = &a;
	int *q = p;
}

/*
void main()
{
	int a = 10;
	int b = 20;

	int *p = NULL;
	p = &a;
	*p = 100;
	p = &b;
	*p = 200;
}

/*
void main()
{
	int a = 100;
	a = 200;

	int *p = &a;
	*p = 10;   //解引用
}

/*
void main()
{
	int a = 123456789;
	char *pc = (char*)&a;
	printf("pc = 0x%p, %p\n", pc, pc+1);

	short *ps = (short*)&a;
	printf("ps = 0x%p %p\n", ps, ps+1);

	int *pi = &a;
	printf("pi = 0x%p %p\n", pi, pi+1);
}

/*
void main()
{
	int a = 123456789;
	char *pc = (char*)&a;
	printf("pc = 0x%p, value = %d\n", pc, *pc);

	short *ps = (short*)&a;
	printf("ps = 0x%p value = %d\n", ps, *ps);

	int *pi = &a;
	printf("pi = 0x%p value = %d\n", pi, *pi);
}


/*
void main()
{
	char *pch = NULL;   // 0
	int *pi = NULL;
	double *pd = NULL;
}

/*
void main()
{
	printf("%d\n", sizeof(char*));  //4 
	printf("%d\n", sizeof(short*)); //4
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));
}

/*
void main()
{
	int a = 10;  //内存空间
	int *p = &a; //整形指针变量

	printf("a = %d\n", a);
	printf("a = %d\n", *p);
}

/*
int fun()
{
	static int count = 1;
	return ++count;
}
int main()
{
	int answer;
	answer = fun() - fun() * fun();
	printf("%d\n", answer);//输出多少？
	return 0;
}

/*
void main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int v = (a++) + (b++) + (++c);
	printf("v = %d\n", v);
}


/*
void main()
{
	int i = 0;
	int v = (i++) + (i++) + (++i);
	printf("v = %d\n", v);
}


/*
int fun(int a, int b)
{
	int v = a + b;
	return v;
}

void main()
{
	int result = fun(10,20);
	printf("%d\n", result);
}

/*
int main()
{
	int a = 0 ;
	double d = 12.34;
	a = d;   //隐示转换 //显示转换
	return 0;
}
*/