#include<stdio.h>

int Add(int a, int b)
{
	int res = a + b;
	return res;
}
int Sub(int a, int b)
{
	int res = a - b;
	return res;
}
int Mul(int a, int b)
{
	int res = a * b;
	return res;
}
int Div(int a, int b)
{
	int res = a / b;
	return res;
}

int Mod(int a, int b)
{
	int res = a % b;
	return res;
}

//转移表  函数表
int(*fun_table[])(int, int) = 
{NULL, Add, Sub, Mul, Div, Mod};

void main()
{
	int select = 1;
	int op1, op2, result;
	while(select)
	{
		printf("****************************\n");
		printf("* [1] Add      [2] Sub     *\n");
		printf("* [3] Mul      [4] Div     *\n");
		printf("* [5] Mod      [0] Quit    *\n");
		printf("****************************\n");
		printf("请选择:>");

		scanf("%d", &select);

		if(select == 0)
			break;

		printf("请输入两个数op1 and op2:>");
		scanf("%d %d", &op1, &op2);

		//
		result = fun_table[select](op1, op2);

		printf("result = %d\n", result);
		system("pause");
		system("cls");
	}
}

/*

void main()
{
	int select = 1;
	int op1, op2, result;
	while(select)
	{
		printf("****************************\n");
		printf("* [1] Add      [2] Sub     *\n");
		printf("* [3] Mul      [4] Div     *\n");
		printf("* [5] Mod      [0] Quit    *\n");
		printf("****************************\n");
		printf("请选择:>");

		scanf("%d", &select);

		if(select == 0)
			break;

		printf("请输入两个数op1 and op2:>");
		scanf("%d %d", &op1, &op2);

		switch(select)
		{
		case 1:
			result = Add(op1, op2);
			break;
		case 2:
			result = Sub(op1, op2);
			break;
		case 3:
			result = Mul(op1, op2);
			break;
		case 4:
			result = Div(op1, op2);
			break;
		case 5:
			result = Mod(op1, op2);
			break;

		//................

		}
		printf("result = %d\n", result);
		system("pause");
		system("cls");
	}
}

/*
void fun()
{}
void main()
{
	printf("%p\n", fun);
	printf("%p\n", &fun);
}

/*
void fun(int **ptr)
{}
void main()
{
	int a = 0;
	int *pa = &a;
	fun(&pa);

	int ar[3][5] = {0};
	fun(ar);
}

/*
void fun(int *p)
{}
void main()
{
	int a = 0;
	fun(&a);

	int ar[10] = {0};
	fun(ar);
}

/*
void test(int (*arr)[5])//ok？
{}
void test(int **arr)//ok？
{}
int main()
{

	int arr[3][5] = { 0 };

	test(arr);  //地址
};

/*
void test2(int **arr)//ok?
{}


int main()
{
	int arr[10] = { 0 };
	int *arr2[20] = { 0 }; //int**

	//test(arr);
	test2(arr2);  //
}

/*
typedef int* Ar[10];

void main()
{
	int ar[10];
	Ar br;
}

/*
int *(*(*fun)(int *))[10];

int (*func)(int *, int (*)(int *)); //
//
int (*func[5])(int *);//
//
int (*(*func)[5])(int *);//
//
int (*(*func)(int *)) [5];
//
int*(*func(int*))[5]

//(*(void(*)())0)()
//

/*
用变量a给出下面的定义
a) 一个整型数 int a;
b) 一个指向整型数的指针 int *a;
c) 一个指向指针的指针，它指向的指针是指向一个整型数 int **a;
d) 一个有10个整型数的数组 int a[10];
e) 一个有10个指针的数组，该指针是指向一个整型数的。int *a[10];
f) 一个指向有10个整型数数组的指针  int(*a)[10]
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数
   int(*a)(int)
h) 一个有10个指针的数组，该指针指向一个函数，
   该函数有一个整型参数并返回一个整型数
   int(*a[10])(int)


/*
int* fun(int a, int b)
{
	int ret = a + b;
	return &ret;
}

void main()
{
}

/*
int fun(int a, int b)
{
	int ret = a + b;
	return ret;
}

void fun1(int a, int b)
{

}

void main()
{
	int result = fun(10, 20);

	int(*pfun)(int, int);  //函数指针
	void(*pfun1)(int, int);//

	//标准写法
	pfun = &fun;
	result = (*pfun)(10,20);
	printf("result = %d\n", result);

	//简化的写法
	pfun = fun;
	result = pfun(100, 200);
	printf("result = %d\n", result);
}

/*
#define ROW 3
#define COL 5

void Print_Ar_1(int ar[ROW][COL])
{
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}
}

void Print_Ar_2( int (*ar)[COL] )
{
	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			//printf("%d ", *(ar[i]+j));  //ar[i] + j
			printf("%d ", ar[i][j]); 
		}
		printf("\n");
	}
}

void main()
{
	int ar[ROW][COL] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	Print_Ar_2(ar);

}

/*
void main()
{
	int ar[3] = {10, 20, 30};
	int(*par)[3] = &ar;

	printf("%d\n", par[0][0]);
	printf("%d\n", par[0][1]);
	printf("%d\n", par[0][2]);
}

/*
void main()
{
	int ar[3] = {10, 20, 30};

	int br[4] = {10, 20, 30, 40};

	int cr[3] = {10, 20, 30};

	int (*pa)[3] = &ar;
	pa = &cr;
}

/*
void main()
{
	int ar[3] = {10, 20, 30};
	printf("%p\n", ar);
	printf("%p\n", &ar[0]);
	printf("%p\n", &ar);

	int *p1 = ar;
	int *p2 = &ar[0];
	int (*p3)[3] = &ar;  //int (*)[3]  int [3]

	printf("%p : %p\n", p1, p1+1);
	printf("%p : %p\n", p2, p2+1);
	printf("%p : %p\n", p3, p3+1);
}

/*
int main()
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3  = "hello bit.";
	char *str4  = "hello bit.";

	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");

	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");

	strcmp(str1, str2);

	return 0;
}


/*
void main()
{
	char str[] = "Hello Bit.";  //字符数组
	char *str1 = "Hello Bit.";  //字符指针

	printf("str size = %d\n", sizeof(str));
	printf("str1 size = %d\n", sizeof(str1));

	printf("str = %s\n", str);
	printf("str1 = %s\n", str1);

	str[0] = 'h';
	str1[0] = 'h';
	printf("str = %s\n", str);
	printf("str1 = %s\n", str1);
}


/*
void main()
{
	char ch = 'A';
	char *pch = &ch;
	*pch = 'a';
}


void main()
{
	int a = 10;
	int *pa = &a;
	//pa
	//int * 这是pa指针的自身类型
	//int   这是pa指针所指的类型
}
*/