for (int j = 0; j < 5; j++)
	{
		for (int i=0 ; i < 4; i++)
		{
			if (arr[i]>arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}	

	}