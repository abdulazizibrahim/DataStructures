#include<iostream>
using namespace std;
int main()
{
	int arr[9];
	for (int i = 1; i < 9; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <9 ; i++)
	{
		cout << arr[i] << " ";
	}
	int temp;

	for (int j = 0; j<9; j++)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (arr[2 * i]>arr[i])
			{
				temp = arr[2 * i];
				arr[2 * i] = arr[i];
				arr[i] = temp;
			}
			if (arr[(2 * i) + 1] > arr[i])
			{
				temp = arr[(2 * i) + 1];
				arr[(2 * i) + 1] = arr[i];
				arr[i] = temp;
			}

		}
	}
	cout << endl;

	for (int i = 1; i <9; i++)
	{
		cout << arr[i] << " ";
	}
	
}