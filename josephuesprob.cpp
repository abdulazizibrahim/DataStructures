#include<iostream>
using namespace std;
struct node
{
	node *next;
	int info;
};
class jl
{
	private:
		node *head;
		node *temp;
	public:
		jl()
		{
			head = NULL;
			temp = NULL;
		}
		void insert()
		{
			if(head == NULL)
			{
				head = new node;
				cout<<"enter info"<<endl;
				cin>>head->info;
				head ->next = head;
			}
			else
			{
				temp = head;
				while(temp -> next != head)
				{
					temp = temp->next;
				}	
				node *temp1;
				temp1 = new node;
				cout<<"enter value for new"<<endl;
				cin>>temp1->info;
				temp->next=temp1;
				temp1->next = head;
				temp1=NULL;
			}
		}
		void jp()
		{
			temp = head;
			int m;
			if(head == NULL)
			{
					cout<<"link list does not exist "<<endl;
			}
			while(temp->next != NULL)
			{
				cout<<"enter jump"<<endl;
				cin>>m;
				for(int i =0; i<=m; i++)
		s		{
					if(i == m)
					{
						node *temp1;
						temp1 = head;
						while(temp1 -> next = temp)
						{
							temp1 = temp1->next;
						}
						temp1 -> next = temp->next;
						delete temp;
						temp = temp1;
						temp1 = NULL;
					}
					else
					{
						temp = temp->next;
					}
				}
			
			}
		}
		void print()
		{
			if(head == NULL)
			{
				cout<<"ll does not exist"<<endl;
			}
			else
			{
				temp = head;
				cout<<temp->info<<endl;
				temp = temp->next;
				while(temp != head)
				{
					cout<<temp->info<<endl;
					temp = temp->next;
				}
			}
		}
		
};
int main()
{
	jl k;
	k.insert();
	k.insert();
	k.insert();
	k.insert();
	k.insert();
	k.insert();
	k.print();
	k.jp();
	k.print();
}
