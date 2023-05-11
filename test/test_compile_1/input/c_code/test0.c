#include <stdio.h>

int a,i;

int fib(int y)
{
	int _fib;
	if (y==0)
		_fib = 0;
	else
	{
		if (y==1)
			_fib = 1;
		else
			_fib = fib(y-1)+fib(y-2);
	}
	return _fib;
}

int main()
{
	for(i = 1; i <= 10; i ++)
		printf("%d%c", fib(i), ' ');
	return 0;
}