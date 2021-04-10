#include<iostream>
using namespace std;
class listdta
{
	int *temp1;
	int *temp2;
	int *current;
	int list[8];
	int length;
	int size;
public:
	listdta()
	{
		current = NULL;
		temp1 = NULL;

		length = 0;
		size = 8;

	}
	void create()
	{
		current = list;
		size = 8;

		length = 0;
	}
	void fill()
	{
		length = 0;
		cout << "How much you want to fill(enter number): ";
		int x; cin >> x;
		if (current != list)
		{
			current = list;
		}
		if (x > 8)
		{
			cout << "List out of bound" << endl;
		}
		if (current == list&&x <= 8)
		{
			for (int i = 0; i < x; i++)
			{
				cin >> *current;
				current++;
				length++;
			}
			current--;


		}
	}

	void clear()
	{
		current = list;
		length = 0;
	}

	void insert(int pos, int num)
	{
		if (pos > length)
		{
			cout << "List out of bound" << endl;
		}
		else
		{
			for (int i = length; i > pos; i--)
			{
				current--;
			}
			*current = num;
		}
	}
	void tail()
	{
		current = list;

		for (int i = 0; i < length; i++)
		{
			current++;
		}
		current--;
		cout << *current << endl;
	}
	void back()
	{
		if (length != 0)
		{
			if (current != list)
			{
				current--;
				cout << *current << endl;
			}
			else
			{
				cout << "List out of bound" << endl;
			}
		}
		else
		{
			cout << "List is clear" << endl;
		}
	}
	void display()
	{
		cout << length << endl;
		if (length != 0)
		{
			for (int i = 0; i < length; i++)
			{
				cout << list[i];
			}
		}
		else
		{
			cout << "No data to display" << endl;
		}
		

	}
	void remove()
	{
			temp1 = current;
			temp2 = temp1;
			temp2++;
			*temp1 = *temp2;
			current--;
			temp2++;
			temp1++;
			
			int l = length;
			int s = size - length;
		for (int i = -1; i <=(s); i++)
		{
			
			
			*temp1 = *temp2;
			temp2++;
			temp1++;
		}
		length = l;
		
		length--;
	}

	void next()
	{
		if (length != 0)
		{
			temp1 = list;
			for (int i = 0; i < size; i++)
			{
				temp1++;
			}

			if (current == temp1)
			{
				cout << "List out of bound" << endl;
			}
			else
			{
				current++;
				cout << *current << endl;
			}
		}
		else
		{
			cout << "List is clear" << endl;
		}

	}

};

void main()
{

	listdta l;
	l.create();
	l.fill();
	l.back();
	l.back();
	l.back();
	l.next();
	l.remove();
	l.display();


	
	


}

