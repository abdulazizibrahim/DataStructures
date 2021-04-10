#include<iostream>
using namespace std;

struct node
{
	int data;
	node *pre;
	node *next;
};

class doubly
{
private:
	node *temp, *head;
	node *disp;
	node *n;

public:
	doubly()
	{
		temp = NULL;
		head = NULL;
		n = NULL;
		disp = NULL;
	}

	void Add()
	{
		if (head==NULL)
		{
			
			head = new node;
			head->pre = NULL;
			head->next=NULL;
			cout << "Enter the data: ";
			cin >> head->data;
			temp = head;

		}

		else
		{

			n = new node;
			cout << "Enter the data: ";
			cin >> n->data;
			temp->next = n;
			n->pre = temp;
			temp = n;
			temp->next = NULL;
		}
	}

	void dis()
	{
		disp = head;
		while (disp!= NULL)
		{
			cout << disp->data;
			disp = disp->next;
		}
	}

	void insert()
	{
		cout << "Enter the data after which insertion take place: ";
		int s;
		cin >> s;
		disp = head;

		while (disp->next!= NULL)
		{
			if (disp->data == s)
			{
				n = new node;
				n->data = 5;
				n->next = disp->next;
				disp->next->pre = n;
				n->pre = disp;
				disp->next = n;
			}
			disp = disp->next;
		}
		if (disp->data == s)
		{
			n = new node;
			n->data = 5;
			disp->next = n;
			n->pre = disp;
			disp = n;
			disp->next = NULL;
		}

	}

	void del()
	{
		cout << "Enter the data to be deleted: ";
		int d;
		cin >> d;
		disp = head;
		if (head->data == d)
		{
			head = disp->next;
			head->pre = NULL;
		}
		else
		{
			while (disp->next != NULL)
			{
				if (disp->data == d)
				{
					disp->next->pre = disp->pre;
					disp->pre->next = disp->next;
				}
				disp = disp->next;
			}
		}
	}
};

void main()
{
	doubly d;
	d.Add();
	d.Add();
	d.Add();
	d.Add();
	d.Add();
	d.Add();
	d.insert();
	d.del();
	d.dis();
}