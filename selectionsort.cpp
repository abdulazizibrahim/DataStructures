#include<iostream>
using namespace std;
int print(int *ptr, int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<*(ptr + i)<<" ";
	}
	cout<<endl;
	return 0;
}
int sort(int *ptr, int size, int t)
{
	int temp =*(ptr + t);
	int x = t;
	for(int i = t+1; i<size; i++)
	{
			if(*(ptr + i) <  temp)
			{
				 temp = *(ptr + i);
				x = i;	
			}
			
		
		
	}
	return x;
}
int selection(int *ptr, int size)
{
	static int i =0;
	if(i< size)
	{
		int x = sort(ptr, size, i);
		int temp = *(ptr + i);
		*(ptr + i) = *(ptr + x);
		*(ptr + x) = temp;
		print(ptr, size);
		i++;
		selection(ptr, size); 
	}
	return 0;
}
int bubble(int *ptr, int size)
{
	for(int i =0; i<size; i++)
	{
		for(int j =1 ;j<size; j++)
		{
			if(*(ptr +(j -1)) < *(ptr +j) )
			{
				int temp = *(ptr+(j - 1));
				*(ptr +(j - 1)) = *(ptr + j);
				*(ptr + j) = temp;
			}
		}
	}
	print(ptr, size);
}
int main()
{
	int *ptr = new int[7];
	cout<<"enter number"<<endl;
	for(int i =0; i< 7; i++)
	{
		cin>>*(ptr + i);
	}
	bubble(ptr, 7);
}

