#include<iostream>
using namespace std;
struct node
{
	int info;
	node *right;
	node *left;
	
		
};
class BST
{
	private:
		node *root;
		node *temp;
		node *temp1;
		node *temp2;
		node *temp3;

	public:
		BST()
		{
			temp = NULL;
			root = NULL;
			temp1 = NULL;
			temp2 = NULL;
			temp3 = NULL;
		}
		~BST()
		{
			//make destruction when you have the nuts
		}
		void del_case1(node *temp1, node *temp)
	    {
	    	cout<<"inside case1"<<endl;
	    	if(temp->left == temp1)
	    	{
	    		temp -> left = NULL;
	    		delete temp1;
	    		temp1 = NULL;
	    		return;
			}
			if(temp -> right == temp1)
			{
				temp -> right = NULL;
				delete temp1;
				temp1 = NULL;
				cout<<"node deleted"<<endl;
				return;
			}
		}
		void del_case2_left(node* temp1, node *temp)
		{
			if(temp->info > temp1->info)
			{
				temp -> left = temp1 -> left;
				delete temp1;
				temp1 = NULL;
				return;
			}
			if(temp->info < temp1 -> info)
			{
				temp ->right = temp1 -> left;
				delete temp1;
				temp1 = NULL;
				return;
			}
		}
		void del_case2_right(node* temp1, node *temp)
		{
			if(temp->info > temp1->info)
			{
				temp -> left = temp1 -> right;
				delete temp1;
				temp1 = NULL;
				return;
			}
			if(temp->info < temp1 -> info)
			{
				temp ->right = temp1 -> right;
				delete temp1;
				temp1 = NULL;
				return;
			}
		}
		void del_case3(node *temp2, node *temp)
		{
			if(temp2->left == NULL)
			{
				if(temp ->right == temp1)
				{
					temp -> right = temp2;
					temp3 -> left = temp2 -> right;
					temp2 -> right = temp1 -> right;
					temp2 -> left = temp1 -> left;
					delete temp1;
					temp1 = NULL;
					return;
				}
				if(temp -> left == NULL)
				{
					temp -> left = temp2;
					temp3 -> left = temp2 -> right;
					temp2 -> right = temp1 -> right;
					temp2 -> left = temp1 -> left;
					delete temp1;
					temp1 = NULL;
					return;
				}
			}
			else
			{
				 temp3 = temp2;
				temp2 = temp2 -> left;
				del_case3(temp2, temp);
			}
		}
	    void del_options(node *temp1, node *temp)
	    {
	    	if(temp1->left == NULL and temp1 -> right == NULL)
	    	{
	    		cout<<"calling del case1"<<endl;
	    		del_case1(temp1, temp);
			}
			if(temp1->left == NULL and temp1->right != NULL)
			{
				del_case2_right(temp1, temp);
			}
			if(temp1->left != NULL and temp1->right == NULL)
			{
				del_case2_left(temp1, temp);
			}
			if(temp1->left != NULL and temp1->right != NULL)
			{
				temp2 = temp1->right;
				del_case3(temp2, temp);
			}
		}
	    void del(node*temp, int key)
	    {
	    	if(temp == NULL)
	    	{
	    		cout<<"tree does not exist"<<endl;
			}
			else
			{
				if(temp->info > key)
				{
					if(temp->left->info == key)
					{
						//deletion cases apply
						node* temp1 = temp ->left;
						del_options(temp1, temp);
					}
					if(temp -> left == NULL)
					{
						cout<<"this child does not exist in tree "<<endl;
						return;
					}
					else
					{
						temp = temp->left;
						del(temp, key);
					}
				}
				if(temp ->info < key)
				{
					if(temp->right->info == key)
					{
						//apply deletion cases
						temp1 = temp->right;
						cout<<"calling del options"<<endl;
						del_options(temp1, temp);
					}
					if(temp->right == NULL)
					{
						cout<<"this child does not exist in tree"<<endl;
						return;
					}
					else
					{
						temp = temp->right;
						del(temp, key);
					}
				}
			}
		}
		void dels()
		{
			int key;
			cout<<"enter the value of the child you want to delete"<<endl;
			cin>>key;
			del(root, key);
		}
		int insert_temp(int value, node *temp)
		{
			if( value > temp->info)
			{
				if(temp->right == NULL)
				{
					node *new1 = new node;
					new1->info = value;
					temp->right = new1;
					new1->right = NULL;
					new1->left = NULL;
					new1 = NULL;
					return 0;
				}
				else
				{
					temp = temp->right;
					insert_temp(value, temp);
				}
				
			}
			if(value < temp->info)
			{
				if(temp -> left == NULL)
				{
					node *new1 = new node;
					new1->info = value;
					temp->left = new1;
					new1->right = NULL;
					new1->left = NULL;
					new1 = NULL;
					return 0;
				}
				else
				{
					temp = temp->left;
					insert_temp(value, temp);
					
					
				}
			}
			if(value == temp -> info)
			{
		//		cout<<"this value already exists in tree we dont make duplicates "<<endl;
				return 0;
			}
		}
		int insert()
		{
			if(root == NULL)
			{
				//tree does not exist in memory
				// hence make one
				root = new node;
				cout<<"enter info that you'd like to insert"<<endl;
				cin>>root->info;
				root -> right = NULL;
				root -> left = NULL;
				return 0;
			}
			else
			{
				int value;
				cout<<"enter the info you'd like to insert"<<endl;
				cin>>value;
				insert_temp(value, root);
				
			}
		}
		int traversal(node *temp, int y)
		{
			static int x = 0;
			if( temp == NULL)
			{
				return 0;
			}
			if(x == y)
			{
				cout<<temp->info<<" ";
			}
			if(temp -> left != NULL)
			{
				x++;
				traversal(temp->left, y);
				x--;
			}
			if(temp -> right != NULL)
			{
				x++;
				traversal( temp->right, y );
				x--;
			}
			return 0;
		}
		int paste(node *temp1)
		{
			if(root==NULL)
    		{
				cout<<" Tree is empty.\n";
				return 0;
    		}	
  			if( temp1->left!=NULL )
    			 paste(temp1->left);
  			cout<<temp1->info<<"  ";
  			if( temp1->right!=NULL )
		 		paste(temp1->right);
 		 	return 0;

		}
		int print(int x)
		{
			paste(root);
			cout<<endl;
			traversal(root, x);	 
		}
		
		
};

int main()
{
 	BST b;
	for(int i=0; i<15; i++)
	{
		b.insert();
	}
	b.print(3);

}
