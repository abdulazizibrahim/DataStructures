int k = 0;
int temp = 0;
int i = 0;

	for (int j = 0; j < 5; j++)
	{
		for (i ; i < 5; i++)
		{
			if (arr[k]>arr[i])
			{
				temp = arr[k];
				arr[k] = arr[i];
				arr[i] = temp;
			}
		}

		k++;
		i = k;
		

	}