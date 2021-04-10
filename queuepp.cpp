#include<iostream>
using namespace std;
class queue
{
	private:
		int size;
		int length;
		int tlength;
		int *ptr = new int [size];
		int *head;
		int *tail;
		int hindex;
		int tindex;
	public:
		queue()
		{
			size = 10;
			length = 0;
			tlength = 0;
			head = NULL;
			tail = NULL;
			
		}
		~queue()
		{
			delete [] ptr;
		}
		int enque()
		{
			if(head == NULL)
			{
				cout<<"queue is empty"<<endl;
				cout<<"enter value"<<endl;
				cin>>*(ptr + length);
				head = (ptr + length);
				tail = head;
				hindex = length;
				tindex = length;
				length ++;
				return 0;
			}
			if(length < size)
			{
				cout<<"enter value"<<endl;
				cin>>*(ptr + length);
				tail = (ptr + length);
				tindex = length;
				length ++;
				return 0;
			}
			if(hindex != 0)
			{
				if(tlength < hindex)
				{
				
					cout<<"enter value"<<endl;
					cin>>*(ptr + tlength);
					tindex = tlength;
					tlength ++;
					return 0;
				}
				else 
				{
					cout<<"overflow"<<endl;
					return 0;
				}	
			}
			
			
			
		}
		int deque()
		{
			if(head == NULL)
			{
				cout<<"underflow"<<endl;
			}
			if(hindex < length)
			{
				hindex++;
				head = (ptr + hindex);
				return 0;
			}
			
		}
		int print()
		{
			for(int i = hindex; i<length; i++)
			{
				cout<<*(ptr + i)<<endl;
			}
			if(tlength != 0)
			{
				for(int i =0; i<tlength; i++)
				{
					cout<<*(ptr + i)<<endl;
				}
			}
		}
		
};
int main()
{
	queue q;
	for(int i=0; i<10; i++)
	{
		q.enque();
	}
	q.print();
	q.deque();
	q.enque();
	q.print();
	
}
