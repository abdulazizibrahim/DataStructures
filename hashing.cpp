#include<iostream>
using namespace std;
class hashing
{
private:
	int length;
	int size;
	int *arr = new int[length]
public:
	hashing()
	{
		length = 10;
		size = 0;
		for (int i = 0; i < length; i++)
		{
			*(arr + i) = -1;
		}
	}
	int print()
	{
		for (int i = 0; i < length; i++)
		{
			cout << *(arr + i) << endl;
		}
	}
	int rehashing()
	{
		int *temp = new int[length * 2];
			for (int i = 0; i < length * 2; i++)
			{
				*(temp + i) = -1;
			}
		for (int i = 0; i < length; i++)
		{
			if (*(arr + i) != -1)
			{
				int ind = *(arr + i) % (length * 2);
				if (*(temp + ind) != -1)
				{
					while (*(temp + ind) != -1))
						{
							if (ind == (length * 2) - 1)
							{
								ind = 0;
							}
							ind++;
						}
				}
				*(temp + ind) = *(arr + i);

			}

		}
		length = length * 2;
		//delete[] arr;
		//arr = temp;
		//temp = NULL;
	}
	int insert()
	{
		if (size > (length / 2))
		{
			cout << "the array is more than half full " << endl;
			cout << " we will make another array with double the size" << endl;
			rehashing();

		}
		else
		{
			int x;
			int ind;
			cout << " enter number you want to insert " << endl;
			cin >> x
				ind = x % length;

			if (*(arr + ind) != 0)
			{
				while (*(arr + ind) != -1)
				{
					if (ind == length - 1)
					{
						ind = 0;
					}
					ind++;
				}

			}
			*(arr + ind) = x;
			size++;


		}
		return 0;
	}


};
int main()
{
	hashing h;
	h.insert();

}

