#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};


class ll
{
private:
	node *temp, *head, *n, *temp2;
public:
	ll()
	{
		n=temp = head = NULL;
	}
	void add()
	{
		if (head == NULL)
		{
			head = new node;
			temp = head;
			temp2 = head;
			head->data = 9;
			head->next = NULL;
		}
		else
		{
			n = new node;
			cin >> n->data;
			temp2->next = n;
			temp->next = n;
			temp = n;
			temp2 = n;
			temp->next = NULL;
			temp2->next = NULL;


		}

	}

	void series()
	{
		cout << "Enter the nth term: ";
		int nn;
		cin >> nn;
		temp2 = head;
		for (int i = 0; i < nn; i++)
		{
			
			n = new node;
			int s;
			s = temp2->next->next->data + temp2->next->data + temp2->data;
			n->data = s;
			temp->next = n;
			temp = temp->next;
			temp->next = NULL;
			temp2->next->next->next = n;
			temp2 = temp2->next;
		}

	
	}
	void show()
	{
		temp = head;
		while (temp!= NULL)
		{
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
};

void main()
{
	ll l;
	l.add();
	l.add();
	l.add();
	l.series();
	l.show();

}