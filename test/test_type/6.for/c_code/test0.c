#include <stdio.h>

float arr3[5-1+1];
float startreal,endreal;
int i,start,endint;

int main()
{
	start = 1;
	endint = 5;
	for(i = start; i <= endint; i ++)
	{
		printf("%d", i);
	}
	startreal = 1.5;
	for(arr3 = startreal; arr3 <= endint; arr3 ++)
	{
		printf("%d", i);
	}
	endreal = 5.5;
	for(i = start; i <= endreal; i ++)
	{
		printf("%d", i);
	}
	for(i = startreal; i <= endreal; i ++)
	{
		printf("%d", i);
	}
	return 0;
}