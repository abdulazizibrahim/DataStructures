#include<iostream>
using namespace std;

class a
{
private:
	int *p;
	int *front;
	int *rare;
	int *t;
	int max;
	int current;

public:
	a()
	{
		cout << "Enter the maximum no: ";
		cin >> max;
		p = new int[max];
		front = rare = NULL;
		current = 0;
	}

	void enqueue()
	{
		if (front == NULL)
		{
			front = p;
			cin >> *front;
			rare = front;
			current++;
			return;
		}
		if (current == (max))
		{
			cout << "Queue is full" << endl;
			return;
		}
		else
		{
			rare++;
			cin >> *rare;
			current++;
			t = rare;
		}

	}
	void dequeue()
	{
		

		 if (front == rare)
		{
			cout << *front << " ";
			front++;
			t++;

		}
		
		else if (front == t)
		{
			cout << "Stack underflow" << endl;
			return;
		}
		else if (front != NULL)
		{
			cout << *front << " ";
			front++;
		}
		
	}
};

void main()
{
	a s;
	s.enqueue();
	s.enqueue();
	s.enqueue();
	s.enqueue();
	s.dequeue();
	s.dequeue();
	s.dequeue();
	s.dequeue();
}