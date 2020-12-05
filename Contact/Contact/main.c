#include"contact.h"

int main(int argc, char *argv[])
{
	Contact_t cont;
	ContactInit(&cont);

	int select = 1;
	while(select)
	{
		printf("****************************************\n");
		printf("* [1] AddContact   [2] DelContact      *\n");
		printf("* [3] FindContact  [4] ShowContact     *\n");
		printf("* [5] ModContact   [6] SortContact     *\n");
		printf("* [7] ClearContact [8] DestroyContact  *\n");
		printf("* [0] Exit System                      *\n");
		printf("****************************************\n");
		printf("ÇëÑ¡Ôñ:>");
		scanf("%d", &select);

		if(select == QUIT)
			break;

		switch(select)
		{
		case ADD:
			ContactAdd(&cont);
			break;
		case DEL:
			break;
		case FIND:
			ContactFind(&cont);
			break;
		case SHOW:
			ContactShow(&cont);
			break;
		case MOD:
			break;
		case SORT:
			break;
		case CLEAR:
			break;
		case DESTROY:
			break;
		default:
			break;

		}
	}

	ContactSave(&cont);

	return 0;
}