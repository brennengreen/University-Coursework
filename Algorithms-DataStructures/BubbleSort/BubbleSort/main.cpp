
#include <iostream>

using namespace std;

void sort(int arr[], int numElements);


int main()
{
	int arr[10] = { 0, 4, 5, 6, 2, 1, 7, 9, 8, 3 };
	cout << "Unsorted: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	sort(arr, 10);
	cout << "Sorted: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

void sort(int arr[], int numElements)
{
	for (int i = 0; i < numElements - 1; i++)
	{
		for (int j = i; j < numElements; j++)
		{
			if (arr[i] > arr[j])
			{
				int buf = arr[j];
				arr[j] = arr[i];
				arr[i] = buf;
			}
		}
	}
}