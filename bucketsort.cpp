using namespace std;
#include<iostream>
#include<cmath>
struct node
{
	node *next;
	float info;
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
		int insert(float x)
		{
			if(head == NULL)
			{
				cout<<"ll does not exist hence lets make one "<<endl;
				head = new node;
				cout<<"enter the value you want to insert"<<endl;
				head->info = x;
				head->next = NULL;
				return 0;
			}
			node *temp = new node;
			cout<<"enter value you want to add"<<endl;
			temp->info = x;
			temp -> next = head;
			head = temp;
			temp = NULL;
			return 0;
		}
		int display()
		{
			temp = head;
			if(temp == NULL)
			{
				cout<<"LL does not exits"<<endl;
				return 0;
			}
			
			while(temp!= NULL)
			{
				cout<<temp->info<<" ";
				temp = temp ->next;
			}
			return 0;
		}
		
};
int bucket(float *B)
{
	LL list[10];
	//check
	for(int i=0; i<10; i++)
	{
		float x = *(B + i);
		int a = floor(x*10);
		list[a].insert(x);
	}
	for(int i =0; i<10; i++)
	{
		list[i].display();
	}
		
		
	
}
int main()
{
	float B[10];
	cout<<"enter array B"<<endl;
	for(int i =0; i<10; i++)
	{
		cin>>*(B + i);
	}
	bucket( B);
	

}
