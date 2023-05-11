#include <stdio.h>

float a,sum;

void add(int x, int y)
{
	int result;
	result = x+y;
	printf("%d", result);
}

int main()
{
	a = 3.5;
	add(a, 4);
	return 0;
}