#include<iostream>
using namespace std;

class st
{
private:
	int *top;
	int *stack;
	int current;
	int max;
public:
	st()
	{
		cout << "Enter the limit: ";
		cin >> max;
		stack = new int[max];
		top = NULL;
		current == 0;
	}
	void push()
	{
		if (top == NULL)
		{
			
			top = stack;
			cin >> *top;
			current++;
			return;
		}
		if (current == max)
		{
			cout << "Stack overflow" << endl;
			return;
		}
		else
		{
			top++;
			cin >> *top;
			current++;
		}
	}

	void pop()
	{
		if (top == stack)
		{
			cout << *top << " ";
			top = NULL;
			current = 0;
			return;
		}
		if (top == NULL)
		{
			cout << "Stack underflow" << endl;
			return;
		}
		else
		{
			cout << *top << " ";
			top--;
			current--;
		}
	}
};

void main()
{
	
	st t;
	t.push();
	t.push();
	t.push();
	t.pop();
	t.pop();
	t.pop();
	t.pop();


}