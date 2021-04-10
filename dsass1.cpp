#include<iostream>
using namespace std;
class link
{
	private:
		int *current;
		int *temp1;
		int length;
		int size;
	public:
		link()
		{
			cout << "Enter size here: " << endl;
			cin >> size;
			cout<<"construction"<<endl;
			current = new int[size];
			temp1 = current;
		}
		~link()
		{
			delete [] current;
			cout<<"destruction"<<endl;
		}
		void fill()
		{
			cout << "Input : " << endl;
			for (int i = 0 ; i  <size ; i++)
			{
				cin >> *temp1;
			}
			temp1 = current;
		}
		void get()
		{
			cout<<"*current = "<<*current<<endl;
			cout<<*(current + 3)<<endl;
		}
		void update()
		{
			int up;
			cout<<" enter update "<<endl;
			cin>>up;
			cout<<"*current = "<<*current<<endl;
			*(current) = up;
			cout<<"*current = "<<*current<<endl;
		}
		void start()
		{
			current = &current[0];
			cout<<" current = "<<*current<<endl;
		}
		void end()
		{
			start();
			for(int i =0; i<size; i++)
			{
				current ++;
			}
			current --;
			cout<<*current<<endl;
		}
//		link length()
//		{
//			cout<<size<<endl;
//			return size;
//		}
//		link next()
//		{
//			
//		}
};
int main()
{
	link l1;
	l1.fill();
	l1.get();
	l1.update();
	l1.start();
	l1.end();
	l1.~link();
}
