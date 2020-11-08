#ifndef __HEAD_H__
#define __HEAD_H__

#include"Test.h"

int fun(int a, int b, int c)
{
	int tmp = MyMax(a, b);
	return MyMax(tmp, c);
}

#endif