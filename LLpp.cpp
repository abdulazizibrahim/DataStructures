using namespace std;
#include<iostream>
struct node
{
	node *next;
	int info;
};
class LL
{
	private:
		node *head;
		node *temp;
	public:
		LL()
		{
			head = NULL;
			temp = NULL;
		}
		~LL()
		{
//			delete temp;
//			delete head;
//			
		}
		int insert()
		{
			if(head == NULL)
			{
				cout<<"ll does not exist hence lets make one "<<endl;
				head = new node;
				cout<<"enter the value you want to insert"<<endl;
				cin>>head->info;
				head->next = NULL;
				return 0;
			}
			node *temp = new node;
			cout<<"enter value you want to add"<<endl;
			cin>>temp->info;
			temp -> next = head;
			head = temp;
			temp = NULL;
			return 0;
		}
		int sort()
		{
			node *temp1;
			temp = head;
			while(temp != NULL)
			{
				temp1 = temp -> next;
				while(temp1 != NULL)
				{
					if(temp -> info > temp1 -> info)
					{
						int x = temp -> info;
						temp -> info = temp1 -> info;
						temp1 -> info = x;
					}
					temp1 = temp1 -> next;
				}
				temp = temp -> next;
			}
			//print 
			temp = head;
			while(temp != NULL)
			{
				cout<<temp->info<<" ";
				temp = temp->next;
			}
		}
		int dels()
		{
			sort();
			node *temp = head;
			head = head -> next;
			temp -> next = NULL;
			delete temp;
			temp = NULL;
			
			
			temp = head;
			node* temp1;
			while(temp -> next != NULL)
			{
				temp1 = temp;
				temp = temp -> next;
			}
			temp1 -> next = NULL;
			delete temp;
			temp = NULL;
			temp1 = NULL;
			cout<<endl;
			sort();
			return 0;
			
		}
		int repeat()
		{   
			node* temp1;
			node* temp2;
			temp = head;
			int j =0;
			while(temp != NULL)
			{
				temp2 = temp;
				temp1 = temp->next;
				int i =0;
				while(temp1 != NULL)
				{
					if(temp->info == temp1->info)
					{
						temp2 -> next = temp1 -> next;
						temp1 -> next = NULL;
						delete temp1;
						temp1 = temp2->next;						
						i++;
					}
					temp2 = temp1;
					temp1 = temp1 -> next;
				}
				if(i > 0)
				{
					j ++;
				}
				//cout<<temp->info<<" has appeared "<<i<<" times"<<endl;
				temp = temp->next;
			}
			cout<<j<<" number have been repeated"<<endl;
			return 0;
		}
		
		
};
int main()
{
	LL l1;
	for(int i=0; i<10; i++)
	{
		l1.insert();
	}
	l1.repeat();
	//l1.dels();
	//l1.dels();
}
