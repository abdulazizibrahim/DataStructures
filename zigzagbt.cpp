#include<iostream>
using namespace std;
struct node
{
	int info;
	node* left;
	node* right;
};
class zigzag
{
	private:
		node* root;
		node* temp;
		bool flag;
	public:
		zigzag()
		{
			root = NULL;
			flag = true;
			temp = NULL;
				
		}
		~zigzag()
		{
			delete root;
			delete temp;	
		}
		int insert()
		{
			if(root == NULL)
			{
				cout<<"tree is empty"<<endl;
				cout<<"lets insert"<<endl;
				root = new node;
				cout<<"enter value you want to insert"<<endl;
				cin>>root->info;
				root->left = NULL;
				root->right = NULL;
				return 0;
			}
			insert_temp(root);
			return 0;
		}
		int insert_temp(node* temp)
		{
			static int i = 0;
			if(temp ->left == NULL && temp -> right == NULL)
			{
				if(flag  == true)
				{
					node* temp1 = new node;
					cout<<"enter value"<<endl;
					cin>>temp1->info;
					cout<<" i ="<<i<<endl;
					temp -> right = temp1;
					temp1->left = NULL;
					temp1->right = NULL;
					temp1 = NULL;
					flag = false;
					return 0;
				}
				if(flag == false )
				{
					node* temp1 = new node;
					cout<<"enter value"<<endl;
					cin>>temp1->info;
					cout<<"i = "<<i<<endl;
					temp -> left = temp1;
					temp1->left = NULL;
					temp1->right = NULL;
					temp1 = NULL;
					flag = true;
					return 0;
				}
			}
			if(temp -> right != NULL)
			{
				i++;
				insert_temp(temp->right);
				i--;
				return 0;
			}
			if(temp -> left != NULL)
			{
				i++;
				insert_temp(temp->left);
				i--;
				return 0;
			}
			return 0;
		}
		int print()
		{
			paste(root);
			return 0;
		}
		int paste(node* temp)
		{
			if(temp -> left != NULL || temp -> right != NULL)
			{
				if(temp -> left != NULL)
				{
					cout<<temp->info<<" kai left mein = "<<temp->left->info<<endl;
					paste(temp->left);
					return 0;
				}
				if(temp -> right != NULL)
				{
					cout<<temp->info<<" kai right mein = "<<temp->right->info<<endl;
					paste(temp->right);
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	
			
};
int main()
{
	zigzag f;
	for(int i =0; i<7; i++)
	{
		f.insert();
	}
	f.print();
}
