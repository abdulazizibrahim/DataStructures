#include<iostream>
using namespace std;
class abl
{
	private:
		int length;
		int size;
		int *current;
		int *start;
		int *array;
	public:
		abl()
		{
			length = 8;
			size =5;
			if(size >= length)
			{
				cout<<"size is beyound the length"<<endl;
			}
			int *array = new int[length];
			current = array;
			start = array;
			
		}
		~abl()
		{
			delete [] array;
			current = NULL;
			cout<<"destructor"<<endl;
		}
		void create()
		{
			int x;
			for(int i=0;i<size;i++)
			{
				cout<<"enter value"<<endl;
				cin>>array[i];
			}
		}
		int get()
		{
			cout<<*(current)<<endl;
			return *(current);
		}
		int llength()
		{
			cout<<"size = "<<size<<endl;
			return size;
		}
		int back()
		{
			if(current == start)
			{
				cout<<"you are already on the first index"<<endl;
			}
			else
			{
				current --;
			}
			cout<<"current = "<<*current<<endl;
			return *current;
		}
		void next()
		{
			if(*current != *(array + (size-1)))
			{
				current++;
			}
			else
			{
				cout<<"you are on the last index"<<endl;
			}
		}
//		void start()
//		{
//			current = start;
//		}
		void end()
		{
			current = (array + (size-1));
		}
		void add()
		{
			int x,count;
			cout<<"enter the number you want to add"<<endl;
			cin>>x;
			for(int i =0; i<size; i++)
			{
				if((array + i) != current)
				{
					count++;
				}
				else
				{
					count++;
					break;
				}
			}
			int s = size;
			while(s >= count)
			{
				*(array + (s + 1)) = *(array + s);
				s--;
			}
			*(array + count) = x;
			current++; 
			
		}
		void del()
		{
			int x,count;
			cin>>x;
			for(int i =0; i<size; i++)
			{
				if((array + i) != current)
				{
					count++;
				}
				else
				{
					count++;
					break;
				}
			}
			int s = size;
			
			while(s >=count)
			{
				*(array + (count)) = *(array + (count+1));
				count++;
			}
			*current = x;
		}
		void print()
		{
			for(int i=0;i<size;i++)
			{
				cout<<*(array + i)<<endl;
			}
		}
		
		
		
};
int main()
{
	abl a;
	a.create();
	a.get();
	a.llength();
	a.next();
	a.back();
	a.print();
}
