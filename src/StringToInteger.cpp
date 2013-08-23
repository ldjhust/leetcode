/*************************************************************************
    > File Name: StringToInteger.cpp
    > Author: Ldj
    > Mail: lidongjie2008@gmail.com 
    > Created Time: 2013年06月21日 星期五 09时25分16秒
 ************************************************************************/

#include <iostream>

using namespace std;

int atoi(const char *str) 
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if ((NULL == str) || ('\0' == *str))
    {
	  	return 0;
    }

    const char *p = str;
    bool sign = true;
       
    while (' ' == *p)
    {
        ++p;
    }

    if ('-' == *p)
    {
	   	sign = false;
        ++p;
    }
    
    if ('+' == *p)
    {
	   	sign = true;
	   	++p;
	}

    	
    int res = 0;
    size_t Count = 0;

   	while (*p != '\0')
   	{
    	if ((*p < '0') || (*p > '9'))
    	{
    		break;
    	}

        ++Count;
    	res *= 10;
    	res += *p++ - '0' + 0;
   	}

   	if (sign)
   	{
        // if bigger than biggest positive number, return biggest positive number
        if ((res < 0) || (Count > 10))
        {
            return 2147483647;
        }
        else
        {
   		    return res;
        }
   	}
  	else
  	{
        // if smaller than most small negetive number, return most small negetive number
        if ((res < 0) || (Count > 10))
        {
            return -2147483648;
        }
        else
        {
            return res * -1;   
        }
   	}
}
