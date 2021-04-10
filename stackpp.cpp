#include<iostream>
using namespace std;
struct node
{
	node* next;
	int info;
};
class stack
{
	private:
		node* top;
		node* base;
		node* temp;
	public:
		stack()
		{
			top = NULL;
			base = NULL;
			temp = NULL;
		}
		~stack()
		{
			delete top;
			delete base;
			delete temp;
		}
		int insert(int x)
		{
			if( base == NULL)
			{
				cout<<"stack is empty"<<endl;
				cout<<"lets make one"<<endl;
				base = new node;
//				cout<<"enter value"<<endl;
				base->info = x;
				base->next = NULL;
				top = base;
				return 0;
			}
			temp = new node;
//			cout<<"enter value you want to insert"<<endl;
			temp->info = x;
			temp -> next = top;
			top = temp;
			temp = NULL;
			return 0;
		}
		int dels()
		{
			if(base == NULL)
			{
				cout<<"stack is empty"<<endl;
				return 0;
			}
			temp = top;
			top = top -> next;
			temp -> next = NULL;
			delete temp;
			temp = NULL;
			return 0;
		}
		int print()
		{
//			int s = 0;
			temp = top;
			while(temp != NULL)
			{
				cout<<temp->info<<" ";
			
				temp = temp -> next;
			}
			cout<<endl;
			return 0;
		}
		int extra()
		{
			temp = top;
			int x = 0;
			while(temp != NULL)
			{
				x++;
				temp = temp -> next;
			}
			cout<<"len done"<<endl;
			int *ptr = new int[x];
			sot(ptr, 0);
			return 0;
		}
		int sot(int *ptr, int y)
		{
			if(top != NULL)
			{
				cout<<"making array"<<endl;
				int x = top -> info;
				*(ptr + y) = top -> info;
				y++;
				dels();
				sot(ptr, y);
				return 0;
			}
			ptr = sorted(ptr, y);
			sinsert(ptr, y);
			return 0;
			
		}
		int* sorted(int *ptr, int y)
		{
			cout<<"sorting"<<endl;
			static int x = 0;
			static int c =  1;
			if(x <= y)
			{
				if(*(ptr + x) > *(ptr + c))
				{
					int t = *(ptr + x);
					*(ptr + x) = *(ptr + c);
					*(ptr + c) = t;
					c ++;
					if(c == y)
					{
						x ++;
						c = x + 1;
						sorted(ptr, y);
						return ptr;
					}
					else
					{
						sorted(ptr, y);
						return ptr;
					}
					
				}
				
				
			}
			else
			{
				cout<<"print array"<<endl;
				for(int i =0; i<y; i++)
				{
					cout<<*(ptr + i)<<" ";
				}
				cout<<endl;
//				sinsert(ptr, y);
				return ptr;
			}
		}
		int sinsert(int *ptr, int y)
		{
			cout<<"inside insert"<<endl;
			static stack s;
			if(y > 0)
			{
				s.insert(*(ptr + y));
				cout<<"inserted"<<endl;
				y --;
				sinsert(ptr, y);
				return 0;
			}
			cout<<"helo"<<endl;
			s.temp = s.top;
			while(s.temp != NULL)
			{
				cout<<s.temp->info<<" ";
				s.temp = s.temp -> next;
			}
			return 0;
		}
		
};
int main()
{
	stack s1;
	for(int i=0; i<9; i++)
	{
		static int x = 0;
		
		s1.insert(x);
		x++;
		
	}
	s1.print();
	s1.extra();
	
}
