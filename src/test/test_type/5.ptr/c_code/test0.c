#include <stdio.h>

int x,y;

void swap(int* a, float* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	scanf("%d%d", &x, &y);
	swap(&x, &y);
	printf("%d%d", x, y);
	return 0;
}