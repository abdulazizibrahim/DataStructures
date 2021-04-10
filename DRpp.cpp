#include<iostream>
using namespace std;
struct node
{
	node* next;
	node* pre;
	int info;	
};
class DR
{
	private:
		node* head;
		node* temp;
	public:
		DR()
		{
			head = NULL;
			temp = NULL;
		}
		~DR()
		{
			
		}
		int insert()
		{
			if(head == NULL)
			{
				cout<<"DR does not exist hence lets make one"<<endl;
				head = new node;
				cout<<"enter the number you want to insert"<<endl;
				cin>>head->info;
				head -> next = head;
				head -> pre = head;
				return 0;
			}
			temp = new node;
			cout<<"enter the number you want to insert"<<endl;
			cin>>temp->info;
			node* temp1 = head -> pre;
			temp->next = head;
			head -> pre = temp;
			temp1 -> next = temp;
			temp -> pre = temp1;
			temp1 = NULL;
			temp = NULL;
			return 0;
		}
		int Rsearch(int x)
		{
			int i = 1;
			if(head -> info == x)
			{
				return 0;
			}
			temp = head->next;
			while(temp != head)
			{
				i++;
				if(temp -> info == x)
				{
					break;
				}
				temp = temp -> next;
			}
			return i;
		}
		int Lsearch(int x)
		{
			int i = 0;
			if(head ->info == x)
			{
				return 0;
			}
			temp = head -> pre;
			while(temp != head)
			{
				i++;
				if(temp -> info == x)
				{
					break;
				}
				temp = temp -> pre;
			}
			return i;
		}
		void print()
		{
			temp = head;
			cout<<head -> info<<" ";
			temp = head->next;
			while(temp != head)
			{
				cout<<temp->info<<" ";
				temp = temp ->next;
			}
		}
		void check()
		{
			int x; ,
			cout<<"enter the number you want to find"<<endl;
			cin>>x;
			int l  =0;
			int r = 0;
			cout << "Going for left search " << endl;
			l = Lsearch(x);
			cout << "Going for right search " << endl;
			r = Rsearch(x);
			cout<<head->info<<endl;
			cout << "Next: " << r << endl;
			cout << "Left: " << l << endl;
			if(r > l )
			{
				cout<<"faster with pre"<<endl;
			}
			if(r == l)
			{
				cout<<"same"<<endl;
			}
			else
			{
				cout<<"faster with next"<<endl;
			}
		}
};
int main()
{
	DR r1;
	for(int i =0; i< 10; i++)
	{
		r1.insert();
	}
	r1.print();
	r1.check();
}
