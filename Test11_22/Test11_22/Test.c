#include<stdio.h>
#include<assert.h>
#include<errno.h>

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

	while(count-- > 0)
	{
		*pdest++ = *psrc++;
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
	my_memcpy(str+2, str, 4);

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
		printf("str2 ������.\n");
}

/*
char *my_strncat( char *strDest, const char *strSrc, size_t count)
{
	//�������ͱ���
	assert(strDest!=NULL && strSrc!=NULL);
	char *pDest = strDest;
	const char *pSrc = strSrc;

	//�Ȳ���Dest�ַ�����ĩβ
	while(*pDest != '\0')
		pDest++;

	//ʵ�����ӿ���
	while(count-- > 0)
	{
		*pDest++ = *pSrc++;
	}

	//���ӽ������
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
	assert(strDest!=NULL && strSrc!=NULL); //1������
	char *pDest = strDest;
	char *pSrc = strSrc; //2 ��������

	while(*pSrc != '\0')
	{
		*pDest++ = *pSrc++;
	}
	*pDest = '\0'; //
	return strDest;
}

char *my_strcat( char *strDest, const char *strSrc )
{
	//�������ͱ���
	assert(strDest!=NULL && strSrc!=NULL);
	char *pDest = strDest;
	const char *pSrc = strSrc;

	//�Ȳ���Dest�ַ�����ĩβ
	while(*pDest != '\0')
		pDest++;

	//ʵ�����ӿ���
	while(*pSrc != '\0')
	{
		*pDest++ = *pSrc++;
	}

	//���ӽ������
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
//���  ����
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
	assert(string != NULL);  //1 ���Ϸ���
	size_t len = 0;
	const char *p_str = string; //2 ��ָ����в�������

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
	char ch = '\5';  //ת�������
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