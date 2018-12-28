#define _CRT_SECURE_NO_WARNINGS 1
void Swap(int *a, int *b)
{
	int t= *a;
	*a = *b;
	*b = t;
}
void BubbleSort(int array[], int size)
{
	int isSorted;
	for (int i = 0; i < size - 1; i++){
		isSorted = 1;
		for (int j = 0; j<size - 1 - i; j++)
		if (array[j]>array[j + 1])
		{
			Swap(array + j, array + j + 1);
			isSorted = 0;
		}
	}
	if (isSorted == 1){
		break;
	}
}

int BinarySearch(int array[], int size, int value)
{
	int left = 0;
	int right = size;

	while (left < right){
		int mid = (right - left) / 2 + left;

		if (array[mid] == value)
			return mid;
		else if (array[mid]>value)
			right = mid;
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}