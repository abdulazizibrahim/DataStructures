#include<iostream>
using namespace std;
struct node
{
	node *next;
	node *previous;
	int info;
};
class DLL
{
	private:
		node *head;
		node *temp;
	public:
		DLL()
		{
			head = NULL;
			temp = NULL;
		}
		void insert_start()
		{
			if(head == NULL)
			{
				head = new node;
				cout<<"enter value"<<endl;
				cin>>head->info;
				head -> next = NULL;
				head -> previous = NULL;
			}
			else
			{
				temp = new node;
				cout<<"enter info"<<endl;
				cin>>head->info;
				temp->previous = NULL;
				temp -> next = head;
				head = temp;
				temp = NULL;
				
				
			}
		}
		void insert_end()
		{
			if(head == NULL)
			{
				head = new node;
				cout<<"enter value"<<endl;
				cin>>head->info;
				head->previous = NULL;
				head->next = NULL;
			}
			else
			{
				temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				node *temp1 = new node;
				cout<<"enter info"<<endl;
				cin>>temp1->info;
				temp1->next = NULL;
				temp1->previous = NULL;
			}
		}
		int insert_any(int key)
		{
			if(head == NULL)
			{
				head = new node;
				cout<<"enter value"<<endl;
				cin>>head->info;
				head->previous = NULL;
				head->next = NULL;
			}
			else
			{
				if(head -> info == key)
				{
					node *temp1 = new node;
					cout<<"enter value"<<endl;
					cin>>temp1->info;
					temp1 -> next = head -> next;
					temp1->previous = head;
				}
				temp = head;
				while(temp->next != NULL)
				{
					if(temp->info == key)
					{
						node* temp1;
						temp1 = new node;
						cout<<"enter info"<<endl;
						cin>>temp1->info;
						temp1->next = temp->next;
						temp->next = temp1;
						temp1 ->previous = temp;
						temp1 = NULL;
						return temp->info;
						
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
				cout<<"LL does not exist"<<endl;
			}
			else
			{
				temp = head;
				while(temp!= NULL)
				{
					cout<<"print LL"<<endl;
					cout<<temp->info<<endl;
					temp = temp->next;
				}
			}
		}
	
};
int main()
{
	DLL d;
	d.insert_start();
	d.insert_start();
	d.insert_start();
	d.print();
}
