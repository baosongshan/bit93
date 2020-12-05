#ifndef _CONTACT_H_
#define _CONTACT_H_

#include"sysutil.h"

#define MAX_NAME_SIZE 10
#define MAX_SEX_SIZE 3
#define MAX_TEL_SIZE 12
#define MAX_ADDR_SIZE 256
#define MAX_CONTACT_SIZE 20000
#define DEFAULT_CONTACT_SIZE 2
#define MAX_INC_SIZE  5

typedef enum ENUM_TYPE
{
	QUIT = 0,
	ADD,
	DEL,
	FIND,
	SHOW,
	MOD,
	SORT,
	CLEAR,
	DESTROY
}ENUM_TYPE;

//定义个人信息
typedef struct PersonInfo_t
{
	char name[MAX_NAME_SIZE];
	char sex[MAX_SEX_SIZE];
	char tel[MAX_TEL_SIZE];
	char addr[MAX_ADDR_SIZE];
	int age;
}PersonInfo_t;

//定义通讯录结构
typedef struct Contact_t
{
	//PersonInfo_t base[MAX_CONTACT_SIZE]; //通讯录的存储空间
	PersonInfo_t *base;  //动态大小
	size_t size; //表示通讯录中的信息条数
	size_t capacity;//容量
}Contact_t;
//////////////////////////////////////////////////////////////
//日志
void Log(char *file, int line, char *msg);
#define LOG(msg) Log(__FILE__, __LINE__, msg);

void CheckCapacity(Contact_t *pct);

///////////////////////////////////////////////////////////////
//函数的申明
void ContactInit(Contact_t *pct);
void ContactAdd(Contact_t *pct);
void ContactDel(Contact_t *pct);
void ContactMod(Contact_t *pct);
void ContactSort(Contact_t *pct);
void ContactClear(Contact_t *pct);
void ContactDestroy(Contact_t *pct);
void ContactShow(Contact_t *pct);

void ContactFind(Contact_t *pct);

void ContactLoad(Contact_t *pct);
void ContactSave(Contact_t *pct);

#endif /* _CONTACT_H_ */