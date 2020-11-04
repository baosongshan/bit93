#include<stdio.h>
#include<stdbool.h>

int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

int Mod(int a, int b)
{
	return a % b;
}

void main()
{
	int select = 1;
	int op1, op2, result;

	////////////////////////////////////////////////
	//界面设计
	system("title 简易计算器");
	system("mode con cols=30 lines=15");
	system("color 0F");
	////////////////////////////////////////////////

	while(select)
	{
		printf("******************************\n");
		printf("*        简 易 计 算 器      *\n");
		printf("******************************\n");
		printf("* [1] Add           [2] Sub  *\n");
		printf("* [3] Mul           [4] Div  *\n");
		printf("* [5] Mod           [0] Quit *\n");
		printf("******************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;

		printf("请输入op1 和 op2:>");
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
		default:
			printf("输入的cmd有误，请重新输入......\n");
			break;
		}
		printf("result = %d\n", result);
		system("pause");
		system("cls"); 
	}
	printf("系统退出.\n");
}

/*
int main()
{
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
	{
		printf("aaaaaaaaaaaa\n");
		k++;
	}
	return 0;
}


/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(ar) / sizeof(ar[0]);

	for(int i=0; i<n; ++i)    // n-i  [  )
	{
		printf("%d ", ar[i-1]);
	}
	printf("\n");
}
/*
int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= '0' && ch <= '9')
			continue;
		putchar(ch);
	}
	return 0;
}



/*
int main()
{
	int ch = 0;
	//while (ch = getchar() != EOF)
	while ((ch = getchar()) != EOF)  //END OF FILE  CTRL+Z  0 1
		putchar(ch);
	return 0;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(ar) / sizeof(ar[0]);

	for(int i=0; i<n; ++i)
	{
		if(i == 5)
			break;
		printf("%d ", ar[i]);
	}

	printf("\n");
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(ar) / sizeof(ar[0]);

	for(int i=0; i<n; ++i)
	{
		if(i == 5)
			break;
		printf("%d ", ar[i]);
	}
	printf("\n");
}

/*
void main()
{
	//for(; ;) //死循环
	while(0)
	{
		printf("Hello Bit.\n");
	}
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(ar) / sizeof(ar[0]);

	int i = 0;
	do
	{
		printf("%d ", ar[i]);
		i++;
	}while(i<n);

	printf("\n");
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(ar) / sizeof(ar[0]);

	int i = 0;
	while(i < n)
	{
		printf("%d ", ar[i]);
		i++;
	}

	printf("\n");
}


/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(ar) / sizeof(ar[0]);

	for(int i=0; i<n; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

/*
bool isLeap(int year)
{
	return ((year%4==0&&year%100!=0) ||(year%400==0));
}
void main()
{
	//1
	int days[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year, month;
	while(1)
	{
		printf("input year and month:>"); //3
		scanf("%d %d", &year, &month);   //1 31  5 31 9 30
		if(month == 2)
		{
			if(isLeap(year))
				month = 0;
		}
		printf("%d年的%d月有:%d天\n", year, month, days[month]);
	}
}

/*
void main()
{
	int year, month;
	int days;
	while(1)
	{
		printf("input year and month:>");
		scanf("%d %d", &year, &month);   //1 31  5 31 9 30
		if(month==1 || month==3 || ......)
		{}
		else if(month == 2)
		{}
		else
		{}
	}
}

/*
bool isLeap(int year)
{
	return ((year%4==0&&year%100!=0) ||(year%400==0));
}

void main()
{
	int year, month;
	int days;
	while(1)
	{
		printf("input year and month:>");
		scanf("%d %d", &year, &month);   //1 31  5 31 9 30
		
		switch(month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 2:
			if(isLeap(year))
				days = 29;
			else
				days = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		default:
			printf("输入的月份有误，请重新输入......\n");
			break;
		}
		printf("%d年的%d月有:%d天\n", year, month, days);
	}
}


/*
void main()
{
	int year, month;
	int days;
	while(1)
	{
		printf("input year and month:>");
		scanf("%d %d", &year, &month);   //1 31  5 31 9 30
		
		switch(month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 2:
			if((year%4==0&&year%100!=0) ||(year%400==0))
				days = 29;
			else
				days = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		default:
			printf("输入的月份有误，请重新输入......\n");
			break;
		}
		printf("%d年的%d月有:%d天\n", year, month, days);
	}
}

/*
void main()
{
	int year, month;
	int days;
	while(1)
	{
		printf("input year and month:>");
		scanf("%d %d", &year, &month);   //1 31  5 31 9 30
		
		switch(month)
		{
		case 1:
			days = 31;
			break;
		case 2:
			if((year%4==0&&year%100!=0) ||(year%400==0))
				days = 29;
			else
				days = 28;
			break;
		case 3:
			days = 31;
			break;
		case 4:
			days = 30;
			break;
		case 5:
			days = 31;
			break;
		case 6:
			days = 31;
			break;
		case 7:
			days = 31;
			break;
		case 8:
			days = 31;
			break;
		case 9:
			days = 30;
			break;
		case 10:
			days = 31;
			break;
		case 11:
			days = 30;
			break;
		case 12:
			days = 31;
			break;
		}

		printf("%d年的%d月有:%d天\n", year, month, days);
	}
}

/*
void main()
{
	float ch = 12.34f;
	int a, b;
	a = b = 0;
	switch(a+b)   //整数  整数的表达式
	{
	case 1:
		break;
	case 10:
		break;
	default:
		break;
	}
}

/*
int main()
{
	int day = 0;
	switch (day)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期天\n");
		break;
	default:
		printf("day错误,请重新输入.....\n");
		break;
	}
	return 0;
}

/*
void main()
{
	int a, b, c;
	int a = 0;
	if(10 == a)  
	{
		printf("Equal.\n");
	}
	else
	{
		printf("No Euqal.\n");
		printf("aaaaaaaaaa\n");  
	}
}

/*
int main()
{
	int a = 1;
	int b = 2;
	if (a == 1)
	{
		if (b == 2)
			printf("hehe\n");
	}
	else
		printf("haha\n");
	return 0;
}

/*
void main()
{
	int a = 10;
	if(10 == a)  //
	{
		printf("Equal.\n");
	}
	else
	{
		printf("No Euqal.\n");	
	}
	printf("aaaaaaaaaa\n");  
}

/*
void main()
{
	bool flag = true;

	if(!flag)      //?????
		printf("OK\n");
	else
		printf("Error\n");
}

/*
void main()
{
	int size = 100;
	if(size > 200)  //true
	{
		printf("OK\n");
	}
	else
	{
		printf("Error.\n");
	}
}


/*
void main()
{
	int size = 1000;
	if(size > 200)  //true
	{
		printf("OK\n");
	}
}

/*
struct Student
{
	char name[10];
	int age;
};

void main()
{
	struct Student t = {"比特", 20};
	//t.age = 20;
	//strcpy(t.name,"比特");

	printf("name = %s, age = %d\n", t.name, t.age);
}

/*
void main()
{
	//32
	printf("%d\n", sizeof(bool*));  //bool *pb; sizeof(pb);
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int*));   //int *pi;   sizeof(pi)
	printf("%d\n", sizeof(float*));
	printf("%d\n", sizeof(double*));
	printf("%d\n", sizeof(long*));
}

/*
void main()
{
	int a = 10;
	printf("a = %d\n", a);
	a = 20;
	printf("a = %d\n", a);

	int *pa = &a;
	*pa = 200;
	printf("a = %d\n", a);


}

/*
void main()
{
	char ch = 'A';
	short s = 100;
	int i = 123;
	float f = 12.34f;

	char *pc = &ch;
	short *ps = &s;
	int *pi = &i;
}

/*
void main()
{
	int i = 10; //整形变量 = 整形数据
	char ch = 'A';

	int *p = &i; //p指针变量 = 指针数据 ==> 指针==地址
}


/*
void main()
{
	char ch = 'A';
	short s = 100;
	int i = 123;
	float f = 12.34f;



}

/*
//
#define ADD(a, b) ((a)+(b)) 
#define MUL(a, b) ((a)*(b))
void main()
{
	//int result  = ADD(1,2) * ADD(3,4); //3*7
	           //1+2 * 3+4
	int result = MUL(1+2, 3+4);
	           //(1+2) * (3+4)
	printf("result = %d\n", result);
}

/*
#define MAX_BUFFER_SIZE 256

void main()
{
	int size = MAX_BUFFER_SIZE;
	//int size = 256;
	printf("size = %d\n", size);
}

/*
void main()
{
	int a = 10;
	unsigned int v = ~a;
	//0000 0000 0000 0000 0000 0000 0000 1010
	//1111 1111 1111 1111 1111 1111 1111 0101  内存 补码
	//1111 1111 1111 1111 1111 1111 1111 0100  反码
	//1000 0000 0000 0000 0000 0000 0000 1011
	//-11
	printf("v = %u\n", v);
}

/*
void main()
{
	char ch = -128-1;
	printf("ch = %d\n", ch);
}


int main()
{
	//char ch = "\x25";
	char ch = '\xa7';    //ch <- string
	printf("ch = %d\n", ch);
	return 0;
}

/*
void main()
{
	char *str = "Hello";
	printf("str = %s\n", str);
}

/*
int main()
{
	//char ch = "\x25";
	char ch = "\x25";    //ch <- string
	printf("ch = %d\n", ch);
	return 0;
}
*/