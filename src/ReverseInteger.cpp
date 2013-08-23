/*************************************************************************
    > File Name: ReverseInteger.cpp
    > Author: Ldj
    > Mail: lidongjie2008@gmail.com 
    > Created Time: 2013年06月21日 星期五 09时10分35秒
 ************************************************************************/

#include <iostream>

using namespace std;

int Reverse(int x)
{
	bool sign = true;

	if (x < 0)
	{
		sign = false;
		x *= -1;
	}

	int res = 0;

	while (x != 0)
	{
		res *= 10;
		res += x % 10;
		x /= 10;
	}

	if (sign)
	{
		return res;
	}
	else
	{
		return res * -1;
	}
}
