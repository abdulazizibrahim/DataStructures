#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class LL
{
private:
	node *temp, *head, *n, *temp2;
public:
	LL()
	{
		temp = head = NULL;
	}

	void add()
	{
		if (head == NULL)
		{
			head = new node;

			temp = head;
			cout << "Enter the data: ";
			cin >> temp->data;
			temp->next = NULL;

		}
		else
		{
			n = new node;
			temp->next = n;
			cout << "Enter the data: ";
			cin >> n->data;
			temp = temp->next;
			temp->next = NULL;
		}
	}


	void print()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;

		}
	}
	void insert()
	{
		cout << "Enter the data of insertion: ";
		int search;
		cin >> search;
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->data == search)
			{

				temp2 = new node;
				cout << "Enter the data1: ";
				cin >> temp2->data;
				temp2->next = temp->next;
				temp->next = temp2;
				break;
			}
			else
			{
				temp = temp->next;

			}

		}

		if (temp->data != search)
		{
			cout << "Data not found" << endl;
		}
	}


	void del()
	{
		cout << "Enter the data to delete: ";
		int d;
		cin >> d;
		temp = head;
		temp2 = temp->next;
		if (temp->data == d)
		{
			temp = temp->next;
			head = temp;
		}
		else
		{
			while (temp->next != NULL)
			{

				if (temp2->data == d)
				{
					temp->next = temp2->next;
					delete temp2;
					break;
				}
				else
				{
					temp2 = temp2->next;
					temp = temp->next;
				}

			}
		}
	}
	void delall()
	{
		int no;
		cin >> no;
		temp = head;
		temp = head;
		while (temp != NULL)
		{
			if (head->data == no)
			{
				head = temp->next;
			}

			if (head == NULL)
			{
				cout << "List is empty " << endl;
				add();
				break;
			}
			temp = temp->next;

		}

		temp = head;
		temp2 = temp->next;
		while (temp != NULL)
		{
			if (temp2->data == no)
			{
				temp->next = temp2->next;
			}
			temp2 = temp2->next;
			temp = temp->next;
		}


	}

};

void main()
{
	LL l;

	l.add();

	l.add();
	l.add();
	l.add();

	l.add();
	l.add();
	l.delall();
	l.print();
}