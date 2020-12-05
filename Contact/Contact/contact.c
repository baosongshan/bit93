#include"contact.h"


void Log(char *file, int line, char *msg)
{
	printf("Log: %s : %d : %s : %s  : %s\n", file, line, __DATE__, __TIME__, msg);
}

void CheckCapacity(Contact_t *pct)
{
	if(pct->size >= pct->capacity)
	{
		//�ռ����ˣ���Ҫ����
		pct->base = (PersonInfo_t *)realloc(pct->base, sizeof(PersonInfo_t)*(pct->capacity+MAX_INC_SIZE));
		pct->capacity += MAX_INC_SIZE;
	}
}


void ContactInit(Contact_t *pct)
{
	pct->base = (PersonInfo_t *)malloc(sizeof(PersonInfo_t) * DEFAULT_CONTACT_SIZE);
	memset(pct->base, 0, sizeof(PersonInfo_t) * DEFAULT_CONTACT_SIZE);
	pct->size = 0;
	pct->capacity = DEFAULT_CONTACT_SIZE;

	ContactLoad(pct);
}

/*
typedef struct PersonInfo_t
{
	char name[MAX_NAME_SIZE];
	char sex[MAX_SEX_SIZE];
	char tel[MAX_TEL_SIZE];
	char addr[MAX_ADDR_SIZE];
	int age;
}PersonInfo_t;*/

void ContactAdd(Contact_t *pct)
{
	CheckCapacity(pct);
	printf("����:>");
	scanf("%s", pct->base[pct->size].name);
	printf("�Ա�:>");
	scanf("%s", pct->base[pct->size].sex);
	printf("����:>");
	scanf("%d", &(pct->base[pct->size].age));
	printf("�绰:>");
	scanf("%s", pct->base[pct->size].tel);
	printf("��ַ:>");
	scanf("%s", pct->base[pct->size].addr);

	pct->size++;
	printf("����ͨѶ¼��Ա�ɹ�......\n");
}

void ContactShow(Contact_t *pct)
{
	printf("%-8s %-4s %-4s %-13s %-20s\n", "����","�Ա�","����","�绰","��ַ");
	for(int i=0; i<pct->size; ++i)
	{
		printf("%-8s %-4s %-4d %-13s %-20s\n", pct->base[i].name,
								   pct->base[i].sex,
								   pct->base[i].age,
								   pct->base[i].tel,
								   pct->base[i].addr);
	}
}

void ContactFind(Contact_t *pct)
{
	printf("������Ҫ���ҵ�������:>");
	char name[MAX_NAME_SIZE] = {0};
	scanf("%s", name);

	int i;
	for(i=0; i<pct->size; ++i)
	{
		if(strcmp(name, pct->base[i].name) == 0)
			break;
	}
	if(i >= pct->size)
		printf("Ҫ���ҵ��˲�����......\n");
	else
	{
		printf("%-8s %-4s %-4s %-13s %-20s\n", "����","�Ա�","����","�绰","��ַ");
		printf("%-8s %-4s %-4d %-13s %-20s\n", pct->base[i].name,
								   pct->base[i].sex,
								   pct->base[i].age,
								   pct->base[i].tel,
								   pct->base[i].addr);
	}
}


void ContactLoad(Contact_t *pct)
{
	FILE *fp = fopen("cont.data", "r");
	if(fp == NULL)
	{
		LOG("Open cont.data Failed.");
		return;
	}

	
	char ch;
	//while((ch = fgetc(fp)) != EOF)
	while(!feof(fp))
	{
		CheckCapacity(pct);
		fscanf(fp, "%s %s %d %s %s", pct->base[pct->size].name,
								   pct->base[pct->size].sex,
								   &(pct->base[pct->size].age),
								   pct->base[pct->size].tel,
								   pct->base[pct->size].addr);
								   
		pct->size++;
		if(feof(fp))
			break;
	}

	fclose(fp);
}

void ContactSave(Contact_t *pct)
{
	FILE *fp = fopen("cont.data", "w");
	if(fp == NULL)
	{
		LOG("Open cont.data Failed.");
		return;
	}

	for(int i=0; i<pct->size; ++i)
	{
		fprintf(fp, "%-8s %-4s %-4d %-13s %-20s\n", pct->base[i].name,
								   pct->base[i].sex,
								   pct->base[i].age,
								   pct->base[i].tel,
								   pct->base[i].addr);
	}

	fclose(fp);
}