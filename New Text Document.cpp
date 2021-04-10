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
	node *temp, *head;
	node *n;

public:
	ll()
	{
		temp = head = NULL;
	}

	void add()
	{
		if (head == NULL)
		{
			head = new node;
			cin >> head->data;
			temp = head;
			temp->next = NULL;
		}
		else
		{
			n = new node;
			cin >> n->data;
			temp->next = n;
			temp = temp->next;
			temp->next = NULL;
		}
	}
	void show()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void check_sort()
	{
		int c=0;
		int d=0;

		temp = head;
		while (temp->next!= NULL)
		{
			if (temp->data < temp->next->data)
			{
				c++;
			}
			temp = temp->next;
		}
		temp = head;
		while (temp->next!= NULL)
		{
			if (temp->data > temp->next->data)
			{
				d++;
			}
			temp = temp->next;
		}
		cout << c << " " << d << " " << endl;
		if (c==2)
		{
			cout << "It is sorted assidengly" << endl;
		}
		else if (d==2)
		{
			cout << "It is sorted desending" << endl;
		}
		else
		{
			cout << "It is not sorted" << endl;
		}

	}
};

void main()
{
	ll l;
	l.add();
	l.add();
	l.add();
	l.check_sort();
	l.show();
}