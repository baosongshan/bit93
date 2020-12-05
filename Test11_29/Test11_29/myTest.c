#include<stdio.h>
#include<vld.h>
#include<limits.h>
#include<errno.h>

void main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if(NULL == fpIn)
	{
		printf("Open Input File Error.\n");
		return;
	}
	FILE *fpOut = fopen("myTest.c", "w");
	if(NULL == fpOut)
	{
		printf("Open Output File Error.\n");
		return;
	}

	//¿½±´¹ý³Ì
	char ch = fgetc(fpIn);
	while(ch != EOF)
	{
		fputc(ch, fpOut);
		ch = fgetc(fpIn);
	}
	fputc(ch, fpOut);

	fclose(fpIn);
	fclose(fpOut);
}

/*
void main()
{
	int ar[10];

	FILE *fp = fopen("Test2.txt", "rb");
	if(NULL == fp)
	{
		printf("Open File Error.\n");
		return;
	}

	fread(ar, sizeof(int), 10, fp);

	fclose(fp);
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89, 90, 100};
	//int ar[] = {1000, 2000, 3000};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = fopen("Test2.txt", "wb");
	if(NULL == fp)
	{
		printf("Open File Error.\n");
		return;
	}

	fwrite(ar, sizeof(int), n, fp);

	fclose(fp);
}

/*
void main()
{
	//int ar[] = {12,23,34,45,56,67,78,89, 90, 100};
	int ar[] = {1000, 2000, 3000};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = fopen("Test1.txt", "a");
	if(NULL == fp)
	{
		printf("Open File Error.\n");
		return;
	}

	for(int i=0; i<n; ++i)
	{
		fprintf(fp, "%d ", ar[i]);
	}

	fclose(fp);
}

/*
void main()
{
	int ar[10];
	FILE *fp = fopen("Test1.txt", "r");
	if(NULL == fp)
	{
		printf("Open File Error.\n");
		return;
	}

	for(int i=0; i<10; ++i)
	{
		//scanf("%d", &ar[i]);
		fscanf(fp, "%d", &ar[i]);
	}

	fclose(fp);
}

/*
void main()
{
	int ar[] = {12,23,34,45,56,67,78,89, 90, 100};
	int n = sizeof(ar) / sizeof(ar[0]);

	FILE *fp = fopen("Test1.txt", "w");
	if(NULL == fp)
	{
		printf("Open File Error.\n");
		return;
	}

	for(int i=0; i<n; ++i)
	{
		fprintf(fp, "%d ", ar[i]);
	}

	fclose(fp);
}

/*
void main()
{
	FILE *fp = NULL; //1
	fp = fopen("Test1.txt", "w");  //2
	//fp = fopen("C:\\Bit\\xa.txt", "w");  //2
	//fp = fopen("..\\xa.txt", "w");  //2
	if(NULL == fp)
	{
		printf("Open File Error.\n");
		printf("%s\n", strerror(errno));
		return;
	}

	fclose(fp);   //3
}

/*
//void *_alloca( size_t size );

void main()
{
	int *ptr = _alloca(sizeof(int) * 10);  //²»ÄÜÊÍ·ÅµÄ

	//free(ptr);
}

/*
#define ROW 5
#define COL 5

void main()
{
	//int ar[ROW][COL] = {0};  ar[i][j]
	int **ar = (int **)malloc(sizeof(int*) * ROW);
	if(NULL == ar)
		return;

	for(int i=0; i<ROW; ++i)
	{
		ar[i] = (int*)malloc(sizeof(int) * COL);
	}

	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			ar[i][j] = i+j;
		}
	}

	for(int i=0; i<ROW; ++i)
	{
		for(int j=0; j<COL; ++j)
		{
			printf("%d ", ar[i][j]);
		}
		printf("\n");
	}

	for(int i=0; i<ROW; ++i)
		free(ar[i]);
	free(ar);
}

/*
typedef struct Test
{
	char a;
	double b;
	int c;
	char ptr[0]; //ÈáÐÔÊý×é³ÉÔ±   ²»Õ¼¿Õ¼ä
}Test;

void main()
{
	char str[] = "hello Bit";
	Test *pt = (Test*)malloc(sizeof(Test) + strlen(str) + 1);
	if(NULL == pt)
	{
		printf("Out Of Memory.\n");
		return;
	}

	strcpy(pt->ptr,str);

	printf("str = %s\n", pt->ptr);

	free(pt);
}

/*
typedef struct Test
{
	char a;
	double b;
	int c;
	char *ptr; //ÈáÐÔÊý×é³ÉÔ±   ²»Õ¼¿Õ¼ä
}Test;

void main()
{
	char str[] = "hello Bit";
	Test *pt = (Test*)malloc(sizeof(Test));
	if(NULL == pt)
	{
		printf("Out Of Memory.\n");
		return;
	}

	pt->ptr = (char *)malloc(strlen(str) + 1);
	strcpy(pt->ptr,str);

	printf("str = %s\n", pt->ptr);

	free(pt->ptr);
	free(pt);
}

/*
typedef struct Test
{
	char a;
	double b;
	int c;
	char ptr[0]; //ÈáÐÔÊý×é³ÉÔ±   ²»Õ¼¿Õ¼ä
}Test;

void main()
{
	char str[] = "hello Bit";
	Test *pt = (Test*)malloc(sizeof(Test) + strlen(str) + 1);
	if(NULL == pt)
	{
		printf("Out Of Memory.\n");
		return;
	}

	strcpy(pt->ptr,str);

	printf("str = %s\n", pt->ptr);

	free(pt);
}

/*
typedef struct Test
{
	int ar[0];
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
	Test t;
}

/*
typedef struct Test
{
	char a;
	double b;
	int c;
	int d;
	char ptr[0]; //ÈáÐÔÊý×é³ÉÔ±   ²»Õ¼¿Õ¼ä
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
	free(p);//p²»ÔÙÖ¸Ïò¶¯Ì¬ÄÚ´æµÄÆðÊ¼Î»ÖÃ
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
		*(p + i) = i;//µ±iÊÇ10µÄÊ±ºòÔ½½ç·ÃÎÊ
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


	*p = 20;//Èç¹ûpµÄÖµÊÇNULL£¬¾Í»áÓÐÎÊÌâ
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
	

	free(p);  //ÄÚ´æÐ¹Â©
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
	int*p = (int*)realloc(p, sizeof(int) * n); //Ä£ÄâÊµÏÖ
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

	int *p1 = (int *)calloc(10, sizeof(int)); //ÓÃ0³õÊ¼»¯
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
	p = (int *)realloc(p, sizeof(int) * n); //Ä£ÄâÊµÏÖ
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
	free(p);  //ÊÍ·Å¿Õ¼ä

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
	free(p);  //ÊÍ·Å¿Õ¼ä
	p = NULL; //ÊÍ·ÅÖ¸Õë

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

	//¶¯Ì¬ÄÚ´æ¿ª±Ù
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
	int m;  //¾Ö²¿±äÁ¿
	int n;
}

void main()
{
	//¾²Ì¬¿ª±Ù  Õ»Çø
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
	
	strcpy(arr, p);//½«Êý¾Ý¿½±´Ò»·Ý£¬´¦ÀíarrÊý×éµÄÄÚÈÝ
	
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
*/ÿ