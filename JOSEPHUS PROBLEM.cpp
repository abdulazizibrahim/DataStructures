#include<iostream>
using namespace std;



struct node
{

	int data;
	node *next;
	node *pre;

};
class ring
{
private:
	node *temp, *head, *n;
	int count;
public:
	ring()
	{
		temp = head = n = NULL;
		count = 0;
	}
	void add()
	{
		if (head == NULL)
		{
			head = new node;
			cin >> head->data;
			temp = head;
			temp->next = head;
			temp->pre = head;
		}
		else
		{
			n = new node;
			temp->next = n;
			cin >> n->data;
			n->pre = temp;
			n->next = head;
			head->pre = n;
			temp = n;
			n = head;
		}
	}

	void dis()
	{
		temp = head;
		cout << temp->data;
		temp = temp->next;
		while (temp != head)
		{
			cout << temp->data;
			temp = temp->next;
		}

	}

	void del()
	{
		if (count == 0)
		{
			temp = head;
			count++;
		}

		else
		{
			temp = temp;
		}
		int key;
		cout << "Enter the number: ";
		cin >> key;
		while (temp->next != head)
		{
			if (head->data == key)
			{

				head = head->next;
				head->pre->pre->next = head;
				head->pre = temp->pre;
			}
			temp = temp->next;
		}

		temp = head;
		{
			temp = temp->next;
			while (temp != head)
			{
				if (temp->data == key)
				{
					temp->pre->next = temp->next;
					temp->next->pre = temp->pre;
				}
				temp = temp->next;

			}
		}
	}

	void deljosph()
	{
		int c;
		cout << "Enter the number: ";
		cin >> c;

		
		for (int i = 0; i < c; i++)
		{
			n = n->next;
		}
		if (n == head)
		{
			head = head->next;
			head->pre->pre->next = head;
			head->pre = n->pre;
			n = n->next;
		}
		else
		{
			n->pre->next = n->next;
			n->next->pre = n->pre;
			n = n->next;

		}
		cout << "Current: " << n->data << endl;
		
	}
};

void main()
{
	ring r;
	r.add();
	r.add();
	r.add();
	r.add();
	r.deljosph(); r.dis();
	r.deljosph();
	r.dis();
	r.deljosph(); r.dis();
}