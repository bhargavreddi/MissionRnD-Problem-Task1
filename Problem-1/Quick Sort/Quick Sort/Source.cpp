#include<stdio.h>
#include<stdlib.h>
int generateRandom(int n)
{
	return rand() % n;
}
void swap(int* list, int i, int j)
{
	if (i != j)
	{
		int c = list[i];
		list[i] = list[j];
		list[j] = c;
	}
}
int partition(int* list, int start, int end)
{
	int pivot = generateRandom(end + 1);
	int i = start, j = end;
	while (i < j)
	{
		while (list[i] < list[pivot] && i < pivot)
			i++;
		if (i == pivot)
		{
			if (list[j] < list[pivot])
				swap(list, j, pivot);
			return j;
		}
		while (list[j] > list[pivot] && j > pivot)
			j--;
		if (j == pivot)
		{
			if (list[i] > list[pivot])
				swap(list, i, pivot);
			return i;
		}
		swap(list, i, j);
		i++;
		j--;
	}
	return pivot;
}
void quickSort(int* list, int start, int end)
{
	if (end < 0)
		return;
	if (start < end)
	{
		int pivot = partition(list, start, end);
		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}
int main()
{
	int i;
	int list[] = { 5,4,3,2,1 };
	//int list[] = { 1,2,3,4,5 };
	//int list[] = { 5,1,6,2,4 };
	quickSort(list, 0, 4);
	for (i = 0; i < 5; i++)
		printf("%d\n", list[i]);
	return 0;
}