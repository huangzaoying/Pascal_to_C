#include <stdio.h>

float diff;
float a;
int sum;

float add(int x, int y)
{
	float _add;
	float result;
	result = x+y;
	return _add;
}

int minus(float x, float y)
{
	int _minus;
	int result;
	result = x-y;
	return _minus;
}

int main()
{
	a = 3.5;
	sum = add(a, 4);
	diff = minus(a, 4.5);
	return 0;
}