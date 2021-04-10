#include<iostream>
using namespace std;
struct node
{
	node *left;
	node *right;
	int info;
	int level;
};
class CBT
{
	private:
		node *root;
		node *temp;
		node *temp1;
	public:
		CBT()
		{
			root = NULL;
			temp = NULL;
		}
		int height(node *temp)
		{
			if (temp == NULL)
			{
				//cout << "temp is null" << endl;
				return 0;
			}
			else
			{

				int LD = height(temp->left);
				int RD = height(temp->right);

				if (LD>RD)
				{
					return (LD + 1);
				}

				else
				{
					return (RD + 1);
				}
		}
		int insert()
		{
			if (root == NULL)
			{
				cout << " tree does not exist hence making " << endl;
				root = new node;
				cout << "enter value " << endl;
				cin >> root->info;
				root->left = NULL;
				root->right = NULL;
				return 0;
			}
			else
			{
				insert_temp(root);
			}
		}
		int insert_temp(node *temp)
		{
			if (temp->left == NULL && temp->right == NULL)
			{
				node *new1 = new node;
				cout << "enter value" << endl;
				cin >> new1->info;
				new1->left = NULL;
				new1->right = NULL;
				temp->left = new1;
				new1 = NULL;
				return 0;
			}
			if (temp->left != NULL && temp->right == NULL)
			{
				node *new1 = new node;
				cout << "enter value " << endl;
				cin >> new1->info;
				new1->left = NULL;
				new1->right = NULL;
				temp->right = new1;
				new1 = NULL;
				return 0;
			}
			if (temp->left != NULL && temp->right != NULL)
			{
				insert_temp(temp->left);
			}
		}

};
int main()
{
	
}
