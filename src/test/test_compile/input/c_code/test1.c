#include <stdio.h>

int k,m,tempout;
int a[101-1+1];

int partition(int low, int high)
{
	int _partition;
	int i,j,temp;
	i = low-1;
	for(j = low; j <= (high-1); j ++)
	{
		if (a[j-1]<=a[high-1])
		{
			i = i+1;
			temp = a[i-1];
			a[i-1] = a[j-1];
			a[j-1] = temp;
		}
	}
	i = i+1;
	temp = a[i-1];
	a[i-1] = a[high-1];
	a[high-1] = temp;
	_partition = i;
	return _partition;
}

void qs(int low, int high)
{
	int pivot;
	pivot = 0;
	if (low<=high)
	{
		pivot = partition(low, high);
		qs(low, pivot-1);
		qs(pivot+1, high);
	}
}

int main()
{
	scanf("%d", &m);
	for(k = 1; k <= m; k ++)
	{
		scanf("%d", &tempout);
		a[k-1] = tempout;
	}
	qs(1, m);
	for(k = 1; k <= m; k ++)
	{
		printf("%d%c", a[k-1], ' ');
	}
	return 0;
}