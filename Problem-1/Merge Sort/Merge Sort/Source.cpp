#include<stdio.h>
#include<malloc.h>
void merge(int* list, int start, int mid, int end)
{
	int i = start, j = mid + 1;
	int* temp = (int*)malloc((end - start + 1)*sizeof(int));
	int index = 0;
	while (i <= mid && j <= end)
	{
		if (list[i] > list[j])
		{
			temp[index++] = list[j];
			j++;
		}
		else
		{
			temp[index++] = list[i];
			i++;
		}
	}
	while (i <= mid)
	{
		temp[index++] = list[i];
		i++;
	}
	while (j <= end)
	{
		temp[index++] = list[j];
		j++;
	}
	index = 0;
	for (i = start; i <= end; i++)
	{
		list[i] = temp[index++];
	}
	free(temp);
}
void mergeSort(int list[], int start, int end)
{
	if (start <0 || end < 0)
		return;
	if (start == end)
		return;
	else
	{
		int mid = (start + end) / 2;
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, mid, end);
	}
}
int main()
{
	int size;
	int i;
	int list[] = { 1 };
	size = 1;
	mergeSort(list, 0, size - 1);
	printf("Sorted List:\n\n");
	for (i = 0; i < size; i++)
		printf("%d\t", *(list + i));
	printf("\n");
	return 0;
}