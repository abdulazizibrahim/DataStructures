#include<iostream>
using namespace std;
struct node
{
	node* next;
	int info;
};
class SLL
{
	private:
		node* head;
		node* temp;
	public:
		SLL()
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
				head->next = NULL;
			}
			else
			{
				temp = new node;
				cout<<"enter value"<<endl;
				cin>>temp->info;
				temp->next = head;
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
				head->next = NULL;
			}
			else
			{
				temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
					cout<<"in"<<endl;
				}
				node* temp1 = new node;
				cout<<"enter info"<<endl;
				cin>>temp1->info;
				temp->next = temp1;
				temp1->next = NULL;
				temp1 = NULL;
				
			}
		}
		int insert_any(int key)
		{
			if(head == NULL)
			{
				head = new node;
				cout<<"enter value"<<endl;
				cin>>head->info;
				head->next = NULL;
			}
			else
			{
				if(head ->info == key)
				{
						node* temp1;
						temp1 = new node;
						cout<<"enter info"<<endl;
						cin>>temp1->info;
						temp1->next = head->next;
						head->next = temp1;
						temp1 = NULL;
						return head->info;
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
		void del(int key)
		{
			if(head == NULL)
			{
				cout<<"LL does not exist"<<endl;
			}
			else
			{
				temp = head;
				if(head->info == key)
				{
					head = temp->next;
					temp->next = NULL;
					delete temp;
					temp = NULL;
				}
				temp = head->next;
				while(temp->next != NULL)
				{
					if(temp->next->info == key)
					{
						node *temp1 = temp->next;
						temp -> next = temp1->next;
						temp1 ->next = NULL;
						delete temp1;
						temp1 = NULL;
						break;
					}
					else
					{
						temp = temp->next;
					}
				}
			}
		}
		int search(int key)
		{
			if(head == NULL)
			{
				cout<<"LL does not exist"<<endl;
			}
			else
			{
				temp = head;
				while(temp->next != NULL)
				{
					if(temp->info == key)
					{
						cout<<"key is found"<<endl;
						return key;
					}
					else
					{
						temp = temp->next;
					}
				}
			cout<<"key not found"<<endl;
				
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
					cout<<temp->info<<" ";
					temp = temp->next;
				}
			}
		}
};
int main()
{
	SLL s;
	s.insert_end();
	s.insert_end();
	s.insert_end();
	s.insert_end();
	s.insert_any(2);
	s.search(55);
	s.print();
	s.del(55);
	s.print();
}
