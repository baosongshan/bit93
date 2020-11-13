#include<stdio.h>
#include<assert.h>

void main()
{
	int a = 10;
	int b = 20;

	 int *const pa = &a;

	//a = 100;
	//*pa = 100;
	pa = &b;
}

/*
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}

/*
void main()
{
	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		ret = 1;
		for (j = 1; j <= i; j++)
		{
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);
	return 0;

}

/*
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

int Sum(int a, int b)
{
	int sum = a + b;
	return sum;
}

void main()
{
	int select = 1;
	int op1, op2, result;
	while(select)
	{
		printf("****************************\n");
		printf("* [1] Add      [2] Sub     *\n");
		printf("* [3] Mul      [4] Div     *\n");
		printf("* [0] Quit System          *\n");
		printf("****************************\n");
		printf("请选择:>");

		//int x = Sum(10 ,20);  //断点  F9

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
		}
	}
	
}

/*
void main()
{
	int a = 10;
	assert(a == 0); //预言
	printf("OK");
}


int my_strlen(char *str)
{
	assert(str != NULL); //断言
	int count = 0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void main()
{
	//char *str = "abcxyz"; //""
	char *str = NULL;
	printf("len = %d\n", my_strlen(str));
}

/*
typedef struct Student
{
	int sn; //学号
	char name[10]; //姓名
	char sex[3];
	int age;
}Student, *PStu;

void Print_Stu_1(struct Student s)
{
	printf("sn = %d, name = %s, sex = %s, age = %d\n",
		s.sn, s.name, s.sex, s.age);
}

void Print_Stu_2(struct Student *ps)
{
	printf("sn = %d, name = %s, sex = %s, age = %d\n",
		ps->sn, ps->name, ps->sex, ps->age);
}

void main()
{
	Student s =  {1000, "附近阿里", "男", 20};
	printf("size = %d\n", sizeof(s)); //24
	Print_Stu_2(&s);
}

/*
void main()
{
	Student s =  {1000, "附近阿里", "男", 20};
	struct Student *ps = &s;
	
	printf("sn = %d, name = %s, sex = %s, age = %d\n",
		s.sn, s.name, s.sex, s.age);

	printf("sn = %d, name = %s, sex = %s, age = %d\n",
		ps->sn, ps->name, ps->sex, ps->age);

	printf("sn = %d, name = %s, sex = %s, age = %d\n",
		(*ps).sn, (*ps).name, (*ps).sex, (*ps).age);
}

/*
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;

typedef struct Time
{
	int hour;
	int minute;
	int second;
}Time;

typedef struct Birthday
{
	struct Date date;
	struct Time time;
}Birthday;

void main()
{
	Birthday bh;
	bh.date.year = 2000;
}

/*
typedef struct Birthday
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}Birthday;

void main()
{
	Birthday bh;
}


/*
typedef struct Student
{
	int sn; //学号
	char name[10]; //姓名
	char sex[3];
	int age;
}Student, *PStu;

void main()
{
	struct Student s1;
	//struct Student s1 = {1000, "附近阿里", "男", 20}; //初始化
	//struct Student s1 = {1000}; 

	//赋值
	s1.sn = 1000;
	strcpy(s1.name,"附近阿里");
	strcpy(s1.sex, "男");
	s1.age = 20;
	printf("sn = %d, name = %s, sex = %s, age = %d\n",
		   s1.sn, s1.name, s1.sex, s1.age);
}

/*
void main()
{
	//C/C++
	struct Student s1;
	Student s2;
	PStu s3, s4;

	Student *ps5, *ps6
}

/*
#define U_INT unsigned int
#define U_LONG unsigned long

//type define
typedef unsigned int u_int;
typedef unsigned long u_long;

void main()
{
	unsigned int a = 100;
	unsigned long b = 200;

	U_INT x = 10;
	U_LONG y = 20;

	u_int m = 1;
	u_long n = 2;
}

/*
typedef struct Student
{
	int sn; //学号
	char name[10]; //姓名
	char sex[3];
	int age;
}Student;

void main()
{
	//C/C++
	struct Student s1;
	Student s2;
}


/*
struct 
{
	int sn; //学号
	char name[10]; //姓名
	char sex[3];
	int age;
}stu;

void main()
{
	
}


struct Student
{
	int sn; //学号
	char name[10]; //姓名
	char sex[3];
	int age;
}stu2;

void main()
{
	struct Student stu;
	struct Student stu1;
}

/*
struct Test
{
	int a;
};

void main()
{
	struct Test t;
}


void main()
{
	char ch;
	int i;
	int a;
	int b;
	float c;

	int ar[10]; //
}
*/