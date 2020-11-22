#include<stdio.h>
#include<assert.h>
#include<errno.h>
#include<stdbool.h>

//基本数据类型有一个对齐值
//自定义类型有一个对齐值
//程序指定对齐值
//程序有效对齐值

typedef struct Test
{
	short a;
	struct
	{
		int b;
		double c;
		long d;
	};
	int e;
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
}

/*
#pragma pack(8)
typedef struct Test
{
	char a;    //1 + 3
	int c;     //4
	double b;  //8
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 100;
}

/*
typedef struct Test
{
	char a;    //1 + 7
	double b;  //8
	int c;     //4 + 4
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 100;
}

/*
struct
{
	int a;
	double b;
	struct Test *t;
};

void main()
{
}

/*
struct
{
	int a;
	char b;
	float c;
}x;

struct
{
	int a;
	char b;
	float c;
}*p;

void main()
{
	p = &x;
}


/*
typedef struct Test
{
	char a;
	double b;
	int c;
}Test;

void main()
{
	Test t;
}

/*
int main()
{
	int n = 9;
	float *pFloat = (float *)&n;
	printf("n的值为：%d\n", n);   //9

	//0 000 0000 0 000 0000 0000 0000 0000 1001
	//s    e       m
	//0    -126    0.000 0000 0000 0000 0000 1001
	printf("*pFloat的值为：%f\n", *pFloat);

	*pFloat = 9.0;  //1001.0 => (-1)^0 * 1.001 * 2^3

	//0     100 0001 0      001 0000 0000 0000 0000 0000
	//0100 0001 0001 0000 0000 0000 0000 0000
	//  4   1     1   0    0    0     0    0
	printf("num的值为：%d\n", n); //
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}

/*
void main()
{
	float f = 10.125;  //1010.001  (-1)^s * m *2^e
	                   //1.010001  (-1)^s * 

	float f1 = 12.5;
}

/*
int main()
{
	int n = 9;
	float *pFloat = (float *)&n;
	printf("n的值为：%d\n", n);   //9
	printf("*pFloat的值为：%f\n", *pFloat);

	*pFloat = 9.0;
	printf("num的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}

/*
unsigned char i = 0; //0 ~ 255

int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}

/*
int main()
{
	char a[1000];

	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i; //-1 -2 ..........-128 127 126 .......1 0
	}

	printf("%d", strlen(a));
	return 0;
}

/*
void main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i); //9 8 7 6 5 4 3 2 1 0
	}
}

/*
void main()
{
	int i = -20;
	//1111 1111 1111 1111 1111 1111 1110 1100
	unsigned int j = 10;
	//0000 0000 0000 0000 0000 0000 0000 1010

	//1111 1111 1111 1111 1111 1111 1111 0110
	//1111 1111 1111 1111 1111 1111 1111 0101
	//1000 0000 0000 0000 0000 0000 0000 1010
	printf("%u\n", i + j); //-10
}

/*
int main()
{
	char a = 128;  //-128
	printf("%u\n", a);
	return 0;
}

/*
int main()
{
	char a = -128; // 1000 0000
	               // 1000 0000 0000 0000 0000 0000 1000 0000
	               // 1111 1111 1111 1111 1111 1111 0111 1111
	               // 1111 1111 1111 1111 1111 1111 1000 0000
	printf("%d\n", a); //128
	return 0;
}

/*
int main()
{
	char a = -1;
	signed char b = -1;

	unsigned char c = -1;   //1000 0001  
	                        //1111 1110
	                        //1111 1111 FF

	printf("a=%d,b=%d,c=%d\n", a, b, c);
	return 0;
}

/*
void main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;

	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;

	printf("%x\n", a.k); //

}

/*
bool check_mode()
{
	union
	{
		int i;
		char ch;
	}un;

	un.i = 1; //00 00 00 01

	return un.ch == 1;
}

void main()
{
	bool flag = check_mode();
	if(flag)
		printf("This is little.\n");
	else
		printf("This is big.\n");
}

/*
void main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;

	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;

	printf("%x\n", a.k);
}


/*
bool check_mode()
{
	int a = 1;
	return (*(char*)&a) == 1;
}

void main()
{
	bool flag = check_mode();
	if(flag)
		printf("This is little.\n");
	else
		printf("This is big.\n");
}

/*
//人看
void main()
{
	int a = -10;
	//1000 0000 0000 0000 0000 0000 0000 1010 原
	//1111 1111 1111 1111 1111 1111 1111 0101 反
	//1111 1111 1111 1111 1111 1111 1111 0110 补
	// F    F    F    F    F     F   F    6
	printf("%d\n", a); //
}

/*
void main()
{
	//char ch = 4791491;
	char ch = 195;
	printf("%d\n", ch);  //-128 ~ 127
}

/*
void main()
{
	long long a = 100;
	printf("size = %d\n", sizeof(long long));
	long long b = 200;
}

/*
//  0  1 2
// dir a b

//xx.exe op1 op2
//Linux 
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("argument error.\n");
		return;
	}
	int result = atoi(argv[1]) + atoi(argv[2]);
	printf("%d + %d = %d\n", atoi(argv[1]), atoi(argv[2]), result);

	return 0;
}

/*
void main(int argc, char *argv[])
{
	//int result = atoi(argv[1]) + atoi(argv[2]);
	char *str = "123";
	int x = atoi(str);
	printf("x = %d\n", x);
	
}

/*
//命令行参数
//argc argument count
//argv argument value
void main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	for(int i=0; i<argc; ++i)
		printf("%s\n", argv[i]);

}

/*
void* my_memset( void *dest, int c, size_t count )
{
	assert(dest != NULL);
	char *pdest = (char *)dest;

	while(count-- > 0)
	{
		*pdest++ = c;
	}
	return dest;
}

void* my_memcpy( void *dest, const void *src, size_t count )
{
	assert(dest!=NULL && src!=NULL);
	char *pdest = (char *)dest;
	const char *psrc = (const char *)src;

	if(psrc>=pdest || pdest>=psrc+count)
	{
		while (count-- > 0)
		{
			*pdest++ = *psrc++;
		}
	}
	else
	{
		//存在内存重叠
		psrc = psrc + count - 1;
		pdest = pdest + count - 1;
		while(count-- > 0)
		{
			*pdest-- = *psrc--;
		}
	}
	
	return dest;
}

int my_memcmp( const void *buf1, const void *buf2, size_t count )
{
	assert(buf1!=NULL && buf2!=NULL);
	const char *pbuf1 = (const char *)buf1;
	const char *pbuf2 = (const char *)buf2;

	while(count-- > 0)
	{
		if(*pbuf1 - * pbuf2 != 0)
			break;
		pbuf1++;
		pbuf2++;
	}
	return (*pbuf1 - *pbuf2);
}


void main()
{
	char str[20] = "abcdefghijk";
	
	printf("str = %s\n", str);
	//my_memcpy(str, str+3, 4);
	//my_memcpy(str+4, str, 2);
	memmove(str+2, str, 4);

	printf("str = %s\n", str);
}

/*
void main()
{
	char str[20];
	char *str1 = "abcxyz";
	my_memset(str, 1, sizeof(str));
	my_memcpy(str, str1, strlen(str1)+1); //sizeof(str1)
	int flag = my_memcmp(str, str1, strlen(str1));
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int br[10] = {1,2,3,4,5,60,70,80,90,100};

	//memset(br, 0, sizeof(int)*10);
	//memcpy(br, ar, sizeof(int)*10);
	//int flag = memcmp(ar, br, sizeof(int)*6);
	//memmove(br, ar, sizeof(int)*10);
}


/*
void my_to_upper(char *str)
{
	assert(str != NULL);
	while(*str != '\0')
	{
		if(islower(*str))
		//if(*str>='a' && *str<='z')
			*str -= 32;
		str++;
	}
}

void main()
{
	char str[] = "abCXyz";
	printf("str = %s\n", str);
	my_to_upper(str);
	printf("str = %s\n", str);
}


/*
void main()
{
	FILE *fp = fopen("Test.txt", "r");
	if(fp == NULL)
	{
		//printf("Open File Error.\n");
		printf("errno = %d\n", errno);
		char *err_msg = strerror(errno);
		printf("err_msg = %s\n", err_msg);
		return;
	}
}

/*
void main()
{
	char *str1 = "adebcdefghijdefklmn";
	char *str2 = "";

	char *ret = strstr(str1, str2);
	if(ret != NULL)
		printf("ret = %s\n", ret);
	else
		printf("str2 不存在.\n");
}

/*
char *my_strncat( char *strDest, const char *strSrc, size_t count)
{
	//参数检查和保护
	assert(strDest!=NULL && strSrc!=NULL);
	char *pDest = strDest;
	const char *pSrc = strSrc;

	//先查找Dest字符串的末尾
	while(*pDest != '\0')
		pDest++;

	//实行连接拷贝
	while(count-- > 0)
	{
		*pDest++ = *pSrc++;
	}

	//增加结束标记
	*pDest = '\0';

	return strDest;
}

void main()
{
	char str1[20] = "Hello";

	char *str2 = "Bit.";
	printf("str1 = %s\n", str1);
	             //strcpy();
	char *pret = strncpy(str1, str2, 5);
	//char *pret = my_strncat(str1, str2, 1);     //vos_strncat();
	printf("str1 = %s\n", str1);
	printf("str1 = %s\n", pret);

}

/*
int my_strncmp( const char *string1, const char *string2, size_t count )
{
	assert(string1!=NULL && string2!=NULL);
	const char *ps1 = string1;
	const char *ps2 = string2;

	int ret = 0;

	while(--count > 0)
	{
		if(*ps1 - *ps2 != 0)
			break;
		ps1++;
		ps2++;
	}

	ret = *ps1 - *ps2;
	return ret;
}

void main()
{
	char *str1 = "Hello";
	char *str2 = "HexloAAA";

	int ret = my_strncmp(str1, str2, 2); //<0 ==0 >0

	if(ret == 0)
		printf("str1 == str2");
	else if(ret < 0)
		printf("str1 < str2");
	else
		printf("str1 > str2");
}

/*
size_t my_strlen( const char *string )
{
	if(*string == '\0')
		return 0;
	else 
		return my_strlen(string+1) + 1;
}

char* my_strcpy( char *strDest, const char *strSrc )
{
	assert(strDest!=NULL && strSrc!=NULL); //1检查参数
	char *pDest = strDest;
	char *pSrc = strSrc; //2 保护参数

	while(*pSrc != '\0')
	{
		*pDest++ = *pSrc++;
	}
	*pDest = '\0'; //
	return strDest;
}

char *my_strcat( char *strDest, const char *strSrc )
{
	//参数检查和保护
	assert(strDest!=NULL && strSrc!=NULL);
	char *pDest = strDest;
	const char *pSrc = strSrc;

	//先查找Dest字符串的末尾
	while(*pDest != '\0')
		pDest++;

	//实行连接拷贝
	while(*pSrc != '\0')
	{
		*pDest++ = *pSrc++;
	}

	//增加结束标记
	*pDest = '\0';

	return strDest;
}

int my_strcmp( const char *string1, const char *string2 )
{
	assert(string1!=NULL && string2!=NULL);
	const char *ps1 = string1;
	const char *ps2 = string2;

	int ret = 0;

	while(*ps1!='\0' || *ps2!='\0')
	{
		if(*ps1 - *ps2 != 0)
			break;
		ps1++;
		ps2++;
	}

	ret = *ps1 - *ps2;
	return ret;
}

void main()
{
	char *str1 = "Hello";
	char *str2 = "HelloAAA";

	int ret = my_strcmp(str1, str2); //<0 ==0 >0

	if(ret == 0)
		printf("str1 == str2");
	else if(ret < 0)
		printf("str1 < str2");
	else
		printf("str1 > str2");
}

/*
int my_strcmp( const char *string1, const char *string2 )
{
	assert(string1!=NULL && string2!=NULL);
	const char *ps1 = string1;
	const char *ps2 = string2;

	while(*ps1!='\0' && *ps2!='\0')
	{
		if(*ps1 > *ps2)
			return 1;
		else if(*ps1 < *ps2)
			return -1;
		ps1++;
		ps2++;
	}

	if(*ps1 != '\0')
		return 1;
	if(*ps2 != '\0')
		return -1;
	return 0;
}

void main()
{
	char *str1 = "Hello";
	char *str2 = "HelloAAA";

	int ret = my_strcmp(str1, str2); //<0 ==0 >0

	if(ret == 0)
		printf("str1 == str2");
	else if(ret < 0)
		printf("str1 < str2");
	else
		printf("str1 > str2");
}


/*
//入参  出参
void main()
{
	char str1[20] = "Hello";
	char *str2 = "Bit.";
	printf("str1 = %s\n", str1);
	//char *pret = my_strcpy(str1, str2);
	char *pret = my_strcat(str1, str2);
	printf("str1 = %s\n", str1);
	printf("str1 = %s\n", pret);

}

/*
size_t my_strlen( const char *string )
{
	assert(string != NULL);  //1 检查合法性
	size_t len = 0;
	const char *p_str = string; //2 对指针进行参数保护

	while(*p_str++ != '\0')
	{
		len++;
		//p_str++;
	}
	return len;
}

void main()
{
	char *str = "abcxyz";
	//char *str = NULL;
	printf("len = %d\n", my_strlen(str));
}


/*
void main()
{
	char ch = '\5';  //转义成数字
	char ch1 = 5;

}

/*
void main()
{
	char ar[10];
	int i;
	for(i=0; i<5; ++i)
	{
		ar[i] = 'a' + i; // a b c d e
	}
	ar[i] = 0;   //'0' != '\0'   '\0' == 0
	printf("len = %d\n", strlen(ar));
}

/*
void main()
{
	char *str = "a\0bcxyzfnlafkaskfjlakfjklasfjlk";
	//char *str = "";
	printf("len = %d\n", strlen(str));
}

/*
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };

	char**cp[] = { c + 3, c + 2, c + 1, c };

	char***cpp = cp;
	printf("%s\n", **++cpp);

	printf("%s\n", *--*++cpp + 3);

	printf("%s\n", *cpp[-2] + 3);

	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}

/*
void main()
{
	char *str = "abcxyz";
	printf("str = %s\n", str);
	printf("str = %s\n", str+3);
	printf("str = %s\n", &str[3]);
	printf("str = %s\n", &("abcxyz"[3]));
	printf("str = %s\n", "abcxyz"+3);
}

/*
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };

	char**cp[] = { c + 3, c + 2, c + 1, c };

	char***cpp = cp;
	printf("%s\n", **++cpp);

	printf("%s\n", *--*++cpp + 3);

	printf("%s\n", *cpp[-2] + 3);

	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}

/*
int main()
{
	char *a[] = { "work", "at", "alibaba" };
	char**pa = a;
	pa++;
	printf("%s\n", *pa);
	return 0;
}

/*
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int *ptr1 = (int *)(&aa + 1);
	int *ptr2 = (int *)((aa + 1));

	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}

/*
void main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
}
*/