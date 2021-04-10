#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class Queue
{
	node *front, *rare, *n;
public:
	Queue()
	{
		front= rare = NULL;
	}

	void Enqueue()
	{
		if (front == NULL)
		{
			front = new node;
			cin >> front->data;
			rare = front;
			front->next = NULL;
		}
		else
		{
			n = new node;
			rare->next = n;
			cin >> n->data;
			rare = rare->next;
			rare->next = NULL;

		}
	}

	void dequeue()
	{
		if (front == NULL)
		{
			cout << "Queue is emty" << endl;
		}
		if (front == rare)
		{
			cout << front->data;
			front == NULL;
		}
		else
		{
			cout << front->data;
			front = front->next;
		}
	
	}

};

void main()
{
	Queue l;
	l.Enqueue();
	l.Enqueue();
	l.Enqueue();
	l.dequeue();
	l.dequeue();
	l.dequeue();
}