#include"contact.h"

void ContactInit(Contact_t *pct)
{
	memset(pct->base, 0, sizeof(PersonInfo_t) * MAX_CONTACT_SIZE);
	pct->size = 0;
	pct->capacity = MAX_CONTACT_SIZE;
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