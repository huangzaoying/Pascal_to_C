#include <stdio.h>

int arr2[3-1+1][4-1+1],arr3[3-1+1][4-1+1];
int arr1[3-1+1];

int main()
{
	arr1[1-1] = 1;
	arr1[2-1] = 2;
	arr1[3-1] = 3;
	printf("%d\n", arr1[3-1]);
	arr2[1-1][1-1] = 1;
	arr2[1-1][2-1] = 'a';
	arr2[2-1][1-1] = 2;
	arr3[1-1][2-1] = arr2[1-1][1-1];
	printf("%d\n", arr3[1-1][1-1]);
	return 0;
}