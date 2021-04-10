#include<iostream>
using namespace std;

struct node
{
	int data;
	node *down;
};

class sta
{
private:
	node *temp;
	node *top;
	node *n;

public:
	sta()
	{
		top = temp = NULL;

	}
	void push()
	{

		if (top == NULL)
		{
			top = new node;
			cin >> top->data;
			top->down = NULL;
		}
		else
		{
			temp = new node;
			cin >> temp->data;
			temp->down = top;
			top = temp;

		}
	}

	void pop()
	{
		if (top == NULL)
		{
			cout << "Stack underflow";
			return;
		}
		cout << top->data;
		top = top->down;
	}

	void swap()
	{
		
		
		int data;
		data = top->data;
		top->data = top->down->data;
		top->down->data = data;



	}
};

void main()
{

	sta s;
	s.push();
	s.push();
	s.push();
	s.swap();
	s.pop();
	s.pop();
	

}
